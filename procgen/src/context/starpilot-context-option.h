#pragma once
#include "../vecoptions.h"

class StarpilotContextOption
{
private:
    /* data */
public:
    float maxspeed;
    int max_group_size;
    bool can_spawn_left;
    float left_prob;
    int min_enemy_delta_t;
    int max_enemy_delta_t;
    int flyer_prob_weight;
    int meteor_prob_weight;
    int cloud_prob_weight;
    int turret_prob_weight;
    int fastflyer_prob_weight;
    int max_time;
    int min_time;

    float completion_bonus;
    float enemy_reward;


    int max_episode_steps;
    // int fish_interval;

    StarpilotContextOption(/* args */);
    ~StarpilotContextOption();
    void parse_options(VecOptions *opts);
    void copy_options(StarpilotContextOption *opts);
    void init_episode_context(struct libenv_options *e_context);
};