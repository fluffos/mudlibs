
// A generic monster.
// Comments on monster properties are found in /obj/foobird.c

#include <mudlib.h>
inherit MONSTER ;


void create () {

	object ob1, ob2, ob3, ob4 ;

	::create() ;
	seteuid(getuid()) ;
	set ("short", "Bel") ;
	set ("long", "The Powerful Lord of the First Hell.\n"+
	"The Warlord of Avernus, the first layer of Baator.\n"+
	"Sheer power Radiates from his gigantic frame.\n") ;
	set ("id", ({ "bel", "lord", "baatezu"}) ) ;
	set ("capacity", 10000) ;
	set ("max_cap", 10000) ;
	set ("max_vol", 10000) ;
	set ("volume", 200) ;
        set ("mass", 300) ;
        set ("bulk", 250) ;
	set_name ("bel") ;
	set ("gender", "male") ;
	set ("race", "baatezu");
	enable_commands() ;
   	set_living_name("bel") ;
   	set ("stat/constitution", 21);
	set ("stat/strength", 24);
	set ("stat/charisma", 20);
	set ("stat/intelligence", 18);
	set ("stat/dexterity", 22);
	set ("stat/wisdom", 15);
	set ("size", 8);
   	set ("SIZE", 8);
	set("level", 20);
	set("natt", 1);
	set ("thac0", 1);
	set ("base_ac", 4);
	set ("armor_class", 4);
	set ("damage", ({ 1,4 }) ) ;
	set ("weapon_name", "claws") ;
	set ("CLASS", "warrior");
	set ("weap_resist", 4);
	set ("magic_resist", 75);
	set ("resist_type", ([ "cold" : 50, "poison" : 0, "fire" : 0 ]) );
	set_skill("Axes", 5, "Strength") ;
	set_skill("Two Weapon Style", 2, "Strength") ;
	set_skill("Ambidexterity", 1, "Strength") ;
	set_verbs( ({ "poke at", "swing at", "swipe at" }) ) ;
	ob1 = clone_object ("/d/Outer/Abyss/items/molyaxe") ;
    ob1 -> move (this_object()) ;
    ob2 = clone_object ("/d/Outer/Abyss/items/molyaxe") ;
    ob2 -> move (this_object()) ;
   	set_level(40);
   	}
void init () {
::init();
command("wield axe");
command("wield axe 2");
}
