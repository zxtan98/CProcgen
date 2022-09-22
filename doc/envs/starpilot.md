# StarPilot

<div style="text-align:center">
    <img src="https://raw.githubusercontent.com/openai/procgen/master/screenshots/starpilot.png" width="200px">
</div>

## Game Description
A simple side-scrolling shooter game, Starpilot is relatively challenging for humans to play as all enemies fire projectiles that directly target the player. Failing to dodge quickly leads to the player's demise. The game features fast and slow enemies, stationary turrets with high health, clouds that obscure player vision, and impassable meteors.

## Context Description

### Context Example
```
"starpilot": {
    "max_episode_steps": 1000,
    "maxspeed": .75,
    "max_group_size": 5,
    "can_spawn_left": False,
    "left_prob": .1,
    "min_enemy_delta_t": 10,
    "max_enemy_delta_t": 30,
    "flyer_prob_weight": 1,
    "meteor_prob_weight": 0,
    "cloud_prob_weight": 0,
    "turret_prob_weight": 0,
    "fastflyer_prob_weight": 0,
    "min_flyer_speed": .1,
    "min_time": 0,
    "max_time": 10000,
    "completion_bonus": 10.,
    "enemy_reward": 1.,
    # Total: 17
}
```

### Context Parameters
| Parameter | Description | Default Value | Data Type |
|-----------|-------------|---------------|-----------|
|`max_episode_steps`| Maximum number of steps per episode. | 1000 | `int` |
|`maxspeed`| Maximum speed of the player. | 0.75 | `float` |
|`max_group_size`| Maximum size of a group of enemies. | 5 | `int` |
|`can_spawn_left`| Determines if enemies can spawn from the left side of the screen.(Enemies spawning from the left side make the game more challenging.) | False | `bool` |
|`left_prob`| Probability of enemies spawning from the left side of the screen. | 0.1 | `float` |
|`min_enemy_delta_t`| Minimum time between enemy spawns. | 10 | `int` |
|`max_enemy_delta_t`| Maximum time between enemy spawns. | 30 | `int` |
|`flyer_prob_weight`| Weight of flyer enemies in the spawn probability calculation. | 1 | `float` |
|`meteor_prob_weight`| Weight of meteor enemies in the spawn probability calculation. | 0 | `float` |
|`cloud_prob_weight`| Weight of cloud enemies in the spawn probability calculation. | 0 | `float` |
|`turret_prob_weight`| Weight of turret enemies in the spawn probability calculation. | 0 | `float` |
|`fastflyer_prob_weight`| Weight of fast flyer enemies in the spawn probability calculation. | 0 | `float` |
|`min_flyer_speed`| Minimum speed of flyer enemies. | 0.1 | `float` |
|`min_time`| Minimum time for enemies to spawn. | 0 | `int` |
|`max_time`| Maximum time for enemies to spawn. | 10000 | `int` |
|`completion_bonus`| Reward received when the player finishes the game. | 10. | `float` |
|`enemy_reward`| Reward received for destroying an enemy. | 1. | `float` |
