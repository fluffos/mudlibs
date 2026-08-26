#include <mudlib.h>
inherit MONSTER ;


void create () {
    ::create() ;
    seteuid(getuid()) ;
    set ("short", "Earth Elemental") ;
    set ("long", "A being made of pure Earth.\n") ;
    set ("id", ({ "elemental", "earth", "earth elemental"}) ) ;
    set_name ("earth elemental") ;
    set ("gender", "male") ;
    set ("race", "elemental");
    set_size(12);
    enable_commands() ;
    set_living_name("earth elemental") ;
    set ("stat/constitution", 20);
    set ("stat/strength", 22);
    set ("base_ac", 2);
    set ("armor_class", 2);
    set ("damage", ({ 4,32 }) ) ;
    set ("weapon_name", "rocky fists") ;
    set ("CLASS", "warrior");
    set_verbs( ({ "poke at", "swing at", "swipe at" }) ) ;
    set ("weap_resist", 2);
    set_level(12);
}
