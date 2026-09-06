#ifndef _NPC_DEFS_H

#define	_NPC_DEFS_H

#ifndef _LIVING_DEFS_H
#include "living_defs.h"
#endif

#include "race.h"
#include "gender.h"
#include "alignment.h"
#include "attack.h"
#include "stats.h"

#define	CREATE_ORIGINAL		3001
#define	DONT_CREATE_ORIGINAL	-3001
#define	NPC_AGGRESSIVE		3002
#define	NPC_NOT_AGGRESSIVE	-3002
#define	NPC_MONS_AGGRESSIVE	3003
#define	NPC_NOT_MONS_AGGRESSIVE	-3003
#define	NPC_MOVE_AT_RESET	3004
#define	NPC_DONT_MOVE_AT_RESET	-3004
#define	NPC_NO_CONDITION	3005
#define	NPC_YES_CONDITION	-3005
#define	NPC_FOLLOW_ATTACKER	3006
#define	NPC_DONT_FOLLOW_ATTACKER -3006
#define	NPC_POSSESSED_BY	3007
#define	NPC_CONTROLLED		3008
// 24-Aug-96 / Graah: Sets PK flag if attacked by player.
#define NPC_SET_PK_FLAG		3010
//  9-May-98 / Graah: Don't leave a corpse.
#define NPC_NO_CORPSE		3012
#define	NPC_MOVE_AREA		3100

#define	NPC_FILE		"/lib/npc"
#define	EQUIPPED_NPC_FILE	"/lib/equipped_npc"
#define	GROUP_NPC_FILE		"/lib/group_npc"
#define	EQUIPPED_GROUP_NPC_FILE	"/lib/equipped_group_npc"

#endif
