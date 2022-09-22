# Ninja

<div style="text-align:center">
    <img src="https://raw.githubusercontent.com/openai/procgen/master/screenshots/ninja.png" width="200px">
</div>

## Game Description
A simple platformer. The player, a ninja, must jump across narrow ledges while avoiding bomb obstacles. The player can toss throwing stars at several angles in order to clear bombs, if necessary. The player's jump can be charged over several timesteps to increase its effect. The player receives a reward for collecting the mushroom at the end of the level, at which point the episode terminates.

## Context Description

### Context Example
```
"ninja": {
    "max_episode_steps": 1000,
    "gravity": .2,
    "max_jump": 1.25,
    "jump_charge_inc": .25,
    "air_control": .15,
    "maxspeed": .5,
    "visibility": 16,
    "min_num_sections": 1,
    "max_num_sections": 6,
    "min_difficulty": 1,
    "max_difficulty": 3,
    "max_gap_inc": 1,
    "goal_reward": 10.,
    # Total: 13
}
```

### Context Parameters
| Parameter | Description | Default Value | Data Type |
|-----------|-------------|---------------|-----------|
|`max_episode_steps`| Maximum number of steps per episode. | 1000 | `int` |
|`gravity`| Gravity factor affecting the player's movement. | 0.2 | `float` |
|`max_jump`| Maximum height the player can jump. | 1.25 | `float` |
|`jump_charge_inc`| Increment in jump height per timestep when charging the jump. | 0.25 | `float` |
|`air_control`| Control factor for the player's movement in the air. | 0.15 | `float` |
|`maxspeed`| Maximum speed the player can move horizontally. | 0.5 | `float` |
|`visibility`| Visibility range for the player. | 16 | `int` |
|`min_num_sections`| Minimum number of sections in the game. | 1 | `int` |
|`max_num_sections`| Maximum number of sections in the game. | 6 | `int` |
|`min_difficulty`| Minimum difficulty level of the game. (The `difficulty` parameter influences the number of sections, as well as the vertical height variation between two ledges and the `bomb_prob` parameter.) | 1 | `int` |
|`max_difficulty`| Maximum difficulty level of the game. | 3 | `int` |
|`max_gap_inc`| Maximum increment in gap distance between ledges. | 1 | `int` |
|`goal_reward`| Reward received when the player collects the mushroom at the end. | 10. | `float` |
