#pragma once
#include "../vecoptions.h"

class MazeContextOption
{
private:
    /* data */
public:
    int world_dim;
    int min_maze_dim;
    int max_maze_dim;

    float visibility;
    float goal_reward;

    int max_episode_steps;
    
    MazeContextOption(/* args */);
    ~MazeContextOption();
    void parse_options(VecOptions *opts);
    void copy_options(MazeContextOption *opts);
    void init_episode_context(struct libenv_options *e_context);
};