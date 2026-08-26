/*  This is an example of a sword with a special type of damage, in this case
    FIRE.  Hence the name.
  
    Written by Chronos@here (2-16-96)  Happy Valentine's Day! :D
*/
#include <mudlib.h>

inherit WEAPON ;

void create() {
  set("id", ({ "sword", "sword of fire", "fire sword" }) );
  set("short", "a sword of fire");
  set("long", "It's a flaming longsword with a protected hilt.\n");
	set ("mass", 100) ;
	set ("bulk", 20) ;
  set_value(2400);
// "weapon" is the attack class of the weapon. Anything with an attack class
// of 0 is not a weapon. Things with positive numbers are weapons. Higher
// numbers make it easier to hit the target.
      set("weapon", 10);
 set("size", 5) ;
// "damage" is the weapon the damage does in the hands of a normal user
// against an unarmored target. The first element of the array is the
// minimum damage: the second element is the maximum. Actual damage is
// a random number drawn with equal probability from all integers between
// the min and the max.
	set ("damage", ({ 2, 8 }) ) ;
// "type" controls which skill is used in operating the weapon. Should be
// one of three kinds, cutting, blunt, and thrusting, unless you alter
// the skills in which case it can be something else.
	set ("type", "cutting") ;
// "name" is the word the combat routine will use to identify the weapon
// in printing messages. Messages take the form, "You hit the big ugly orc
// with your <name>". The name should not begin with an article or this
// message will not be grammatical.
  set("name", "sword");
  // "damage_type" is where you define the special damage type!
 set("damage_type", "fire");
// set_verbs sets the verbs that will be printed when the weapon is used
// in combat. Messages are of the form "You <verb> the monster" so if the
// verb requires a preposition, it needs to be in the string, as it is in
// the example "swing at".
	set_verbs( ({ "attack", "swing at", "slash at", "cut at" }) ) ;
	set_verbs2( ({ "attacks", "swings at", "slashes at", "cuts at" }) );
// "second" allows the weapon to be used as a second weapon along with some
// other weapon. Daggers and similar small weapons should set this property
// to 1. Others should set it to 0.
	set("second", 0) ;
// "nosecond" prohibits the use of this weapon with a second weapon or a shield.
// Two-handed weapons should set this property to 1, others should leave it 0.
        set("nosecond", 0);
}


