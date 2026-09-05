/******************************************************************************
 * Program: prestige.h
 * Path: /obj/player
 * Type: Include file for player.c
 * Created: Apr 08, 2014 by Dragnar
 *
 * Purpose: Variables and functions that are needed for prestige levels.
 * 
 * History:
 *          04/10/2014 - Gnar
 *            Created
 ******************************************************************************/
#define REQ_XP 100000000
#define REQ_LEV 19
#define REQ_EXLEV 100
#define REQ_GOLD 1000000
#define REQ_GOLD_INC 100000
#define REQUIRED_GOLD(x) ( REQ_GOLD + x * REQ_GOLD_INC )
#define GUILD_REQ_GOLD 250000
 /*****************************************************************************
  * Order of indexes must not change. Skills can be added to the end of the
  * array. Description array index must be in sync with the valid 
  * prestige skills.
  *****************************************************************************/
#define VALID_PRES_SKILL ({ "exp", "wc", "ac", "gold", "regsp",\
                            "reghp", "detox", "hps", "sps" })

#define PRES_SKILL_DESC ({ "Experience", "Weapon Class", "Armor Class",\
                           "Gold", "SP Regeneration", "HP Regeneration",\
                           "Detoxification","HP Bonus","SP Bonus" })

#define VALID_PRES_GUILD ({ "file", "rank", "exp", "home" })
