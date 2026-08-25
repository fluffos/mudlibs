#ifndef __OPTIONS_H
#define __OPTIONS_H

/*
Undefine __OLD_ROOM_BEHAVIOUR if you are starting a new mud.  This will save
substantial memory taken up by room objects.  Leave it defined if you
are upgrading and need room.c to be compatible with your old rooms.
*/
#define __OLD_ROOM_BEHAVIOUR

/*
Undefine __OLD_WEAPON_BEHAVIOUR for the same reasons as above for rooms.
*/
#define __OLD_WEAPON_BEHAVIOUR

#define __OLD_OBJECT_BEHAVIOUR

/* Same for __OLD_FOOD__ */
#define __OLD_FOOD__

#endif /* __OPTIONS_H */
