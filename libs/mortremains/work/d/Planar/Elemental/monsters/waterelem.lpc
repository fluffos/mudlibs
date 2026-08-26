#include <mudlib.h>
inherit MONSTER ;


void create () {
    ::create() ;
    seteuid(getuid()) ;
    set ("short", "Water Elemental") ;
    set ("long", "A being made of pure water.\n") ;
    set ("id", ({ "elemental", "water", "water elemental"}) ) ;
    set_size(9);
    set_name ("water elemental") ;
    set ("gender", "male") ;
    set ("race", "elemental");
    enable_commands() ;
    set_living_name("waterr elemental") ;
    set ("stat/constitution", 20);
    set ("stat/strength", 18);
    set ("base_ac", 2);
    set ("armor_class", 2);
    set ("damage", ({ 5,30 }) ) ;
    set ("weapon_name", "watery fists") ;
    set ("CLASS", "warrior");
    set_verbs( ({ "pummel on", "swing at", "swipe at" }) ) ;
    set ("weap_resist", 2);
    set_level(12);
}
