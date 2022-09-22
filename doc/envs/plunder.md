# Plunder

<div style="text-align:center">
    <img src="https://raw.githubusercontent.com/openai/procgen/master/screenshots/plunder.png" width="200px">
</div>

## Game Description
The player must destroy enemy pirate ships by firing cannonballs from its own ship at the bottom of the screen. An on-screen timer slowly counts down. If this timer runs out, the episode ends. Whenever the player fires, the timer skips forward a few steps, encouraging the player to conserve ammunition. The player must take care to avoid hitting friendly ships. The player receives a positive reward for hitting an enemy ship and a large timer penalty for hitting a friendly ship. A target in the bottom left corner identifies the color of the enemy ships to target.

## Context Description

### Context Example
```
"plunder": {
    "max_episode_steps": 1000,
    "target_time_reward": 0.1,
    "target_time_penalty": 0.1,
    "step_time_penalty": 0.0015,
    "fire_time_penalty": 0.02,
    "target_quota": 20,
    "spawn_prob": .06,
    "num_lanes": 5,
    "r_scale": 1.5,
    "left_prob": .5,
    "enemy_prob": .5,
    "max_speed": .25,
    "min_speed": .15,
    "completion_bonus": 10.,
    "positive_reward": 1.,
    # Total: 15
}
```

### Context Parameters
| Parameter | Description | Default Value | Data Type |
|-----------|-------------|---------------|-----------|
|`max_episode_steps`| Maximum number of steps per episode. | 1000 | `int` |
|`target_time_reward`| Reward received for hitting an enemy ship. | 0.1 | `float` |
|`target_time_penalty`| Penalty applied to the timer for hitting a friendly ship. | 0.1 | `float` |
|`step_time_penalty`| Penalty for each game step taken. | 0.0015 | `float` |
|`fire_time_penalty`| Penalty for each cannonball fired. | 0.02 | `float` |
|`target_quota`| Total number of enemy ships to destroy in an episode. | 20 | `int` |
|`spawn_prob`| Probability of spawning an enemy ship at each step. | 0.06 | `float` |
|`num_lanes`| Number of lanes for enemy ship movement. | 5 | `int` |
|`r_scale`| Scaling factor for enemy ship size. | 1.5 | `float` |
|`left_prob`| Probability of an enemy ship spawning from the left side of the screen. | 0.5 | `float` |
|`enemy_prob`| Probability of an enemy ship spawning. | 0.5 | `float` |
|`max_speed`| Maximum speed of ships. | 0.25 | `float` |
|`min_speed`| Minimum speed of ships. | 0.15 | `float` |
|`completion_bonus`| Reward received when the player completes the game. | 10. | `float` |
|`positive_reward`| Reward received for hitting an enemy ship. | 1. | `float` |
