#include "plunder-context-option.h"
#include "../cpp-utils.h"

PlunderContextOption::PlunderContextOption(/* args */)
{
}
    

PlunderContextOption::~PlunderContextOption()
{
}

void PlunderContextOption::parse_options(VecOptions *opts)
{
    opts->consume_float("target_time_reward", &target_time_reward, true, 0.1);
    opts->consume_float("target_time_penalty", &target_time_penalty, true, 0.1);
    opts->consume_float("step_time_penalty", &step_time_penalty, true, 0.0015);
    opts->consume_float("fire_time_penalty", &fire_time_penalty, true, 0.02);
    opts->consume_int("target_quota", &target_quota, true, 20);
    opts->consume_float("spawn_prob", &spawn_prob, true, 0.06);
    opts->consume_int("num_lanes", &num_lanes, true, 5);
    opts->consume_float("r_scale", &r_scale, true, 1.5);
    opts->consume_float("left_prob", &left_prob, true, 0.5);
    opts->consume_float("enemy_prob", &enemy_prob, true, 0.5);
    opts->consume_float("max_speed", &max_speed, true, 0.15);
    opts->consume_float("min_speed", &min_speed, true, 0.25);

    opts->consume_float("completion_bonus", &completion_bonus, true, 10.0);
    opts->consume_float("positive_reward", &positive_reward, true, 1.0);
    opts->consume_int("max_episode_steps", &max_episode_steps, true, 1000);
}

void PlunderContextOption::copy_options(PlunderContextOption *opts)
{
    target_time_reward = opts->target_time_reward;
    target_time_penalty = opts->target_time_penalty;
    step_time_penalty = opts->step_time_penalty;
    fire_time_penalty = opts->fire_time_penalty;
    target_quota = opts->target_quota;
    spawn_prob = opts->spawn_prob;
    num_lanes = opts->num_lanes;
    r_scale = opts->r_scale;
    left_prob = opts->left_prob;
    enemy_prob = opts->enemy_prob;
    max_speed = opts->max_speed;
    min_speed = opts->min_speed;

    completion_bonus = opts->completion_bonus;
    positive_reward = opts->positive_reward;

    max_episode_steps = opts->max_episode_steps;
}