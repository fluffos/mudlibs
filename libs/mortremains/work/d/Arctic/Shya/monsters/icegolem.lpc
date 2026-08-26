

#include <mudlib.h>
inherit MONSTER ;


void create () {
    ::create() ;
    seteuid(getuid()) ;
    set("author", "shya");
    set ("short", "Ice Golem");
    set ("long", "a majestic creature of ice.\n");
    set ("id", ({"ice", "golem", "ice golem"}) );
    set_name("ice golem");
    set ("gender", "male") ;
    set ("race", "golem");
    enable_commands() ;
    set_living_name("ice golem");
    set ("stat/constitution", 20);
    set ("stat/strength", 24);
    set ("base_ac", 3);
    set ("armor_class", 3);
    set ("damage", ({ 4,40 }) ) ;
    set ("weapon_name", "ice blade");
    set ("CLASS", "warrior");
    set_verbs( ({ "smashes at", "swing at", "swipe at" }) ) ;
    set ("weap_resist", 3);
    set("resist_type", ([ "fire":0 ]));
    set("magic_resist", 500);
    set_size(12);
    set_level(18);
    set ("moving", 2);
    set ("speed", 10);
}
