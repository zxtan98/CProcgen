# Jumper

<div style="text-align:center">
    <img src="https://raw.githubusercontent.com/openai/procgen/master/screenshots/jumper.png" width="200px">
</div>

## Game Description
A platformer with an open-world layout, Jumper features a bunny as the player character. The objective is to navigate through the world and find the carrot. The player can move horizontally, ascend or descend levels, and perform "double jumps" to reach higher platforms. However, contact with spike obstacles results in the player's destruction. The screen includes a compass that displays the direction and distance to the carrot. The only reward in the game comes from collecting the carrot, which signals the end of the episode. Note that there is a bug in the game that may occasionally cause the player to spawn on critical objects (obstacles or the goal). Approximately 7% of levels may terminate after a single action, with the majority of these having no reward.

## Context Description

### Context Example
```
"jumper": {
    "max_episode_steps": 1000,
    "world_dim": 20,
    "visibility": 12,
    "compass_dim": 3,
    "jump_cooldown": 3,
    "max_jump_count": 2,
    "goal_reward": 10.,
    # Total: 7
}
```

### Context Parameters
| Parameter | Description | Default Value | Data Type |
|-----------|-------------|---------------|-----------|
|`max_episode_steps`| Maximum number of steps per episode. | 1000 | `int` |
|`world_dim`| Dimension of the game world. | 20 | `int` |
|`visibility`| The visible range of the screen. | 12 | `int` |
|`compass_dim`| Size of the compass. | 3 | `int` |
|`jump_cooldown`| Cooldown period between jumps. | 3 | `int` |
|`max_jump_count`| Maximum number of consecutive jumps. | 2 | `int` |
|`goal_reward`| Reward received upon collecting the carrot (goal). | 10. | `float` |
