#ifndef __ATTRIBUTES_H__

#define __ATTRIBUTES_H__

#define DODGE_BONUS  0
#define PARRY_BONUS  1
#define ENC_BONUS    2
#define HIT_BONUS    3
#define DAMAGE_BONUS 4
#define REGEN_BONUS  5  // this number should never be greater than
                        //   5 in a player or 20 in a monster

#define NO_OF_ATTRS  6

#define MAX_ATTR_MOD 10
#define MIN_ATTR_MOD -10

#define ATTRIBUTE_TYPE ({ "dodge_bonus", "parry_bonus",\
  "encumbrance_bonus", "hit_bonus", "damage_bonus", "regeneration_bonus" })

#endif // __ATTRIBUTES_H__
