# C-Procgen Benchmark

<img src="./doc/asset/NinjaGame.png" width="600px">

C-Procgen is an enhanced benchmark based on [Procgen](https://github.com/openai/procgen).
It provides precise control over context generation, allowing researchers to customize context parameters according to their specific requirements. 
With added engineering enhancements such as flexible context assignment, dynamic modification, and detailed context tracking, C-Procgen offers improved usability. 
This makes it an excellent platform for studying curriculum reinforcement learning and analyzing learning dynamics in various Procgen contexts.

Please note that this README assumes you have some familiarity with the original Procgen. If you would like to learn more about Procgen, you can refer to the original Procgen [documentation](./doc/Original_README.md) here or visit the official Procgen [repository](https://github.com/openai/procgen).

## Installation

C-Procgen can be installed following the same steps as the original Procgen's "Install from source" method. Please ensure that the dependencies listed in the [`environment.yml`](environment.yml) file are met, and then install C-Procgen.
1. Update the conda environment:
```
conda env update --file environment.yml
```
2. Once the dependencies are installed, proceed to install C-Procgen:
```
pip install -e .
# this should say "building procgen...done"
```

The environment code is in C++ and is compiled into a shared library exposing the [`gym3.libenv`](https://github.com/openai/gym3/blob/master/gym3/libenv.h) C interface that is then loaded by python.  The C++ code uses [Qt](https://www.qt.io/) for drawing.

## Quick Start
To quickly get started with C-Procgen, follow the example below:

1. **Creating games with specific contexts.** We recommend using `ProcgenEnv` to create game environments with specific contexts. Here is an example:
```
# Import the C-Procgen environment
from procgen import ProcgenEnv

# Define the context parameters for different contexts
context_1 = {
    "min_num_sections": 2,
    "max_num_sections": 6,
}
context_2 = {
    "air_control": 0.2,
    "visibility": 6,
}

# Create a Procgen environment with 2 specific contexts
env = ProcgenEnv(num_envs=2, env_name='ninja', context_options=[context_1, context_2])
```
2. **Tracking variational contexts in games.** For games where the context varies within a specified range and is randomly generated for each episode, you can use the `get_context()` method to track the context for each episode.

```
# Get the contexts for current episodes
episodic_contexts = env.get_context()

# Print the contexts for current episodes
print(episodic_contexts)
```
3. **Adjust contexts during training.** If you want to dynamically adjust the context of the game during the training process, you can use the `set_context_to()` method. The specified context will be stored in a buffer and take effect at the beginning of the next episode.
```
# Define a new context
new_context = {
    "min_num_sections": 1,
    "max_num_sections": 1,
}

# Assign the new context to the first environment
env.set_context_to(0, new_context)
```


## Environment Parameters

In C-Procgen, some of the original Procgen parameters, such as `Level seed`,  are no longer fully supported. Instead, C-Procgen focuses on providing more specific context information. The following table lists the parameters that are supported in C-Procgen:

| Parameter| Description|
|----------|------------|
|`env_name`| Name of the environment(s) to instantiate as each environment in the VecEnv.|
|`context_options`|A list of dictionaries, where each dictionary represents a specific context configuration.|
|`use_backgrounds=True`| Determines if games use human-designed backgrounds (`True`). If set to `False`, games will use pure black backgrounds.|
|`restrict_themes=False`| For games that select assets from multiple themes, setting this parameter to `True` ensures they only use a single theme.|
|`use_monochrome_assets`| If set to `True`, games will use monochromatic rectangles instead of human-designed assets. Best used with `restrict_themes=True`. |


## Context Parameters
In C-Procgen, the games generated using the default context have the same game logic and difficulty as the games generated under the `easy` setting in the original Procgen. The following code demonstrates how to view and use the default context:
```
from procgen.default_context import default_context_options

default_context = default_context_options['ninja']

print(default_context)

new_context = {
    **default_context,
    "min_num_sections": 2,
    "max_num_sections": 6,
}
```
The default context for the `ninja` game has the following parameter values:
```
{
    'max_episode_steps': 1000,
    'gravity': 0.2,
    'max_jump': 1.25,
    'jump_charge_inc': 0.25,
    'air_control': 0.15,
    'maxspeed': 0.5,
    'visibility': 16,
    'bomb_prob': 0.5,
    'min_num_sections': 1,
    'max_num_sections': 6,
    'min_difficulty': 1,
    'max_difficulty': 3,
    'max_gap_inc': 1,
    'goal_reward': 10.0
}
```
For more information on the context parameters, please refer to the [Environment List](#environments-list) section.

# Environments List

Here are the 16 games that are currently supported in C-Procgen. For the context parameters of each game, please refer to the links provided in the rightmost column.

| Image | Name | Description | Details |
| --- | --- | --- | --- |
| <img src="https://raw.githubusercontent.com/openai/procgen/master/screenshots/bigfish.png" width="100px"> | `bigfish` | The player starts as a small fish and becomes bigger by eating other fish. The player may only eat fish smaller than itself, as determined solely by width. If the player comes in contact with a larger fish, the player is eaten and the episode ends. The player receives a small reward for eating a smaller fish and a large reward for becoming bigger than all other fish, at which point the episode ends. | [Context Details🔗](./doc/envs/bigfish.md)
| <img src="https://raw.githubusercontent.com/openai/procgen/master/screenshots/bossfight.png" width="100px"> | `bossfight` | The player controls a small starship and must destroy a much bigger boss starship. The boss randomly selects from a set of possible attacks when engaging the player. The player must dodge the incoming projectiles or be destroyed. The player can also use randomly scattered meteors for cover. After a set timeout, the boss becomes vulnerable and its shields go down. At this point, the players projectile attacks will damage the boss. Once the boss receives a certain amount of damage, the player receives a reward, and the boss re-raises its shields. If the player damages the boss several times in this way, the boss is destroyed, the player receives a large reward, and the episode ends. | [Context Details🔗](./doc/envs/bossfight.md)
| <img src="https://raw.githubusercontent.com/openai/procgen/master/screenshots/caveflyer.png" width="100px"> | `caveflyer` | The player must navigate a network of caves to reach the exit. Player movement mimics the Atari game “Asteroids”: the ship can rotate and travel forward or backward along the current axis. The majority of the reward comes from successfully reaching the end of the level, though additional reward can be collected by destroying target objects along the way with the ship's lasers. There are stationary and moving lethal obstacles throughout the level. | [Context Details🔗](./doc/envs/caveflyer.md)
| <img src="https://raw.githubusercontent.com/openai/procgen/master/screenshots/chaser.png" width="100px"> | `chaser` | Inspired by the Atari game “MsPacman”. Maze layouts are generated using Kruskal’s algorithm, and then walls are removed until no dead-ends remain in the maze. The player must collect all the green orbs. 3 large stars spawn that will make enemies vulnerable for a short time when collected. A collision with an enemy that isn’t vulnerable results in the player’s death. When a vulnerable enemy is eaten, an egg spawns somewhere on the map that will hatch into a new enemy after a short time, keeping the total number of enemies constant. The player receives a small reward for collecting each orb and a large reward for completing the level. | [Context Details🔗](./doc/envs/chaser.md)
| <img src="https://raw.githubusercontent.com/openai/procgen/master/screenshots/climber.png" width="100px"> | `climber` | A simple platformer. The player must climb a sequence of platforms, collecting stars along the way. A small reward is given for collecting a star, and a larger reward is given for collecting all stars in a level. If all stars are collected, the episode ends. There are lethal flying monsters scattered throughout the level. | [Context Details🔗](./doc/envs/climber.md)
| <img src="https://raw.githubusercontent.com/openai/procgen/master/screenshots/coinrun.png" width="100px"> | `coinrun` | A simple platformer. The goal is to collect the coin at the far right of the level, and the player spawns on the far left. The agent must dodge stationary saw obstacles, enemies that pace back and forth, and chasms that lead to death. Note that while the previously released version of CoinRun painted velocity information directly onto observations, the current version does not. This makes the environment significantly more difficult. | [Context Details🔗](./doc/envs/coinrun.md)
| <img src="https://raw.githubusercontent.com/openai/procgen/master/screenshots/dodgeball.png" width="100px"> | `dodgeball` | Loosely inspired by the Atari game “Berzerk”. The player spawns in a room with a random configuration of walls and enemies. Touching a wall loses the game and ends the episode. The player moves relatively slowly and can navigate throughout the room. There are enemies which also move slowly and which will occasionally throw balls at the player. The player can also throw balls, but only in the direction they are facing. If all enemies are hit, the player can move to the unlocked platform and earn a significant level completion bonus. | [Context Details🔗](./doc/envs/dodgeball.md)
| <img src="https://raw.githubusercontent.com/openai/procgen/master/screenshots/fruitbot.png" width="100px"> | `fruitbot` | A scrolling game where the player controls a robot that must navigate between gaps in walls and collect fruit along the way. The player receives a positive reward for collecting a piece of fruit, and a larger negative reward for mistakenly collecting a non-fruit object. Half of the spawned objects are fruit (positive reward) and half are non-fruit (negative reward). The player receives a large reward if they reach the end of the level. Occasionally the player must use a key to unlock gates which block the way. | [Context Details🔗](./doc/envs/fruitbot.md)
| <img src="https://raw.githubusercontent.com/openai/procgen/master/screenshots/heist.png" width="100px"> | `heist` | The player must steal the gem hidden behind a network of locks. Each lock comes in one of three colors, and the necessary keys to open these locks are scattered throughout the level. The level layout takes the form of a maze, again generated by Kruskal's algorithm. Once the player collects a key of a certain color, the player may open the lock of that color. All keys in the player's possession are shown in the top right corner of the screen. | [Context Details🔗](./doc/envs/heist.md)
| <img src="https://raw.githubusercontent.com/openai/procgen/master/screenshots/jumper.png" width="100px"> | `jumper` | A platformer with an open world layout. The player, a bunny, must navigate through the world to find the carrot. It might be necessary to ascend or descend the level to do so. The player is capable of “double jumping”, allowing it to navigate tricky layouts and reach high platforms. There are spike obstacles which will destroy the player on contact. The screen includes a compass which displays direction and distance to the carrot. The only reward in the game comes from collect the carrot, at which point the episode ends. Due to a bug that permits the player to spawn on top of critical objects (an obstacle or the goal), ~7% of levels will terminate after a single action, the vast majority of which will have 0 reward. | [Context Details🔗](./doc/envs/jumper.md)
| <img src="https://raw.githubusercontent.com/openai/procgen/master/screenshots/leaper.png" width="100px"> | `leaper` | Inspired by the classic game “Frogger”. The player must cross several lanes to reach the finish line and earn a reward. The first group of lanes contains cars which must be avoided. The second group of lanes contains logs on a river. The player must hop from log to log to cross the river. If the player falls in the river, the episode ends. | [Context Details🔗](./doc/envs/leaper.md)
| <img src="https://raw.githubusercontent.com/openai/procgen/master/screenshots/maze.png" width="100px"> | `maze` | The player, a mouse, must navigate a maze to find the sole piece of cheese and earn a reward. Mazes are generated by Kruskal's algorithm and range in size from 3x3 to 25x25. The maze dimensions are uniformly sampled over this range. The player may move up, down, left or right to navigate the maze. | [Context Details🔗](./doc/envs/maze.md)
| <img src="https://raw.githubusercontent.com/openai/procgen/master/screenshots/miner.png" width="100px"> | `miner` | Inspired by the classic game “BoulderDash”. The player, a robot, can dig through dirt to move throughout the world. The world has gravity, and dirt supports boulders and diamonds. Boulders and diamonds will fall through free space and roll off each other. If a boulder or a diamond falls on the player, the game is over. The goal is to collect all the diamonds in the level and then proceed through the exit. The player receives a small reward for collecting a diamond and a larger reward for completing the level. | [Context Details🔗](./doc/envs/miner.md)
| <img src="https://raw.githubusercontent.com/openai/procgen/master/screenshots/ninja.png" width="100px"> | `ninja` | A simple platformer. The player, a ninja, must jump across narrow ledges while avoiding bomb obstacles. The player can toss throwing stars at several angles in order to clear bombs, if necessary. The player's jump can be charged over several timesteps to increase its effect. The player receives a reward for collecting the mushroom at the end of the level, at which point the episode terminates. | [Context Details🔗](./doc/envs/ninja.md)
| <img src="https://raw.githubusercontent.com/openai/procgen/master/screenshots/plunder.png" width="100px"> | `plunder` | The player must destroy enemy pirate ships by firing cannonballs from its own ship at the bottom of the screen. An on-screen timer slowly counts down. If this timer runs out, the episode ends. Whenever the player fires, the timer skips forward a few steps, encouraging the player to conserve ammunition. The player must take care to avoid hitting friendly ships. The player receives a positive reward for hitting an enemy ship and a large timer penalty for hitting a friendly ship. A target in the bottom left corner identifies the color of the enemy ships to target. | [Context Details🔗](./doc/envs/plunder.md)
| <img src="https://raw.githubusercontent.com/openai/procgen/master/screenshots/starpilot.png" width="100px"> | `starpilot` | A simple side scrolling shooter game. Relatively challenging for humans to play since all enemies fire projectiles that directly target the player. An inability to dodge quickly leads to the player's demise. There are fast and slow enemies, stationary turrets with high health, clouds which obscure player vision, and impassable meteors. | [Context Details🔗](./doc/envs/starpilot.md)
