#ifndef _GUILD_arkanisten_H
#define _GUILD_arkanisten_H

#include <defines.h>
#include <moredef.h>
#include <properties.h>
#include <moving.h>
#include <combat.h>
#include <wizlevels.h>
#include <new_skills.h>
#include <class.h>
#include <mnpc.h>
#include <verben.h>
#include <guard.h>
#include <language.h>
#include <attributes.h>
#include <npcmaster.h>
#include <ansi.h> 

#include "langext.h"

#define GUILD_NAME "arkanisten"
#define GUILD "arkanisten"
#define GUILD_NAME_CAPITALIZED "Arkanisten"
#define GUILD_FOLDER "/gilden/"+GUILD_NAME+"/"

#include "/gilden/arkanisten/abilities/ability.h"

#define GADGET_ID "\narkanisten_gadget"
#define GUILD_OBJ_ID "\narkanisten_bandolier"

#define OBJ "/gilden/arkanisten/obj/"
#define ABILITIES "/gilden/arkanisten/abilities/"

#define P_WATCHER_REPORT_LEVEL "watcher_report_level"
#define P_WATCHER_PREPARING_ABILITY "watcher_preparing_ability"
#define P_WATCHER_COMBAT_ABILITIES "watcher_combat_abilities"
#define P_WATCHER_DEFENSIVE_ABILITIES "watcher_defense_abilities"

#define ABILITY_SERVICE "/gilden/arkanisten/abilities/ability_service"

#define pDebug(who, what) if(who->QueryProp(P_TESTPLAYER)) tell_object(who, ANSI_BOLD+ANSI_YELLOW+what+ANSI_NORMAL)
#define DEBUG(what) if(objectp(find_player("gwenshara"))) tell_object(find_player("gwenshara"), ANSI_BOLD+ANSI_YELLOW+what+ANSI_NORMAL)
#endif