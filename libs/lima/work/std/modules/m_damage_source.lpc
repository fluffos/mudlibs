/* Do not remove the headers from this file! see /USAGE for more info. */

/*
 * The concept is a bit abstract, so the name isn't entirely correct.  This
 * is an abstraction of the concept of something that one attacks with;
 * either a weapon or one's self.  It controls the combat messages, and
 * modifies the result based on the target, etc.
 *
 * This means that when you fight with a weapon, the _weapon_ is really
 * attacking, not you.  Some of the names in this are a bit backwards compat,
 * though.
 *
 * April, 1998: Iizuka made significant changes and updated for adversary.
 */

inherit CLASS_EVENT_INFO;

private
int weapon_class = 1;
private
int to_hit_bonus;
private
nosave int disarm_bonus;
private
nosave int damage_bonus;
private
nosave int anti_disarm;
private
string *damage_type = ({"bludgeon"});
private
nosave mapping def_combat_messages = ([]);
private
mapping combat_messages = ([]);
private
nosave int must_dual_wield = 0;
private
nosave int can_dual_wield = 0;

/* Restrictions */
private
nosave string restricted_skill = "combat";
private
nosave string restricted_message = "You do not feel skilled with this weapon.";
private
nosave int restriction_level = 0;
private
nosave int restriction_rank = 0;
private
nosave int restricted = 0;

/* Train limits */
private
nosave int train_limit;

int query_train_limit()
{
   return train_limit;
}
void set_train_limit(int l)
{
   train_limit = l;
}

int query_must_dual_wield()
{
   return must_dual_wield;
}
void set_must_dual_wield(int x)
{
   must_dual_wield = x;
   if (x)
      this_object()->add_property("2 hands");
   else
      this_object()->remove_property("2 hands");
}

int query_can_dual_wield()
{
   return can_dual_wield;
}
void set_can_dual_wield(int x)
{
   can_dual_wield = x;
   if (x)
      this_object()->add_property("versatile");
   else
      this_object()->remove_property("versatile");
}

mixed adjust_my_result(mixed result)
{
   return result;
}

string *query_damage_type()
{
   return damage_type;
}

//: FUNCTION query_to_hit_bonus
// Queries the direct bonus chance to hit adversaries.
int query_to_hit_bonus(object target)
{
   return to_hit_bonus;
}
int query_raw_hit_bonus()
{
   return to_hit_bonus;
}

//: FUNCTION set_to_hit_bonus
// Sets a direct bonus chance to hit adversaries.
void set_to_hit_bonus(int x)
{
   to_hit_bonus = x;
   if (x > 0)
      this_object()->add_property("precise");
   else
      this_object()->add_property("imprecise");
}

//: FUNCTION query_diarm_bonus
// Queries the direct bonus chance to disarm adversaries.
int query_disarm_bonus(object target)
{
   return disarm_bonus;
}
int query_raw_disarm_bonus()
{
   return disarm_bonus;
}

//: FUNCTION set_disarm_bonus
// Sets a direct bonus chance to disarm adversaries.
void set_disarm_bonus(int x)
{
   disarm_bonus = x;
   if (x > 0)
      this_object()->add_property("disarming");
   else
      this_object()->add_property("arming");
}

//: FUNCTION query_damage_bonus
// Queries the direct damage bonus on adversaries.
int query_damage_bonus(object target)
{
   return damage_bonus;
}
int query_raw_damage_bonus()
{
   return damage_bonus;
}

//: FUNCTION query_damage_bonus
// Queries the direct damage bonus on adversaries.
void set_damage_bonus(int x)
{
   damage_bonus = x;
   if (x > 0)
      this_object()->add_property("keen");
   else
      this_object()->add_property("dull");
}

//: FUNCTION query_anti_disarm_bonus
// Queries the direct bonus chance to AVOID disarm from adversaries.
int query_anti_disarm(object target)
{
   return anti_disarm;
}

int query_raw_anti_disarm()
{
   return anti_disarm;
}

//: FUNCTION query_anti_disarm_bonus
// Queries the direct bonus chance to AVOID disarm from adversaries.
void set_anti_disarm(int x)
{
   anti_disarm = x;
   if (x > 0)
      this_object()->add_property("good grip");
   else
      this_object()->add_property("bad grip");
}

