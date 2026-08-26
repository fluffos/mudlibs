// foobird.c
// An example monster, heavily documented to explain what all of its various
// properties do.
// Created by Mobydick, 8-28-92

#include <mudlib.h>

inherit MONSTER ;

void create () {
	::create();
	seteuid(getuid()) ;
	set("short", "a mighty foobird") ;
	set("long", "If you don't know the joke about the foobird, just \"ask\".\n") ;
	set ("id", ({ "bird", "foobird" }) ) ;
// Monsters need to set mass and bulk, so that when they die we'll know what
// the mass and bulk of the corpse need to be.
// For reference, the mass of a human player is 7500, and the bulk is
// 500.
	set ("mass", 3000) ;
	set ("bulk", 300) ;
// Any monster that's going to carry objects needs to set a capacity and
// volume. For a human players, the capacity is 5000 and the volume is 500.
	set ("capacity", 2500) ;
	set ("volume", 100) ;
// You must also set the max_cap and max_vol properties, so that inventory
// is handled properly. If you don't set these, then the monster's inventory
// won't show the proper weight of items if a wizard takes the body over.
	set ("max_cap", 2500) ;
	set ("max_vol", 100) ;
// All monsters need to set a name for combat messages. This also takes care
// of setting cap_name.
	set_name ("foobird") ;
// Living_name is the name by which the find_living efun can find it.
	set_living_name("foobird") ;
	enable_commands() ;
// The monster should have a gender set.
	set ("gender", "neuter") ;
// The number of hit points the monster has.
	set ("hit_points", 30) ;
// The monster's armor class.
	set ("armor_class", 2) ;
// The maximum hit points the monster can heal to. If you don't want monsters
// to heal, take the heal_up call out of their heart_beat, and you won't need
// this property anymore.
	set ("max_hp", 30) ;
// Aggressive monsters will attack any player that enters their room. If you
// set "aggressive" to 1, the monster is aggressive, otherwise he is not.
	set ("aggressive", 0) ;
// The weapon Class of the monster's barehanded attack. If the monster
// has a weapon this isn't used.
	set ("attack_strength", 6) ;
// The damage range of the monster's attack. As above.
	set ("damage", ({ 2,6 }) ) ;
// The word to be used in describing the thing the monster attacks with.
// Printed in messages of the form "The foobird attacks you with its "+name
// so it should not contain articles.
	set ("weapon_name", "mighty beak") ;
// Monsters have statistics and skills just like players do.
	set ("stat/strength", 10) ;
	set ("stat/dexterity", 6) ;
	set_skill ("attack", 5, "strength") ;
	set_skill ("defense", 5, "dexterity") ;
// The verbs to be used in describing the monster's attack. They are
// conjugated by adding an "s" to the FIRST word in the string. They are
// printed in messages of the form "The foobird "+verb+" you" so if they
// require prepositions those need to be in the string.
	set_verbs( ({ "swipe at" , "slash at", "chew on" }) ) ;
// In the case of irregular conjugations, you can use set_verbs2() to set
// the correct conjugations. In this case, "slash at" would conjugate to
// "slashs at" which isn't correct. So we call set_verbs2 to get the
// proper form. If all the verbs in the list are correctly conjugated by
// adding an s to the first word, then you do not need to call this.
	set_verbs2( ({ "swipes at", "slashes at", "chews on" }) ) ;
// Set the spell the monster will cast, and the chance that it will do so
// on any given attack.
	spell_cast("missile",30) ;
// If you wish the monster to be able to output messages (ie: talk) define
// chat_chance as to the chance between 1 - 100 that the monster will give
// a chat at heartbeat. It will select the output from the chat_output
// array. It will use those found in the att_chat_output if the monster
// is in battle.
	set("chat_chance", 10);
	set("chat_output", ({
	 	"The Foobird warbles merrily at you.\n",
		"The Foobird flaps its wings noisily.\n"
			}));
	set("att_chat_output", ({
		"The Foobird screams angrily at you.\n",
		"The Foobird tries to fly away to avoid the battle.\n",
			}));
}

void init() {
	add_action ("ask", "ask") ;
}

int ask (string str) {
	write (
"  Many years ago a famous explorer went to deepest darkest Africa in\n"+
"search of the mighty foobird. He made contact with members of a remote\n"+
"tribe deep in the jungle, and asked them to show him the foobird. They\n"+
"agreed, but warned him that if the foobird should excrete on him, he\n"+
"must never wipe it off or else he would die! The explorer disregarded\n"+
"this as native superstition, but he agreed to their condition and was\n"+
"taken into the jungle to see the foobird. They came upon the foobird\n"+
"and sure, enough, the foobird excreted directly upon the famous explorer.\n"+
"Seeing a chance to debunk the native's silly superstitions, he wiped it\n"+
"off, and immediately fell over dead!\n"+
"The story has a moral:\n\n"+
"If the foo shits, wear it.\n") ;
	return 1 ;
}
