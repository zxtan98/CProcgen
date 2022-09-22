#include "../basic-abstract-game.h"
#include "../assetgen.h"
#include "../context/bossfight-context-option.h"
#include <set>
#include <queue>

const std::string NAME = "bossfight";

const int COMPLETION_BONUS = 10.0f;
const int POSITIVE_REWARD = 1.0f;

const int PLAYER_BULLET = 1;
const int BOSS = 2;
const int SHIELDS = 3;
const int ENEMY_BULLET = 4;
const int LASER_TRAIL = 5;
const int REFLECTED_BULLET = 6;
const int BARRIER = 7;

const float BOSS_R = 3;

const int NUM_ATTACK_MODES = 4;

const int NUM_LASER_THEMES = 3;

const int PLAYER_BULLET_VEL = 1;

const int BOTTOM_MARGIN = 6;

const int BOSS_VEL_TIMEOUT = 20;
const int BOSS_DAMAGED_TIMEOUT = 40;

class BossfightGame : public BasicAbstractGame {
  public:
    std::shared_ptr<Entity> boss, shields;
    std::vector<int> attack_modes;
    int last_fire_time = 0; // 上一次fire的时间（两次fire之间有间隙）
    int time_to_swap = 0;
    int invulnerable_duration = 0;
    int vulnerable_duration = 0;
    int num_rounds = 0;         // 总共有多少round（Boss每个有多个round的状态）
    int round_num = 0;          // 当前是第几个round
    int round_health = 0;       // 每个round，boss的血量
    int boss_vel_timeout = 0;   // boss切换方向的时间间隔
    int curr_vel_timeout = 0;   // 当前的时间间隔
    int attack_mode = 0;        // 攻击模式
    int player_laser_theme = 0; // 玩家的子弹皮肤
    int boss_laser_theme = 0;   // boss的子弹皮肤
    int damaged_until_time = 0;

    bool shields_are_up = false; // 是否有护盾
    bool barriers_moves_right = false; // 没有用到的变量
    float base_fire_prob = 0.0f;
    float boss_bullet_vel = 0.0f;
    float barrier_vel = 0.0f;
    float barrier_spawn_prob = 0.0f;
    float rand_pct = 0.0f;
    float rand_fire_pct = 0.0f;
    float rand_pct_x = 0.0f;
    float rand_pct_y = 0.0f;

    BossfightGame()
        : BasicAbstractGame(NAME) {
        timeout = 4000;

        main_width = 20;
        main_height = 20;

        mixrate = .5;
        maxspeed = 0.85f;
    }

    void load_background_images() override {
        main_bg_images_ptr = &space_backgrounds;
    }

    void asset_for_type(int type, std::vector<std::string> &names) override {
        if (type == PLAYER) {
            names.push_back("misc_assets/playerShip1_blue.png");
            names.push_back("misc_assets/playerShip1_green.png");
            names.push_back("misc_assets/playerShip2_orange.png");
            names.push_back("misc_assets/playerShip3_red.png");
        } else if (type == BOSS) {
            names.push_back("misc_assets/enemyShipBlack1.png");
            names.push_back("misc_assets/enemyShipBlue2.png");
            names.push_back("misc_assets/enemyShipGreen3.png");
            names.push_back("misc_assets/enemyShipRed4.png");
        } else if (type == ENEMY_BULLET) {
            names.push_back("misc_assets/laserGreen14.png");
            names.push_back("misc_assets/laserRed11.png");
            names.push_back("misc_assets/laserBlue09.png");
        } else if (type == PLAYER_BULLET) {
            names.push_back("misc_assets/laserGreen14.png");
            names.push_back("misc_assets/laserRed11.png");
            names.push_back("misc_assets/laserBlue09.png");
        } else if (type == SHIELDS) {
            names.push_back("misc_assets/shield2.png");
        } else if (type == BARRIER) {
            names.push_back("misc_assets/spaceMeteors_001.png");
            names.push_back("misc_assets/spaceMeteors_002.png");
            names.push_back("misc_assets/spaceMeteors_003.png");
            names.push_back("misc_assets/spaceMeteors_004.png");
            names.push_back("misc_assets/meteorGrey_big1.png");
            names.push_back("misc_assets/meteorGrey_big2.png");
            names.push_back("misc_assets/meteorGrey_big3.png");
            names.push_back("misc_assets/meteorGrey_big4.png");
        }
    }

