//----------------------------------------------------------------------------
// Title:						Author:
//	Monk's guild skill defs file.				Sauron.
//
// File:						Started:
//	/players/sauron/guild/include/skill.h			220696.
//
// Purpose:
//	This file contains all the defs required to use the skill system
//	properly.
//
// History of revisions/fixes:
//
// 230696: Sauron: Started programming.
// 041096: Sauron: Moved to skill_defs.h
//
//----------------------------------------------------------------------------

#ifndef __GUILD_SKILL_DEFS_H__

#define __GUILD_SKILL_DEFS_H__


// Skill roll situations.

#define SIMPLE		0
#define STRESS		1


// Skill roll results.

#define BOTCH		-1
#define FAILURE		0
#define SUCCESS		1


// Skill types: broad definitions. See sub-types.

#define TALENT		0
#define SKILL		1


// Skill sub-types. :)


// Stat indexing.

#define S_STR		0
#define S_DEX		1
#define S_CON		2
#define S_INT		3
#define S_WIS		4
#define S_CHR		5

#define MAX_STAT	40


// Stat boni definitions.

#define B_NON		0
#define B_STR		1
#define B_DEX		2
#define B_CON		4
#define B_INT		8
#define B_WIS		16
#define B_CHR		32


// Skill mapping entry indexing.

#define SKILL_NAME	0
#define SKILL_TYPE	1
#define SKILL_SUBTYPE	2
#define SKILL_BONI	3
#define SKILL_LEARN	4
#define SKILL_RAISE	5


// Cmd types.

#define PEACE_CMD	0
#define NON_AGGR_CMD	1
#define AGGR_CMD	2


// Specialisations.

#define SPECS		({ "general","monk","druid","spec_3" })

#define GENERAL		0
#define MONK		1
#define DRUID		2
#define SPEC_3		3	// ADD 3RD DEF!


// Cmd mapping entry indexing.

#define CMD_SKILL	0
#define CMD_SPEC	1
#define CMD_TYPE	2
#define CMD_TIME	3
#define CMD_LEVEL	4
#define CMD_COST	5
#define CMD_LEARN	6
#define CMD_RAISE	7

#define MAX_SKILL_VAL	100

#define STATS ({ \
                "strength", \
                "dexterity", \
                "constitution", \
                "intelligence", \
                "wisdom", \
                "charisma", \
              })

#define NUM_STATS	6

#define RACES ({ \
                "human", \
                "elf", \
                "half-elf", \
                "hobbit", \
                "gnome", \
                "dwarf", \
                "orc", \
                "troll", \
                "giant", \
              })

#endif // __GUILD_SKILL_DEFS_H__
