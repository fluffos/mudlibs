#ifndef __DAMAGE_H__

#define __DAMAGE_H__

#define PHYSICAL       0
#define MAGIC          1
#define FIRE           2
#define COLD           3
#define ELECTRICITY    4
#define ACID           5
#define POISON         6
#define DISEASE        7
#define DEATH_MAGIC    8
#define BREATH_WEAPON  9
#define PSIONIC        10
#define UNKNOWN        11

#define NO_OF_DAMAGE_TYPES  12
#define MAX_DAMAGE_ALLOWED  1000

#define DAMAGE_TYPES ({ "physical", "magic", "fire", "cold",\
  "electricity", "acid", "poison", "disease", "death magic",\
  "breath weapon", "psionic", "unknown" })

#endif // __DAMAGE_H__