void set_damage_type(string *str...)
{
   string *exclude = str - DAMAGE_D->query_damage_types();
   if (sizeof(exclude))
      error("Invalid damage type(s) : " + implode(exclude, ","));
   damage_type = str;
}

int is_weapon()
{
   return 1;
}

//: FUNCTION set_combat_messages
// Set the set of combat messages which are used by default
void set_combat_messages(string type)
{
   if (!(def_combat_messages = MESSAGES_D->query_messages(type)))
      error("No messages of that type '" + type + "'.\n");
}

//: FUNCTION set_combat_message
// Set a single combat message, removing the existing one(s)
void set_combat_message(string type, string msg)
{
   combat_messages[type] = msg;
}

mapping query_combat_messages()
{
   return combat_messages;
}

//: FUNCTION query_combat_message
// Returns the combat message for a given type
mixed query_combat_message(string type)
{
   return combat_messages[type] || def_combat_messages[type];
}

private
mixed merge_lists(mixed list, mixed item, mixed def)
{
   if (arrayp(list))
      return list + ({item});
   else if (list)
      return ({list, item});
   else if (def)
      return merge_lists(def, item, 0);
   else
      return item;
}

//: FUNCTION add_combat_message
// Adds another combat message to the damage source.
//
// add_combat_message("miss","$N $vmiss completely, $n seems drunk.");
void add_combat_message(string type, string msg)
{
   combat_messages[type] = merge_lists(combat_messages[type], msg, def_combat_messages[type]);
}

//: FUNCTION replace_combat_message
// Replace any other messages with this message
//
// replace_combat_message("miss","$N $vmiss completely, $n seems drunk.");
void replace_combat_message(string type, string msg)
{
   combat_messages[type] = ({msg});
}

void set_weapon_class(int x)
{
   weapon_class = CLAMP(x, 1, 100);
   train_limit = 1 + (weapon_class / 10);
   this_object()->set_max_durability(100 * x);
}

//Override in weapons if you want. Default is a 25% bonus
//if you dual wield a weapon. At least 1.
int query_weapon_class_bonus()
{
   if (this_object()->query_dual_wielded())
      return to_int(weapon_class*0.25) || 1;
}

int query_weapon_class()
{
   return weapon_class + query_weapon_class_bonus();
}

private
string skill_used = "combat/melee/unarmed";

string query_skill_used()
{
   // Can be removed once all .o files are fixed
   if (skill_used == "combat/unarmed")
      skill_used = "combat/melee/unarmed";
   return skill_used;
}

void set_restricted(int rest)
{
   restricted = rest;
}
void set_skill_used(string new_skill_used)
{
   skill_used = new_skill_used;
}
void set_skill_restriction_message(string new_restriction_msg)
{
   restricted_message = new_restriction_msg;
}

void set_skill_restriction(string new_restricted_skill, int rank)
{
   if (rank < 0)
      return;
   restricted_skill = new_restricted_skill;
   restriction_level = SKILL_D->ranks()[rank - 1];
   restriction_rank = rank;
}

string get_extra_long()
{
   string restricted_str = "";
   string durability_str;

   if (this_object()->query_wielded_by())
      restricted_str = restricted
                           ? "This weapon requires skill rank " +
                                 SKILL_D->skill_req_pretty(restricted_skill, restriction_rank) +
                                 " before it can be trained and used proficiently."
                           : "You meet the rank of " + SKILL_D->skill_req_pretty(restricted_skill, restriction_rank) +
                                 " so you can train and use this weapon.";
   else
      restricted_str =
          "This weapon requires skill rank " + SKILL_D->skill_req_pretty(restricted_skill, restriction_rank) + ".";

   durability_str = this_object()->has_durability() ? " " + this_object()->durability_extra_long() : "";

   if (this_object()->is_living())
      return "";
   return (restriction_level ? restricted_str : "") + durability_str;
}

// Set when wield has found that the weapon was restricted. You need to unwield and wield to clear this.
int query_restricted()
{
   return restricted;
}

string query_restriction_message()
{
   return restricted_message;
}

string query_restricted_skill()
{
   return restricted_skill;
}

int query_restriction_level()
{
   return restriction_level;
}

class event_info source_modify_event(class event_info evt)
{
   return evt;
}
