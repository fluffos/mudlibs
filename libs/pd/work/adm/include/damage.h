#ifndef __DAMAGE_H__
#define __DAMAGE_H__

#include "damage_types.h"

#define DAMAGE_NO_HP            (1 << 0)
#define DAMAGE_LIMBS_ONLY       (1 << 0)
#define DAMAGE_NO_LIMBS         (1 << 1)
#define DAMAGE_HP_ONLY          (1 << 1)
#define DAMAGE_BYPASS_ARMOUR    (1 << 2)
#define DAMAGE_IGNORE_ARMOUR    (1 << 2)
#define DAMAGE_NO_SEVER         (1 << 3)
#define DAMAGE_NO_PLAYER_REDUCE (1 << 4)
#define DAMAGE_NO_KILL          (1 << 5)
#define DAMAGE_NONLETHAL        (1 << 5)
#define DAMAGE_BYPASS_STRENGTHS (1 << 6)
#define DAMAGE_IGNORE_STRENGTHS (1 << 6)

#endif
