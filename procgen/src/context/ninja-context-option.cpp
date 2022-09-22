#include "ninja-context-option.h"
#include "../cpp-utils.h"
#include "string.h"

NinjaContextOption::NinjaContextOption(/* args */) {
}

NinjaContextOption::~NinjaContextOption() {
}

void NinjaContextOption::parse_options(VecOptions *opts) {
    opts->consume_float("gravity", &gravity, true, .2);
    opts->consume_float("max_jump", &max_jump, true, 1.25);
    opts->consume_float("jump_charge_inc", &jump_charge_inc, true, .25);
    opts->consume_float("air_control", &air_control, true, .15);
    opts->consume_float("maxspeed", &maxspeed, true, .5);
    opts->consume_int("visibility", &visibility, true, 16);
    opts->consume_float("bomb_prob", &bomb_prob, true, .5); // The probability of a bomb appearing in each section
    opts->consume_int("min_num_sections", &min_num_sections, true, 3);
    opts->consume_int("max_num_sections", &max_num_sections, true, 6);
    opts->consume_int("max_difficulty", &max_difficulty, true, 3);
    opts->consume_int("min_difficulty", &min_difficulty, true, 1);
    opts->consume_int("max_gap_inc", &max_gap_inc, true, 1);

    opts->consume_float("goal_reward", &goal_reward, true, 10.0);
    opts->consume_int("max_episode_steps", &max_episode_steps, true, 1000);
}

void NinjaContextOption::copy_options(NinjaContextOption *opts) {
    gravity = opts->gravity;
    max_jump = opts->max_jump;
    jump_charge_inc = opts->jump_charge_inc;
    air_control = opts->air_control;
    maxspeed = opts->maxspeed;
    visibility = opts->visibility;
    bomb_prob = opts->bomb_prob;
    min_num_sections = opts->min_num_sections;
    max_num_sections = opts->max_num_sections;
    max_difficulty = opts->max_difficulty;
    min_difficulty = opts->min_difficulty;
    max_gap_inc = opts->max_gap_inc;

    goal_reward = opts->goal_reward;
    max_episode_steps = opts->max_episode_steps;
}

void NinjaContextOption::init_episode_context(struct libenv_options *e_context)
{
    int count_num = 2;
    e_context->count = count_num;
    e_context->items = new struct libenv_option[count_num];

    strcpy(e_context->items[0].name, "difficulty");
    e_context->items[0].dtype = LIBENV_DTYPE_INT32;
    e_context->items[0].count = 1;
    e_context->items[0].data = new int32_t[1];

    strcpy(e_context->items[1].name, "num_sections");
    e_context->items[1].dtype = LIBENV_DTYPE_INT32;
    e_context->items[1].count = 1;
    e_context->items[1].data = new int32_t[1];
}