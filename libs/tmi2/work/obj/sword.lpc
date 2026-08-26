// sword.c
// A standard sword, heavily commented to explain what all the properties
// it sets control.
// Written by Mobydick@TMI-2, 9-20-92

#include <mudlib.h>

inherit WEAPON ;

void create() {
	set ("id", ({ "sword" }) ) ;
	set ("short", "a sturdy sword") ;
	set ("long", "It has a long blade which is very sharp.\n") ;
	set ("mass", 100) ;
	set ("bulk", 20) ;
	set ("value", ({ 25, "gold" }) ) ;
// "weapon" is the attack Class of the weapon. Anything with an attack Class
// of 0 is not a weapon. Things with positive numbers are weapons. Higher
// numbers make it easier to hit the target.
	set ("weapon", 6) ;
// "damage" is the weapon the damage does in the hands of a normal user
// against an unarmored target. The first element of the array is the
// minimum damage: the second element is the maximum. Actual damage is
// a random number drawn with equal probability from all integers between
// the min and the max.
	set ("damage", ({ 2,10 }) ) ;
// "type" controls which skill is used in operating the weapon. Should be
// one of three kinds, cutting, blunt, and thrusting, unless you alter
// the skills in which case it can be something else.
	set ("type", "cutting") ;
// "name" is the word the combat routine will use to identify the weapon
// in printing messages. Messages take the form, "You hit the big ugly orc
// with your <name>". The name should not begin with an article or this
// message will not be grammatical.
	set ("name", "sword") ;
// set_verbs sets the verbs that will be printed when the weapon is used
// in combat. Messages are of the form "You <verb> the monster" so if the
// verb requires a preposition, it needs to be in the string, as it is in
// the example "swing at".
	set_verbs( ({ "attack", "swing at", "stab at", "slash at" }) ) ;
// Verbs are conjugated by adding an "s" to the FIRST word in the string,
// thus, if you set the verb to be "swing at", the messages will print as:
// "You swing at an orc" "Mobydick swings at an orc." For most verbs this
// is fine, but in irregular cases it is not. In this case you can override
// the conjugator by calling set_verbs2 with the appropriate second verb.
// If none of the conjugations are irregular, this is not necessary.
	set_verbs2( ({ "attacks", "swings at", "stabs at", "slashes at" }) ) ;
// "second" allows the weapon to be used as a second weapon along with some
// other weapon. Daggers and similar small weapons should set this property
// to 1. Others should set it to 0.
	set("second", 0) ;
// "nosecond" prohibits the use of this weapon with a second weapon or a shield.
// Two-handed weapons should set this property to 1, others should leave it 0.
	set("nosecond",0) ;
// "type" controls which skill is used in determining hit chances when the
// weapon is used in an attack. MudOS comes with three types: thrusting,
// cutting, and blunt. You can add more by adding the appropriate skills.
	set ("type", "cutting") ;
}