    void handle_agent_collision(const std::shared_ptr<Entity> &obj) override {
        BasicAbstractGame::handle_agent_collision(obj);

        if (obj->type == BOSS) {
            step_data.done = true;
        } else if (obj->type == BARRIER) {
            step_data.done = true;
        }
        if (obj->type == ENEMY_BULLET) {
            step_data.done = true;
        }
    }

    bool should_draw_entity(const std::shared_ptr<Entity> &entity) override {
        if (entity->type == SHIELDS)
            return shields_are_up && bossfight_context_option->enable_shield;

        return BasicAbstractGame::should_draw_entity(entity);
    }

    void handle_collision(const std::shared_ptr<Entity> &src, const std::shared_ptr<Entity> &target) override {
        if (src->type == PLAYER_BULLET) {
            bool will_erase = false;

            if (target->type == SHIELDS) {
                if (shields_are_up && bossfight_context_option->enable_shield) {
                    src->type = REFLECTED_BULLET;

                    float theta = PI * (1.25 + .5 * rand_pct);
                    src->vy = bossfight_context_option->player_bullet_vel * sin(theta) * .5;
                    src->vx = bossfight_context_option->player_bullet_vel * cos(theta) * .5;
                    src->expire_time = 4;
                    src->life_time = 0;
                    src->alpha_decay = 0.8f;
                }
            } else if (target->type == BOSS) {
                if (!(shields_are_up && bossfight_context_option->enable_shield)) {
                    target->health -= 1;
                    will_erase = true;

                    if (int(target->health) % round_health == 0) {
                        step_data.reward += bossfight_context_option->positive_reward;

                        if (target->health == 0) {
                            step_data.done = true;
                            step_data.reward += bossfight_context_option->completion_bonus;
                            step_data.level_complete = true;
                        } else {
                            round_num++;
                            prepare_boss();
                            curr_vel_timeout = bossfight_context_option->boss_damage_timeout;
                            damaged_until_time = cur_time + bossfight_context_option->boss_damage_timeout;
                        }
                    }
                }
            }

            if (will_erase && !src->will_erase) {
                src->will_erase = true;

                auto explosion = spawn_child(src, EXPLOSION, .5 * src->rx);
                explosion->vx = target->vx;
                explosion->vy = target->vy;
            }
        } else if (src->type == BARRIER) {
            if (target->type == ENEMY_BULLET || target->type == PLAYER_BULLET) {
                target->will_erase = true;
                spawn_child(target, EXPLOSION, .5 * target->rx);
            } else if (target->type == LASER_TRAIL) {
                target->will_erase = true;
            }

            if (src->health <= 0) {
                if (!src->will_erase) {
                    auto explosion = spawn_child(src, EXPLOSION, .5 * src->rx);
                    explosion->vx = src->vx;
                    explosion->vy = src->vy;
                }

                src->will_erase = true;
            }
        }
    }

    void prepare_boss() {
        shields_are_up = true;
        curr_vel_timeout = boss_vel_timeout;
        time_to_swap = invulnerable_duration;
        attack_mode = attack_modes[round_num % attack_modes.size()];
        boss->vx = 0;
        boss->vy = 0;
    }

