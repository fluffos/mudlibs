#ifndef _LIVING_DEFS_H

#define	_LIVING_DEFS_H

#include "race.h"
#include "gender.h"
#include "alignment.h"
#include "attack.h"
#include "stats.h"

#define	LIV_UNDEAD		1000
#define	LIV_NOT_UNDEAD		-1000
#define	LIV_JUST_MOVED		1001
#define	LIV_NOT_JUST_MOVED 	-1001
#define	LIV_BRIEF		1002
#define	LIV_NOT_BRIEF		-1002
#define	LIV_BRIEF_WEATHER	1003
#define	LIV_NOT_BRIEF_WEATHER	-1003
#define	LIV_IS_FLEEING		1004
#define	LIV_NOT_FLEEING		-1004
#define	LIV_DEATH_MARK		1005
#define	LIV_NO_DEATH_MARK	-1005
#define	LIV_SITTING		1006
#define	LIV_STANDING		-1006
#define	LIV_RESTING		1007
#define	LIV_IS_NPC		1008
#define	LIV_IS_PLAYER		-1008
#define	LIV_IS_PLAYER_OR_NPC	1009
#define	LIV_OK_TO_PK		1010
#define	LIV_NIGHT		1011

#define	LIV_MAX_CARRY		1100
#define	LIV_CARRY_RATE		1101
#define	LIV_HEAL_RATE		1102
#define	LIV_DAMAGE_TYPE	1103
#define	LIV_ATTACKERS		1104
#define	LIV_REAL_ATTACKERS	1105
#define	LIV_INFRAVISION		1106
#define	LIV_WC_FORMULA		1107

#define	LIV_CAN_SEE		0x0001
#define	LIV_CAN_HEAR		0x0002
#define	LIV_CAN_SMELL		0x0004
#define	LIV_CAN_FEEL		0x0008

#define	LIVING_FILE		"/lib/living"

#endif
