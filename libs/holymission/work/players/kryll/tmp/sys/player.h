#ifndef __PLAYER_H__

#define __PLAYER_H__

#define INTERVAL_BETWEEN_HEALING	10
#define WEAPON_CLASS_OF_HANDS		0
#define ARMOUR_CLASS_OF_BARE		0
#define KILL_NEUTRAL_ALIGNMENT		10
#define ADJ_ALIGNMENT(al)		((-al - KILL_NEUTRAL_ALIGNMENT)/4)
#define MAX_LIST			20
#define NAME_OF_GHOST			"Some mist"

#define NUM_STATS	6

#define Str	(TO->query_stats(0))
#define Dex	(TO->query_stats(1))
#define Con	(TO->query_stats(2))
#define Int	(TO->query_stats(3))
#define Wis	(TO->query_stats(4))
#define Chr	(TO->query_stats(5))

#define WIZ 1
#define ARCH 0
#define SM             "/obj/skill_master"
#define SPELL_MASTER   "/spells/master"
#define ABILITY_MASTER "/abilities/master"
#define SOCIAL_MASTER  "/masters/feelings"
#define SKILL_MASTER   "/masters/skills"

#define DEF_START       "/room/church"
#define MAX_POISON      40
#define POISON_STATES   "barely/very weak/weakly/medium/strong/very strong/critical"
#define ARENA           "/players/patience/arena/prep_room"
#define NO_OF_LANG      3         // take care: defined in living too !!!
#define PLAYER          "/sys/bin/player/"
#define BIN_SYSTEM_IN   0

#include "lw.h"
#include "log.h"
#include "/sys/levels.h"
#include "/sys/prompt.h" // Added by Sauron - contains all prompt defs.
#include "/sys/expander.lpc"
#include "/sys/who.lpc"
#include "/sys/env_var.lpc"
#include "/sys/mylook.lpc"
#include "/sys/smell.lpc"
#include "/sys/quest_sys.lpc"
#include "/spells/spell.h"

#include "std_features.lpc"   /* some additional commands :) Llort 22.10.94 */

inherit "/sys/living";

#endif // __PLAYER_H__

