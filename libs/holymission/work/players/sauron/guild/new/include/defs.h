//----------------------------------------------------------------------------
// Title:						Author:
//	Monk's guild generic defs file.				Sauron.
//
// File:						Started:
//	/players/sauron/guild/include/defs.h			180696.
//
// Purpose:
//	This generic defs file contains all the simple definitions needed in
//	the guild.
//
// History of revisions/fixes:
//
// 180696: Sauron: Started programming.
// 210696: Sauron: Revised layout of header.
//
//----------------------------------------------------------------------------

#ifndef __GUILD_DEFS_H__

#define __GUILD_DEFS_H__

// Preprocessor directives:

#include "/players/sauron/include/include.h"
#include "/players/sauron/guild/include/skill_defs.h"

// End preprocessor directives.

#define TESTING

#define G_PATH		"/players/sauron/guild/"
#define G_BIN		G_PATH+"bin/"		// Secure
#define   G_BIN_AD	G_BIN+"advanced/"
#define   G_BIN_CR	G_BIN+"creator/"
#define   G_BIN_GM	G_BIN+"gm/"
#define   G_BIN_PL	G_BIN+"player/"
#define   G_BIN_PROT	G_BIN+"protector/"
#define   G_BIN_WIZ	G_BIN+"wizard/"
#define G_OBJ		G_PATH+"clone/"
#define G_DATA		G_PATH+"data/"
#define   G_LOG		G_DATA+"log/"
#define   G_SAVE	G_DATA+"p/"		// Secure
#define G_INCLUDE	G_PATH+"include/"
#define G_INFO		G_PATH+"info/"
#define G_INHERIT	G_PATH+"inherit/"
#define G_MONS		G_PATH+"npc/"
#define G_ROOMS		G_PATH+"rooms/"
#define G_SEC		G_PATH+"secure/"	// Secure ;)	
#define   G_CREATOR	G_SEC+"area_creators/"
#define G_SHAD		G_PATH+"shadows/"

#define G_ROOM		"/players/sauron/guild/room"
#define G_SOUL		"/players/sauron/guild/soul"
#define G_SM		"/players/sauron/guild/secure/skill_master"

#define GM		"/guild/master"
#define RM		"/race/master"

#define L_GM		4 // GM has full rights.
#define L_LDR		3 // Honourary guild leader.
#define L_PR		2 // Protectors have special rights/features.
// These 2 should not be used in the GUILD_LEVELS mapping below.
#define L_AD		1 // (AD = advanced player, see LVL_AD)
#define L_PL		0 // 

#define LVL_AD		50 // The level a player has to reach to be called
			   // "advanced" (replaces legends).

#define GUILD_LEVELS	([ \
				"Sauron":	L_GM, \
				"Misticalla":	L_GM, \
				"Shaitan":	L_LDR, \
				"Daniella":	L_PR, \
				"Gwynn":	L_PR, \
				"Notud":	L_PR, \
			])

#define CREATORS ({ \
				"Shaitan", \
			})

#define GN		7	// The index of the guild in /guild/master.c

#endif // __GUILD_DEFS_H__
