// Cyanide fixed this, 21 Nov 98.

#include <mudlib.h>
inherit MONSTER ;

void create () {
    ::create() ;
    seteuid(getuid()) ;
    set("prevent_summon", 1);
    set("short", "a pathetic human slave");
    set("long", "A poor human slave, forced to toil for the Baatezu.\n");
    set("id", ({ "slave", "human" }) );
    set_align("le");
    set_size(6);
    set("author", "cyanide");
    set_name("poor slave");
    set("race", "human");
    set ("gender", "male") ;
    enable_commands() ;
    set_living_name("human slave");
    set("resist_type",([ "cold":50, "fire":0, "poison":0]));
    set("damage", ({ 1, 3 }) );
    set("weapon_name", "fists");
    set_verbs( ({ "swing at" }) );
    set_level(1);
    add("hit_points", -10);
    set("chat_chance", 6);
    set("chat_output", ({
      "The slave begs for liberation.\n",
      "The slave says [to you]: Please, kill me.\n",
      "The slaves searches for solid stone for the City.\n",
    }) );
}


/* EOF */
