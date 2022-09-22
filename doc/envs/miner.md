# Miner

<div style="text-align:center">
    <img src="https://raw.githubusercontent.com/openai/procgen/master/screenshots/miner.png"  width="200px">
</div>

## Game Description
Inspired by the classic game “BoulderDash”. The player, a robot, can dig through dirt to move throughout the world. The world has gravity, and dirt supports boulders and diamonds. Boulders and diamonds will fall through free space and roll off each other. If a boulder or a diamond falls on the player, the game is over. The goal is to collect all the diamonds in the level and then proceed through the exit. The player receives a small reward for collecting a diamond and a larger reward for completing the level.

## Context Description

### Context Example
```
"miner": {
    "max_episode_steps": 1000,
    "world_dim": 15,
    "diamond_pct": .03,
    "boulder_pct": .2,
    "completion_bonus": 10.,
    "diamond_reward": 1.,
    # Total: 5
}
```

### Context Parameters
| Parameter | Description | Default Value | Data Type |
|-----------|-------------|---------------|-----------|
|`max_episode_steps`| Maximum number of steps per episode. | 1000 | `int` |
|`world_dim`| Dimension of the game world. | 15 | `int` |
|`diamond_pct`| Percentage of cells that contain diamonds. | 0.03 | `float` |
|`boulder_pct`| Percentage of cells that contain boulders. | 0.2 | `float` |
|`completion_bonus`| Reward received when the player completes the game. | 10. | `float` |
|`diamond_reward`| Reward received for collecting a diamond. | 1. | `float` |