    void game_reset() override {
        bossfight_context_option->copy_options((BossfightContextOption *)assigned_context_option);
        BasicAbstractGame::game_reset();

        timeout = bossfight_context_option->max_episode_steps;

        damaged_until_time = 0;
        last_fire_time = 0;
        boss_bullet_vel = options.distribution_mode == EasyMode ? .5 : .75;
        int max_extra_invulnerable = options.distribution_mode == EasyMode ? 1 : 3;

        boss_bullet_vel = bossfight_context_option->boss_bullet_vel;
        max_extra_invulnerable = bossfight_context_option->max_extra_invulnerable;

        options.center_agent = false;

        // 添加Boss实体
        boss = add_entity(main_width / 2, main_height / 2, 0, 0, bossfight_context_option->boss_r, BOSS);
        choose_random_theme(boss);
        match_aspect_ratio(boss);

        // 给Boss添加护盾图层
        shields = add_entity_rxy(boss->x, boss->y, 0, 0, 1.2 * boss->rx, 1.2 * boss->ry, SHIELDS);

        // Boss改变方向的timeout
        boss_vel_timeout = bossfight_context_option->boss_vel_timeout;
        base_fire_prob = 0.1f;
        // 生成这个level的rounds数量和每个round中boss的血量
        int health_range = bossfight_context_option->max_round_health - bossfight_context_option->min_round_health + 1;
        round_health = rand_gen.randn(health_range) + bossfight_context_option->min_round_health;
        int rounds_range = bossfight_context_option->max_rounds_num - bossfight_context_option->min_rounds_num + 1;
        num_rounds = rand_gen.randn(rounds_range) + bossfight_context_option->min_rounds_num;
        invulnerable_duration = 2 + rand_gen.randn(max_extra_invulnerable + 1);
        vulnerable_duration = 500; // essentially infinite

        boss->health = round_health * num_rounds;

        choose_random_theme(agent);

        player_laser_theme = rand_gen.randn(NUM_LASER_THEMES);
        boss_laser_theme = rand_gen.randn(NUM_LASER_THEMES);

        attack_modes.clear();

        int modes_num = 0;
        int num_map[4] = {0, 0, 0, 0};
        if (bossfight_context_option->enable_attack_mode_0) {
            num_map[modes_num++] = 0;
        }
        if (bossfight_context_option->enable_attack_mode_1) {
            num_map[modes_num++] = 1;
        }
        if (bossfight_context_option->enable_attack_mode_2) {
            num_map[modes_num++] = 2;
        }
        if (bossfight_context_option->enable_attack_mode_3) {
            num_map[modes_num++] = 3;
        }
        for (int i = 0; i < num_rounds; i++) {
            attack_modes.push_back(
                num_map[rand_gen.randn(modes_num)]
            );
        }

        round_num = 0;
        prepare_boss();

        agent->rx = .75;
        match_aspect_ratio(agent);
        reposition_agent();
        agent->y = agent->ry;

        barrier_vel = 0.1f;
        barriers_moves_right = rand_gen.randbool();
        barrier_spawn_prob = 0.025f;

        spawn_barriers();

        // for (int i = 0; i < main_width / barrier_vel; i++) {
        //     spawn_barriers();
        //     step_entities(entities);
        // }
        ((int32_t *)e_context.items[0].data)[0] = round_health;
        ((int32_t *)e_context.items[1].data)[0] = num_rounds;
    }

    void boss_fire(float bullet_r, float vel, float theta) {
        auto new_bullet = add_entity(boss->x, boss->y, vel * cos(theta), vel * sin(theta), bullet_r, ENEMY_BULLET);
        new_bullet->image_theme = boss_laser_theme;
        new_bullet->expire_time = 50;
        new_bullet->vrot = PI / 8;
    }

    void passive_attack_mode() {
        if (rand_fire_pct < base_fire_prob) {
            boss_fire(.5, boss_bullet_vel, PI * (1 + rand_pct));
        }
    }

    void attack_mode_0() {
        // 每过8个frame发射五颗向前的子弹
        if (cur_time % 8 == 0) {
            for (int i = 0; i < 5; i++) {
                boss_fire(.5, boss_bullet_vel, PI * 1.5 + (i - 2) * PI / 8);
            }
        }
    }

