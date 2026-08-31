#ifndef __DAMAGE_TYPES_H__
#define __DAMAGE_TYPES_H__

#define DAMAGE_PHYSICAL  (1 << 0)
#define DAMAGE_MAGIC     (1 << 1)
#define DAMAGE_MAGICAL   (1 << 1)
#define DAMAGE_FAITH     (1 << 2)
#define DAMAGE_PRAYER    (1 << 2)
#define DAMAGE_SONG      (1 << 3)
#define DAMAGE_DANCE     (1 << 4)
#define DAMAGE_HOLY      (1 << 5)
#define DAMAGE_GOOD      (1 << 5)
#define DAMAGE_UNHOLY    (1 << 6)
#define DAMAGE_EVIL      (1 << 6)
#define DAMAGE_SLASH     (1 << 7)
#define DAMAGE_BLADE     (1 << 7)
#define DAMAGE_AXE       (1 << 7)
#define DAMAGE_PIERCE    (1 << 8)
#define DAMAGE_STAB      (1 << 8)
#define DAMAGE_KNIFE     (1 << 8)
#define DAMAGE_BASH      (1 << 9)
#define DAMAGE_BLUNT     (1 << 9)
#define DAMAGE_IMPACT    (1 << 9)
#define DAMAGE_FIRE      (1 << 10)
#define DAMAGE_HEAT      (1 << 10)
#define DAMAGE_ICE       (1 << 11)
#define DAMAGE_COLD      (1 << 11)
#define DAMAGE_AIR       (1 << 12)
#define DAMAGE_WIND      (1 << 12)
#define DAMAGE_EARTH     (1 << 13)
#define DAMAGE_ROCK      (1 << 13)
#define DAMAGE_STONE     (1 << 13)
#define DAMAGE_SHOCK     (1 << 14)
#define DAMAGE_ELECTRIC  (1 << 14)
#define DAMAGE_LIGHTNING (1 << 14)
#define DAMAGE_ACID      (1 << 15)
#define DAMAGE_ILLUSION  (1 << 16)
#define DAMAGE_PSYCHIC   (1 << 17)
#define DAMAGE_POISON    (1 << 18)
#define DAMAGE_DISEASE   (1 << 19)
#define DAMAGE_MELEE     (1 << 20)
#define DAMAGE_UNARMED   (1 << 20)
#define DAMAGE_WATER     (1 << 21)
#define DAMAGE_OTHER     (1 << 30)

#define MAX_DAMAGE_BIT   30

#define DAMAGE_ALL \
  DAMAGE_PHYSICAL | DAMAGE_MAGIC | DAMAGE_FAITH | \
  DAMAGE_SONG | DAMAGE_DANCE | DAMAGE_HOLY | DAMAGE_UNHOLY | \
  DAMAGE_SLASH | DAMAGE_PIERCE | DAMAGE_BLUNT | \
  DAMAGE_FIRE | DAMAGE_ICE | DAMAGE_AIR | DAMAGE_EARTH | \
  DAMAGE_SHOCK | DAMAGE_ACID | DAMAGE_ILLUSION | DAMAGE_PSYCHIC | \
  DAMAGE_POISON | DAMAGE_DISEASE | DAMAGE_MELEE | DAMAGE_WATER | \
  DAMAGE_OTHER

#endif

