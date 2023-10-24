Freeciv
=======

[![Build Status](https://github.com/freeciv/freeciv/workflows/continuous%20integration/badge.svg)](https://github.com/freeciv/freeciv/actions?query=workflow%3A%22continuous+integration%22)
[![License: GPL v2](https://img.shields.io/badge/License-GPL%20v2-blue.svg)](https://www.gnu.org/licenses/old-licenses/gpl-2.0.en.html)

Freeciv is a Free and Open Source empire-building strategy game inspired by the history of human civilization.

Please see the [doc](doc) directory for a complete list of documentation files.

Links
=====
Freeciv website: [Freeciv.org](https://www.freeciv.org/)

Submit patches: [OSDN](https://osdn.net/projects/freeciv/ticket/)

Community forum: [forum.freeciv.org](https://forum.freeciv.org/)

Basic Updates
=====
| type        | module                            | content                                                       |
| ---   | --- | -- |
| luascript   | server/scripting/script_server.c  | add luascript_signal: `action_started_worker_build`            |
|             | server/scripting/script_server.c  | add luascript_signal: `action_finished_worker_build`            |
|             | server/scripting/script_server.c  | add luascript_signal: `game_started`            |
|             | server/scripting/script_server.c  | add luascript_signal: `game_ended`            |
| score       | common/city.c                     | add weighted score calculation function: `city_tile_weight_score_calculation`            |
|             | common/city.h                     | add float `total_tiles_resource_indic` and `city_resource_indic` for struct `city`     |

Important Updates
=====
## Control of succeeded conditions

We add an option for ending the game when some players succeed. If this option is set to true, the game will only end at the end of the given turn or when all players are killed:
```
game.server.end_victory = FALSE
```
The option has several advantages, including:
1. The client can perceive the success information, which can help them understand the game’s progress and make informed decisions.
2. Updating the status of players inside the server can help ensure that the game is fair and that all players have equal opportunities to succeed.

Background

    The default config of victory conditions
    ```
    enum victory_condition_type
    {
    VC_SPACERACE = 0,
    VC_ALLIED,
    VC_CULTURE
    };

    #define GAME_DEFAULT_VICTORY_CONDITIONS (1 << VC_SPACERACE | 1 << VC_ALLIED )
    #define GAME_DEFAULT_END_SPACESHIP   TRUE
    ```
    The enum victory_condition_type defines three types of victory conditions: VC_SPACERACE, VC_ALLIED, and VC_CULTURE. 

    The GAME_DEFAULT_VICTORY_CONDITIONS macro is set to include the first two types of victory conditions, i.e., VC_SPACERACE and VC_ALLIED.

    The server has end control for max turn, which can be accessed using the following command:
    ```
    game.server.end_turn
    ```
    If we set the following option to be False, the spaceship succeeded condition would be closed, but the information about the spaceship succeed status would not be updated:
    ```
    game.server.endspaceship = FALSE
    ```
    Similarly, the victory succeeded condition would be closed as following option:
    ```
    game.info.victory_conditions = 0
    ```

