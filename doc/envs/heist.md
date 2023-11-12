# Heist

<div style="text-align:center">
    <img src="https://raw.githubusercontent.com/openai/procgen/master/screenshots/heist.png" width="200px">
</div>

## Game Description
The player must steal the gem hidden behind a network of locks. Each lock comes in one of three colors, and the necessary keys to open these locks are scattered throughout the level. The level layout takes the form of a maze, generated using Kruskal's algorithm. Once the player collects a key of a certain color, they can open the lock of that color. The keys in the player's possession are displayed in the top right corner of the screen.


## Context Description

### Context Example
```
"heist": {
    "max_episode_steps": 1000,
    "world_dim": 9,
    "max_maze_dim": 9,
    "min_maze_dim": 5,
    "min_keys": 0,
    "max_keys": 3,
    "maxspeed": 0.75,
    "completion_bonus": 10.,
    # Total: 8
}
```

### Context Parameters
| Parameter | Description | Default Value | Data Type |
|-----------|-------------|---------------|-----------|
|`max_episode_steps`| Maximum number of steps per episode. | 1000 | `int` |
|`world_dim`| Dimension of the game world. | 9 | `int` |
|`max_maze_dim`| Maximum dimension of the maze. | 9 | `int` |
|`min_maze_dim`| Minimum dimension of the maze. | 5 | `int` |
|`min_keys`| Minimum number of keys required to complete the level. | 0 | `int` |
|`max_keys`| Maximum number of keys that can be collected in the level. | 3 | `int` |
|`maxspeed`| Maximum speed of the player robot. | 0.75 | `float` |
|`completion_bonus`| Reward received when the player completes the level. | 10. | `float` |
