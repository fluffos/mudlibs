// A generic monster.
// Comments on monster properties are found in /obj/foobird.c

#include <mudlib.h>
#include "plane.h"
inherit MONSTER ;


void create () {

        object ob1, ob2, ob3, ob4 ;

        ::create() ;
        seteuid(getuid()) ;
        set ("short", "pirate") ;
        set ("long", "Just a pirate.\n") ;
        set ("id", ({ "pirate" }) ) ;
        set ("capacity", 10000) ;
        set ("max_cap", 10000) ;
        set ("max_vol", 10000) ; 
        set ("volume", 200) ;
        set ("mass", 300) ;
        set ("bulk", 250) ;
        set_name ("pirate") ;
        set ("gender", "male") ;
        set ("race", "human");
        enable_commands() ;
        set_living_name("pirate") ;
        set ("stat/constitution", 16);
        set ("stat/strength", 17);
        set ("stat/charisma", 2);
        set ("stat/intelligence", 9);
        set ("stat/dexterity", 15);
        set ("stat/wisdom", 4);
        set_level(4);
        set("thac0", 10);
        set ("damage", ({ 4,7 }) ) ;
        set ("weapon_name", "hands") ;
        set ("CLASS", "thief");
        set_skill("Short Blades", 2, "Strength");
        set_verbs( ({ "strike at", "swing at", "slash at" }) ) ;
        ob1 = clone_object (PLANE+"weapon/pirdag") ;
        ob1 -> move (this_object()) ;
        }
void init () {
::init();
command("wield dagger");
}
