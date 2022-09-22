# Leaper

<div style="text-align:center">
    <img src="https://raw.githubusercontent.com/openai/procgen/master/screenshots/leaper.png" width="200px">
</div>

## Game Description
Inspired by the classic game "Frogger", Leaper requires the player to cross several lanes to reach the finish line and earn a reward. The first group of lanes contains cars that must be avoided. The second group of lanes contains logs on a river. The player must hop from log to log to cross the river. If the player falls in the river, the episode ends.

## Context Description

### Context Example
```
"leaper": {
    "max_episode_steps": 1000,
    "world_dim": 9,
    "min_car_speed": .03,
    "max_car_speed": .12,
    "min_log_speed": .025,
    "max_log_speed": .075,
    "max_extra_space": 0,
    "max_road": 3,
    "min_road": 0,
    "max_log": 3,
    "min_log": 0,
    "car_left_prob": .5,
    "goal_reward": 10.,
    # Total: 13
}
```

### Context Parameters
| Parameter | Description | Default Value | Data Type |
|-----------|-------------|---------------|-----------|
|`max_episode_steps`| Maximum number of steps per episode. | 1000 | `int` |
|`world_dim`| Dimension of the game world. | 9 | `int` |
|`min_car_speed`| Minimum speed of the cars. | 0.03 | `float` |
|`max_car_speed`| Maximum speed of the cars. | 0.12 | `float` |
|`min_log_speed`| Minimum speed of the logs. | 0.025 | `float` |
|`max_log_speed`| Maximum speed of the logs. | 0.075 | `float` |
|`max_extra_space`| Maximum extra space allowed. | 0 | `int` |
|`max_road`| Maximum number of road lanes for cars | 3 | `int` |
|`min_road`| Minimum number of road lanes for cars. | 0 | `int` |
|`max_log`| Maximum number of water lanes for logs. | 3 | `int` |
|`min_log`| Minimum number of water lanes for logs. | 0 | `int` |
|`car_left_prob`| Probability of cars moving to the left. | 0.5 | `float` |
|`goal_reward`| Reward received when the player reaches the finish line. | 10. | `float` |
