// Adversary's unarmed weapon

inherit CLASS_EVENT_INFO;

private nosave int weapon_speed = 1;
private nosave int stun_bonus = 0;
private nosave int slow_bonus = 0;
private nosave int tear_bonus = 0;
private nosave string skill_used = "unarmed";
private nosave string death_message = "";
private nosave mapping def_combat_messages = ([]);
private nosave mapping combat_messages = ([]);
private nosave mapping damage_types = ([ ]);
private nosave mapping damage_bonuses = ([ ]);

int query_primary_level();
int query_agi();
int query_str();
int query_skill(string skill);

int can_swing()
{
   return 1;
}

mixed adjust_my_result(mixed result)
{
   return result;
}

varargs int query_to_hit_base(object target)
{
   // Unarmed to-hit penalty or bonus

   if (target)
   {
      return (query_agi() * 100 / target->query_agi()) - 100;
   }

   return 0;
}

//:FUNCTION set_damage_type
// Set a damage type for the weapon
void set_damage_type(string type, int amount)
{
   damage_types[type] = amount;
}

mapping query_damage_types()
{
   if (sizeof(damage_types))
   {
      mapping types = ([ ]);

      foreach (string type in keys(damage_types) + keys(damage_bonuses))
      {
         if ((damage_types[type] + damage_bonuses[type]) > 0)
         {
            types[type] = damage_types[type] + damage_bonuses[type];
         }
      }

      return types;
   }
   else
   {
      int level = query_primary_level();
      int strength = query_str();
      int rank = query_skill("unarmed") / 100;
      int unarmed_damage = level * strength * rank / 1000;

      if (unarmed_damage < ((level / 5) + (strength / 5) + rank)) { unarmed_damage = (level / 5) + (strength / 5) + rank; }

      return ([ "striking" : unarmed_damage + damage_bonuses["striking"] ]) + filter(damage_bonuses, (: $1 != "striking" :));
   }

   return ([ "striking" : 1 ]);
}

//:FUNCTION set_death_message
// Set the targetted_action for the death message when something is killed with this weapon
void set_death_message(string message)
{
   if (strlen(message))
   {
      death_message = message;
   }
}

//:FUNCTION query_death_message
// Returns the targetted_action for the death message when something is killed with this weapon
string query_death_message()
{
   if (strlen(death_message))
   {
      return death_message;
   }

   return "$N was killed by $N1 with $p1 bare hands at $o1.";
}

//:FUNCTION set_combat_messages
// Set the set of combat messages which are used by default
void set_combat_messages(string type)
{
   if (!(def_combat_messages = MESSAGES_D->get_messages(type)))
   {
      error("No messages of that type.\n");
   }
}

//:FUNCTION query_combat_message
// Returns the combat message for a given type
mixed query_combat_message(string type)
{
   return combat_messages[type] || def_combat_messages[type];
}

mixed query_combat_messages()
{
   if (sizeof(combat_messages))
   {
      return combat_messages;
   }

   if (sizeof(def_combat_messages))
   {
      return def_combat_messages;
   }

   return MESSAGES_D->get_messages("combat-unarmed");
}

private mixed merge_lists(mixed list, mixed item, mixed def)
{
   if (arrayp(list)) { return list + ({ item }); }
   else if (list) { return ({ list, item }); }
   else if (def) { return merge_lists(def, item, 0); }
   else { return item; }
}

void add_combat_message(string type, string msg)
{
   combat_messages[type] = merge_lists(combat_messages[type], msg, def_combat_messages[type]);
}

int is_weapon()
{
   return 1;
}

//:FUNCTION query_backstab_message
// Returns the targetted_action displayed on a successful backstab with this weapon
string query_backstab_message()
{
   return "$N $vdeliver a surprising blow to the back of $p1 neck!";
}

//:FUNCTION query_durability
// Query the current durability of an object.  Higher is better.
int query_durability()
{
   return 100;
}

//:FUNCTION query_max_durability
// Query the current max durability of an object.  Higher is better.
int query_max_durability()
{
   return 100;
}

//:FUNCTION query_chance_to_be_damaged
// Query the probability for this to be damaged
int query_chance_to_be_damaged()
{
   return 0;
}

//:FUNCTION set_damage_bonus
// Set an overall modifier of weapon class on the object.  The bonus
// does not get saved, so should only be used for temporary bonuses. (i.e. buffs)
void set_damage_bonus(string type, int bonus)
{
   damage_bonuses[type] = bonus;
}

void add_damage_bonus(string type, int value)
{
   damage_bonuses[type] += value;
}

mapping query_damage_bonuses()
{
   return damage_bonuses;
}

void add_stun_bonus(int x)
{
   stun_bonus += x;
}

int query_stun_bonus()
{
   return stun_bonus;
}

void add_slow_bonus(int x)
{
   slow_bonus += x;
}

int query_slow_bonus()
{
   return slow_bonus;
}

void add_tear_bonus(int x)
{
   tear_bonus += x;
}

int query_tear_bonus()
{
   return tear_bonus;
}

int query_weapon_class()
{
   mapping damage_types = query_damage_types();

   if (sizeof(damage_types))
   {
      int total = 0;

      foreach (string type in keys(damage_types))
      {
         total += damage_types[type];
      }

      return total;
   }

   return 0;
}

void set_weapon_speed(int x)
{
   weapon_speed = x;
}

int query_weapon_speed()
{
   return weapon_speed;
}

void set_skill_used(string new_skill_used)
{
   skill_used = new_skill_used;
}

string query_skill_used()
{
   return skill_used;
}

class event_info source_modify_event(class event_info evt)
{
   return evt;
}