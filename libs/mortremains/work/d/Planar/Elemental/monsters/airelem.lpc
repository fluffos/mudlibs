#include <mudlib.h>
inherit MONSTER ;

void create () {
    ::create() ;
    seteuid(getuid()) ;
    set ("short", "Air Elemental") ;
    set ("long", "A being made of pure air.\n") ;
    set ("id", ({ "elemental", "air", "air elemental"}) ) ;
    set_name ("air elemental") ;
    set ("gender", "male") ;
    set ("race", "elemental");
    enable_commands() ;
    set_living_name("air elemental") ;
    set ("stat/constitution", 20);
    set ("stat/strength", 18);
    set ("base_ac", 2);
    set ("armor_class", 2);
    set ("damage", ({ 2,20 }) ) ;
    set ("weapon_name", "whirlwhind") ;
    set ("CLASS", "warrior");
    set_verbs( ({ "pummel on", "swing at", "swipe at" }) ) ;
    set ("weap_resist", 2);
    set_size(8);
    set_level(12);
}
