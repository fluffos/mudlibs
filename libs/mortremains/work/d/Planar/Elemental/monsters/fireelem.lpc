#include <mudlib.h>
inherit MONSTER ;


void create () {
    ::create() ;
    seteuid(getuid()) ;
    set ("short", "Fire Elemental") ;
    set ("long", "A being made of pure fire.\n") ;
    set("id", ({ "elemental", "fire elemental" }) );
    set_size(8);
    set_name ("fire elemental") ;
    set("gender", "neuter");
    set ("race", "elemental");
    enable_commands() ;
    set_living_name("fire elemental") ;
    set ("stat/constitution", 20);
    set ("stat/strength", 20);
    set ("base_ac", 2);
    set ("armor_class", 2);
    set("damage_type", "fire");
    set ("damage", ({ 3,24 }) ) ;
    set ("weapon_name", "flaming fists") ;
    set ("CLASS", "warrior");
    set_verbs( ({ "poke at", "swing at", "swipe at" }) ) ;
    set ("weap_resist", 2);
    set_level(12);
}
