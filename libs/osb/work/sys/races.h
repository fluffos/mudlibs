#ifndef RACES_H
#define RACES_H

/* Definitions for races and the race-objects */

#define RACEDIR DAEMONPATH "races/data/"
#define RACEOBJ DAEMONPATH "races/raceobj"

#define RD_ALIGN      0  /* Basic alignment */
#define RD_FOOD       1  /* value for P_MAX_FOOD */
#define RD_DRINK      2  /* value for P_MAX_DRINK */
#define RD_ALC        3  /* value for P_MAX_ALC */
#define RD_WEIGHT     4  /* default WEIGHT */
#define RD_HANDS      5  /* default P_HANDS */
#define RD_DEFENCES   6  /* intrinsic P_DEFENCES, must be at least ({ 0 }) */
#define RD_HOME       7  /* default entry-point */
#define RD_LONG       8  /* long description */
#define RD_STAT       9  /* Alist of intrinsic stats */
#define RD_ATTR      10  /* Alist of intrinsic attributes */
#define RD_SIZE      11  /* The livings default size */
#define RD_MAXSTAT   12  /* Alist of intrinsic max stats */
#define RD_PORTAL    13  /* Room where the other portal is (if at all) */
#define RD_EQUIP     14  /* Equipment mapping */
#define RD_INFO      15  /* Information string */
#define RD_PLURAL    16  /* The plural of the racename, or 0 for default. */

#define RD_LEGS      17  /* default P_LEGS */
#define RD_NO_ITEMS  18

// Subindices in RD_EQUIP
#define RDE_FILE   0  // Filename
#define RDE_LEVEL  1  // Max. XP-Level (0: always for players, -1: always
#define RDE_PROPS  2  // Additional properties
#define RDE_ALIAS  3  // Alias-IDs

#define RDE_NO_ITEMS  4

#endif
