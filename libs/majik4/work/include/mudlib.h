/* Majik 4 server
 * Copyright (C) 1998, 1999  Majik Development Team <majik@majik.netti.fi>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

#ifndef __MUDLIB_H__
#define __MUDLIB_H__

#include "mcp.h"

#define THIS 			this_player()
#define THOB 			this_object()
#define PREV(x) 		previous_object(x)
#define ENV(x) 			environment(x)
#define MAPENV(x)       environment(environment(x))

#define WORLDMAP		"/world/worldmap.lpc"
#define GRIDMAP 		"/inherit/gridmap.lpc"
#define AREAMAP         "/inherit/areamap.lpc"
#define GRIDOBJECT 		"/inherit/gridobject.lpc"
#define ITEM			"/inherit/item.lpc"
#define LIVING          "/inherit/living.lpc"
#define BASE 			"/inherit/base.lpc"
#define WEAPON			"/inherit/weapon.lpc"
#define SHIELD			"/inherit/shield.lpc"
#define MISSILE_WEAPON	"/inherit/missile_weapon.lpc"
#define MISSILE			"/inherit/missile.lpc"
#define ARMOR			"/inherit/armor.lpc"
#define CLOTHING		"/inherit/clothing.lpc"
#define BODYPART		"/inherit/bodypart.lpc"
#define HITLOC          "/inherit/hitloc.lpc"
#define NATURAL_WEAPONS "/inherit/natweapon.lpc"
#define EFFECT			"/inherit/effect.lpc"
#define SKILL_SYSTEM	"/inherit/skillsys.lpc"
#define SPELL_SYSTEM	"/inherit/spellsys.lpc"
#define SKILL			"/inherit/skill.lpc"
#define SPELL			"/inherit/spell.lpc"
#define COMBAT_STYLE	"/inherit/cstyle.lpc"
#define MONSTER         "/inherit/monster.lpc"
#define SHOP            "/inherit/shop.lpc"
#define BANK            "/inherit/bank.lpc"
#define BEHAVIOR        "/inherit/behavior.lpc"
#define CHANNEL         "/inherit/channel.lpc"
#define HORSEMAN		"/inherit/horseman.lpc"
#define INTRODUCE       "/inherit/introduce.lpc"

#define TIME_D          "/daemon/time.lpc"
#define WORLDGEN_D		"/daemon/worldgen.lpc"
#define CHANNEL_D		"/daemon/channel.lpc"
#define MATERIAL_D      "/daemon/material.lpc"
#define GENERIC_D       "/daemon/generic.lpc"
#define LOG_D			"/daemon/log.lpc"
#define RACE_D          "/daemon/race.lpc"
#define BATTLE_D		"/daemon/battle.lpc"
#define SKILL_D			"/daemon/skill.lpc"
#define SPELL_D			"/daemon/spell.lpc"
#define WEATHER_D       "/daemon/weather.lpc"
#define OFFLINE_D       "/daemon/offline.lpc"
#define FEELING_D		"/daemon/feeling.lpc"

#define SPELL_DIR       "/spell/"
#define SKILL_DIR       "/skill/"

#define VISIBLE_RADIUS  7

#define TRUE			1
#define FALSE			0

#endif /* __MUDLIB_H__ */
