#pragma once
#include "../vecoptions.h"

class DodgeballContextOption
{
private:
    /* data */
public:
    // float start_r;
    int world_dim;
    float thickness;
    float enemy_r;
    float ball_r;
    float ball_vscale;
    float maxspeed;
    float exit_r;

    float enemy_speed;
    int enemy_reward;

    int num_iterations; 

    bool allow_left_exit;
    bool allow_right_exit;
    bool allow_top_exit;
    bool allow_bottom_exit;

    int max_extra_enemies;
    int base_num_enemies;


    int fire_interval;

    float completion_bonus;

    int max_episode_steps;
    DodgeballContextOption(/* args */);
    ~DodgeballContextOption();
    void parse_options(VecOptions *opts);
    void copy_options(DodgeballContextOption *opts);
    void init_episode_context(struct libenv_options *e_context);
};