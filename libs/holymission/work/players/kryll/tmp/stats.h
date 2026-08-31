#ifndef __STATS_H__

#define __STATS_H__

#define STRENGTH      0
#define DEXTERITY     1
#define CONSTITUTION  2
#define INTELLIGENCE  3
#define WISDOM        4
#define CHARISMA      5

#define NO_OF_STATS   6

#define STAT_TYPE ({ "strength", "dexterity", "constitution",\
  "intelligence", "wisdom", "charisma" })

#define STAT_MIN_AVG  10
#define STAT_MAX_AVG  20
#define STAT_AVG      18

#define MAX_STAT_MOD  5
#define MIN_STAT_MOD  -5

#endif // __STATS_H__
