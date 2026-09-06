#ifndef _PLAYER_PRIVATE_H
#define	_PLAYER_PRIVATE_H

#ifndef _LIVING_PRIVATE_H
#include "/basic/living/living_private.h"
#endif

// Saveable player flags:
#define F_PLR_INFO_ON		(1 << 0)
#define	F_PLR_BRIEF		(1 << 1)
#define	F_PLR_BRIEF_WEATHER	(1 << 2)
#define	F_PLR_DEATH_MARK	(1 << 3)
#define	F_PLR_HPSP		(1 << 4)

// Non-saveable player flags:
#define	F_PLR_BUSY_KILL		(1 << 1)
#define	F_PLR_ALLOW_SUMMON	(1 << 2)
#define	F_PLR_WIZ		(1 << 3)
#define	F_PLR_FIZ		(1 << 4)
#define	F_PLR_LICH		(1 << 5)
// Someone forgot this:
#define F_PLR_AWIZ		(1 << 6)

#define	PLR_FLAGS		20
#define	PLR_SAVE_FLAGS		25

#define	_FIRST_PLR_VALUE	2000
#define	_LAST_PLR_VALUE		2000

#endif
