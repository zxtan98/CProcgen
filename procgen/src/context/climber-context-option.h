#pragma once
#include "../vecoptions.h"

class ClimberContextOption
{
private:
    /* data */
public:
    float gravity;
    float max_jump;
    float air_control;
    float maxspeed;

    int min_platforms; // The minimum number of platforms to generate. [1, 10]
    int max_platforms; // The maximum number of platforms to generate. [1, 10]

    float enemy_prob; // The probability of generating an enemy. [0, 1]

    float coin_prob; // The probability of generating a coin. [0, 1]

    int max_plat_len; // The maximum length of a platform. [1, 10]
    int min_plat_len; // The minimum length of a platform. [1, 10]

    int world_width; // The width of the world. [1, 10]

    int margin_bottom; // The margin from the bottom of the screen. 

    float completion_bonus;
    float coin_reward;

    int max_episode_steps;
    ClimberContextOption(/* args */);
    ~ClimberContextOption();
    void parse_options(VecOptions *opts);
    void copy_options(ClimberContextOption *opts);
    void init_episode_context(struct libenv_options *e_context);
};