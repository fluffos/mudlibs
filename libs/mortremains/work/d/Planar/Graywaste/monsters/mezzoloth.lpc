#include <mudlib.h>

inherit MONSTER ;

void create () {
    ::create() ;
    seteuid(getuid()) ;
    set ("short", "Mezzoloth") ;
    set ("long", "A mantis-like demon from the lower planes.\n") ;
    set ("id", ({ "mezzoloth", "yugoloth" }) ) ;
    set_size(7);
    set_name ("mezzoloth") ;
    set ("race", "yugoloth");
    set ("gender", "male") ;
    enable_commands() ;
    set_living_name("mezzoloth") ;
    set("resist_type",([  "poison":0, "acid":0, "cold":100, "fire":0]));
    set("magic_resist", 50);
    set("stat/strength", 20);
    set("stat/constitution", 20);
    set("weap_resist", 2);
    set ("base_ac", -1);
    set ("armor_class", -1);
    set("natt", 2);
    set("CLASS", "warrior");
    set("thac0", 11);
    set_skill("Polearms", 1, "Strength");
    set ("damage", ({ 3,7 }) ) ;
    set ("weapon_name", "claws") ;
    set_verbs( ({ "rip", "slash at", "swipe at" }) ) ;
    set_level(15);
}


