#ifndef _sys_resistance_h
#define _sys_resistance_h

// The resistances are values from -100 .. 100, whereas -100 is 'no resistance'
// and 100 stands for 'immunity'.

#define RES_ICE         "res_ice"
#define RES_FIRE        "res_fire"
#define RES_MAGIC       "res_magic"
#define RES_ELECTRICITY "res_electricity"
#define RES_EARTH       "res_earth"
#define RES_WATER       "res_water"
#define RES_HOLY        "res_holy"
#define RES_UNHOLY      "res_unholy"
#define RES_POISON      "res_poison"
#define RES_ACID        "res_acid"
#define RES_PSIONIC     "res_psionic"

#define RESISTANCE_TYPES ({ RES_ICE,             \
                            RES_FIRE,            \
                            RES_MAGIC,           \
                            RES_ELECTRICITY,     \
                            RES_EARTH,           \
                            RES_WATER,           \
                            RES_HOLY,            \
                            RES_UNHOLY,          \
                            RES_POISON,          \
                            RES_ACID,            \
                            RES_PSIONIC,         \
                         })

#endif
