#ifndef _STATS_H
#define	_STATS_H

// Standard defines to be used when setting or querying statistics
// of livings.

#define ST_STR		1
#define ST_INT		2
#define ST_CON		3
#define ST_DEX		4
#define ST_FAT		5
#define	ST_SP_HEAL_RATE	6
#define	ST_HP_HEAL_RATE	7
#define	ST_FP_HEAL_RATE	8

#define ST_BASE_STR	11
#define ST_BASE_INT	12
#define ST_BASE_CON	13
#define ST_BASE_DEX	14
#define ST_BASE_FAT	15
#define	ST_DRAINED	128

#define	ST_FIRST_STAT	1
#define	ST_LAST_STAT	8
#define	ST_ALL_STATS	-1
#define	ST_STAT_BOOSTS	-2
#define	ST_CLEAR_ALL	-3
#define	ST_DEBUG_DATA	-4

// Racial limits still hold!
#define MAX_STAT	500
#define	MAX_TMP_STAT	530
#define	ABS_MAX_STAT	500

#define	MAX_PLAYER_STAT	500

#endif
