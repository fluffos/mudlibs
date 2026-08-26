#ifndef __COMBAT_H__
#define __COMBAT_H__

#define MISSED_HIT_TRAINS_DEFENSE         6
#define MISS_OR_HIT_TRAINS_DBL            (3+random(4))
#define INEFFECTIVE_HIT_TRAINS_DEFENSE    4
#define INEFFECTIVE_HIT_TRAINS_ATTACK     2
#define INEFFECTIVE_HIT_TRAINS_WEAPON     2
#define HIT_TRAINS_DEFENSE                1
#define HIT_TRAINS_ATTACK                 (dam<100?dam/2:50)
#define HIT_TRAINS_WEAPON                 (dam<100?dam/2:50)

#endif

