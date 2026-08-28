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

#include <material.h>
#include <color.h>
#include <generic.h>
#include <symbol.h>
#include <living.h>
#include <weapon.h>
#include <shield.h>
#include <clothing.h>
#include <armor.h>
#include <missile_weapon.h>
#include <missile.h>
#include <behavior.h>

mapping generic = ([
"item" : ([

/* light sources (ext1: fuel, ext2: gridlight ) */

"torch" : ({ 50, 5, 5, 0, MTYPE_WOOD, ITEM_LIGHT, IS_TOOL, C_BROWN, ({ 5000, 4 }) }),
"oil lamp" : ({ 15, 25, 15, 35, MTYPE_METAL, ITEM_LIGHT, IS_TOOL, C_YELLOW, ({ 7500, 3 }) }),
"candle" : ({ 3, 30, 3, 0, "wax", ITEM_LIGHT, IS_TOOL, C_WHITE, ({ 10000, 2 }) }),
"lantern" : ({ 15, 25, 15, 75, MTYPE_METAL, ITEM_LIGHT, IS_TOOL, C_YELLOW, ({ 7500, 5 }) }),

/* liquid containers */

"canteen" : ({ 10, 20, 5, 92, MTYPE_METAL, ITEM_DRINKCON, IS_POTION, C_LIGHT_GRAY }),
"barrel" : ({ 50, 100, 50, 94, MTYPE_WOOD, ITEM_DRINKCON, IS_POTION, C_BROWN }),
"potion" : ({ 10, 20, 10, 97, "glass", ITEM_DRINKCON, IS_POTION, C_LIGHT_BLUE }),
				
/* containers */

"sack" : ({ 50, 100, 50, 97, MTYPE_CLOTH, ITEM_CONTAINER, IS_TOOL, C_BROWN }),
"chest" : ({ 100, 50, 50, 95, MTYPE_WOOD, ITEM_CONTAINER, IS_TOOL, C_BROWN }),

/* tools */

"rope" : ({ 300, 2, 2, 4, MTYPE_CLOTH, ITEM_TOOL, IS_TOOL, C_BROWN }),
"mirror" : ({ 20, 20, 1, 0, "glass", ITEM_TOOL, IS_TOOL, C_LIGHT_GRAY }),
"blindfold" : ({ 35, 4, 1, 0, MTYPE_CLOTH, ITEM_TOOL, IS_TOOL, C_DARK_GRAY }),
"towel" : ({ 50, 50, 1, 0, MTYPE_CLOTH, ITEM_TOOL, IS_TOOL, C_MAGENTA }),
"lock pick" : ({ 1, 1, 1, 0, MTYPE_METAL, ITEM_TOOL, IS_TOOL, C_CYAN }),
"pick axe" : ({ 25, 5, 5, 0, MTYPE_METAL, ITEM_TOOL, IS_TOOL, C_LIGHT_GRAY }),
"key" : ({ 5, 2, 1, 0, MTYPE_METAL, ITEM_TOOL, IS_TOOL, C_LIGHT_GRAY }),

/* money */

"gold coin" : ({ 5, 5, 1, 0, "gold", ITEM_MONEY, IS_MONEY, C_YELLOW }),

]),

"food" : ([

/* meat */

"tripe ration" : ({ 25, 10, 25, 0, "flesh", ITEM_FOOD, IS_FOOD, C_BROWN }),
"egg" : ({ 1, 1, 1, 0, "flesh", ITEM_FOOD, IS_FOOD, C_WHITE }),

/* fruits & veggies */

"apple" : ({ 5, 5, 5, 0, "vegetable", ITEM_FOOD, IS_FOOD, C_RED }),
"orange" : ({ 5, 5, 5, 0, "vegetable", ITEM_FOOD, IS_FOOD, C_LIGHT_RED }),
"pear" : ({ 4, 6, 4, 0, "vegetable", ITEM_FOOD, IS_FOOD, C_LIGHT_GREEN }),
"melon" : ({ 11, 13, 9, 0, "vegetable", ITEM_FOOD, IS_FOOD, C_LIGHT_GREEN }),
"banana" : ({ 3, 10, 3, 0, "vegetable", ITEM_FOOD, IS_FOOD, C_YELLOW }),
"carrot" : ({ 2, 10, 2, 0, "vegetable", ITEM_FOOD, IS_FOOD, C_BROWN }),

/* people food */

"cream pie" : ({ 25, 2, 25, 0, "vegetable", ITEM_FOOD, IS_FOOD, C_WHITE }),
"pancake" : ({ 30, 2, 30, 0, "vegetable", ITEM_FOOD, IS_FOOD, C_YELLOW }),
"lembas wafer" : ({ 10, 2, 10, 0, "vegetable", ITEM_FOOD, IS_FOOD, C_WHITE }),
"food ration" : ({ 30, 4, 30, 0, "vegetable", ITEM_FOOD, IS_FOOD, C_BROWN }),

]),

"armor" : ([

"great helm" : ({ 40, 50, 30, 90, MTYPE_METAL, ITEM_ARMOR, IS_ARMOR, C_LIGHT_GRAY, ({ "head" }), ({ }), ([ DT_IMPACT:30, DT_STAB:30, DT_CUT:30 ]) }),
"chainmail" : ({ 50, 100, 10, 95, MTYPE_METAL, ITEM_ARMOR, IS_ARMOR, C_LIGHT_GRAY, ({ "torso", "left shoulder", "right shoulder" }), ({ }), ([ DT_IMPACT:15, DT_CUT:20, DT_STAB:15 ]) }),
"black boots" : ({ 20, 50, 20, 95, MTYPE_CLOTH, ITEM_ARMOR, IS_ARMOR, C_DARK_GRAY, ({ "right foot", "right ankle", "left foot", "left ankle" }), ({ }), ([ DT_IMPACT:5, DT_CUT:10, DT_STAB:5 ]) }),

]),

"weapon" : ([

/* blades */
"knife" : ({ 2, 1, 20, 0, MTYPE_METAL, ITEM_WEAPON, IS_WEAPON, C_LIGHT_GRAY, ([ DT_CUT:25, DT_STAB:25 ]), RANG_CLOSE, WEAPON_1H, "daggers" }),
"dagger" : ({ 2, 1, 30, 0, MTYPE_METAL, ITEM_WEAPON, IS_WEAPON, C_LIGHT_GRAY, ([ DT_CUT:25, DT_STAB:35 ]), RANG_CLOSE, WEAPON_1H, "daggers" }),
"short sword" : ({ 4, 1, 55, 0, MTYPE_METAL, ITEM_WEAPON, IS_WEAPON, C_LIGHT_GRAY, ([ DT_CUT:45, DT_STAB:40 ]), RANG_CLOSE, WEAPON_1H, "1h swords" }),
"cutlass" : ({ 4, 1, 75, 0, MTYPE_METAL, ITEM_WEAPON, IS_WEAPON, C_LIGHT_GRAY, ([ DT_CUT:45, DT_STAB:45 ]), RANG_CLOSE, WEAPON_1H, "1h swords" }),
"bastard sword" : ({ 4, 1, 130, 0, MTYPE_METAL, ITEM_WEAPON, IS_WEAPON, C_LIGHT_GRAY, ([ DT_CUT:60, DT_STAB:50 ]), RANG_CLOSE, WEAPON_12H, "2h swords" }),
"great sword" : ({ 5, 1, 130, 0, MTYPE_METAL, ITEM_WEAPON, IS_WEAPON, C_LIGHT_GRAY, ([ DT_CUT:75, DT_STAB:35 ]), RANG_CLOSE, WEAPON_2H, "2h swords" }),

/* axes */
"dwarvish double-axe" : ({ 4, 1, 80, 0, MTYPE_METAL, ITEM_WEAPON, IS_WEAPON, C_LIGHT_GRAY, ([ DT_CUT:60 ]), RANG_CLOSE, WEAPON_2H, "axes" }),

/* throwing weapons */
"throwing spear" : ({ 1, 1, 80, 0, MTYPE_WOOD, ITEM_WEAPON, IS_WEAPON, C_BROWN, ([ DT_STAB:45 ]), RANG_CLOSE|RANG_THROWN, WEAPON_1H, "throwing spears" }),

]),

"shield" : ([

"large shield" : ({ 60, 50, 1, 50, MTYPE_METAL, ITEM_SHIELD, IS_ARMOR, C_LIGHT_GRAY, 40, ([ DT_IMPACT:10 ]) }),
"spiked shield" : ({ 40, 40, 1, 50, MTYPE_METAL, ITEM_SHIELD, IS_ARMOR, C_LIGHT_GRAY, 30, ([ DT_STAB:30 ]) }),

]),

"missile weapon" : ([

"long bow" : ({ 1, 1, 200, 0, MTYPE_WOOD, ITEM_MISSILE_WEAPON, IS_MISSILE_WEAPON, C_BROWN, WEAPON_2H, ([ "arrow":40 ]), "bows" }),

]),

"missile" : ([

"arrow" : ({ 1, 1, 50, 0, MTYPE_WOOD, ITEM_MISSILE, IS_MISSILE, C_BROWN, ([ DT_STAB:25 ]), "arrow" }),

]),

"clothing": ([

"straw hat"	: ({ 35, 10, 35, 95, MTYPE_CLOTH, ITEM_CLOTHING, IS_CLOTHING, C_YELLOW, ({ "head" }), ({ }) }),
"striped pants" : ({ 50, 120, 20, 95, MTYPE_CLOTH, ITEM_CLOTHING, IS_CLOTHING, C_WHITE, ({ "left thigh", "left knee", "left shin", "right thigh", "right knee", "right shin" }), ({ }) }),
"black robe" : ({ 50, 200, 20, 95, MTYPE_CLOTH, ITEM_CLOTHING, IS_CLOTHING, C_DARK_GRAY, ({ "torso", "left leg", "right leg", "right arm", "left arm" }), ({ "left hand", "right hand", "left foot", "right foot" }) }),
  
]),

]);

