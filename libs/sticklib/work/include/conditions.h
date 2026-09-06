// * Condition definations for StickMUD
#ifndef _CONDITIONS_H
#define _CONDITIONS_H

#define	C_FORCE_FLAG	(1<<30)
/* How much to the negative hp we can go before death */
#define DEATH_HP(x) (x / 3)

/* Condition 0 yet unused */
#define C_BLIND		1
/* Deafness might not be so easy to implement... */
#define C_DEAF		2
#define C_STUNNED	3
#define C_UNCONSCIOUS	4
#define C_CONFUSED	5
#define C_POISONED	6
#define C_DETECT_INVIS	7
#define C_SLOWED	8
#define C_HASTED	9
#define C_HALLUCINATING	10
/* Not yet implemented, but can be used */
#define C_DETECT_MAGIC	11
#define C_RESIST_POISON	12
#define C_RESIST_FIRE	13
#define C_RESIST_COLD	14
#define C_RESIST_ACID	15
#define C_RESIST_ELECTRICITY 16
#define C_CASTING	17
/* Castrate them */
#define C_EUNUCH	18
/* New: Sickness - just prevents normal heal. */
#define C_SICK		19
/* This is the condition of death resistance, NOT a resistance */
#define	C_RESIST_DEATH	20

/* Pass out from drinking. This must be a different condition. */
/* Do not EVER use this for attacks! */
#define C_PASSED_OUT	21

/* Best way to avoid conflicts in dodge - Starks */

#define C_NO_DODGE	22

/* Possible future expansions...
#define C_RESIST_EARTH
#define C_RESIST_WATER
#define C_RESIST_AIR
#define C_RESIST_TIME
#define C_RESIST_NETHER
#define C_RESIST_PLASMA
#define C_RESIST_NEGATIVE
#define C_RESIST_POSITIVE
#define C_RESIST_DISEASE
*/

#define	RESISTANCE(x)	-x
#endif /* _CONDITIONS_H */
