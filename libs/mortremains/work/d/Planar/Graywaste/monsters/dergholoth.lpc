#include <mudlib.h>

inherit MONSTER ;

void create () {
    ::create() ;
    seteuid(getuid()) ;
    set ("short", "Dergholoth") ;
    set ("long", "A round bodied, three legged, five armed demon from Hades.\n") ;
    set ("id", ({ "dergholoth", "yugoloth" }) ) ;
    set_name ("dergholoth") ;
    set ("race", "yugoloth");
    set ("gender", "male") ;
    enable_commands() ;
    set_living_name("dergholoth") ;
    set("resist_type",([  "poison":0, "acid":0, "cold":200, "fire":0]));
    set("magic_resist", 40);
    set("stat/strength", 20);
    set("stat/constitution", 20);
    set("weap_resist", 1);
    set_level(12);
    set ("base_ac", -3);
    set ("armor_class", -3);
    set("natt", 5);
    set("CLASS", "warrior");
    set("thac0", 13);
    set_skill("Long Blades", 1, "Strength");
    set ("damage", ({ 3,7 }) ) ;
    set ("weapon_name", "claws") ;
    set_verbs( ({ "rip", "slash at", "swipe at" }) ) ;
    set_size(8);
}


