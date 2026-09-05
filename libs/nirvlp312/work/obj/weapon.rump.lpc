inherit "/inherit/base/base_obj";

#include "/include/fn_specs/weapon.spc"
#include "/include/sarlf.h"

#define ALT "external"  /* alternative object to wield this */
#define MAX_WEAPON_STR (250 + class_of_weapon*100) /* max dmg over lifetime */
#define DEFAULT_LENGTH 35  /* length of weapons if not set */
#define NPC this_player()->query_npc()

status wielded;        /* 1 == weapon is wielded */
status wielded_right;  /* 1 == weapon in right hand */
status wielded_left;   /* 1 == weapon in left hand */
object wielded_by;     /* wielder */

string weapon_type;    /* damaging type of the weapon */
string *attack_msg;    /* customized attack messages for weapon */
int class_of_weapon;   /* weapon class of the weapon */
int length;            /* length of weapon in inches */
object hit_func;       /* object containing a hit function */

int weapon_strength;   /* lifetime of dmg left for weapon */
int repair;            /* how many times we can repair this item */

/***************************************************************************/

void reset(status arg) {
  if (arg) return;

  /* default values */

  set_name("longsword");
  set_type("slash");
  set_short("Longsword");
  set_long("A rusty longsword");
  set_wc(9);
  set_weight(5);
  set_value(350);
  set_length(30);  /* 30" blade length */
}

status get() { return 1; }

void init() {
  ::init();
  if (!weapon_strength) weapon_strength = MAX_WEAPON_STR;
  if (!length) length = DEFAULT_LENGTH;
  if (environment() != this_player()) return;
  add_action("wield", "wield");
}

string short(status wiz) {
  object ob;

  if (environment() != wielded_by) { /* failsafe */
    if (wielded_by) wielded_by->recalc_wc(); /* since not inv. of wielded_by */
    dewield();
  }
  if (wielded_left) {
    if (!wielded_by->query_right_weapon())
      set_right_wielded(wielded_by);
    else
      return ::short(wiz) + " (wielded in left hand)";
  }
  if (wielded_right) {
    return ::short(wiz) + " (wielded in right hand)";
  }
  return ::short(wiz);
}

status drop(status silently) {
  object left, ob;
  string str;

  if (wielded) {
    if (wielded_right) {
      str = "You drop your right weapon";
      if (wielded_by) {
        if ((left = (object)wielded_by->query_left_weapon())) {
          left->set_right_wielded(wielded_by);
          str += " and wield your left weapon in your right hand";
        }
      }
    }
    else {
      str = "You drop your left weapon";
    }
    ob = wielded_by;
    dewield();
    if (ob) ob->recalc_wc();
    if (!silently) tell_object(ob, str + ".\n");
  }
  return 0;
}


/***************************************************************************/
/*  query */

string query_attacker() {
  return (string)this_player()->query_attack()->query_cap_name();
}

status query_wielded(string weapon_side) {
  if (weapon_side == "left") return wielded_left;
  if (weapon_side == "right") return wielded_right;
  return wielded;
}

status query_sell_destruct() {
  if (query_wc() > 15 || query_enchanted() || query_modified()) return 1;
  return ::query_sell_destruct();
}

int weapon_class()      { return class_of_weapon; }
int query_wc()          { return class_of_weapon; }
int query_repair()      { return repair;          }

object query_hit_func() { return hit_func;        }

string query_type()     { return weapon_type;     }
string weapon_type()    { return weapon_type;     }

int query_length()      { return length;          }

string query_object_type() { return "Weapon"; }

string *query_attack_msg() { return attack_msg; }


/***************************************************************************/
/*  set */

int set_wc(int wc) { return class_of_weapon = wc; }

void set_hit_func(object ob) {
  hit_func = ob;
  set_enchanted(1);
}

void set_right_wielded(object ob) { /* change a left to right wielded */
  wielded = 1;
  wielded_right = 1;
  wielded_left = 0;
  wielded_by = ob;
}

string set_type(string t) { return weapon_type = t; }

