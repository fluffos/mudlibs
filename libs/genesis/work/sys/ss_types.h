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
#define SS_NO_STATS	10
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
#define SS_CRAFT	 9

/* List of skills as is going to be used */

/* Specialized fighting skills */
#define SS_2H_COMBAT		20
#define SS_UNARM_COMBAT		21
#define SS_BLIND_COMBAT		22
#define SS_PARRY		23
/* Allow for both DEFENCE and DEFENSE spelling */
#define SS_DEFENCE		24
#define SS_DEFENSE	 	24
#define SS_MOUNTED_COMBAT	25
#define SS_BLOCK                26

/* Magic skills */
#define SS_SPELLCRAFT		30
#define SS_HERBALISM            36
#define SS_ALCHEMY              37
/* These are the forms of magic available. */
#define SS_FORM_ABJURATION	32
#define SS_FORM_ILLUSION	34
#define SS_FORM_ENCHANTMENT	35
#define SS_FORM_TRANSMUTATION	38
#define SS_FORM_DIVINATION	39
#define SS_FORM_CONJURATION	40
/* These are the elements available. */
#define SS_ELEMENT_DEATH   	31
#define SS_ELEMENT_LIFE  	33
#define SS_ELEMENT_FIRE		41
#define SS_ELEMENT_AIR		42
#define SS_ELEMENT_EARTH	43
#define SS_ELEMENT_WATER	44

/* Thief skills */
#define SS_OPEN_LOCK		50
#define SS_PICK_POCKET		51
#define SS_ACROBAT		52
#define SS_FR_TRAP		53
#define SS_SNEAK		54
#define SS_HIDE			55
#define SS_BACKSTAB		56

/* Language skills - obsolete.
 * #define SS_LANG_COMMON        70
 */

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
#define SS_LANGUAGE		109
#define SS_AWARENESS		110
#define SS_TRADING		111
#define SS_RIDING		112

/*
 * Grouping of Skills. Needed for GMCP, but also helpful otherwise.
 */
#define SS_SKILL_GROUPS ({ "General", "Weapon", "Fighting", "Magic", "Thief", "Guild" })

/* Gives the minimum and maximum values of the skill group ranges. */
#define SS_SKILL_GROUP_LIMIT ([ \
    "General" : ({ 70, 200 }), \
    "Weapon"  : ({  0,  19 }), \
    "Fighting": ({ 20,  29 }), \
    "Magic"   : ({ 30,  49 }), \
    "Thief"   : ({ 50,  69 }), \
    "Guild"   : ({ 10000, MAXINT }), \
    "All"     : ({  0,    MAXINT }) ])

/* The min level a trained skill decays */
#define MIN_SKILL_LEVEL         0
/* Maximum level allowed. */
#define MAX_SKILL_LEVEL       100

/* The time between skill decays in seconds (3h) */
#define SKILL_DECAY_INTERVAL    10800

/* These are used in guild_support.c */
#define GS_PRIMARY_FOCUS        150
#define GS_SECONDARY_FOCUS       90
#define GS_DEFAULT_FOCUS         30

/* The highest skill number available for mudlib skills */
#define SS_MUDLIB_SKILL_END    4999

/* Define this if you want skills to be limited by stats. */
#define STAT_LIMITED_SKILLS
/* No stat limitation until this skill. */
#define STAT_LIM_MIN_SKILL 20

/*
 * Limits are defined using the limiting stat and limiting weight in the
 * mapping SS_SKILL_DESC
 */

/* List of skills as is going to be used */
#define SS_WEP_FIRST               0   /* The first weapon index */

#define SS_WEP_SWORD            SS_WEP_FIRST + 0  /* W_SWORD */
#define SS_WEP_POLEARM          SS_WEP_FIRST + 1  /* W_POLEARM */
#define SS_WEP_AXE              SS_WEP_FIRST + 2  /* W_AXE */
#define SS_WEP_KNIFE            SS_WEP_FIRST + 3  /* W_KNIFE */
#define SS_WEP_CLUB             SS_WEP_FIRST + 4  /* W_CLUB */
#define SS_WEP_MISSILE          SS_WEP_FIRST + 5  /* W_MISSILE */
#define SS_WEP_JAVELIN          SS_WEP_FIRST + 6  /* W_JAVELIN */

