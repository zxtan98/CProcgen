#pragma once
#include "../vecoptions.h"

class JumperContextOption
{
private:
    /* data */
public:
    int world_dim;
    int visibility;
    int compass_dim;
    int jump_cooldown;
    int max_jump_count;

    float goal_reward;

    int max_episode_steps;
    
    JumperContextOption(/* args */);
    ~JumperContextOption();
    void parse_options(VecOptions *opts);
    void copy_options(JumperContextOption *opts);
};