#include "maze-context-option.h"
#include "../cpp-utils.h"
#include "string.h"

MazeContextOption::MazeContextOption(/* args */)
{
}
    

MazeContextOption::~MazeContextOption()
{
}

void MazeContextOption::parse_options(VecOptions *opts)
{
    opts->consume_int("world_dim", &world_dim, true, 15);
    opts->consume_int("min_maze_dim", &min_maze_dim, true, 3);
    opts->consume_int("max_maze_dim", &max_maze_dim, true, 15);

    opts->consume_float("visibility", &visibility, true, 8.0);
    opts->consume_float("goal_reward", &goal_reward, true, 10.0);
    opts->consume_int("max_episode_steps", &max_episode_steps, true, 1000);
}

void MazeContextOption::copy_options(MazeContextOption *opts)
{
    world_dim = opts->world_dim;
    min_maze_dim = opts->min_maze_dim;
    max_maze_dim = opts->max_maze_dim;

    visibility = opts->visibility;
    goal_reward = opts->goal_reward;
    max_episode_steps = opts->max_episode_steps;
}

void MazeContextOption::init_episode_context(struct libenv_options *e_context){
    int count_num = 1;
    e_context->count = count_num;
    e_context->items = new struct libenv_option[count_num];

    strcpy(e_context->items[0].name, "maze_dim");
    e_context->items[0].dtype = LIBENV_DTYPE_INT32;
    e_context->items[0].count = 1;
    e_context->items[0].data = new int32_t[1];
}