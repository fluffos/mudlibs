#include <mudlib.h>
#include <weapon_types.h>
 
inherit WEAPON;
 
//Weapon index #s are derived by the following equation:
//avg_damage * (to_hit bonus + parry_modifier + 500)
//So that the index for this weapon is:
//17 * (50 + 20 + 500)
//or: 17 * 570 = 9690
//The minimum price is derived by taking the weapon index (WI)
//dividing it by a (to be determined) constant, and squaring the
//result, so the better a weapon is, the more it costs.  This 
//minimum price is to be in silver. eg:
// (9690 / const) * (9690 / const)
//The values in this dagger are designed to kill a unarmoured 
//player in 20 swings of the blade, approx. (w/o skill 
//modifiers)  This may be modified at any time, but 
//annoucements WILL be made if it does.
 
void setup()
{
  set_weapon_info(({
  14,    //damage bonus
  7,    //damage range (damage of 14-20 per hit, avging at 17)
  50,   //to_hit bonus (50 = 5%)
  20,   //Parry modifier (20 = 2%)
  ({"stab", "slice", "cut"}),     //hit_verbs
  ({"stabs", "slices", "chops"}),  //hit_verbs2
  ({"feint", "slice short", "narrowly miss"}),      //miss_verbs
  ({"feints", "slices short", "narrowly misses"}),  //miss_verbs_2
  ({"dagger","short blade","wicked blade"}),        //weapon_names
  WEAPON_DAGGER,  //weapon_type
  this_object(),     //this object.  =>
  0,                 //hands used (not set here)
  WEAP_SKILL_DAGGER, //Skill weapon uses.
  }));
  set_hands(1);
 
  set_short("a dagger");
  set_long(@ENDLONG
This is a small dagger created for the basic purpose of
killing.  It's blade is short, curved, sharp, and polished,
with a small hand guard, the ideal weapon for creating pure 
havoc in the world.
ENDLONG);
 
  add_ids(({"dagger","weapon"})); //Please have "weapon" in 
                                  //all weapons.
  set_weight(2);                                 // 2 lbs.(?) --Casper
  set_value(({ 0, 0 }));  // To be determined --Casper
}
