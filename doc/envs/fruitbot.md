# Fruitbot

<div style="text-align:center">
    <img src="https://raw.githubusercontent.com/openai/procgen/master/screenshots/fruitbot.png" width="200px">
</div>

## Game Description
A scrolling game where the player controls a robot that must navigate between gaps in walls and collect fruit along the way. The player receives a positive reward for collecting a piece of fruit, and a larger negative reward for mistakenly collecting a non-fruit object. Half of the spawned objects are fruit (positive reward) and half are non-fruit (negative reward). The player receives a large reward if they reach the end of the level. Occasionally the player must use a key to unlock gates which block the way.

## Context Description

### Context Example
```
"fruitbot": {
    "max_episode_steps": 1000,
    "main_width": 10,
    "main_height": 60,
    "min_sep": 4,
    "num_walls": 5,
    "object_group_size": 6,
    "buf_h": 4,
    "door_prob": 0.125,
    "min_pct": 0.2,
    "min_fruits": 10,
    "max_fruits": 19,
    "min_foods": 10,
    "max_foods": 19,
    "completion_bonus": 10.0,
    "positive_reward": 1.0,
    "penalty": -4.0
}

```

### Context Parameters
| Parameter | Description | Default Value | Data Type |
|-----------|-------------|---------------|-----------|
|`max_episode_steps`| Maximum number of steps per episode. | 1000 | `int` |
|`main_width`| Width of the main game area. | 10 | `int` |
|`main_height`| Height of the main game area. | 60 | `int` |
|`min_sep`| Minimum separation between walls. | 4 | `int` |
|`num_walls`| Number of walls in the game. | 5 | `int` |
|`object_group_size`| Number of objects generated together in each group. | 6 | `int` |
|`buf_h`| The distance between the agent and the first wall.  | 4 | `int` |
|`door_prob`| Probability of generating a door. | 0.125 | `float` |
|`min_pct`| Minimum ratio of passage width to wall width. | 0.2 | `float` |
|`min_fruits`| Minimum number of fruit objects in the game. | 10 | `int` |
|`max_fruits`| Maximum number of fruit objects in the game. | 19 | `int` |
|`min_foods`| Minimum number of non-fruit objects in the game. | 10 | `int` |
|`max_foods`| Maximum number of non-fruit objects in the game. | 19 | `int` |
|`completion_bonus`| Reward received when the player finishes the game. | 10.0 | `float` |
|`positive_reward`| Reward received when the player collects a fruit. | 1.0 | `float` |
|`penalty`| Penalty received when the player collects a non-fruit object. | -4.0 | `float` |
