/*
** File: da_mon.c
*/

#include <mudlib.h>

inherit MONSTER ;

void create () {
    ::create();
    seteuid(getuid());
    enable_commands() ;

    set("author", "nsd");
    set("short", "Darkangel the God of Chaos (chaotic stupid)");
    set ("long",@EndText
He is carrying:
A sexy skirt (equipped)
A rubber chicken (wielded in both hands)
A black crystal staff
He says he's an "angel".  .oO(NOT)
EndText);
    set ("id", ({ "Darkangel", "darkangel", "DA", "admin" }) );
    set_size(6);
    set_name ("Darkangel");
    set ("gender", "male");
    set ("race", "admin");
    enable_commands() ;
    set_living_name("Darkangel");
    set ("natt", 2);
    set("armor_class", 4);
    set("stat/charisma", 25);
    set("stat/dexterity", 25);
    set("stat/wisdom", 25);
    set("stat/constitution", 25);
    set("stat/intelligence", 25);
    set("stat/strength", 25);
    set("chat_chance", 30);
    set("chat_output", ({
      "Darkangel tips his hat.\n",
      "Darkangel says: you have a sharp tongue, I'll have to nuke you.\n",
      "Darkangel ponders the situation.\n",
      "Darkangel says: oh?\n",
      "Darkangel pulls a feather from his wings, when it lands"+
      " it becomes a sexy skirt.\n",
      "Darkangel wears a sexy skirt.\n",
      "Darkangel wields a rubber chicken.\n",
    }) );
    set("alive", 1);
    set("damage", ({ 1,2 }) );
    set("damage_type", "acid");
    set("weapon_name", "rubber chicken");
    set_verbs( ({ "attack", "swing at", "peer at", "hit" }) );
    set_level(2);
    set("prevent_summon", 1);
}
/* End of File */
