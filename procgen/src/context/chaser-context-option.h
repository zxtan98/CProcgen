#pragma once
#include "../vecoptions.h"

class ChaserContextOption
{
private:
    /* data */
public:
    int maze_dim; // The maze dimension
    int total_enemies; // The total number of enemies
    int extra_orb_sign; // Used to control the number of orbs

    int eat_time; // The time for eating mode (in this mode, the agent can eat the enemies)
    int egg_time; // The time for egg mode (in this mode, the enemies are in egg mode)

    int total_orbs; // The total number of orbs. (If this value mod 4 is 2, then this value will be increased by 1.)

    float completion_bonus; // The bonus for completing the level.
    float orb_reward; // The reward for eating an enemy.

    int max_episode_steps;
    ChaserContextOption(/* args */);
    ~ChaserContextOption();
    void parse_options(VecOptions *opts);
    void copy_options(ChaserContextOption *opts);
};