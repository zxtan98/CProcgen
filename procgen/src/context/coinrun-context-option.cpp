#include "coinrun-context-option.h"
#include "../cpp-utils.h"
#include "string.h"

CoinrunContextOption::CoinrunContextOption(/* args */)
{
}
    

CoinrunContextOption::~CoinrunContextOption()
{
}

void CoinrunContextOption::parse_options(VecOptions *opts)
{
    opts->consume_int("visibility", &visibility, true, 13);
    opts->consume_float("maxspeed", &maxspeed, true, 0.5);
    opts->consume_int("main_width", &main_width, true, 64);
    opts->consume_int("main_height", &main_height, true, 64);
    opts->consume_bool("allow_pit", &allow_pit, true, true);
    opts->consume_bool("allow_crate", &allow_crate, true, true);
    opts->consume_bool("unenven_ground", &unenven_ground, true, true);
    opts->consume_bool("allow_lava", &allow_lava, true, true);
    opts->consume_bool("allow_saw", &allow_saw, true, true);
    opts->consume_bool("allow_monsters", &allow_monsters, true, false);
    opts->consume_int("min_crate_height", &min_crate_height, true, 1);
    opts->consume_int("max_crate_height", &max_crate_height, true, 3);
    opts->consume_int("max_difficulty", &max_difficulty, true, 3);
    opts->consume_int("min_difficulty", &min_difficulty, true, 1);
    opts->consume_int("max_section_num", &max_section_num, true, 5);
    opts->consume_int("min_section_num", &min_section_num, true, 1);
    opts->consume_float("goal_reward", &goal_reward, true, 0.5);
    opts->consume_int("max_episode_steps", &max_episode_steps, true, 1000);
}

void CoinrunContextOption::copy_options(CoinrunContextOption *opts)
{
    visibility = opts->visibility;
    maxspeed = opts->maxspeed;
    main_width = opts->main_width;
    main_height = opts->main_height;
    allow_pit = opts->allow_pit;
    allow_crate = opts->allow_crate;
    unenven_ground = opts->unenven_ground;
    allow_lava = opts->allow_lava;
    allow_saw = opts->allow_saw;
    allow_monsters = opts->allow_monsters;
    min_crate_height = opts->min_crate_height;
    max_crate_height = opts->max_crate_height;
    max_difficulty = opts->max_difficulty;
    min_difficulty = opts->min_difficulty;
    min_section_num = opts->min_section_num;
    max_section_num = opts->max_section_num;
    min_section_num = opts->min_section_num;
    goal_reward = opts->goal_reward;
    max_episode_steps = opts->max_episode_steps;
}

void CoinrunContextOption::init_episode_context(struct libenv_options *e_context)
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