/*** size scale: 1 = 1", 2 = 2", etc... ***/

int set_length(int l) { return length = l; }

string *set_attack_msg(string *msg) {
  sizeof(msg);
  return attack_msg = msg;
}


/***************************************************************************/
/*  misc */

/* drop(), un_wield() of right, causes left to be wielded right
 * sometimes we don't want that (see wield)
 */

void dewield() {
  wielded = 0;
  wielded_right = 0;
  wielded_left = 0;
  wielded_by = 0;
}

void un_wield() {
  this_object()->drop(1);
}

int hit(object attacker) {
  if (hit_func) return (int)hit_func->weapon_hit(attacker);
  return 0;
}


status check_class_no_allow() {
  object env;
  string *weapons;

  env = environment(this_object());

  if (env->query_class("fighter")) return 0;  /* fighters can use anything */

  weapons = ({});
  if (env->query_class("mage"))
    weapons += ({ "sstaff", "rod", "dagger", "dirk", "knife", "dart", "sling"});

  if (env->query_class("cleric"))
    weapons += ({ "club", "flail", "hammer", "war hammer", "mace", "staff",
                  "lasso", "sap", "sling" });

  if (env->query_class("thief"))
    weapons += ({ "club", "dagger", "dart", "dirk", "knife", "garrot", "sap",
                  "sling", "broadsword", "longsword", "shortsword", "falchion",
                  "rapier", "cutlass", "sabre", "tulwar", "scimitar" });

  if (member_array(query_name(), weapons) > -1) return 0;
  if (env->query_class("mage")) {
    if (env->query_level() > 15)
      tell_object(env, "A mage of your standing would never be seen dead " +
                       "wielding such a weapon!\n");
    else
      tell_object(env, "A student mage, such as yourself, would never know " +
                       "\nwhere to hold such a primitive weapon!\n");
  }
  else if (env->query_class("thief")) {
    tell_object(env, "Such a weapon would surely interfere with your " +
                     "skills of stealth!\n");
  }
  else {
    tell_object(env, "As a cleric your God would never approve of the use " +
                     "of such a weapon.\n");
  }
  return 1;
}


void load_weapon(mixed *str) {
  int i;
  mixed t;

  for (i = 0; i < sizeof(str); i += 2) {
    t = str[i+1];
    switch(str[i]) {
      case "weight"       : set_weight(t);        break;
      case "altname"      : set_alt_name(t);      break;
      case "length"       : set_length(t);        break;
      case "hitfun"       : hit_func = t;         break;
      case "alias"        : set_alias(t);         break;
      case "short"        : set_short(t);         break;
      case "long"         : set_long(t);          break;
      case "read"         : set_read(t);          break;
      case "type"         : set_type(t);          break;
      case "id"           : set_id(t);            break;
      case "info"         : set_info(t);          break;
      case "name"         : set_name(t);          break;
      case "value"        : set_value(t);         break;
      case "wc"           : set_wc(t);            break;
      case "class"        : set_class(t);         break;
      case "quest_item"   : set_quest_item(t);    break;
      case "modified"     : set_modified(t);      break;
      case "enchanted"    : set_enchanted(t);     break;
      case "sell_destruct": set_sell_destruct(t); break;
    }
  }
  return;
}


/***************************************************************************/
/*  actions */