/*
 * SS_SKILL_DESC
 *
 * Description, Costfactor(0-100) Limiting Stat, Limit Weight, Max adv guild
 *
 * When adding/renaming skills, it has to be updated in SS_SKILL_LOOKUP below too.
 */

#define SS_SKILL_DESC ([ \
/* Weapon skills */                                                    \
    SS_WEP_SWORD:     ({ "sword",                 80, SS_DEX, 125, 30 }), \
    SS_WEP_POLEARM:   ({ "polearm",               80, SS_STR, 125, 30 }), \
    SS_WEP_AXE:       ({ "axe",                   80, SS_STR, 125, 30 }), \
    SS_WEP_KNIFE:     ({ "knife",                 60, SS_DEX, 125, 30 }), \
    SS_WEP_CLUB:      ({ "club",                  80, SS_STR, 125, 30 }), \
    SS_WEP_MISSILE:   ({ "missiles",              80, SS_DEX, 125, 30 }), \
    SS_WEP_JAVELIN:   ({ "javelin",               80, SS_STR, 125, 30 }), \
/* General fighting skills */                                           \
    SS_2H_COMBAT:     ({ "two handed combat",    100, SS_DEX, 110,  0 }), \
    SS_UNARM_COMBAT:  ({ "unarmed combat",        80, SS_STR, 110, 30 }), \
    SS_BLIND_COMBAT:  ({ "blindfighting",         95, SS_DEX, 110, 20 }), \
    SS_PARRY:         ({ "parry",                 80, SS_STR, 110,  0 }), \
    SS_DEFENCE:       ({ "defence",               80, SS_DEX, 110, 20 }), \
    SS_MOUNTED_COMBAT:({ "mounted combat",       100, SS_STR, 150,  0 }), \
    SS_BLOCK:         ({ "block",                100, SS_STR, 110, 30 }), \
/* Magic skills */                                                   \
    SS_SPELLCRAFT:    ({ "spellcraft",            70, SS_INT, 125, 20 }), \
    SS_HERBALISM:     ({ "herbalism",             70, SS_WIS, 125, 20 }), \
    SS_ALCHEMY:       ({ "alchemy",               70, SS_INT, 125, 20 }), \
\
    SS_FORM_TRANSMUTATION: ({ "transmutation",    80, SS_INT, 110, 20 }), \
    SS_FORM_ILLUSION:    ({ "illusion",           80, SS_INT, 110, 20 }), \
    SS_FORM_DIVINATION:  ({ "divination",         80, SS_INT, 110, 20 }), \
    SS_FORM_ENCHANTMENT: ({ "enchantment",        80, SS_INT, 110, 20 }), \
    SS_FORM_CONJURATION: ({ "conjuration",        80, SS_INT, 110, 20 }), \
    SS_FORM_ABJURATION:  ({ "abjuration",         80, SS_INT, 110, 20 }), \
    SS_ELEMENT_FIRE:     ({ "fire spells",        75, SS_WIS, 110, 20 }), \
    SS_ELEMENT_AIR:      ({ "air spells",         75, SS_WIS, 110, 20 }), \
    SS_ELEMENT_EARTH:    ({ "earth spells",       75, SS_WIS, 110, 20 }), \
    SS_ELEMENT_WATER:    ({ "water spells",       75, SS_WIS, 110, 20 }), \
    SS_ELEMENT_LIFE:     ({ "life spells",        75, SS_WIS, 110, 20 }), \
    SS_ELEMENT_DEATH:    ({ "death spells",       75, SS_WIS, 110, 20 }), \
/* Thief skills */                                                  \
    SS_OPEN_LOCK:     ({ "open lock",             70, SS_DEX, 110, 20 }), \
    SS_PICK_POCKET:   ({ "pick pocket",           70, SS_DEX, 110, 20 }), \
    SS_ACROBAT:       ({ "acrobat",               80, SS_DEX, 110, 20 }), \
    SS_FR_TRAP:       ({ "find/remove traps",     70, SS_DEX, 110, 20 }), \
    SS_SNEAK:         ({ "sneak",                 70, SS_DEX, 125, 20 }), \
    SS_HIDE:          ({ "hide",                  70, SS_DEX, 125, 20 }), \
    SS_BACKSTAB:      ({ "backstab",              70, SS_DEX, 110,  0 }), \
