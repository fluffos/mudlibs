#ifndef	_DOOR_DEFS_H
#define	_DOOR_DEFS_H

#define	DOOR_IS_CLOSED		1
#define	DOOR_IS_OPEN		2
#define	DOOR_IS_LOCKED		3
#define	DOOR_IS_UNLOCKED	4
#define	DOOR_CAN_BE_LOCKED	5
#define	DOOR_CANT_BE_LOCKED	6

#define		BEFORE		0
#define		AFTER		1

#define		NR_OF_PHASES	2

#define		GO		0
#define		OPEN		1
#define		CLOSE		2
#define		LOCK		3
#define		UNLOCK		4
#define		KNOCK		5

#define		NR_OF_ACTIONS	6

#define		MASTER_KEY	"zap"
#define		DOOR_FILE	"/lib/door"
#define		KEY_FILE	"/std/obj/key"

#endif
