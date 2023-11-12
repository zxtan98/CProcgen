# Bossfight

<div style="text-align:center">
    <img src="https://raw.githubusercontent.com/openai/procgen/master/screenshots/bossfight.png" width="200px">
</div>

## Game Description
The player controls a small starship and must destroy a much bigger boss starship. The boss randomly selects from a set of possible attacks when engaging the player. The player must dodge the incoming projectiles or be destroyed. The player can also use randomly scattered meteors for cover. After a set timeout, the boss becomes vulnerable and its shields go down. At this point, the player's projectile attacks will damage the boss. Once the boss receives a certain amount of damage, the player receives a reward, and the boss raises its shields again. If the player damages the boss several times in this way, the boss is eventually destroyed, the player receives a large reward, and the episode ends.

## Context Description

### Context Example
```
"bossfight": {
    "max_episode_steps": 1000,
    "completion_bonus": 10,
    "positive_reward": 1,
    "boss_r": 3.,
    "player_bullet_vel": 1,
    "bottom_margin": 6,
    "boss_bullet_vel": .5,
    "max_extra_invulnerable": 1,
    "boss_vel_timeout": 20,
    "boss_damage_timeout": 40,
    "max_rounds_num": 5,
    "min_rounds_num": 1,
    "max_round_health": 9,
    "min_round_health": 1,
    "enable_attack_mode_0": True,
    "enable_attack_mode_1": True,
    "enable_attack_mode_2": True,
    "enable_attack_mode_3": True,
    "enable_shield": True,
    "max_barriers_num": 3,
    "min_barriers_num": 1,
    "completion_bonus": 10,
    "positive_reward": 1,
    # Total: 23
}
```
### Context Parameters
| Parameter | Description | Default Value | Data Type |
|-----------|-------------|---------------|-----------|
|`max_episode_steps`| Maximum number of steps per episode. | 1000 | `int` |
|`completion_bonus`| Reward received when the boss is destroyed. | 10 | `int` |
|`positive_reward`| Reward received for damaging the boss. | 1 | `int` |
|`boss_r`| Radius of the boss starship. | 3. | `float` |
|`player_bullet_vel`| Velocity of the player's projectiles. | 1 | `int` |
|`bottom_margin`| Bottom margin for the barriers. | 6 | `int` |
|`boss_bullet_vel`| Velocity of the boss's projectiles. | 0.5 | `float` |
|`max_extra_invulnerable`| Maximum extra duration of boss invulnerability after each round. | 1 | `int` |
|`boss_vel_timeout`| Time interval for the boss to change direction. | 20 | `int` |
|`boss_damage_timeout`| The time duration a boss remains vulnerable after being hit. | 40 | `int` |
|`max_rounds_num`| Maximum number of rounds for the boss. | 5 | `int` |
|`min_rounds_num`| Minimum number of rounds for the boss. | 1 | `int` |
|`max_round_health`| Maximum health for each round of the boss. | 9 | `int` |
|`min_round_health`| Minimum health for each round of the boss. | 1 | `int` |
|`enable_attack_mode_0`| Enables attack mode 0 for the boss. (Different attack modes include circular, star-shaped, and wave-shaped) | True | `bool` |
|`enable_attack_mode_1`| Enables attack mode 1 for the boss. | True | `bool` |
|`enable_attack_mode_2`| Enables attack mode 2 for the boss. | True | `bool` |
|`enable_attack_mode_3`| Enables attack mode 3 for the boss. | True | `bool` |
|`enable_shield`| 	Enables the invincibility shield for the boss. When enabled, the boss will have periods of invulnerability, during which it cannot be damaged by the player's attacks. | True | `bool` |
|`max_barriers_num`| Maximum number of barriers. | 3 | `int` |
|`min_barriers_num`| Minimum number of barriers. | 1 | `int` |
|`completion_bonus`| Reward received when the boss is destroyed. | 10 | `int` |
|`positive_reward`| Reward received for damaging the boss. | 1 | `int` |
