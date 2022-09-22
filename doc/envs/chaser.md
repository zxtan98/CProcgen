# Chaser

<div style="text-align:center">
    <img src="https://raw.githubusercontent.com/openai/procgen/master/screenshots/chaser.png" width="200px">
</div>

## Game Description
Inspired by the Atari game "MsPacman," the Chaser game in C-Procgen features maze layouts generated using Kruskal's algorithm. Walls are removed until no dead-ends remain in the maze. The objective of the game is for the player to collect all the green orbs while avoiding enemies. Three large stars spawn in the maze, making enemies vulnerable when collected. The player's death occurs upon collision with a non-vulnerable enemy. When a vulnerable enemy is eaten, an egg spawns on the map and hatches into a new enemy after a short time, maintaining a constant number of enemies. The player receives a small reward for collecting each orb and a large reward for completing the level.

## Context Description

### Context Example
```
"chaser":{
    "max_episode_steps": 1000,
    "maze_dim": 11,
    "total_enemies": 3,
    "extra_orb_sign": 0,
    "eat_time": 75,
    "egg_time": 50,
    "total_orbs": 10,
    "completion_bonus":10.,
    "orb_reward": 0.04,
    # Total: 9
}
```
### Context Parameters
| Parameter | Description | Default Value | Data Type |
|-----------|-------------|---------------|-----------|
| `max_episode_steps` | Maximum number of steps per episode. | 1000 | `int` |
| `maze_dim` | Dimension of the maze. | 11 | `int` |
| `total_enemies` | Total number of enemies in the maze. | 3 | `int` |
| `extra_orb_sign` | A context that can have a complex explanation. When its value is 0, it represents the normal condition. When its value is n, it signifies that there are n additional enemies in a specific quadrant. | 0 | `int` |
| `eat_time` | Time interval during which enemies can be eaten. | 75 | `int` |
| `egg_time` | Time duration for an egg to hatch into a new enemy after being eaten. | 50 | `int` |
| `total_orbs` | The game ends when the agent eats this number of enemies. | 10 | `int` |
| `completion_bonus` | Reward received when the player completes the level. | 10. | `float` |
| `orb_reward` | Reward received for collecting each orb. | 0.04 | `float` |
