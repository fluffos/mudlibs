// A generic monster.
// Comments on monster properties are found in /obj/foobird.c

#include <mudlib.h>
#include "plane.h"

inherit MONSTER ;


void create () {

        object ob1, ob2, ob3, ob4 ;

        ::create() ;
        seteuid(getuid()) ;
        set ("short", "First Mate Silver");
        set ("long", "A gruff pirate, the first mate of the ship.\n");
        set ("id", ({ "mate", "silver", "first mate silver"}) );
        set ("capacity", 10000) ;
        set ("max_cap", 10000) ;
        set ("max_vol", 10000) ; 
        set ("volume", 200) ;
        set ("mass", 300) ;
        set ("bulk", 250) ;
        set_name ("First Mate Silver");
        set ("gender", "male") ;
        set ("race", "human");
        enable_commands() ;
        set_living_name("First Mate Silver");
        set ("stat/constitution", 14);
        set ("stat/strength", 14);
        set ("stat/charisma", 7);
        set ("stat/intelligence", 12);
        set ("stat/dexterity", 13);
        set ("stat/wisdom", 8);
        set("natt", 1);
        set("thac0", 10);
        set ("damage", ({ 8,13 }) ) ;
        set ("weapon_name", "hands") ;
        set ("CLASS", "warrior");
        set_skill("Long Blades", 3, "Strength") ;
        set_verbs( ({ "strike at", "swing at", "slash at" }) ) ;
        ob1 = clone_object ("/obj/weapon/longsword") ;
        ob1 -> move (this_object()) ;
        ob2 = clone_object (PLANE+"armor/patch") ;
        ob2 -> move (this_object()) ;
        ob3 = clone_object ("/obj/armor/chainmail") ;
        ob3 -> move (this_object()) ;
        set_level(7);
        }
void init () {
::init();
command("wield sword");
command("equip all");
}
