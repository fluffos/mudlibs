#ifndef _VIRTUAL_ROOM_H
#define _VIRTUAL_ROOM_H

/* Let's not inherit room/room.c. It's in virtual_room.c */
#include "room_defs.h"

/* Include defs */
#include "virtual_defs.h"

#if !defined(NO_INHERIT) && !defined(VIRTUAL_ROOM_NO_INHERIT)
inherit VIRTUAL_ROOM_FILE;
#endif

#endif /* _VIRTUAL_ROOM_H */
