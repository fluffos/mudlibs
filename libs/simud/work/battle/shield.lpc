#include <battle.h>
#include <item.h>
#include <object.h>
#include <saveload.h>
#include <condition.h>

int base_ac;      // general armour class (applies to all types)
mapping ac_mod;      // armour class. ex (["edged":3, "blunt":-5])
int cursed;

// Object editor information.
string shield_info() {
  return "base_ac\nac_mod\n";
}

ICON( '[', 7, 1 )

/****************************** Queries ****************************/

/** Return the armour class of this object. If called with a string
 * parameter, then one particular ac is returned (ie, query_ac("fire")
 * returns the armour's fire ac).
 *
 * If called without any parameters and there are any modifiers defined, the
 * object's entire ac mapping is returned. Otherwise, the base ac is returned.
 */
varargs mixed query_ac(string param) {
  mapping temp = copy(ac_mod);
  string str;
  if (param)
    return ac_mod[param]+base_ac;

  if (sizeof(ac_mod)) {
    foreach (str: ac_mod)
      temp[str] = ac_mod[str] + base_ac;
    return temp;
  } else {
    return base_ac;
  }
}

int query_base_ac() { return base_ac; }

varargs mixed query_ac_mod(string param) {
  if (param)
    return ac_mod[param];
  return ac_mod;
}

string query_armour_type() { return "shield"; }
int query_cursed() { return cursed; }

/******************************* Sets *******************************/

set_cursed(int x) {
  if (x >= 0)
    cursed = x;
}

void set_base_ac(int x) { base_ac = x; }

varargs void set_ac_mod(mixed one, int two) {
  if (mappingp(one))
    ac_mod = copy(one);
  else if (stringp(one))
    ac_mod[one] = two;
}

/** Laziness method for declaring base ac and ac modifiers in one shot. This
 * function takes several different possible sets of parameters and does
 * various wierd and unholy things to armour class depending on the sort of
 * input you give it.
 *
 * set_ac( "fire",3 )
 *   Would set the fire ac of the object to 3. This means that if the object
 *   already has a base ac of 2, it would set ac_mod["fire"] to 1, or if the
 *   base were 5, it would set the modifier to -2. Note that changing the base
 *   ac afterward will affect the specific ac's set in the modifier mapping.
 *
 * set_ac( (["fire":3,"ice":2]) )
 *   Would set the ac modifier mapping to the mapping given. No change is
 *   made to base ac.
 *
 * set_ac( 3 )
 *   This sets the base ac to 3. No changes are maded the the mod mapping.
 *
 * set_ac( (["fire":3]), 5 )
 *   This is perhaps the most efficient way to set armour class. It sets the
 *   base ac to 5 and then sets the fire ac to 3 (by setting the modifier to
 *   -2).
 */
varargs void set_ac(mixed one, int two) {
  string str;
  if (!one)
    return;
  if (intp(one)) {
    base_ac = one;
  } else if (mappingp(one)) {
    if (two) {
      base_ac = two;
      foreach(str: one)
        ac_mod[str] = base_ac - one[str];
    } else {
      ac_mod = copy(one);
    }
  } else if (stringp(one) && two) {
    ac_mod[one] = two - base_ac;
  }
}

/****************************** Other *******************************/

create() {
   ::create();
   ac_mod = ([]);
   base_ac = 0;
/* OBJEDIT { */
   set_gettable( 1 );
   set_droppable( 1 );
   set_holdable( 1 );
   set_type( "shield" );
/* } OBJEDIT */
}

/// \return True, indicating that this object is armour.
int query_armour() { return 1; }

/// \return True, indicating that this object is a shield.
int query_shield() { return 1; }
