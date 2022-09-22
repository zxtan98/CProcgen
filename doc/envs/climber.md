# Climber

<div style="text-align:center">
    <img src="https://raw.githubusercontent.com/openai/procgen/master/screenshots/climber.png" width="200px">
</div>

## Game Description
A simple platformer where the player must climb a sequence of platforms and collect stars along the way. Each collected star gives a small reward, and a larger reward is given for collecting all the stars in a level. If all stars are collected, the episode ends. However, there are lethal flying monsters scattered throughout the level that the player must avoid.

## Context Description

### Context Example
```
"climber": {
    "max_episode_steps": 1000,
    "gravity": 0.2,
    "max_jump": 1.5,
    "air_control": 0.15,
    "maxspeed": 0.5,
    "min_platforms": 1,
    "max_platforms": 10,
    "enemy_prob": 0.3,
    "coin_prob": 0.5,
    "max_plat_len": 11,
    "min_plat_len": 2,
    "world_width": 16,
    "margin_bottom": 5,
    "completion_bonus": 10.,
    "coin_reward": 1.,
    # Total: 14
}
```

### Context Parameters
| Parameter | Description | Default Value | Data Type |
|-----------|-------------|---------------|-----------|
|`max_episode_steps`| Maximum number of steps per episode. | 1000 | `int` |
|`gravity`| Strength of gravity in the game. | 0.2 | `float` |
|`max_jump`| Maximum height the player can jump. | 1.5 | `float` |
|`air_control`| Control the player has while in mid-air. (Higher values allow more control.) | 0.15 | `float` |
|`maxspeed`| Maximum horizontal speed of the player. | 0.5 | `float` |
|`min_platforms`| Minimum number of platforms in the game. | 1 | `int` |
|`max_platforms`| Maximum number of platforms in the game. | 10 | `int` |
|`enemy_prob`| Probability of generating an enemy at each platform. | 0.3 | `float` |
|`coin_prob`| Probability of generating a coin at each platform. | 0.5 | `float` |
|`max_plat_len`| Maximum length of a platform. | 11 | `int` |
|`min_plat_len`| Minimum length of a platform. | 2 | `int` |
|`world_width`| Width of the game world. | 16 | `int` |
|`margin_bottom`| Margin at the bottom of the level. | 5 | `int` |
|`completion_bonus`| Reward received when the player completes the level by collecting all stars. | 10. | `float` |
|`coin_reward`| Reward received when the player collects a coin. | 1. | `float` |
