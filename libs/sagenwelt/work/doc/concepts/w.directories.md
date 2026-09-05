This file describes the directory structure used by this mudlib.

- /Domains
    Here resides all domains and their related files. Each domain has it's own
    directory with following mandatory sub directories:
    - members   - contains the subdirectories of the domain members, directory
        structure follows the player home directories
    - map       - contains support files for this domains part of the world
        map
    - include   - standard include files
    - lib       - standard inherits for this domain
    - obj       - standard objects
    - rooms     - standard rooms not part of the world map
    - log       - domain specific log files
    - cfg       - domain specific configurations

- /doc
    Here one can find the complete ingame documentation

- /players
    Each player can find his/her home directory here, for a better overview
    those home directories are sorted according their first letter into
    subdirectories.
    These directories also have some mandatory subdirs:
    - include
    - obj
    - rooms
    - log

- /secure
    The objects within this directory are critical for the function of this
    mudlib. Most notable are
    - master.c      - the first object to be loaded, without it nothing goes
    - simul_efun.c  - provides all sefun's

- /std/include
    standard inherits
    Here one can find all neccessary includes need by the standard
    inherits/objects as well as the world map and standard room

- /std/lib
    standard inherits
    Whatever you are trying to do, first take a look here if it is already
    done, even if it's only partial...

- /std/map
    world map
    Parts may be delegated to some domain.

- /std/obj
    standard objects
    In many if not most cases it is enough to clone one of these objects and
    modify it via it's set_* lfuns

- /std/rooms
    standard rooms
    These are some base rooms apart the world map for players to explore.

- /tmp
    A place for temporary files, what ever is stored here doesn't outlive a
    reboot! Older files will be automatically deleted.

- /var/cfg
    Here one can find config files for all system critical objects.

- /var/log
    This is the place to look for system logs. Not all of them are readable by
    everyone!

- /var/player_save
    Here one can fknd the player save files. Like with their home directories
    sorted into subdirs according their first letter.

- /var/save
    These too are configurations for the system critical objects, but where
    the files within /var/cfg are static, these are dynamic.

- /var/spool/mail
    Here are the mailboxes of all users stored, like with the home directories
    and their save files sorted into subdirs:

- /var/spool/news
    Here is the storing place for the news boards.

- /var/tmp
    Like /tmp but outlives a reboot. Older files will be automatically
    deleted.
