#pragma once
#include "../vecoptions.h"

class CaveflyerContextOption
{
private:
    /* data */
public:
    // float start_r;
    int world_dim; // The world dimension. Usually, the world size increases when this value increases. [10, 100]
    int objects_factor; // Usually, the number of objects increases when this value increases. [0, 20]

    bool enable_obstacle; // Whether to enable obstacles.
    bool enable_target; // Whether to enable targets.
    bool enable_enemy; // Whether to enable enemies.

    float enemy_v_fast; // The fast speed of enemies.
    float enemy_v_slow; // The slow speed of enemies.

    float goal_reward; // The reward of reaching the goal.
    float target_reward; // The reward of reaching the target.

    int max_episode_steps;

    CaveflyerContextOption(/* args */);
    ~CaveflyerContextOption();
    void parse_options(VecOptions *opts);
    void copy_options(CaveflyerContextOption *opts);
};