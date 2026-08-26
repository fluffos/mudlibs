// This weapon is an example of how to make a weapon with a hit function.
// This weapon happens to be about twice as powerful when fighting
// any Giants.  (not giant crabs or giant rats, just Storm Giants, Hill
// Giants, etc.)
// Written Chronos@DarkTowers 8/6/95 
#include <mudlib.h>

inherit WEAPON ;

void create() {
	set ("id", ({ "slayer", "sword", "giant slayer" }) ) ;
	set ("short", "Giant Slayer") ;
	set ("long", "This is the mighty Giant Slayer.\n") ;
	set ("mass", 100) ;
	set ("bulk", 20) ;
set_value(2000);
// "weapon" is the attack class of the weapon. Anything with an attack class
// of 0 is not a weapon. Things with positive numbers are weapons. Higher
// numbers make it easier to hit the target.
	set ("weapon", 9) ;
// "damage" is the weapon the damage does in the hands of a normal user
// against an unarmored target. The first element of the array is the
// minimum damage: the second element is the maximum. Actual damage is
// a random number drawn with equal probability from all integers between
// the min and the max.
	set ("damage", ({ 2, 8 }) ) ;
// dont forget to set the weapon size.
  set("size", 6);  // 6 = human sized.
// "type" controls which skill is used in operating the weapon. Should be
// one of three kinds, cutting, blunt, and thrusting, unless you alter
// the skills in which case it can be something else.
	set ("type", "cutting") ;
// "name" is the word the combat routine will use to identify the weapon
// in printing messages. Messages take the form, "You hit the big ugly orc
// with your <name>". The name should not begin with an article or this
// message will not be grammatical.
	set ("name", "Giant Slayer") ;
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
	set("nosecond", 1) ;
}

// Weapon_hit is called everytime the weapon hits!  The damage
// it did is passed as a variable so you can use it. 
// The value you return is added onto the damage. ;)
int weapon_hit(int damage) {
  object victim;
  victim=environment()->query_current_attacker();
  if (!victim) return 0;
  if ((string)victim->query("race") == "giant" ||
       victim->id("giant")) {
    tell_object(environment(environment()), 
	      "The Giant Slayer glows brightly!\n");
    return 10;
  }
  return 0;
}
    
