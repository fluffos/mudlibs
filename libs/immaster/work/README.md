# A MUD Game Based On LPC/Fluffos/MudCore

Ongoing building of the mudlib, as a learning project. The master branch is kept in working condition.

This mudlib contains the following parts:

1. ext: external modules, including mudcore and www
2. system: the system that controls the game
3. game: the world players live in

External modules kept separated to allow future updates to the modules; System kept separated from game specific files to allow developing other games in the future.

This repository does not contain driver and configuration file/folders, to run the mudlib, the following file/folders need to be added to root:

1. driver: https://www.fluffos.info
2. config: see mudcore/ for config example
3. data/
4. log/

using the web client included in ext/www can access the game from browser

This mudlib is based on "MudCore" from: https://github.com/oiuv/mudcore
