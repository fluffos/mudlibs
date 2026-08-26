/*  This is an example of a sword that raises a stat for a player.
  
    (04-30-96) Written by Chronos.
*/
#include <mudlib.h>

inherit WEAPON ;

void create() {
  set("id", ({ "sword", "sword of quickness" }) );
  set("short", "sword of quickness");
  set("long", "It's a extremely light shortsword of superior quality.\n");
  set("size", 4);
set ("mass", 60) ;
set ("bulk", 20) ;
  set_value(3000);
// "weapon" is the attack class of the weapon. Anything with an attack class
// of 0 is not a weapon. Things with positive numbers are weapons. Higher
// numbers make it easier to hit the target.
      set("weapon", 12);
// "damage" is the weapon the damage does in the hands of a normal user
// against an unarmored target. The first element of the array is the
// minimum damage: the second element is the maximum. Actual damage is
// a random number drawn with equal probability from all integers between
// the min and the max.
  set ("damage", ({ 1, 6 }) ) ;
// "type" controls which skill is used in operating the weapon. Should be
// one of three kinds, cutting, blunt, and thrusting, unless you alter
// the skills in which case it can be something else.
  set ("type", "thrusting") ;
// "name" is the word the combat routine will use to identify the weapon
// in printing messages. Messages take the form, "You hit the big ugly orc
// with your <name>". The name should not begin with an article or this
// message will not be grammatical.
  set("name", "sword");
// set_verbs sets the verbs that will be printed when the weapon is used
// in combat. Messages are of the form "You <verb> the monster" so if the
// verb requires a preposition, it needs to be in the string, as it is in
// the example "swing at".
set_verbs( ({ "attack", "swing at", "thrust at", "cut at" }) ) ;

// "second" allows the weapon to be used as a second weapon along with some
// other weapon. Daggers and similar small weapons should set this property
// to 1. Others should set it to 0.
set("second", 0) ;
// "nosecond" prohibits the use of this weapon with a second weapon or a shield.
// Two-handed weapons should set this property to 1, others should leave it 0.
        set("nosecond", 0);
// Raise_stat is which stat to raise.  Modifier is by how much.
  set("modifier", 3);
  set("raise_stat", "dexterity");
}
