// A generic monster.
// Comments on monster properties are found in /obj/foobird.c

#include <mudlib.h>
inherit MONSTER ;


void create () {

        object ob1, ob2, ob3, ob4 ;

        ::create() ;
        seteuid(getuid()) ;
        set ("short", "John") ;
        set ("long", "Just some guy.\n") ;
        set ("id", ({ "john", "guy"}) ) ;
        set ("capacity", 10000) ;
        set ("max_cap", 10000) ;
        set ("max_vol", 10000) ; 
        set ("volume", 200) ;
        set ("mass", 300) ;
        set ("bulk", 250) ;
        set_name ("John") ;
        set ("gender", "male") ;
        set ("race", "human");
        enable_commands() ;
        set_living_name("John") ;
        set ("stat/constitution", 18);
        set ("stat/strength", 20);
        set ("stat/charisma", 14);
        set ("stat/intelligence", 11);
        set ("stat/dexterity", 20);
        set ("stat/wisdom", 12);
        set_level(15);
        set("level", 15);
        set("natt", 1);
        set("thac0", 15);    // just as a note this is done automatically by set_level
        set ("damage", ({ 1,4 }) ) ;
        set ("weapon_name", "hands") ;
        set ("CLASS", "warrior");
set ("resist_type", ([ "cold" : 50, "poison" : 50, "force" : 50, "electricity" : 0 ]) );
        set_skill("Long Blades", 5, "Strength") ;
        set_verbs( ({ "strike at", "swing at", "slash at" }) ) ;

//You forgot these:
set_size(6);       //Man szed.
set_align("cg");   //Nobody ever puts this in......i made him Chaotic Good,
                        //Just to show u how to do it.

 //set_level should always be last in the function so the xp is
  // calculated right.
set_level(15);
        ob1 = clone_object ("/d/Prime/Toril/Arabel/weap/frostsword1") ;
        ob1 -> move (this_object()) ;
        ob1 = clone_object ("/d/Outer/Sigil/items/regenring") ;
        ob1 -> move (this_object()) ;
        ob1 = clone_object ("/d/Prime/Toril/Arabel/armour/fieldplate") ;
        ob1 -> move (this_object()) ;
        ob1 = clone_object ("/d/Outer/Sigil/items/ring3") ;
        ob1 -> move (this_object()) ;
        }
void init () {
::init();
command("wield sword");
command("equip all");
}