    void attack_mode_1() {
        // 每过5个frame发射四颗子弹，方向为360度四等分，每过一定的frame后会微幅改变方向
        int dt = 5;
        if (cur_time % dt == 0) {
            int k = cur_time / dt;
            k = abs(8 - (k % 16));
            for (int i = 0; i < 4; i++) {
                boss_fire(.5, boss_bullet_vel, PI * (1.25 + .5 * k / 8.0) + i * PI / 2);
            }
        }
    }

    void attack_mode_2() {
        // 每过10个frame发射8颗子弹，方向为360度八等分
        if (cur_time % 10 == 0) {
            int num_bullets = 8;
            float offset = rand_pct * 2 * PI;
            for (int i = 0; i < num_bullets; i++) {
                float vel = boss_bullet_vel;
                float theta = 2 * PI / num_bullets * i + offset;
                boss_fire(.5, vel, theta);
            }
        }
    }

    void attack_mode_3() {
        // 每过4个frame发射一颗子弹，方向为随机
        if (cur_time % 4 == 0) {
            boss_fire(.5, boss_bullet_vel, PI * (1 + rand_pct));
        }
    }

    void damaged_mode() {
        if (cur_time % 3 == 0) {
            float pos_x = boss->x + (2 * rand_pct_x - 1) * boss->rx;
            float pos_y = boss->y + (2 * rand_pct_y - 1) * boss->ry;
            add_entity(pos_x, pos_y, 0, 0, .75, EXPLOSION);
        }
    }

    void active_attack() {
        if (attack_mode == 0) {
            attack_mode_0();
        } else if (attack_mode == 1) {
            attack_mode_1();
        } else if (attack_mode == 2) {
            attack_mode_2();
        } else if (attack_mode == 3) {
            attack_mode_3();
        }
    }

    void spawn_barriers() {
        // 生成陨石障碍物
        int barriers_range = bossfight_context_option->max_barriers_num - bossfight_context_option->min_barriers_num + 1;
        int num_barriers = rand_gen.randn(barriers_range) + bossfight_context_option->min_barriers_num ;
        ((int32_t *)e_context.items[2].data)[0] = num_barriers;
        for (int i = 0; i < num_barriers; i++) {
            float barrier_r = 0.6f;
            float min_barrier_y = 2 * agent->ry + barrier_r + .5;
            float ent_y = rand_gen.rand01() * (bossfight_context_option->bottom_margin - min_barrier_y - barrier_r) + min_barrier_y;
            float ent_x = rand_gen.rand01() * (main_width - 2 * barrier_r) + barrier_r;

            auto ent = std::make_shared<Entity>(ent_x, ent_y, 0, 0, barrier_r, BARRIER);
            choose_random_theme(ent);
            match_aspect_ratio(ent);
            ent->health = 3;
            ent->collides_with_entities = true;

            if (!has_any_collision(ent)) {
                entities.push_back(ent);
            }
        }
    }

