#ifndef _ROOM_PRIVATE_H
#define	_ROOM_PRIVATE_H
// To be only used by mudlib in internal operations!

#define	F_ROOM_RESET_USED		1
#define	F_ROOM_INIT_USED		(1 << 1)
#define	F_ROOM_EXITS_SKIPPED		(1 << 2)
#define F_ROOM_NO_CLEANUP		(1 << 3)
#define	F_ROOM_PREVENT_TELEPORT_TO	(1 << 4)
#define	F_ROOM_PREVENT_TELEPORT_FROM	(1 << 5)
#define	F_ROOM_NO_PK			(1 << 6)
#define	F_ROOM_IN_CITY			(1 << 7)
#define	F_ROOM_EXIT_LISTS_UPDATED	(1 << 8)
#define	F_ROOM_PREVENT_SHOUT		(1 << 9)
#define	F_ROOM_PREVENT_EMOTE		(1 << 10)
#define	F_ROOM_CATCH_TELL_USED		(1 << 11)
#define	F_ROOM_PREVENT_WHERE		(1 << 12)
#define	F_ROOM_EXTRA_LOOK_USED		(1 << 13)
#define	F_ROOM_GUILD_ROOM		(1 << 14)
#define	F_ROOM_HAS_EFFECTS	        (1 << 15)
#define	F_ROOM_HB_ON			(1 << 16)
#define F_ROOM_ISOLATED			(1 << 17)
#define F_ROOM_BANK                     (1 << 18)
#define F_ROOM_MAZE                     (1 << 19)
#define F_ROOM_MAP_REGISTERED           (1 << 20)

#define	ROOM_FLAGS			50

#endif
