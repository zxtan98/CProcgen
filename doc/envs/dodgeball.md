# Dodgeball

<div style="text-align:center">
   <img src="https://raw.githubusercontent.com/openai/procgen/master/screenshots/dodgeball.png" width="200px">
</div>

## Game Description
Loosely inspired by the Atari game "Berzerk," Dodgeball is a game where the player spawns in a room with random configurations of walls and enemies. The objective is to navigate the room without touching the walls, as doing so will result in losing the game and ending the episode. The player moves relatively slowly and can throw balls in the direction they are facing. The enemies also move slowly and will occasionally throw balls at the player. If the player successfully hits all enemies, they can move to the unlocked platform and earn a significant level completion bonus.

## Context Description

### Context Example
```
"dodgeball": {
    "max_episode_steps": 1000,
    "world_dim": 20,
    "fire_interval": 7,
    "thickness": .6,
    "enemy_r": 1.,
    "ball_r": .5,
    "ball_vscale": .5,
    "maxspeed": .75,
    "exit_r": 1.5,
    "enemy_speed": .05,
    "num_iterations": 2,
    "max_extra_enemies": 3,
    "base_num_enemies": 3,
    "allow_left_exit": True,
    "allow_right_exit": True,
    "allow_top_exit": True,
    "allow_bottom_exit": True,
    "completion_bonus": 10.,
    # Total: 18
}
```

### Context Parameters
| Parameter | Description | Default Value | Data Type |
|-----------|-------------|---------------|-----------|
|`max_episode_steps`| Maximum number of steps per episode. | 1000 | `int` |
|`world_dim`| Dimension of the game world (width and height). | 20 | `int` |
|`fire_interval`| Time interval between enemy ball throws. | 7 | `int` |
|`thickness`| Thickness of the walls. | 0.6 | `float` |
|`enemy_r`| Radius of the enemies. | 1. | `float` |
|`ball_r`| Radius of the balls. | 0.5 | `float` |
|`ball_vscale`| Scaling factor for the velocity of the balls. | 0.5 | `float` |
|`maxspeed`| Maximum speed of the player. | 0.75 | `float` |
|`exit_r`| Radius of the unlocked platform for level completion. | 1.5 | `float` |
|`enemy_speed`| Speed of the enemies. | 0.05 | `float` |
|`num_iterations`| The number of times rooms are subdivided, affecting the complexity and layout of the game map. | 2 | `int` |
|`max_extra_enemies`| Maximum number of extra enemies that can be added. | 3 | `int` |
|`base_num_enemies`| Base number of enemies in the game. | 3 | `int` |
|`allow_left_exit`| Flag indicating whether left-side exit is allowed. | True | `bool` |
|`allow_right_exit`| Flag indicating whether right-side exit is allowed. | True | `bool` |
|`allow_top_exit`| Flag indicating whether top-side exit is allowed. | True | `bool` |
|`allow_bottom_exit`| Flag indicating whether bottom-side exit is allowed. | True | `bool` |
|`completion_bonus`| Reward received when the player completes the game. | 10. | `float` |
