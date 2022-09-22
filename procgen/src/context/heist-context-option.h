#pragma once
#include "../vecoptions.h"

class HeistContextOption
{
private:
    /* data */
public:
    // float start_r;
    int world_dim;
    int max_maze_dim;
    int min_maze_dim;
    int min_keys;
    int max_keys;
    float maxspeed;

    float completion_bonus;

    int max_episode_steps;

    HeistContextOption(/* args */);
    ~HeistContextOption();
    void parse_options(VecOptions *opts);
    void copy_options(HeistContextOption *opts);
    void init_episode_context(struct libenv_options *e_context);
};