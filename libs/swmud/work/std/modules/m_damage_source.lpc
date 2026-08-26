/* The concept is a bit abstract, so the name isn't entirely correct.  This
 * is an abstraction of the concept of something that one attacks with;
 * either a weapon or one's self.  It controls the combat messages, and
 * modifies the result based on the target, etc.
 *
 * This means that when you fight with a weapon, the _weapon_ is really
 * attacking, not you.  Some of the names in this are a bit backwards compat, though.
 *
 * April, 1998: Iizuka made significant changes and updated for adversary. */

inherit CLASS_EVENT_INFO;

int test_flag(int);
void clear_flag(int);
void assign_flag(int, int);

private int weapon_speed = 1;
private int to_hit_base = 0;
private int to_hit_bonus = 0;
private int stun_base = 0;
private int stun_bonus = 0;
private int slow_base = 0;
private int slow_bonus = 0;
private int tear_base = 0;
private int tear_bonus = 0;
private int critical_chance_base = 0;
private int critical_chance_bonus = 0;
private int critical_multiplier_base = 0;
private int critical_multiplier_bonus = 0;
private nosave string skill_used = "";
private mapping damage_types = ([ ]);
private mapping damage_bonuses = ([ ]);
private nosave string backstab_message = "";
private nosave string death_message = "";
private nosave mapping def_combat_messages = ([]);
private mapping combat_messages = ([]);

void mudlib_setup()
{
   this_object()->add_save( ({ "damage_types", "damage_bonuses", "critical_chance_base", "critical_chance_bonus", "critical_multiplier_base", "critical_multiplier_bonus", "weapon_speed", "to_hit_base", "to_hit_bonus", "stun_base", "stun_bonus", "slow_base", "slow_bonus", "tear_base", "tear_bonus" }) );
}

int can_swing()
{
   return 1;
}

mixed adjust_my_result(mixed result)
{
   return result;
}

void set_to_hit_base(int x)
{
   to_hit_base = x;
}

int query_to_hit_base(object target)
{
   return to_hit_base;
}

void set_to_hit_bonus(int x)
{
   to_hit_bonus = x;
}

void add_to_hit_bonus(int x)
{
   to_hit_bonus += x;
}

int query_to_hit_bonus()
{
   return to_hit_bonus;
}

void reset_to_hit_bonus()
{
   to_hit_bonus = 0;
}

void set_stun_base(int x)
{
   stun_base = x;
}

int query_stun_base()
{
   return stun_base;
}

void add_stun_bonus(int x)
{
   stun_bonus += x;
}

int query_stun_bonus()
{
   return stun_bonus;
}

void reset_stun_bonus()
{
   stun_bonus = 0;
}

void set_slow_base(int x)
{
   slow_base = x;
}

int query_slow_base()
{
   return slow_base;
}

void add_slow_bonus(int x)
{
   slow_bonus += x;
}

int query_slow_bonus()
{
   return slow_bonus;
}

void reset_slow_bonus()
{
   slow_bonus = 0;
}

void set_tear_base(int x)
{
   tear_base = x;
}

int query_tear_base()
{
   return tear_base;
}

void add_tear_bonus(int x)
{
   tear_bonus += x;
}

int query_tear_bonus()
{
   return tear_bonus;
}

void reset_tear_bonus()
{
   tear_bonus = 0;
}

void set_critical_chance_base(int x)
{
   critical_chance_base = x;
}

int query_critical_chance_base()
{
   return critical_chance_base;
}

void add_critical_chance_bonus(int x)
{
   critical_chance_bonus += x;
}

int query_critical_chance_bonus()
{
   return critical_chance_bonus;
}

void reset_critical_chance_bonus()
{
   critical_chance_bonus = 0;
}

void set_critical_multiplier_base(int x)
{
   critical_multiplier_base = x;
}

int query_critical_multiplier_base()
{
   return critical_multiplier_base;
}

void add_critical_multiplier_bonus(int x)
{
   critical_multiplier_bonus += x;
}

int query_critical_multiplier_bonus()
{
   return critical_multiplier_bonus;
}

void reset_critical_multiplier_bonus()
{
   critical_multiplier_bonus = 0;
}

int is_weapon()
{
   return 1;
}

//:FUNCTION set_backstab_message
// Set the targetted_action displayed on a successful backstab with this weapon
void set_backstab_message(string message)
{
   if (strlen(message))
   {
      backstab_message = message;
   }
}

//:FUNCTION query_backstab_message
// Returns the targetted_action displayed on a successful backstab with this weapon
string query_backstab_message()
{
   if (strlen(backstab_message))
   {
      return backstab_message;
   }

   switch (skill_used)
   {
      case "unarmed": return "$N $vdeliver a surprising blow to the back of $p1 neck!";
      case "slash 1h":
      case "slash 2h": return "$N $vbury $p $o into $p1 back!";
      case "strike 1h":
      case "strike 2h": return "$N viciously $vclub $t in the back of the head with $p $o!";
   }

   return "$N $vbackstab $t with $p $o2!";
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

   return "$N was killed by $N1 with $p1 $o at $o1.";
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

   return MESSAGES_D->get_messages("combat-blunt");
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

//:FUNCTION set_damage_type
// Set a damage type for the weapon
void set_damage_type(string type, int amount)
{
   damage_types[type] = amount;
}

//:FUNCTION set_damage_types
// Set damage types for the weapon
void set_damage_types(mapping types)
{
   damage_types = types;
}

mapping query_damage_types()
{
   if (sizeof(damage_types))
   {
      mapping types = ([ ]);
      int durability = this_object()->query_durability();
      int max_durability = this_object()->query_max_durability();
      int damage_class;

      foreach (string type in keys(damage_types) + keys(damage_bonuses))
      {
         damage_class = damage_types[type] + damage_bonuses[type];

         if (damage_class >= max_durability)
         {
            damage_class = damage_class * durability / max_durability;
         }
         else
         {
            damage_class = to_int(ceil(damage_class * 1.0 * durability / max_durability));
         }

         if (damage_class > 0)
         {
            types[type] = damage_class;
         }
      }

      return types;
   }

   return ([ "striking" : 1 ]);
}

mapping query_damage_types_pure()
{
   return damage_types;
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

void reset_damage_bonuses()
{
   damage_bonuses = ([ ]);
}

mapping query_damage_bonuses()
{
   return damage_bonuses;
}

int query_weapon_class()
{
   mapping types = query_damage_types();

   if (sizeof(types))
   {
      return array_sum(values(types));
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

string query_skill_used()
{
   return skill_used;
}

void set_skill_used(string new_skill_used)
{
   skill_used = new_skill_used;
}

void do_adjust_weapon(int amount)
{
   if (test_flag(F_ADJUSTED) || (amount < 1))
   {
      return;
   }

   foreach (string type in keys(damage_types))
   {
      damage_types[type] += ceil(damage_types[type] * amount / 30.0);
   }
}

class event_info source_modify_event(class event_info evt)
{
   return evt;
}