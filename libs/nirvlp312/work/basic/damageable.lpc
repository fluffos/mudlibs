/*
 * /basic/damageable.c
 * This will be inherited by anything that can be damaged
 */

#include <event.h>

// this function will put modify the damage mapping according to the situation
// of the damageable object, e.g. a bodypart covered by armour will let the
// armour change the damage so that some of it is absorbed by the armour,
// possibly damaging the armour instead.
// damage here is a mapping object -> (damage_type -> amount_of_damage)
void modify_damage(mapping damage) { }

// This will actually damage the damaged thing according to the damage.
// Each damageable item should decide itself, how it deals with damage.
// damage here is a mapping damage_type -> amount_of_damage
void inflict_damage(mapping damage) { }

// This function is called by weapon
void modify_damage_event(mapping e,string t,int p) {
  modify_damage(e[E_DAMAGE]);
}

// This function is called by the weapon
void notice_damage_event(mapping e,string t,int p) {
  inflict_damage(e[E_DAMAGE][this_object()]); // damage us only
}

