// googol.c
// A patrolling and talking monster.
// He uses the say command so that he may speak in different languages.
// If you just want a monster to speak in Common, you can use the
// chat_chance property instead, which is easier and faster.
// Comments on monster properties are found in /obj/foobird.c
// Mobydick, 10-2-92.

#include <mudlib.h>

inherit MONSTER ;

int language ;

#define LANGS ({ "common", "human", "elvish", "dwarvish", "gnomish" })

void create () {

	object ob1, ob2, ob3 ;

	::create() ;
	seteuid(getuid()) ;
	set ("short", "Googol the dwarf") ;
	set ("long", "The dwarf is walking around in a purposeful way.\n") ;
	set ("id", ({ "googol", "Googol", "dwarf", "old dwarf" }) ) ;
	set_name ("googol") ;
	set ("gender", "male") ;
	enable_commands() ;
	set_living_name("googol") ;
	set ("languages", ([ "human" : 100, "elvish" : 100, "dwarvish" : 100, "gnomish" : 100, "common" : 100 ]) ) ;
	set ("hit_points", 40) ;
	set ("max_hp",40) ;
	set ("attack_strength", 22) ;
	set ("damage", ({ 2,8 }) ) ;
	set ("weapon_name", "flamethrower") ;
	set ("stat/strength", 12) ;
	set ("stat/dexterity", 15) ;
	set_skill("attack", 12, "strength") ;
	set_skill("defense", 8, "dexterity") ;
	set_verbs( ({ "poke at", "swing at", "swipe at" }) ) ;
	set ("patrol", ({ "east", "east", "west", "north", "west", "west",
		"north", "south", "east", "south", "north",
		"east", "north", "east", "west", "south", "south", "west"
	}) ) ;
	set ("speed",8) ;
	set ("moving", 1) ;
	call_out ("advertise", 11) ;
}

void advertise() {

// If this is the master copy (ie, in the void) don't do this.
	if (!environment(this_object())) return ;
	language = language+1 ;
	if (language==sizeof(LANGS)) language=0 ;
	command("say in "+LANGS[language]+" Go see the museum in Smallville!\n") ;
	call_out ("advertise", 11) ;
}
