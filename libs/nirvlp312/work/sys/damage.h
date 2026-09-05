#ifndef _sys_damage_h
#define _sys_damage_h

#define DT_CRUSHING      "crushing" // by clubs and other blunt tools
#define DT_CUTTING       "cutting"  // by swords and other edged tools
#define DT_IMPALING      "impaling" // by rapiers and other pointy tools
#define DT_BURNING       "burning"  // by fire, cold, acid etc.
#define DT_SCALDING      "scalding" // by hot liquids and steam etc.

#define DAMAGE_TYPES     ({ DT_CRUSHING,DT_CUTTING,DT_IMPALING,DT_BURNING, \
                            DT_SCALDING })

/* more proposals
 * DT_HOLY, DT_UNHOLY, DT_ELECTRIC, DT_POISON, DT_ACID, DT_FIRE, DT_ICE,
 * DT_MAGIC, DT_EARTH, DT_PSIONIC, DT_WATER
 */

#endif /* _sys_damage_h */
