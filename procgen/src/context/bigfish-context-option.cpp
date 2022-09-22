#include "bigfish-context-option.h"
#include "../cpp-utils.h"
#include "string.h"

BigfishContextOption::BigfishContextOption(/* args */)
{
}

BigfishContextOption::~BigfishContextOption()
{
}

void BigfishContextOption::parse_options(VecOptions *opts)
{
    opts->consume_float("start_r", &start_r, true, 1);
    opts->consume_float("fish_prob", &fish_prob, true, .1);

    opts->consume_float("completion_bonus", &completion_bonus, true, 10);
    opts->consume_float("positive_reward", &positive_reward, true, 1);

    opts->consume_float("fish_min_r", &fish_min_r, true, .25);
    opts->consume_float("fish_max_r", &fish_max_r, true, 2.);

    opts->consume_int("fish_quota", &fish_quota, true, 30);

    opts->consume_float("from_left_prob", &from_left_prob, true,.5);
    opts->consume_float("min_speed", &min_speed, true, .15);
    opts->consume_float("max_speed", &max_speed, true, .4);

    opts->consume_int("max_episode_steps", &max_episode_steps, true, 1000);
}

void BigfishContextOption::copy_options(BigfishContextOption *opts)
{
    start_r = opts->start_r;
    fish_prob = opts->fish_prob;
    completion_bonus = opts->completion_bonus;
    positive_reward = opts->positive_reward;
    fish_min_r = opts->fish_min_r;
    fish_max_r = opts->fish_max_r;
    fish_quota = opts->fish_quota;
    from_left_prob = opts->from_left_prob;
    min_speed = opts->min_speed;
    max_speed = opts->max_speed;

    max_episode_steps = opts->max_episode_steps;
}

void BigfishContextOption::init_episode_context(struct libenv_options *e_context){
    int count_num = 1;
    e_context->count = count_num;
    e_context->items = new struct libenv_option[count_num];

    strcpy(e_context->items[0].name, "start_r");
    e_context->items[0].dtype = LIBENV_DTYPE_FLOAT32;
    e_context->items[0].count = 1;
    e_context->items[0].data = new float[1];
}