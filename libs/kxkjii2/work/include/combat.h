// combat.h

#ifndef __COMBAT__
#define __COMBAT__

#define TYPE_REGULAR	0
#define TYPE_RIPOSTE	1
#define TYPE_QUICK		2

#define RESULT_DODGE	-1
#define RESULT_PARRY	-2

// This is used as skill_power()'s argument to indicate which type of skill
// usage will be used in calculating skill power.
#define SKILL_USAGE_ATTACK		1
#define SKILL_USAGE_DEFENSE		2
#define SKILL_USAGE_OTHER		3

#define STATUS(x) "/cmds/std/hp"->status_color( me->query(x), me->query( "max_" + x ) )

#endif
