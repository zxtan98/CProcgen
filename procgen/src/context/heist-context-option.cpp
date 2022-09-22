#include "heist-context-option.h"
#include "../cpp-utils.h"
#include "string.h"

HeistContextOption::HeistContextOption(/* args */)
{
}
    

HeistContextOption::~HeistContextOption()
{
}

void HeistContextOption::parse_options(VecOptions *opts)
{
    // opts->consume_float("start_r", &start_r);
    opts->consume_int("world_dim", &world_dim, true, 9);
    opts->consume_int("max_maze_dim", &max_maze_dim, true, 9); // max maze dim is the world dim in the original game.
    opts->consume_int("min_maze_dim", &min_maze_dim, true, 5); // 5 is the min maze dim in the original game [5, world_dim].
    opts->consume_int("min_keys", &min_keys, true, 0);
    opts->consume_int("max_keys", &max_keys, true, 3);  // 3 is the max number of keys in the original game. [0, 3]
    opts->consume_float("maxspeed", &maxspeed, true, 0.75);

    opts->consume_float("completion_bonus", &completion_bonus, true, 10.0);
    opts->consume_int("max_episode_steps", &max_episode_steps, true, 1000);
}

void HeistContextOption::copy_options(HeistContextOption *opts)
{
    // opts->start_r = opts->start_r;
    world_dim = opts->world_dim;
    max_maze_dim = opts->max_maze_dim;
    min_maze_dim = opts->min_maze_dim;
    min_keys = opts->min_keys;
    max_keys = opts->max_keys;
    maxspeed = opts->maxspeed;

    completion_bonus = opts->completion_bonus;
    max_episode_steps = opts->max_episode_steps;
}

void HeistContextOption::init_episode_context(struct libenv_options *e_context)
{
    int count_num = 2;
    e_context->count = count_num;
    e_context->items = new struct libenv_option[count_num];

    strcpy(e_context->items[0].name, "maze_dim");
    e_context->items[0].dtype = LIBENV_DTYPE_INT32;
    e_context->items[0].count = 1;
    e_context->items[0].data = new int32_t[1];

    strcpy(e_context->items[1].name, "num_keys");
    e_context->items[1].dtype = LIBENV_DTYPE_INT32;
    e_context->items[1].count = 1;
    e_context->items[1].data = new int32_t[1];
}