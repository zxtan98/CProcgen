#pragma once
#include "../vecoptions.h"

class FruitbotContextOption {
  private:
    /* data */
  public:
    // float start_r;
    int main_width;
    int main_height;

    int min_sep;
    int num_walls;
    int object_group_size;
    int buf_h;
    float door_prob;
    float min_pct;
    int min_fruits;
    int max_fruits;
    int min_foods;
    int max_foods;

    float completion_bonus;
    float positive_reward;
    float penalty;

    int max_episode_steps;
    
    FruitbotContextOption(/* args */);
    ~FruitbotContextOption();
    void parse_options(VecOptions *opts);
    void copy_options(FruitbotContextOption *opts);
    void init_episode_context(struct libenv_options *e_context);
};