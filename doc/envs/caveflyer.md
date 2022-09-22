# Caveflyer

<div style="text-align:center">
    <img src="https://raw.githubusercontent.com/openai/procgen/master/screenshots/caveflyer.png" width="200px">
</div>

## Game Description
The player must navigate a network of caves to reach the exit. Player movement mimics the Atari game "Asteroids": the ship can rotate and travel forward or backward along the current axis. The majority of the reward comes from successfully reaching the end of the level, though additional reward can be collected by destroying target objects along the way with the ship's lasers. There are stationary and moving lethal obstacles throughout the level.

## Context Description

### Context Example
```
"caveflyer": {
    "max_episode_steps": 1000,
    "world_dim": 30,
    "objects_factor": 10,
    "enable_obstacle": False,
    "enable_target": False,
    "enable_enemy": True,
    "enemy_v_fast": 0.2,
    "enemy_v_slow": 0.1,
    "goal_reward": 10.0,
    "target_reward": 3.0,
    # Total: 10
}

```

### Context Parameters
| Parameter | Description | Default Value | Data Type |
|-----------|-------------|---------------|-----------|
|`max_episode_steps`| Maximum number of steps per episode. | 1000 | `int` |
|`world_dim`| Dimension of the game world. | 30 | `int` |
|`objects_factor`| A coefficient that influences the number of objects in the game world. (A higher value results in more objects in the map, including obstacles and enemies.) | 10 | `int` |
|`enable_obstacle`| Enable or disable the presence of obstacles in the game. | False | `bool` |
|`enable_target`| Enable or disable the presence of target objects in the game. | False | `bool` |
|`enable_enemy`| Enable or disable the presence of enemy objects in the game. | True | `bool` |
|`enemy_v_fast`| Speed of fast-moving enemies. (Each enemy has a 1/2 chance of having this speed.) | 0.2 | `float` |
|`enemy_v_slow`| Speed of slow-moving enemies. | 0.1 | `float` |
|`goal_reward`| Reward received upon reaching the exit. | 10.0 | `float` |
|`target_reward`| Reward received for destroying an enemy object. | 3.0 | `float` |
