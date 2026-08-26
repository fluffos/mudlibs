/*
** File: faerie.c
** Author: Lady Nsd
** Other comments: To secure peace is to prepare for war!!!
*/

#include <mudlib.h>
inherit MONSTER ;

void create () {
    ::create() ;
    seteuid(getuid()) ;
    set("author", "nsd");
    set ("short", "Water Fay");
    set ("long", wrap(
	"Beautiful faeries with crystal wings. They are the guardians\n"+
	"of nature secrets, and pour healing water to refresh us. Their\n"+
	"wings produce a sound of wind chimes as they fly...\n"));
    set ("id", ({ "water fay", "fay", "faerie" }) );
    set_size(1);
    set_name ("water fay");
    set ("gender", "female");
    set ("race", "faerie");
    enable_commands() ;
    set_living_name("faerie");
    set ("natt", 1);
    set("chat_chance", 50);
    set("chat_output", ({
      "Water fay flies around you...\n",
      "Water fay is suspended in the air like a helicopter...\n",
      "Water fay stares at you, smiles, and prepares to leave...\n",
      "Water fay produces a wind chime sound as she flies you by...\n",
    }) );
    set("patrol", ({ "north", "south", "east", "west", "northeast", "southwest"
    }) );
    set_verbs( ({ "attack", "bite", "swing at", "slash" }) );
    set("weapon_name", "tiny sharp teeth");
    set("speed", 5);
    set("armor_class", 2);
    set("alive", 1);
    set("CLASS", "mage");
    set("damage", ({5,8}) );
    set("stat/intelligence", 16);
    set("stat/strength", 8);
    set("stat/constitution", 10);
    set("stat/dexterity", 9);
    set("stat/charisma", 16);
    set("wealth", 50);
    set_level(10);
}

/* EOF */
