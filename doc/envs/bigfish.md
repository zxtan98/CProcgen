# Bigfish

<div style="text-align:center">
    <img src="https://raw.githubusercontent.com/openai/procgen/master/screenshots/bigfish.png" width="200px">
</div>

## Game Description
The player starts as a small fish and becomes bigger by eating other fish. The player may only eat fish smaller than itself, as determined solely by width. If the player comes in contact with a larger fish, the player is eaten and the episode ends. The player receives a small reward for eating a smaller fish and a large reward for becoming bigger than all other fish, at which point the episode ends.

## Context Description

### Context Example
```
"bigfish": {
    "max_episode_steps": 1000,
    "start_r": 1.,
    "fish_prob": .1,
    "from_left_prob": .5,
    "completion_bonus": 10.,
    "positive_reward": 1.,
    "fish_min_r": .25,
    "fish_max_r": 2.,
    "fish_quota": 30,
    "min_speed": .15,
    "max_speed": .4,
    # Total: 11
}
```

### Context Parameters
| Parameter | Description | Default Value | Data Type |
|-----------|-------------|---------------|-----------|
|`max_episode_steps`| Maximum number of steps per episode. | 1000 | `int` |
|`start_r`| Initial radius of the player. (Greater values make the player bigger and easier to play.) | 1. | `float` |
|`fish_prob`| Probability of generating a fish at each step. (The greater the value, the denser the fish.) | 0.1 | `float` |
|`from_left_prob`| Probability of generating a fish from the left side of the screen. | 0.5 | `float` |
|`completion_bonus`| Reward received when the player finishes the game. | 10 | `int` |
|`positive_reward`| Reward received when the player eats a smaller fish. | 1 | `int` |
|`fish_min_r`| Minimum radius of a generated fish. | 0.25 | `float` |
|`fish_max_r`| Maximum radius of a generated fish. | 2. | `float` |
|`fish_quota`| Total number of fish to be eaten in an episode. | 30 | `int` |
|`min_speed`| Minimum speed of the other fishes. | 0.15 | `float` |
|`max_speed`| Maximum speed of the other fishes. | 0.4 | `float` |