mapping npc_class = ([
"peasant" : ({ }),	 
"magic-user" : ({ }),
"thief" : ({ }),
"warrior" : ({ }),
"cleric" : ({ })
]);

mixed
query_generic (string type, string str)
{
   if (!str)
	 return keys (generic[type]);
   
   return generic[type][str];
}

/* This function generates a virtual object by the hints given by the
 * arguments. If the argument is 0 then it is interpreted as random
 * value. If all of them are 0 then the item is completely random. The
 * function returns always an object, upon failure it returns a bug. :)
 */

object
generate (string type, string material, string item)
{
   object o;
   
   if (!type || type == "" || type == "random" || (member_array (type, keys(generic)) == -1 && type != "monster"))
	 type = keys(generic)[random(sizeof(keys(generic)))];;
      
   if ((!material || material == "" || material == "random" || member_array (material, MATERIAL_D->query_material()) == -1) && type != "monster")
	 material = MATERIAL_D->query_material ()[random(sizeof (MATERIAL_D->query_material ()))];
   
   if (!item || item == "" || item == "random" || (type != "monster" && member_array (item, keys(generic[type])) == -1))
	 {
		if (type == "monster")
		  item = RACE_D->query_random_race();
		else
		  item = keys(generic[type])[random(sizeof(keys(generic[type])))];
	 }
   
   switch (type)
	 {
	  case "item":
		if (generic[type][item][GARR_ITEM] == ITEM_LIGHT)
		  o = new ("/inherit/light");
		else if (generic[type][item][GARR_ITEM] == ITEM_MONEY)
		  o = new ("/inherit/money");
		else if (item == "key")
		  o = new ("/inherit/key");
		else
		  o = new ("/inherit/item");
		break;
	  case "food":
		o = new ("/inherit/item");
		break;
	  case "monster":
		o = new ("/inherit/living");
		break;
	  case "weapon":
		o = new ("/inherit/weapon");
		break;
	  case "shield":
		o = new ("/inherit/shield");
		break;
	  case "missile weapon":
		o = new ("/inherit/missile_weapon");
		break;
	  case "missile":
		o = new("/inherit/missile");
		break;
	  case "clothing":
		o = new ("/inherit/clothing");
		break;
	  case "armor":
		o = new ("/inherit/armor");
		break;
	  default:
		o = new ("generic");
		break;
	 }
   
   if (type != "monster")
	 {
		o->set_name (item);
		o->set_gridchar (generic[type][item][GARR_SYMBOL]);
		o->set_gridcolor (generic[type][item][GARR_COLOR]);
		o->set_physical (FALSE);
		o->set_material (material);
		o->set_dimension (generic[type][item][GARR_XDIM], generic[type][item][GARR_YDIM],
						  generic[type][item][GARR_ZDIM], generic[type][item][GARR_HOLLOW]);
		o->set_generate (type, material, item);
   
		switch (generic[type][item][GARR_ITEM])
		  {
		   case ITEM_LIGHT:
			 o->add_command ("light", file_name(o) + "->command_light");
			 o->add_command ("ignite", file_name(o) + "->command_light");
			 o->add_command ("extinguish", file_name(o) + "->command_extinguish");
			 o->add_command ("unlit", file_name(o) + "->command_extinguish");
			 o->add_command ("douse", file_name(o) + "->command_douse");
			 o->set_default ("light");
			 o->set_fuel (generic[type][item][GARR_EXT][0]);
			 o->set_maxlight (generic[type][item][GARR_EXT][1]);
			 break;
		   case ITEM_DRINKCON:
			 o->set_default ("drink");
			 break;
		   case ITEM_WEAPON:
			 o->set_damage (generic[type][item][WEAPON_DAMAGE]);
			 o->set_range (generic[type][item][WEAPON_RANGE]);
			 o->set_handedness (generic[type][item][WEAPON_HANDEDNESS]);
			 o->set_skill (generic[type][item][WEAPON_SKILL]);
			 o->set_default ("wield");
			 break;
		   case ITEM_SHIELD:
			 o->set_skill ("clubs");
			 o->set_handedness (WEAPON_1H);
			 o->set_default ("wield");
			 o->set_shielding (generic[type][item][SHIELD_SHIELDING]);
			 o->set_damage (generic[type][item][SHIELD_DAMAGE]);
			 break;
		   case ITEM_MISSILE_WEAPON:
			 o->set_handedness (generic[type][item][MISSW_HANDEDNESS]);
			 o->set_missiles (generic[type][item][MISSW_MISSILES]);
			 o->set_skill (generic[type][item][MISSW_SKILL]);
			 o->set_default ("wield");
			 break;
		   case ITEM_MISSILE:
			 o->set_damage (generic[type][item][MISS_DAMAGE]);
			 o->set_missile_type (generic[type][item][MISS_TYPE]);
			 break;
		   case ITEM_CLOTHING:
			 o->set_target (generic[type][item][CLOTHING_TARGET], generic[type][item][CLOTHING_EXCLUDE]);
			 o->set_default ("wear");
			 break;
		   case ITEM_ARMOR:
			 o->set_target (generic[type][item][ARMOR_TARGET], generic[type][item][ARMOR_EXCLUDE]);
			 o->set_protection (generic[type][item][ARMOR_PROTS]);
			 o->set_default ("wear");
		   default:
			 break;
		  }
	 }
   else
	 {
		o->set_name(item);
		o->set_race(item);
		o->set_physical(TRUE);     
		o->set_wander(1, 20);
		o->set_talk( 
		  ({ 
			 "Hello.", 
			 "The world will soon be ready.", 
			 "You better not attack me.",
			 "I wish I had some more intelligence." 
		  })
					);
		
		o->add_chat_subject("you", "I'm just "+article(item)+". Leave me alone now!");
		
		switch (item)
		  {
		   case "orc":
			 o->set_relation("race", "elf", -100);
			 o->set_relation("race", "orc", 60);
			 break;
		   case "elf":
			 o->set_relation("race", "orc", -100);
			 o->set_relation("race", "elf", 100);
			 o->set_wimpy(50);
			 break;
		   case "greater demon":
			 o->set_personality(P_AGGRESSIVENESS, 200);
			 o->set_speed(300000);
			 break;
		   case "shadow":
			 o->set_ethereal (1);
			 o->set_personality(P_AGGRESSIVENESS, 200);
			 o->add_spell ("elemental", "flaming dart");
		   default:
			 break;
		  }
	 
	 }
   return o;
}
