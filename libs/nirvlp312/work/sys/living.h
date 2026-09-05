#ifndef __LDMUD__
#include "security.h"
#include "/obj/lib/living/settings.h"


inherit "obj/living.lpc";
#else

#ifndef _sys_living_h_
#define _sys_living_h_

#if 0
#define INTERVAL_BETWEEN_HEALING    10
#else
#define INTERVAL_BETWEEN_HEALING     5
#endif
#define KILL_NEUTRAL_ALIGNMENT      10
#define ADJ_ALIGNMENT(al)           ((-al - KILL_NEUTRAL_ALIGNMENT)/4)
#define MAX_LIST                    20
#define NAME_OF_GHOST               "some mist"

#if 0
#  define MAX_STAT_TOTAL            80
#else
#  define MAX_VALUE_FOR_ONE_STAT    30
#  define MAX_STAT_TOTAL            300
#endif

#define LOAD_CONSTANT               10
#define MAX_STAT                    30

#if 0
#define REGENERATION_HP_SP          "both"
#define REGENERATION_HP             "hp"
#define REGENERATION_SP             "sp"
#else
#define REGENERATION_FRACTION_LIMIT 19
#endif

#endif /* _sys_living_h */

#endif /* LDMUD */

