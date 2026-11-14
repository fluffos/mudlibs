/*
 * Standard damage types.  Used by living and std object (in different ways).
 */

/* weapon support */

#define	DAM_PHYSICAL	0
#define	DAM_EDGED	10
#define	DAM_POINT	11

/* A bunch of spell damages that the std object recognises */

#define	DAM_FIRE	1
#define	DAM_COLD	2
#define	DAM_SHOCK	4
#define	DAM_MISSILE	5

/* special weapon/armour support */
#define	DAM_ACID	7
#define	DAM_RUST	8
#define	DAM_CURSE	9
#define	DAM_POISON	6

/* water damage for scrolls, etc */
#define	DAM_WATER	3

/* maximum known damage type - after this, it's guild damage */
#define	DAM_LAST	11
