#ifndef _ROOM_DEFS_H

#define _ROOM_DEFS_H
#include "weatherdesc.h"
#include "lights.h"

#define ROOM_FILE               "/lib/room"

#define SKIP_EXITS               5000
#define SHOW_EXITS              -5000
#define PREVENT_TELEPORT         5001
#define ALLOW_TELEPORT          -5001
#define NO_CLEANUP               5002
#define YES_CLEANUP             -5002

#ifndef NO_PK
#define NO_PK                    5004
#else
#define ROOM_NO_PK               5004
#endif

#define YES_PK                  -5004
#define IN_CITY                  5005
#define OUT_CITY                -5005
#define PREVENT_SHOUT            5006
#define ALLOW_SHOUT             -5006
#define PREVENT_EMOTE            5007
#define ALLOW_EMOTE             -5007
#define PREVENT_TELEPORT_TO      5008
#define ALLOW_TELEPORT_TO       -5008
#define PREVENT_TELEPORT_FROM    5009
#define ALLOW_TELEPORT_FROM     -5009
#define ROOM_PREVENT_WHERE       5010
#define ROOM_ALLOW_WHERE        -5010
#define ROOM_GUILD               5011
#define ROOM_NOT_GUILD          -5011
#define ROOM_ISOLATED            5012
#define ROOM_NOT_ISOLATED       -5012
#define ROOM_WD                  5100
#define ROOM_NIGHT_LONG_DESC     5101
#define ROOM_EFFECT              5102
#define ROOM_EXIT                5103
#define ROOM_ITEM                5104
#define ROOM_SHORT_DESC          5105
#define ROOM_LONG_DESC           5106
#define ROOM_SHORT_EXIT_LIST     5107

#define set_wd(x)                set(ROOM_WD,x)
#define set_outdoors(x)          set(ROOM_WD,x)

#endif // _ROOM_DEFS_H