status wield(string wielding) {
  object ob, env, alt, old_weapon, opp_weapon;
  string str;
  int tmp_left, i, total;

  env = environment();
  if (!wielding) {
    write("Usage: wield <item>\n" +
          "       wield <item> in right hand\n");
    if (this_player()->query_class("fighter")) {
      write("       wield <item> in left hand\n");
    }
    return 1;
  }

  if (sscanf(wielding, "%s in left hand", str)) {
    if (!this_player()->query_two_weapon()) {
      notify_fail("You don't have the fighting skill to do that.\n");
      return 0;
    }
    if (this_player()->query_right_weapon()) {
      tmp_left = 1;
    }
    else {
      write("You decide to wield it in your right hand.\n");
    }
  }
  else if (!sscanf(wielding, "%s in right hand", str)) {
    str = wielding;
  }
  if (!(ob = present(lower_case(str), this_player()))) {
    notify_fail("You don't have a " + str + " to wield.\n");
    return 0;
  }
  if (ob != this_object()) {
    notify_fail("You can't do that!\n");
    return 0;
  }
  if (wielded) {
    if ((wielded_left && !tmp_left) || (wielded_right && tmp_left)) {
      drop(1);
    }
    else {
      tell_object(env, "You already wield it!\n");
      return 1;
    }
  }
  for (i = 1; (alt = present(ALT + " " + i, this_player())); i++) {
    if (alt->wield_func(ob, tmp_left)) return 1;
  }
  if (!NPC && query_wc() > 15 && (int)env->query_strength() < 10) {
    tell_object(env, "You lack the strength to use that weapon effectively.\n");
    return 1;
  }
  if (!NPC && check_class_no_allow()) return 1;
  if (env->query_armour_type("shield") && tmp_left) {
    tell_object(env, "You cannot wield a left weapon when using a shield.\n");
    return 1;
  }
  if (tmp_left) {
    old_weapon = (object)env->query_left_weapon();
    opp_weapon = (object)env->query_right_weapon();
    total = ((opp_weapon) ? (int)opp_weapon->query_length() : 0) + length;
    if (total/6 > (int)env->query_two_weapon() + 2) {
      tell_object(env, "The weapons are too long.\n" +
                  "You do not have the skill to wield these two weapons.\n");
      return 1;
    }
  }
  else {
    old_weapon = (object)env->query_right_weapon();
  }
  if (old_weapon) old_weapon->dewield();

  /* wield this */

  wielded_by = env;
  wielded = 1;
  wielded_left = tmp_left;
  wielded_right = !wielded_left;
  wielded_by->recalc_wc();
  if (tmp_left) {
    write("You wield the " + query_name() + " in your left hand.\n");
  }
  else {
    write("You wield the " + query_name() + " in your right hand.\n");
  }
  return 1;
}


/***************************************************************************/
/*  weapon deteriation */

void long(status wiz) {
  string str;

  ::long(wiz);
  str = "";
  if (wiz) str += "Weapon Strength: " + weapon_strength + "/" +
                  MAX_WEAPON_STR + ".\n";
  str += "The " + query_name() + " is ";
  str += (weapon_strength > MAX_WEAPON_STR/2)
      ? "in superb condition.\n"
      : (weapon_strength > MAX_WEAPON_STR/3)
      ? "in fine condition.\n"
      : (weapon_strength > MAX_WEAPON_STR/4)
      ? "in average condition.\n"
      : (weapon_strength > MAX_WEAPON_STR/5)
      ? "showing wear and tear.\n"
      : (weapon_strength > MAX_WEAPON_STR/6)
      ? "very old and worn.\n"
      : "lucky to be here at all!\n";
  write(str);
}

void hit_weapon(int dam) {
  weapon_strength -= dam;
  if (weapon_strength < 0) {
    tell_object(environment(), "Your " + ((wielded_left) ? "left" : "right") +
                               " weapon breaks!!\n");
    say((string)environment()->query_name() + " breaks " +
        (string)environment()->query_possessive() + " " +
        ((wielded_left) ? "left" : "right") + " weapon!!\n");
    drop(1);
    if (!this_object()) return;  /* quick hack, don't remove this */
    environment()->recalc_wc();
    destruct(this_object());
  }
}

int query_max_strength()       { return MAX_WEAPON_STR;   }
int query_weapon_strength()    { return weapon_strength;  }
int query_current_strength()   { return weapon_strength;  }

int set_weapon_strength(int i) { return weapon_strength = i; }

int repair_weapon(int i) {
  if (repair > 3) return 0;
  weapon_strength += i;
  if (weapon_strength > (query_max_strength()))
    weapon_strength = query_max_strength();
  repair++;
  return weapon_strength;
}

