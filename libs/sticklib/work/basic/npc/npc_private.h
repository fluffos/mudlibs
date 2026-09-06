#ifndef _NPC_PRIVATE_H
#define	_NPC_PRIVATE_H

// Header file containing internal flags.
// ONLY TO BE USED BY MUDLIB!!!

#ifndef _LIVING_PRIVATE_H
#include "/basic/living/living_private.h"
#endif

#define	F_NPC_AGGRESSIVE		(1 << 0)
#define	F_NPC_MONS_AGGRESSIVE		(1 << 1)
#define	F_NPC_NO_CONDITION		(1 << 2)
#define	F_NPC_MOVE_AT_RESET		(1 << 3)
#define	F_NPC_FOLLOW_ATTACKER		(1 << 4)
#define	F_NPC_CREATE_ORIGINAL		(1 << 5)
#define	F_NPC_BLOCKING			(1 << 6)

#define F_NPC_CATCH_TELL_USED           (1 << 21)
#define	F_NPC_SM1_ARRAY			(1 << 22)
#define	F_NPC_SM2_ARRAY			(1 << 23)
#define	F_NPC_RESET_USED		(1 << 24)
#define	F_NPC_INIT_USED			(1 << 25)
#define	F_NPC_IS_ORIGINAL		(1 << 26)
#define	F_NPC_HB_IS_ON			(1 << 27)
#define	F_NPC_HAS_TEXT			(1 << 28)
#define	F_NPC_BUSY_CATCH_TELL		(1 << 29)
#define	F_NPC_CONTROLLED		(1 << 30)

#define	NPC_FLAGS			30

#define _FIRST_NPC_VALUE		3000
#define	_LAST_NPC_VALUE			3999

#endif