    void game_step() override {
        BasicAbstractGame::game_step();

        // spawn_barriers();
        // 将shields的位置设置为boss的位置
        shields->x = boss->x;
        shields->y = boss->y;

        rand_pct = rand_gen.rand01();
        rand_fire_pct = rand_gen.rand01();
        rand_pct_x = rand_gen.rand01();
        rand_pct_y = rand_gen.rand01();

        if (curr_vel_timeout <= 0) {
            // 当boss的一次移动超时候，重新设置移动方向
            float dest_x = rand_pct_x * (main_width - 2 * bossfight_context_option->boss_r) + bossfight_context_option->boss_r;
            float dest_y = rand_pct_y * (main_height - 2 * bossfight_context_option->boss_r - bossfight_context_option->bottom_margin) + bossfight_context_option->boss_r + bossfight_context_option->bottom_margin;
            boss->vx = (dest_x - boss->x) / boss_vel_timeout;
            boss->vy = (dest_y - boss->y) / boss_vel_timeout;
            curr_vel_timeout = boss_vel_timeout;

            if (time_to_swap > 0) {
                time_to_swap -= 1;
            } else {
                if (shields_are_up && bossfight_context_option->enable_shield) {
                    time_to_swap = vulnerable_duration;
                } else {
                    time_to_swap = invulnerable_duration;
                }

                shields_are_up = !shields_are_up;
            }
        } else {
            curr_vel_timeout -= 1;
        }

        if (special_action == 1 && (cur_time - last_fire_time) >= 3) {
            // 生成agent的子弹， agent对物体进行fire
            auto new_bullet = add_entity(agent->x, agent->y, 0, bossfight_context_option->player_bullet_vel, .25, PLAYER_BULLET);
            new_bullet->image_theme = player_laser_theme;
            new_bullet->collides_with_entities = true;
            new_bullet->expire_time = 25;
            last_fire_time = cur_time;
        }

        if (damaged_until_time >= cur_time) {
            // damage模式，boss将会出现爆炸效果
            damaged_mode();
        } else if (shields_are_up) {
            // shields是可见的
            active_attack();
        } else {
            passive_attack_mode();
        }

        for (int i = (int)(entities.size()) - 1; i >= 0; i--) {
            // 移动所有物体
            auto ent = entities[i];

            if (ent->type == ENEMY_BULLET) {
                float v_trail = .5;
                auto trail = add_entity_rxy(ent->x, ent->y, ent->vx * v_trail, ent->vy * v_trail, ent->rx, ent->ry, LASER_TRAIL);
                trail->alpha_decay = 0.7f;
                trail->image_type = ENEMY_BULLET;
                trail->image_theme = boss_laser_theme;
                trail->vrot = ent->vrot;
                trail->rotation = ent->rotation;
                trail->expire_time = 8;
            }
        }
    }

    void serialize(WriteBuffer *b) override {
        BasicAbstractGame::serialize(b);
        b->write_vector_int(attack_modes);
        b->write_int(last_fire_time);
        b->write_int(time_to_swap);
        b->write_int(invulnerable_duration);
        b->write_int(vulnerable_duration);
        b->write_int(num_rounds);
        b->write_int(round_num);
        b->write_int(round_health);
        b->write_int(boss_vel_timeout);
        b->write_int(curr_vel_timeout);
        b->write_int(attack_mode);
        b->write_int(player_laser_theme);
        b->write_int(boss_laser_theme);
        b->write_int(damaged_until_time);
        b->write_bool(shields_are_up);
        b->write_bool(barriers_moves_right);
        b->write_float(base_fire_prob);
        b->write_float(boss_bullet_vel);
        b->write_float(barrier_vel);
        b->write_float(barrier_spawn_prob);
        b->write_float(rand_pct);
        b->write_float(rand_fire_pct);
        b->write_float(rand_pct_x);
        b->write_float(rand_pct_y);
    }

    void deserialize(ReadBuffer *b) override {
        BasicAbstractGame::deserialize(b);
        attack_modes = b->read_vector_int();
        last_fire_time = b->read_int();
        time_to_swap = b->read_int();
        invulnerable_duration = b->read_int();
        vulnerable_duration = b->read_int();
        num_rounds = b->read_int();
        round_num = b->read_int();
        round_health = b->read_int();
        boss_vel_timeout = b->read_int();
        curr_vel_timeout = b->read_int();
        attack_mode = b->read_int();
        player_laser_theme = b->read_int();
        boss_laser_theme = b->read_int();
        damaged_until_time = b->read_int();
        shields_are_up = b->read_bool();
        barriers_moves_right = b->read_bool();
        base_fire_prob = b->read_float();
        boss_bullet_vel = b->read_float();
        barrier_vel = b->read_float();
        barrier_spawn_prob = b->read_float();
        rand_pct = b->read_float();
        rand_fire_pct = b->read_float();
        rand_pct_x = b->read_float();
        rand_pct_y = b->read_float();

        int boss_idx = find_entity_index(BOSS);
        fassert(boss_idx >= 0);
        boss = entities[boss_idx];

        int shields_idx = find_entity_index(SHIELDS);
        fassert(shields_idx >= 0);
        shields = entities[shields_idx];
    }
};

REGISTER_GAME(NAME, BossfightGame);
