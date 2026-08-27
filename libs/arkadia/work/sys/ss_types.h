/*
 * ss_types.h
 *
 * This file defines the available stats and skills. Use this file to
 * in conjunction with query_stat() and query_skill() calls.
 *
 */

#ifndef SS_TYPES_DEF
#define SS_TYPES_DEF

#define SS_MAX           150

/*
 * There are 2 categories of stats, exp-based-, and guild-stats.
 * Exp based stats have fixed names and are bound to experience points.
 * Guild stats have their names and their values set by the guild.
*/
#define SS_STAT_DESC ({ "str", "dex", "con", "int", "wis", "dis", "race", "occup", "layman" })
#define SS_NO_STATS	 9
#define SS_NO_EXP_STATS  6

#define SS_STR	         0
#define SS_DEX	         1
#define SS_CON	         2
#define SS_INT	         3
#define SS_WIS	         4
#define SS_DIS	         5
#define SS_RACE	         6
#define SS_OCCUP	 7
#define SS_LAYMAN	 8

/* Do we need these? */
#define SS_GUILD	 7
#define SS_OTHER	 8

/* List of skills as is going to be used */

/* Specialized fighting skills */
#define SS_2H_COMBAT		20
#define SS_UNARM_COMBAT		21
#define SS_BLIND_COMBAT		22
#define SS_PARRY		23
#define SS_SHIELD_PARRY		26
#define SS_DEFENCE		24
/*
 * Someone said defence can be spelled defense too.. 
 */
#define SS_DEFENSE	 	24
#define SS_MOUNTED_COMBAT	25

/* Magic skills */
#define SS_SPELLCRAFT		30
#define SS_HERBALISM            36
#define SS_ALCHEMY              37

/*
 * These are the forms of magic available.
 */
#define SS_FORM_TRANSMUTATION	38
#define SS_FORM_ILLUSION	34
#define SS_FORM_DIVINATION	39
#define SS_FORM_ENCHANTMENT	35
#define SS_FORM_CONJURATION	40
#define SS_FORM_ABJURATION	32

/*
 * These are the elements available.
 */
#define SS_ELEMENT_FIRE		41
#define SS_ELEMENT_AIR		42
#define SS_ELEMENT_EARTH	43
#define SS_ELEMENT_WATER	44
#define SS_ELEMENT_LIFE  	33
#define SS_ELEMENT_DEATH   	31

/* Thief skills */
#define SS_OPEN_LOCK		50
#define SS_PICK_POCKET		51
#define SS_ACROBAT		52
#define SS_FR_TRAP		53
#define SS_SNEAK		54
#define SS_HIDE			55
#define SS_BACKSTAB		56

/* Language skills */
#define SS_LANG_COMMON          70
#define SS_LANGUAGE		109

/* General skills */
#define SS_APPR_MON		100
#define SS_APPR_OBJ		101
#define SS_APPR_VAL		102
#define SS_SWIM			103
#define SS_CLIMB		104
#define SS_ANI_HANDL		105
#define SS_LOC_SENSE		106
#define SS_TRACKING		107
#define SS_HUNTING		108
#define SS_AWARENESS		110
#define SS_TRADING		111
#define SS_RIDING		112

/* The min level a trained skill decays */
#define MIN_SKILL_LEVEL         20

/* The time between skill decays in seconds (3h) */
#define SKILL_DECAY_INTERVAL    10800

#include "/config/sys/ss_types2.h"

#endif	SS_TYPES_DEF
