// weapon.h
// owns attribs from 600-619
//
// Defines the characteristic of a weapon as defined by the AD&D
// system.

#define a_damage_die 600 // Which die is used for damage points
#define a_damage_num_dice 601 // Number of dice to roll
// Note that the a_damage_modifier is not to be used for
// magical bonuses.  The a_magical_bonus attribute defined in
// attrs/magic.h should be used for that instead.
#define a_damage_modifier 602 // Number to add/subtract from damage roll
// As an example damage of 3d6+3 in AD&D would be set as:
//  set(a_damage_die, 6);
//  set(a_damage_num_dice, 3);
//  set(a_damage_modifier, 3);
// Note that the modifier can be negative.
#define a_damage_string 603
// This attribute is not really stored.  It is used as a front end to
// the numeric attributes.  You would use it as follows:
//  set(a_damage_string, "3d6+3");
// which would set up the same as the example above.
#define a_speed_factor 604
#define a_weapon_type 605 // 1 for Piercing, 2 for Slashing, 4 for Bludgeoning
