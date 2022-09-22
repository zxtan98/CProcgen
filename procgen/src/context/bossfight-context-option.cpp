#include "bossfight-context-option.h"
#include "../cpp-utils.h"
#include "string.h"

BossfightContextOption::BossfightContextOption(/* args */) {
}

BossfightContextOption::~BossfightContextOption() {
}

void BossfightContextOption::parse_options(VecOptions *opts) {
    opts->consume_int("completion_bonus", &completion_bonus, true, 10);
    opts->consume_int("positive_reward", &positive_reward, true, 1);

    opts->consume_float("boss_r", &boss_r, true, 3.0);
    opts->consume_int("player_bullet_vel", &player_bullet_vel, true, 1);
    opts->consume_int("bottom_margin", &bottom_margin, true, 6);

    opts->consume_float("boss_bullet_vel", &boss_bullet_vel, true, 0.5);
    opts->consume_int("max_extra_invulnerable", &max_extra_invulnerable, true, 1);

    opts->consume_int("boss_vel_timeout", &boss_vel_timeout, true, 20);
    opts->consume_int("boss_damage_timeout", &boss_damage_timeout, true, 40);

    opts->consume_int("max_rounds_num", &max_rounds_num, true, 5);
    opts->consume_int("min_rounds_num", &min_rounds_num, true, 1);
    opts->consume_int("max_round_health", &max_round_health, true, 9);
    opts->consume_int("min_round_health", &min_round_health, true, 1);

    opts->consume_bool("enable_attack_mode_0", &enable_attack_mode_0, true, true);
    opts->consume_bool("enable_attack_mode_1", &enable_attack_mode_1, true, true);
    opts->consume_bool("enable_attack_mode_2", &enable_attack_mode_2, true, true);
    opts->consume_bool("enable_attack_mode_3", &enable_attack_mode_3, true, true);
    
    opts->consume_bool("enable_shield", &enable_shield, true, true);

    opts->consume_int("max_barriers_num", &max_barriers_num, true, 3);
    opts->consume_int("min_barriers_num", &min_barriers_num, true, 1);

    opts->consume_int("max_episode_steps", &max_episode_steps, true, 1000);
}

void BossfightContextOption::copy_options(BossfightContextOption *opts){
    completion_bonus = opts->completion_bonus;
    positive_reward = opts->positive_reward;

    boss_r = opts->boss_r;
    player_bullet_vel = opts->player_bullet_vel;
    bottom_margin = opts->bottom_margin;

    boss_bullet_vel = opts->boss_bullet_vel;
    max_extra_invulnerable = opts->max_extra_invulnerable;

    boss_vel_timeout = opts->boss_vel_timeout;
    boss_damage_timeout = opts->boss_damage_timeout;

    max_rounds_num = opts->max_rounds_num;
    min_rounds_num = opts->min_rounds_num;
    max_round_health = opts->max_round_health;
    min_round_health = opts->min_round_health;

    enable_attack_mode_0 = opts->enable_attack_mode_0;
    enable_attack_mode_1 = opts->enable_attack_mode_1;
    enable_attack_mode_2 = opts->enable_attack_mode_2;
    enable_attack_mode_3 = opts->enable_attack_mode_3;

    enable_shield = opts->enable_shield;

    max_barriers_num = opts->max_barriers_num;
    min_barriers_num = opts->min_barriers_num;

    max_episode_steps = opts->max_episode_steps;
}

void BossfightContextOption::init_episode_context(struct libenv_options *e_context){
    int count_num = 3;
    e_context->count = count_num;
    e_context->items = new struct libenv_option[count_num];

    strcpy(e_context->items[0].name, "round_health");
    e_context->items[0].dtype = LIBENV_DTYPE_INT32;
    e_context->items[0].count = 1;
    e_context->items[0].data = new int32_t[1];

    strcpy(e_context->items[1].name, "num_rounds");
    e_context->items[1].dtype = LIBENV_DTYPE_INT32;
    e_context->items[1].count = 1;
    e_context->items[1].data = new int32_t[1];

    strcpy(e_context->items[2].name, "num_barriers");
    e_context->items[2].dtype = LIBENV_DTYPE_INT32;
    e_context->items[2].count = 1;
    e_context->items[2].data = new int32_t[1];
}