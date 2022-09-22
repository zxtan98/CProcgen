#include "jumper-context-option.h"
#include "../cpp-utils.h"

JumperContextOption::JumperContextOption(/* args */) {
}

JumperContextOption::~JumperContextOption() {
}

void JumperContextOption::parse_options(VecOptions *opts) {
    opts->consume_int("world_dim", &world_dim, true, 20);
    opts->consume_int("visibility", &visibility, true, 12);
    opts->consume_int("compass_dim", &compass_dim, true, 3);
    opts->consume_int("jump_cooldown", &jump_cooldown, true, 3);
    opts->consume_int("max_jump_count", &max_jump_count, true, 2);

    opts->consume_float("goal_reward", &goal_reward, true, 10.0);
    opts->consume_int("max_episode_steps", &max_episode_steps, true, 1000);
}

void JumperContextOption::copy_options(JumperContextOption *opts) {
    world_dim = opts->world_dim;
    visibility = opts->visibility;
    compass_dim = opts->compass_dim;
    jump_cooldown = opts->jump_cooldown;
    max_jump_count = opts->max_jump_count;

    goal_reward = opts->goal_reward;
    max_episode_steps = opts->max_episode_steps;
}