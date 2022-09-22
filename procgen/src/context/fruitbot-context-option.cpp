#include "fruitbot-context-option.h"
#include "../cpp-utils.h"
#include "string.h"

FruitbotContextOption::FruitbotContextOption(/* args */) {
}

FruitbotContextOption::~FruitbotContextOption() {
}

void FruitbotContextOption::parse_options(VecOptions *opts) {
    // opts->consume_float("start_r", &start_r);
    opts->consume_int("main_width", &main_width, true, 10);
    opts->consume_int("main_height", &main_height, true, 60);
    opts->consume_int("min_sep", &min_sep, true, 4);
    opts->consume_int("num_walls", &num_walls, true, 10);
    opts->consume_int("object_group_size", &object_group_size, true, 6);
    opts->consume_int("buf_h", &buf_h, true, 4);
    opts->consume_float("door_prob", &door_prob, true, .125);
    opts->consume_float("min_pct", &min_pct, true, .2); // If this value is high, the distance between two gate is big, thus aget need move more steps to get to the other gate.
    opts->consume_int("min_fruits", &min_fruits, true, 10);
    opts->consume_int("max_fruits", &max_fruits, true, 19);
    opts->consume_int("min_foods", &min_foods, true, 10);
    opts->consume_int("max_foods", &max_foods, true, 19);

    opts->consume_float("completion_bonus", &completion_bonus, true, 1.0);
    opts->consume_float("positive_reward", &positive_reward, true, 1.);
    opts->consume_float("penalty", &penalty, true, -4.);
    opts->consume_int("max_episode_steps", &max_episode_steps, true, 1000);
}

void FruitbotContextOption::copy_options(FruitbotContextOption *opts) {
    // opts->start_r = opts->start_r;
    main_width = opts->main_width;
    main_height = opts->main_height;
    min_sep = opts->min_sep;
    num_walls = opts->num_walls;
    object_group_size = opts->object_group_size;
    buf_h = opts->buf_h;
    door_prob = opts->door_prob;
    min_pct = opts->min_pct;
    min_fruits = opts->min_fruits;
    max_fruits = opts->max_fruits;
    min_foods = opts->min_foods;
    max_foods = opts->max_foods;

    completion_bonus = opts->completion_bonus;
    positive_reward = opts->positive_reward;
    penalty = opts->penalty;
    max_episode_steps = opts->max_episode_steps;
}

void FruitbotContextOption::init_episode_context(struct libenv_options *e_context)
{
    int count_num = 2;
    e_context->count = count_num;
    e_context->items = new struct libenv_option[count_num];

    strcpy(e_context->items[0].name, "num_good");
    e_context->items[0].dtype = LIBENV_DTYPE_INT32;
    e_context->items[0].count = 1;
    e_context->items[0].data = new int32_t[1];

    strcpy(e_context->items[1].name, "num_bad");
    e_context->items[1].dtype = LIBENV_DTYPE_INT32;
    e_context->items[1].count = 1;
    e_context->items[1].data = new int32_t[1];
}