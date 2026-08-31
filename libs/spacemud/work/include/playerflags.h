/* Do not remove the headers from this file! see /USAGE for more info. */

/*
** playerflags.h
**
** Player flags (PLAYER_FLAGS and PLAYER_NP_FLAGS flag sets).  To be used
** with the new flags functions.
**
** See also: flags.h, userbits.h
*/

#ifndef __PLAYERFLAGS_H__
#define __PLAYERFLAGS_H__

// NOTE: use absolute cuz of simuls usage
#include "/include/flags.h"

#define F_SNOOPABLE	MakeFlag(PLAYER_FLAGS, 3)
#define F_BRIEF		MakeFlag(PLAYER_FLAGS, 6)

// non-persistent flags (they clear when you log off)

#define F_IN_EDIT	MakeFlag(PLAYER_NP_FLAGS, 0)
#define F_INACTIVE	MakeFlag(PLAYER_NP_FLAGS, 1)


#endif /* __PLAYERFLAGS_H__ */
