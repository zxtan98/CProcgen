#include "climber-context-option.h"
#include "../cpp-utils.h"
#include "string.h"

ClimberContextOption::ClimberContextOption(/* args */)
{
}
    

ClimberContextOption::~ClimberContextOption()
{
}

void ClimberContextOption::parse_options(VecOptions *opts)
{
    opts->consume_float("gravity", &gravity, true, 0.2);
    opts->consume_float("max_jump", &max_jump, true, 1.5);
    opts->consume_float("air_control", &air_control, true, 0.15);
    opts->consume_float("maxspeed", &maxspeed, true, 0.5);
    opts->consume_int("min_platforms", &min_platforms, true, 1);
    opts->consume_int("max_platforms", &max_platforms, true, 10);
    opts->consume_float("enemy_prob", &enemy_prob, true, 0.3);
    opts->consume_float("coin_prob", &coin_prob, true, 0.5);
    opts->consume_int("max_plat_len", &max_plat_len, true, 11);
    opts->consume_int("min_plat_len", &min_plat_len, true, 2);
    opts->consume_int("world_width", &world_width, true, 16);
    opts->consume_int("margin_bottom", &margin_bottom, true, 5);
    opts->consume_float("completion_bonus", &completion_bonus, true, 10);
    opts->consume_float("coin_reward", &coin_reward, true, 1);    
    opts->consume_int("max_episode_steps", &max_episode_steps, true, 1000);
}

void ClimberContextOption::copy_options(ClimberContextOption *opts)
{
    gravity = opts->gravity;
    max_jump = opts->max_jump;
    air_control = opts->air_control;
    maxspeed = opts->maxspeed;
    min_platforms = opts->min_platforms;
    max_platforms = opts->max_platforms;
    enemy_prob = opts->enemy_prob;
    coin_prob = opts->coin_prob;
    max_plat_len = opts->max_plat_len;
    min_plat_len = opts->min_plat_len;
    world_width = opts->world_width;
    margin_bottom = opts->margin_bottom;
    completion_bonus = opts->completion_bonus;
    coin_reward = opts->coin_reward;
    max_episode_steps = opts->max_episode_steps;
}

void ClimberContextOption::init_episode_context(struct libenv_options *e_context){
    int count_num = 1;
    e_context->count = count_num;
    e_context->items = new struct libenv_option[count_num];

    strcpy(e_context->items[0].name, "num_platforms");
    e_context->items[0].dtype = LIBENV_DTYPE_INT32;
    e_context->items[0].count = 1;
    e_context->items[0].data = new int32_t[1];
}