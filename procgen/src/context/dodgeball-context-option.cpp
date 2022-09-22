#include "dodgeball-context-option.h"
#include "../cpp-utils.h"
#include "string.h"

DodgeballContextOption::DodgeballContextOption(/* args */)
{
}
    

DodgeballContextOption::~DodgeballContextOption()
{
}

void DodgeballContextOption::parse_options(VecOptions *opts)
{
    // opts->consume_float("start_r", &start_r);
    opts->consume_int("world_dim", &world_dim, true, 20); // The dimension of the world
    opts->consume_int("fire_interval", &fire_interval, true, 7); // The interval of the agent's fire
    opts->consume_float("thickness", &thickness, true, 0.6); // The thickness of the walls
    opts->consume_float("enemy_r", &enemy_r, true, 1.0); // The radius of the enemy
    opts->consume_float("ball_r", &ball_r, true, 0.5); // The radius of the ball
    opts->consume_float("ball_vscale", &ball_vscale, true, 0.5); // The speed of the ball
    opts->consume_float("maxspeed", &maxspeed, true, 0.75); // The maximum speed of the agent
    opts->consume_float("exit_r", &exit_r, true, 1.5); // The radius of the exit erea
    opts->consume_float("enemy_speed", &enemy_speed, true, 0.05); // The speed of the enemy
    opts->consume_int("enemy_reward", &enemy_reward, true, 2); // The reward of killing an enemy
    opts->consume_int("num_iterations", &num_iterations, true, 2);  // The number of walls increases with iterations
    opts->consume_bool("allow_left_exit", &allow_left_exit, true, true); 
    opts->consume_bool("allow_right_exit", &allow_right_exit, true, true);
    opts->consume_bool("allow_top_exit", &allow_top_exit, true, true);
    opts->consume_bool("allow_bottom_exit", &allow_bottom_exit, true, true);

    opts->consume_int("max_extra_enemies", &max_extra_enemies, true, 3); // The maximum number of extra enemies
    opts->consume_int("base_num_enemies", &base_num_enemies, true, 3); // The number of base enemies. The sum of base_num_enemies and max_extra_enemies is the number of all enemies

    opts->consume_float("completion_bonus", &completion_bonus, true, 10.0); // The bonus of completing the task
    opts->consume_int("max_episode_steps", &max_episode_steps, true, 1000);
}


void DodgeballContextOption::copy_options(DodgeballContextOption *opts)
{
    // opts->start_r = opts->start_r;
    world_dim = opts->world_dim;
    fire_interval = opts->fire_interval;
    thickness = opts->thickness;
    enemy_r = opts->enemy_r;
    ball_r = opts->ball_r;
    ball_vscale = opts->ball_vscale;
    maxspeed = opts->maxspeed;
    exit_r = opts->exit_r;
    enemy_speed = opts->enemy_speed;
    enemy_reward = opts->enemy_reward;
    num_iterations = opts->num_iterations;
    allow_left_exit = opts->allow_left_exit;
    allow_right_exit = opts->allow_right_exit;
    allow_top_exit = opts->allow_top_exit;
    allow_bottom_exit = opts->allow_bottom_exit;

    max_extra_enemies = opts->max_extra_enemies;
    base_num_enemies = opts->base_num_enemies;
    completion_bonus = opts->completion_bonus;

    max_episode_steps = opts->max_episode_steps;
}

void DodgeballContextOption::init_episode_context(struct libenv_options *e_context)
{
    int count_num = 2;
    e_context->count = count_num;
    e_context->items = new struct libenv_option[count_num];

    strcpy(e_context->items[0].name, "exit_wall_id");
    e_context->items[0].dtype = LIBENV_DTYPE_INT32;
    e_context->items[0].count = 1;
    e_context->items[0].data = new int32_t[1];

    strcpy(e_context->items[1].name, "num_enemies");
    e_context->items[1].dtype = LIBENV_DTYPE_INT32;
    e_context->items[1].count = 1;
    e_context->items[1].data = new int32_t[1];
}