/*
** File: butterfly2.c
** Author: Lady Nsd
** Other comments: To secure peace is to prepare for war!!!!
*/

#include <mudlib.h>
inherit MONSTER ;

void create () {
    ::create() ;
    seteuid(getuid()) ;
    set("author", "nsd");
    set ("short", "Glowing Butterfly");
    set ("long", wrap(
	"A crystal butterfly that glows in pastel colors as the\n"+
	"sun rays illuminate its wings.\n"));
    set ("id", ({ "butterfly" }) ) ;
    set_name ("butterfly");
    set ("gender", "neuter") ;
    set ("race", "gloomwing");
    enable_commands() ;
    set_living_name("butterfly");
    set ("natt", 1);
    set("armor_class", 1);
    set("base_ac", -10);
    set("damage", ({5,20}) );
    set_size(8);
    set("stat/intelligence", 1);
    set("stat/strength", 10);
    set("stat/constitution", 8);
    set("stat/dexterity", 10);
    set("stat/charisma", 9);
    set("weapon_name", "strong scent");
    set_verbs( ({ "attack", "poison", "swing at", "drowse" }) );
    set_level(7);
}

/* EOF */
