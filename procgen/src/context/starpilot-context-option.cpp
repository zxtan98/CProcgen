#include "starpilot-context-option.h"
#include "../cpp-utils.h"
#include "string.h"

// define the intmax
#define INTMAX 2147483647

StarpilotContextOption::StarpilotContextOption(/* args */)
{
}
    

StarpilotContextOption::~StarpilotContextOption()
{
}

void StarpilotContextOption::parse_options(VecOptions *opts)
{
    // opts->consume_float("start_r", &start_r);
    opts->consume_float("maxspeed", &maxspeed, true, 0.75);
    opts->consume_int("max_group_size", &max_group_size, true, 5);
    opts->consume_bool("can_spawn_left", &can_spawn_left, true, false);
    opts->consume_float("left_prob", &left_prob, true, 0.1);
    opts->consume_int("min_enemy_delta_t", &min_enemy_delta_t, true, 10);
    opts->consume_int("max_enemy_delta_t", &max_enemy_delta_t, true, 30);
    opts->consume_int("flyer_prob_weight", &flyer_prob_weight, true, 1);
    opts->consume_int("meteor_prob_weight", &meteor_prob_weight, true, 0);
    opts->consume_int("cloud_prob_weight", &cloud_prob_weight, true, 0);
    opts->consume_int("turret_prob_weight", &turret_prob_weight, true, 0);
    opts->consume_int("fastflyer_prob_weight", &fastflyer_prob_weight, true, 0);
    opts->consume_int("max_time", &max_time, true, INTMAX);
    opts->consume_int("min_time", &min_time, true, 0);

    opts->consume_float("completion_bonus", &completion_bonus, true, 10.0);
    opts->consume_float("enemy_reward", &enemy_reward, true, 1.0);
    opts->consume_int("max_episode_steps", &max_episode_steps, true, 1000);
}

void StarpilotContextOption::copy_options(StarpilotContextOption *opts)
{
    maxspeed = opts->maxspeed;
    max_group_size = opts->max_group_size;
    can_spawn_left = opts->can_spawn_left;
    left_prob = opts->left_prob;
    min_enemy_delta_t = opts->min_enemy_delta_t;
    max_enemy_delta_t = opts->max_enemy_delta_t;
    flyer_prob_weight = opts->flyer_prob_weight;
    meteor_prob_weight = opts->meteor_prob_weight;
    cloud_prob_weight = opts->cloud_prob_weight;
    turret_prob_weight = opts->turret_prob_weight;
    fastflyer_prob_weight = opts->fastflyer_prob_weight;
    max_time = opts->max_time;
    min_time = opts->min_time;

    completion_bonus = opts->completion_bonus;
    enemy_reward = opts->enemy_reward;

    max_episode_steps = opts->max_episode_steps;
}

void StarpilotContextOption::init_episode_context(struct libenv_options *e_context)
{
    int count_num = 1;
    e_context->count = count_num;
    e_context->items = new struct libenv_option[count_num];

    strcpy(e_context->items[0].name, "time");
    e_context->items[0].dtype = LIBENV_DTYPE_INT32;
    e_context->items[0].count = 1;
    e_context->items[0].data = new int32_t[1];
}