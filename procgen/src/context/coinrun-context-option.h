#pragma once
#include "../vecoptions.h"

class CoinrunContextOption
{
private:
    /* data */
public:
    int visibility;
    float maxspeed;
    int main_width;
    int main_height;

    bool allow_pit;
    bool allow_crate;
    bool unenven_ground;
    bool allow_lava;
    bool allow_saw;
    bool allow_monsters;

    int min_crate_height;
    int max_crate_height;

    int max_difficulty; // 3
    int min_difficulty; // 1

    int max_section_num; // 5
    int min_section_num; // 1

    float goal_reward;


    int max_episode_steps;

    CoinrunContextOption(/* args */);
    ~CoinrunContextOption();
    void parse_options(VecOptions *opts);
    void copy_options(CoinrunContextOption *opts);
    void init_episode_context(struct libenv_options *e_context);
};