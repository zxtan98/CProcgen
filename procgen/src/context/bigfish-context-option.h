#pragma once
#include "../vecoptions.h"

class BigfishContextOption
{
private:
    /* data */
public:
    float start_r;
    
    float fish_prob;
    
    float completion_bonus;
    float positive_reward;
    
    float fish_min_r;
    float fish_max_r;

    int fish_quota;

    float from_left_prob;
    float min_speed;
    float max_speed;

    int max_episode_steps;

    BigfishContextOption(/* args */);
    ~BigfishContextOption();
    void parse_options(VecOptions *opts);
    void copy_options(BigfishContextOption *opts);
    void init_episode_context(struct libenv_options *e_context);
};