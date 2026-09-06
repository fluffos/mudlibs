#include <battle.h>
#include <inven.h>
#include <condition.h>
#include <object.h>
#include <apparel.h>
#include <item.h>

/** \todo Document this file
 */

int base_ac;      // general armour class (applies to all types)
mapping ac_mod;      // armour class. ex (["edged":3, "blunt":-5])
mapping requirements;   // requirements to wear armour
string armour_type;   // type of armour (body, helmet, shield, etc...)

/// Object editor information.
string armour_info() {
  return "base_ac\nac_mod\nrequirements\narmour_type";
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

string query_armour_type() { return armour_type; }

/** Similar functionality to query_ac, only deals with the requirements to
 * wear a armour (if any).
 */
varargs mixed query_requirement(string req)  {
  if (!mappingp(requirements))
    return 0;
  if (req)
    return requirements[req];
  else
    return requirements;
}

/** Returns the number of basic requirements the player does NOT meet in
 * order to wear this armour. Returns 0 if the player may wear
 * the armour. Returns -1 if player is not a valid object.
 * \param player The player for whom you are doing a stat check
 * against this armour.
 * \param silent (Optional) If true, no message will be printed
 * to the player if they cannot wear the armour. Otherwise,
 * The player is told the reason that they can't wear the armour.
 */
varargs int query_requirements_met(object player, int silent) {
  int fail = 0;
  string name, error = "";

  if( !player ) return -1;
  if( !player->query_is_living() ) return -1;
  if( !armour_type ) return -1;
  if( !requirements ) return 0;

  foreach (name: m_indices(requirements)) {
    switch (name) {

      // Level requirement. Since we are touting ourselves as "level-less"
      // I don't plan on ever using this. However, I am putting it here in
      // the event that someone does want to use it in the future.

      case "level":
        if (player->query_level() < requirements[name]) {
          error += "You are not old enough to wear this armour.";
          fail++;
        }
        break;

      // Requirements based on stats. Admittedly, having a charm, empathy,
      // or constitution requirement to wear a armour is... unusual, but
      // again, we add it in for the sake of completeness, ne?

      case "str":
      case "strength":
        if (player->query_strength() < requirements[name]) {
          error += "You are not strong enough to wear this armour.";
          fail++;
        }
        break;

      case "dex":
      case "dexterity":
        if (player->query_dexterity() < requirements[name]) {
          error += "You are not dexterous enough to wear this armour.";
          fail++;
        }
        break;

      case "con":
      case "constitution":
        if (player->query_constitution() < requirements[name]) {
          error += "You do not have the physical endurance to wear this armour.";
          fail++;
        }
        break;

      case "spd":
      case "speed":
        if (player->query_speed() < requirements[name]) {
          error += "You are not quick enough to wear this armour.";
          fail++;
        }
        break;

      case "wil":
      case "will":
        if (player->query_will() < requirements[name]) {
          error += "You do not have the mental strength to wear this armour.";
          fail++;
        }
        break;

      case "int":
      case "intelligence":
        if (player->query_intelligence() < requirements[name]) {
          error += "You are not intelligent enough to wear this armour.";
          fail++;
        }
        break;

      case "emp":
      case "empathy":
        if (player->query_empathy() < requirements[name]) {
          error += "You are not empathic enough to wear this armour.";
          fail++;
        }
        break;

      case "cha":
      case "charm":
      case "charisma":
        if (player->query_charm() < requirements[name]) {
          error += "You are not charming enough to wear this armour.";
          fail++;
        }
        break;

      // Name requirement. That's right, it's possible for a armour to be
      // attuned to a specific individual and refuse to allow others to
      // use it. Cool, huh?

      case "name":
        if (player->query_name() != requirements[name]) {
          error += "Only "+capitalize(requirements[name])+" may wear this "+armour_type+".";
          fail++;
        }
        break;

      // Armour skill requirement. This really could be handled by the
      // default case, but shrug, different messages are good, right?

      case "skill":
        if (player->query_skill("combat.armour."+armour_type) < requirements[name]) {
          error += "Your skill with ~plur"+armour_type+" is insufficient to wear this armour.";
          fail++;
        }
        break;

      // Default case. We assume that any other strings people might use
      // as requirements are going to be the names of skills, and that the
      // value they contain is an integer representing the minimum level
      // that the skill must be trained to
      default:
        if (!intp(requirements[name])) {
          debug("Requirement for "+(string)this_object()+" is malformed.");
          break;
        }
        if (player->query_skill(name) < requirements[name]) {
          error += "You are not skilled enough at "+name+" to wear this armour.";
          fail++;
        }
        break;
    }
  }

  if (fail && !silent) {
    msg(error);
  }

  return fail;
}

/******************************* Sets *******************************/

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

set_armour_type(string x) { armour_type = x; }

varargs void set_requirement(mixed one, mixed two) {
  if (!one)
    return;
  if (mappingp(one) && widthof(one) == 1)
    requirements = copy(one);
  else if (stringp(one) && two)
    requirements[one] = two;
}


/****************************** Other *******************************/

void create() {
   ::create();
   ac_mod = ([]);
   base_ac = 0;
/* OBJEDIT { */
   set_gettable( 1 );
   set_droppable( 1 );
   set_type( "armour" );
   set_max_condition( 1000 );
/* } OBJEDIT */
}

/// \return True, indicating that this object is armour.
int query_armour() {
   return 1;
}
