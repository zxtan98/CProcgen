# Coinrun

<div style="text-align:center">
    <img src="https://raw.githubusercontent.com/openai/procgen/master/screenshots/coinrun.png" width="200px">
</div>

## Game Description
Coinrun is a simple platformer game where the player's goal is to collect the coin located at the far right of the level. The player starts at the far left and must navigate through stationary saw obstacles, enemies that pace back and forth, and chasms that lead to death. It's important to note that the current version of Coinrun does not include velocity information painted directly onto observations, making the environment significantly more challenging.

## Context Description

### Context Example
```
"coinrun": {
    "max_episode_steps": 1000,
    "visibility": 13,
    "maxspeed": 0.5,
    "main_width": 64,
    "main_height": 64,
    "allow_pit": true,
    "allow_crate": true,
    "unenven_ground": true,
    "allow_lava": true,
    "allow_saw": true,
    "allow_monsters": false,
    "min_crate_height": 1,
    "max_crate_height": 3,
    "max_difficulty": 3,
    "min_difficulty": 1,
    "max_section_num": 5,
    "min_section_num": 1,
    "goal_reward": 10.0
    # Total: 18
}

```

### Context Parameters
| Parameter | Description | Default Value | Data Type |
|-----------|-------------|---------------|-----------|
|`max_episode_steps`| Maximum number of steps per episode. | 1000 | `int` |
|`visibility`| Width of the observation window. | 13 | `int` |
|`maxspeed`| Maximum speed of the player. | 0.5 | `float` |
|`main_width`| Width of the game. | 64 | `int` |
|`main_height`| Height of the game. | 64 | `int` |
|`allow_pit`| Determines if pits are allowed in the game. | true | `bool` |
|`allow_crate`| Determines if crates are allowed in the game. | true | `bool` |
|`unenven_ground`| Determines if the ground is uneven in the game. | true | `bool` |
|`allow_lava`| Determines if lava is allowed in the game. | true | `bool` |
|`allow_saw`| Determines if saw obstacles are allowed in the game. | true | `bool` |
|`allow_monsters`| Determines if monsters are allowed in the game. | false | `bool` |
|`min_crate_height`| Minimum height of crates. | 1 | `int` |
|`max_crate_height`| Maximum height of crates. | 3 | `int` |
|`max_difficulty`| Maximum difficulty level of the game. (This difficulty is a complex parameter that affects the `num_sections`, number of pits, height differences in the ground, and the probability of saws and monsters appearing.) | 3 | `int` |
|`min_difficulty`| Minimum difficulty level of the game. | 1 | `int` |
|`max_section_num`| Maximum number of sections in the game. | 5 | `int` |
|`min_section_num`| Minimum number of sections in the game. | 1 | `int` |
|`goal_reward`| Reward received when the player collects the coin. | 10.0 | `float` |
