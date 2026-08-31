#ifndef __DAMAGE_H__

#define __DAMAGE_H__

#define PHYSICAL       1
#define MAGIC          2
#define FIRE           3
#define COLD           4
#define ELECTRICITY    5
#define ACID           6
#define POISON         7
#define DISEASE        8
#define DEATH_MAGIC    9
#define BREATH_WEAPON  10
#define UNKNOWN        11

#define NO_OF_DAMAGE_TYPES  10

#define DAMAGE_TYPES ({ "none", "physical", "magic", "fire", "cold",\
  "electricity", "acid", "poison", "disease", "death magic",\
  "breath weapon", "unknown" })

#endif // __DAMAGE_H__
