// Header file for priest spells

#include <invis_levels.h>
#include <guild.h>
#include <attack.h>
#include <player_defs.h>
#include <daemons.h>
#include <conditions.h>
#include <room_defs.h>
#include "../priest.h"
#include "../skills.h"

#define ENV environment
#define HERE environment(who)
#define TO this_object()

inherit GEN_SPELL;
