#include "leaper-context-option.h"
#include "../cpp-utils.h"
#include "string.h"

LeaperContextOption::LeaperContextOption(/* args */) {
}

LeaperContextOption::~LeaperContextOption() {
}

void LeaperContextOption::parse_options(VecOptions *opts) {
    opts->consume_int("world_dim", &world_dim, true, 9);
    opts->consume_float("min_car_speed", &min_car_speed, true, 0.03f);
    opts->consume_float("max_car_speed", &max_car_speed, true, 0.12f);
    opts->consume_float("min_log_speed", &min_log_speed, true, 0.025f);
    opts->consume_float("max_log_speed", &max_log_speed, true, 0.75f);
    opts->consume_int("max_extra_space", &max_extra_space, true, 0);
    opts->consume_int("max_road", &max_road, true, 3);
    opts->consume_int("min_road", &min_road, true, 0);
    opts->consume_int("max_log", &max_log, true, 3);
    opts->consume_int("min_log", &min_log, true, 0);
    opts->consume_float("car_left_prob", &car_left_prob, true, .5f);
    opts->consume_float("goal_reward", &goal_reward, true, 10.0);
    opts->consume_int("max_episode_steps", &max_episode_steps, true, 1000);
}

void LeaperContextOption::init_episode_context(struct libenv_options *e_context) {
    int count_num = 2;
    e_context->count = count_num;
    e_context->items = new struct libenv_option[count_num];

    strcpy(e_context->items[0].name, "num_road_lanes");
    e_context->items[0].dtype = LIBENV_DTYPE_INT32;
    e_context->items[0].count = 1;
    e_context->items[0].data = new int32_t[1];

    strcpy(e_context->items[1].name, "num_log_lanes");
    e_context->items[1].dtype = LIBENV_DTYPE_INT32;
    e_context->items[1].count = 1;
    e_context->items[1].data = new int32_t[1];
}


void LeaperContextOption::copy_options(LeaperContextOption *opts) {
    world_dim = opts->world_dim;
    min_car_speed = opts->min_car_speed;
    max_car_speed = opts->max_car_speed;
    min_log_speed = opts->min_log_speed;
    max_log_speed = opts->max_log_speed;
    max_extra_space = opts->max_extra_space;
    max_road = opts->max_road;
    min_road = opts->min_road;
    max_log = opts->max_log;
    min_log = opts->min_log;
    car_left_prob = opts->car_left_prob;
    goal_reward = opts->goal_reward;
    max_episode_steps = opts->max_episode_steps;
}