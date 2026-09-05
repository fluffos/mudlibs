#ifndef _sys_living_h
#define _sys_living_h

#if 0
#define INTERVAL_BETWEEN_HEALING  10
#else
#define INTERVAL_BETWEEN_HEALING  5
#endif
#define KILL_NEUTRAL_ALIGNMENT    10
#define ADJ_ALIGNMENT(al)         ((-al - KILL_NEUTRAL_ALIGNMENT)/4)
#define MAX_LIST                  20
#define NAME_OF_GHOST             "some mist"

#if 0
#  define MAX_STAT_TOTAL          200
#else
#  define MAX_STAT_TOTAL          350
#  define MAX_VALUE_FOR_ONE_STAT  130
#endif

#define LOAD_CONSTANT             10
#define MAX_STAT                  20

#if 0 // Made adjusting healing more flexible
#define REGENERATION_HP_SP        "both"
#define REGENERATION_HP           "hp"
#define REGENERATION_SP           "sp"
#else
// range: -19 .. 19, means a healing fraction hp vs. sp 1:19 .. 19:1
#define REGENERATION_FRACTION_LIMIT  19
#endif

#endif /* _sys_living_h */
