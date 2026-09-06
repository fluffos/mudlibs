/// \todo Document this file

mapping wc;            // weapon class. ex (["edged":3, "blunt":5])
mapping requirements;  // requirements to wield weapon
int hitbonus;          // bonus % to hit
int hands;          // number of hands required to wield the weapon

int material_aspect;	// what am I made out of? C_STEEL, C_COPPER, etc...

/// Object editor information.
string weapon_info() {
  return "weapon_type\nhitbonus\nwc\nrequirements\nhands";
}

/****************************** Queries ****************************/

// Prototype
varargs int unwield_weapon(int silent);

int query_hands() {
  if (!hands)
     hands = 1;
  return hands;
}

/** Return the weapon class of this object. If called with a string
 * parameter, then one particular wc is returned (ie, query_wc("fire")
 * returns the weapon's fire wc). If called without any parameters, the
 * object's entire wc mapping is returned.
 */
varargs mixed query_wc(string param) {
  if (param)
    return wc[param];
  return wc;
}

int query_hitbonus() { return hitbonus; }

string query_weapon_type() { QBODY( "weapon_type", this_object()->query_default_weapon_type() ); }

/** Similar functionality to query_wc, only deals with the requirements to
 * wield a weapon (if any).
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
 * order to wield this weapon. Returns 0 if the player may wield
 * the weapon. Returns -1 if player is not a valid object.
 * \param player The player for whom you are doing a stat check
 * against this weapon.
 * \param silent (Optional) If true, no message will be printed
 * to the player if they cannot wield the weapon. Otherwise,
 * The player is told the reason that they can't wield the weapon.
 */
varargs int query_requirements_met(object player, int silent) {
  int fail = 0;
  string name, error = "";

  if (!player) return -1;
  if (!player->query_is_living()) return -1;
  if (!query_weapon_type()) return -1;

  foreach (name: m_indices(requirements)) {
    switch (name) {

      // Level requirement. Since we are touting ourselves as "level-less"
      // I don't plan on ever using this. However, I am putting it here in
      // the event that someone does want to use it in the future.

      case "level":
        if (player->query_level() < requirements[name]) {
          error += "You are not old enough to wield this weapon.";
          fail++;
        }
        break;

      // Requirements based on stats. Admittedly, having a charm, empathy,
      // or constitution requirement to wield a weapon is... unusual, but
      // again, we add it in for the sake of completeness, ne?

      case "str":
      case "strength":
        if (player->query_strength() < requirements[name]) {
          error += "You are not strong enough to wield this weapon.";
          fail++;
        }
        break;

      case "dex":
      case "dexterity":
        if (player->query_dexterity() < requirements[name]) {
          error += "You are not dexterous enough to wield this weapon.";
          fail++;
        }
        break;

      case "con":
      case "constitution":
        if (player->query_constitution() < requirements[name]) {
          error += "You do not have the physical endurance to wield this weapon.";
          fail++;
        }
        break;

      case "spd":
      case "speed":
        if (player->query_speed() < requirements[name]) {
          error += "You are not quick enough to wield this weapon.";
          fail++;
        }
        break;

      case "wil":
      case "will":
        if (player->query_will() < requirements[name]) {
          error += "You do not have the mental strength to wield this weapon.";
          fail++;
        }
        break;

      case "int":
      case "intelligence":
        if (player->query_intelligence() < requirements[name]) {
          error += "You are not intelligent enough to wield this weapon.";
          fail++;
        }
        break;

      case "emp":
      case "empathy":
        if (player->query_empathy() < requirements[name]) {
          error += "You are not empathic enough to wield this weapon.";
          fail++;
        }
        break;

      case "cha":
      case "charm":
      case "charisma":
        if (player->query_charm() < requirements[name]) {
          error += "You are not charming enough to wield this weapon.";
          fail++;
        }
        break;

      // Name requirement. That's right, it's possible for a weapon to be
      // attuned to a specific individual and refuse to allow others to
      // use it. Cool, huh?

      case "name":
        if (player->query_name() != requirements[name]) {
          error += "Only "+capitalize(requirements[name])+" may wield this "+query_weapon_type()+".";
          fail++;
        }
        break;

      // Weapon skill requirement. This really could be handled by the
      // default case, but shrug, different messages are good, right?

      case "skill":
        if (player->query_skill(query_weapon_type()) < requirements[name]) {
          error += "Your skill with ~plur"+query_weapon_type()+" is insufficient to wield this weapon.";
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
          error += "You are not skilled enough at "+name+" to wield this weapon.";
          fail++;
        }
        break;
    }
  }

  if (!silent)
    msg(error);

  return fail;
}

/******************************* Sets *******************************/

void set_hands(int x) {
   if (hands > 0 && hands < 4)
      hands = x;
}

varargs void set_wc(mixed one, int two) {
  if (mappingp(one))
    wc = copy(one);
  if (!sizeof(wc))
    wc = ([]);
  if (stringp(one) && two)
    wc[one] = two;
}

void set_wielded(int x) {
   debug("set_wielded() is deprecated, use set_held()");
   this_object()->set_held(x);
}

void set_hitbonus(int x) { hitbonus = x; }

void set_weapon_type(string x) { SBODY( "weapon_type", x ); }

varargs void set_requirement(mixed one, mixed two) {
  if (!one)
    return;
  if (mappingp(one) && widthof(one) == 1)
    requirements = copy(one);
  else if (stringp(one) && two)
    requirements[one] = two;
}


/****************************** Other *******************************/

void _weapon_create() {
   wc = ([]);
}

/// \return True, indicating that this object is a weapon.
int query_weapon() { return 1; }

void apply_aspect(int aspect) {
   material_aspect = aspect;
   // at this point, weight and ac should already have been set, so we can
   // alter them happily ;)
   mapping new_wc = "/daemon/material"->apply_wc_mod(wc, aspect);
   if( mappingp(new_wc) )
      wc = new_wc;
   this_object()->set_weight( "/daemon/material"->apply_weight_mod(this_object()->query_weight(), aspect) );
}
int query_material_aspect() { return material_aspect; }
string query_material_string() {
	string buf = "/daemon/material"->query_aspect_string();
	if( buf )
		return buf;
	else
		return "*bugged*";
}