/* General skills */                                                  \
    SS_APPR_MON:      ({ "appraise enemy",        50, SS_WIS, 150, 30 }), \
    SS_APPR_OBJ:      ({ "appraise object",       50, SS_WIS, 150, 30 }), \
    SS_APPR_VAL:      ({ "appraise value",        50, SS_WIS, 150, 30 }), \
    SS_SWIM:          ({ "swim",                  50, SS_STR, 150, 30 }), \
    SS_CLIMB:         ({ "climb",                 50, SS_STR, 125, 30 }), \
    SS_ANI_HANDL:     ({ "animal handling",       50, SS_WIS, 125, 30 }), \
    SS_LOC_SENSE:     ({ "location sense",        50, SS_WIS, 110, 30 }), \
    SS_TRACKING:      ({ "tracking",              50, SS_WIS, 125, 30 }), \
    SS_HUNTING:       ({ "hunting",               50, SS_INT, 125, 30 }), \
    SS_LANGUAGE:      ({ "language",              50, SS_INT, 110, 30 }), \
    SS_AWARENESS:     ({ "awareness",             50, SS_WIS, 110, 30 }), \
    SS_TRADING:       ({ "trading",               50, SS_INT, 110, 30 }), \
    SS_RIDING:        ({ "riding",                75, SS_DEX, 125, 30 }), \
])

/*
 * Reverse lookup of skill number from the name. Used for GMCP.
 * When adding/renaming skills, it has to be updated here too.
 */
#define SS_SKILL_LOOKUP ([ "sword": SS_WEP_SWORD, "polearm": SS_WEP_POLEARM, "axe": SS_WEP_AXE, \
    "knife": SS_WEP_KNIFE, "club": SS_WEP_CLUB, "missiles": SS_WEP_MISSILE, "javelin": SS_WEP_JAVELIN, \
    "two handed combat": SS_2H_COMBAT, "unarmed combat": SS_UNARM_COMBAT, "blindfighting": SS_BLIND_COMBAT, \
    "parry": SS_PARRY, "defence": SS_DEFENCE, "mounted combat": SS_MOUNTED_COMBAT, "block": SS_BLOCK, \
    "spellcraft": SS_SPELLCRAFT, "herbalism": SS_HERBALISM, "alchemy": SS_ALCHEMY, \
    "transmutation": SS_FORM_TRANSMUTATION, "illusion": SS_FORM_ILLUSION, \
    "divination": SS_FORM_DIVINATION, "enchantment": SS_FORM_ENCHANTMENT, \
    "conjuration": SS_FORM_CONJURATION, "abjuration": SS_FORM_ABJURATION, \
    "fire spells": SS_ELEMENT_FIRE, "air spells": SS_ELEMENT_AIR, "earth spells": SS_ELEMENT_EARTH, \
    "water spells": SS_ELEMENT_WATER, "life spells": SS_ELEMENT_LIFE, "death spells": SS_ELEMENT_DEATH, \
    "open lock": SS_OPEN_LOCK, "pick pocket": SS_PICK_POCKET, "acrobat": SS_ACROBAT, \
    "find/remove traps": SS_FR_TRAP, "sneak": SS_SNEAK, "hide": SS_HIDE, "backstab": SS_BACKSTAB, \
    "appraise enemy": SS_APPR_MON, "appraise object": SS_APPR_OBJ, "appraise value": SS_APPR_VAL, \
    "swim": SS_SWIM, "climb": SS_CLIMB, "animal handling": SS_ANI_HANDL, "location sense": SS_LOC_SENSE, \
    "tracking": SS_TRACKING, "hunting": SS_HUNTING, "language": SS_LANGUAGE, "awareness": SS_AWARENESS, \
    "trading": SS_TRADING, "riding": SS_RIDING ])

#endif	SS_TYPES_DEF
