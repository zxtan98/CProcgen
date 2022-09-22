#pragma once
#include "../vecoptions.h"

class PlunderContextOption
{
private:
    /* data */
public:
    float target_time_reward;
    float target_time_penalty;
    float step_time_penalty;
    float fire_time_penalty;
    int target_quota;
    float spawn_prob;
    int num_lanes;
    float r_scale;
    float left_prob;
    float enemy_prob;
    float max_speed;
    float min_speed;

    float completion_bonus;
    float positive_reward;

    int max_episode_steps;
    
    PlunderContextOption(/* args */);
    ~PlunderContextOption();
    void parse_options(VecOptions *opts);
    void copy_options(PlunderContextOption *opts);
};