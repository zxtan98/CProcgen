#include "miner-context-option.h"
#include "../cpp-utils.h"

MinerContextOption::MinerContextOption(/* args */) {
}

MinerContextOption::~MinerContextOption() {
}

void MinerContextOption::parse_options(VecOptions *opts) {
    opts->consume_int("world_dim", &world_dim, true, 15);

    opts->consume_float("diamond_pct", &diamond_pct, true, 12 / 400.);
    opts->consume_float("boulder_pct", &boulder_pct, true, 80 / 400.);

    opts->consume_float("completion_bonus", &completion_bonus, true, 10.0);
    opts->consume_float("diamond_reward", &diamond_reward, true, 1.0);
    opts->consume_int("max_episode_steps", &max_episode_steps, true, 1000);
}

void MinerContextOption::copy_options(MinerContextOption *opts) {
    world_dim = opts->world_dim;
    diamond_pct = opts->diamond_pct;
    boulder_pct = opts->boulder_pct;

    completion_bonus = opts->completion_bonus;
    diamond_reward = opts->diamond_reward;
    max_episode_steps = opts->max_episode_steps;
}