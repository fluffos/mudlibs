// 04-XX-1998: Iizuka updated to conform to the new adversary code.
// 05-XX-1998: Iizuka added support for multiple resistances.
#include <hooks.h>

inherit CLASS_EVENT_INFO;

int test_flag(int);

private mapping resistances = ([ ]);
private mapping resistance_bonuses = ([ ]);
private mapping weaknesses = ([ ]);
private mapping weakness_bonuses = ([ ]);
private int armor_class = 1;
private int armor_bonus = 0;

void mudlib_setup()
{
   this_object()->add_save( ({ "armor_class", "armor_bonus", "resistances", "resistance_bonuses", "weaknesses", "weakness_bonuses" }) );
}

//:FUNCTION set_armor_class
// Set the protection of the particular damage sink, preventing random(class) points of damage
void set_armor_class(int x)
{
   if (x > 0)
   {
      armor_class = x;
      this_object()->set_durability(armor_class);
   }
}

//:FUNCTION query_armor_class
// Query the current armor class of an object.  Higher is better.
int query_armor_class()
{
   int durability = this_object()->query_durability();
   int max_durability = this_object()->query_max_durability();

   if (armor_class >= max_durability)
   {
      return armor_class * durability / max_durability;
   }

   return to_int(ceil(armor_class * 1.0 * durability / max_durability));
}

//:FUNCTION query_max_armor_class
// Query the maximum armor class of an object.  Higher is better.
int query_max_armor_class()
{
   return armor_class;
}

//:FUNCTION add_armor_bonus
// Adds an overall modifier of armor class on the object.
void add_armor_bonus(int amount)
{
   armor_bonus += amount;
}

void reset_armor_bonus()
{
   armor_bonus = 0;
}

int query_armor_bonus()
{
   return armor_bonus;
}

class event_info sink_modify_event(class event_info evt)
{
   object wearer = evt->target;
   int damage_before_sink = event_damage(evt);
   int durability = this_object()->query_durability();
   int max_durability = this_object()->query_max_durability();
   int combined_armor_class = armor_class + armor_bonus;
   int total_armor_class = wearer->query_armor_class() + wearer->query_armor_bonus();
   mapping total_resistances = wearer->query_resistances();
   mapping total_weaknesses = wearer->query_weaknesses();

   if (!mapp(evt->data) || evt->weapon->id("force_reflect")) { return evt; }

   if (this_object()->is_jedi_armor() && wearer->query_guild_level("jedi") && wearer->has_learned_skill("jedi defense"))
   {
      int jedi_alignment = wearer->query_jedi_alignment();

      total_armor_class += wearer->query_jedi_armor_class();

      wearer->test_skill("jedi defense", jedi_alignment * (jedi_alignment < 0 ? -10 : 20));
   }

   if (combined_armor_class >= max_durability)
   {
      combined_armor_class = armor_class * durability / max_durability;
   }
   else
   {
      combined_armor_class = to_int(ceil(combined_armor_class * 1.0 * durability / max_durability));
   }

   if (combined_armor_class > total_armor_class)
   {
      total_armor_class = combined_armor_class;
   }

   foreach (string type in keys(resistances) + keys(resistance_bonuses) + keys(total_resistances))
   {
      total_resistances[type] = total_resistances[type] + resistances[type] + resistance_bonuses[type];
   }

   foreach (string type in keys(weaknesses) + keys(weakness_bonuses) + keys(total_weaknesses))
   {
      total_weaknesses[type] = total_weaknesses[type] + weaknesses[type] + weakness_bonuses[type];
   }

   foreach (string type in keys(evt->data))
   {
      int effective_armor_class = total_armor_class;

      if (effective_armor_class > evt->data[type])
      {
         effective_armor_class = evt->data[type];
      }

      effective_armor_class -= total_weaknesses[type] * durability / max_durability;
      effective_armor_class += total_resistances[type] * max_durability / durability;

      if (effective_armor_class > evt->data[type])
      {
         effective_armor_class = evt->data[type];
      }
      else if (effective_armor_class < 0)
      {
         effective_armor_class = 0;
      }

      if (total_resistances["%" + type])
      {
         evt->data[type] -= (evt->data[type] * total_resistances["%" + type] * durability / max_durability / 100);
      }

      if (total_weaknesses["%" + type])
      {
         evt->data[type] += (evt->data[type] * total_weaknesses["%" + type] * max_durability / durability / 100);
      }

      evt->data[type] -= random(effective_armor_class + 1);
   }

   if (this_object()->query_chance_to_be_damaged())
   {
      int damage_chance = this_object()->query_chance_to_be_damaged();

      if (((damage_before_sink - event_damage(evt)) / 2) > damage_chance)
      {
         damage_chance = (damage_before_sink - event_damage(evt)) / 2;
      }

      // X in 100 chance of the armor getting damaged
      if ((damage_chance > random(100)) || this_object()->is_damaged_by_acid())
      {
         this_object()->decrease_durability(1);
      }

      if ((evt->data["acid"] && !this_object()->test_flag(F_ACID_EXPOSURE))
         || this_object()->test_flag(F_ACID_EXPOSURE))
      {
         this_object()->do_acid_exposure();
      }
   }
/*
//   if (wizardp(owner(this_object())) && (damage_before_sink > 0) && (damage_before_sink > event_damage(evt)))
   if (damage_before_sink > evt->data[1])
   {
      tell(wearer, "(Your " + this_object()->short() + " adjusted damage from " + damage_before_sink + " to " + event_damage(evt) + ")\n");
   }
*/
   return evt;
}

//:FUNCTION set_resist
// Specifies that for damage of type 'type', the armor class should be increased by 'amt'
void set_resist(string type, int amt)
{
   resistances[type] = amt;

   if (resistances[type] < 1)
   {
      map_delete(resistances, type);
   }
}

//:FUNCTION set_resistances
// Set all the resistances an armor possesses.
void set_resistances(mapping x)
{
   foreach (string type, int amount in x)
   {
      set_resist(type, amount);
   }
}

//:FUNCTION add_resistance_bonus
// Allows for setting temporary resistances
void add_resistance_bonus(string type, int amt)
{
   resistance_bonuses[type] += amt;

   if (resistance_bonuses[type] < 1)
   {
      map_delete(resistance_bonuses, type);
   }
}

void reset_resistance_bonuses()
{
   resistance_bonuses = ([ ]);
}

//:FUNCTION query_resistances
// Returns all the resistances an armor possesses.
mapping query_resistances()
{
   mapping resistances = ([ ]);

   foreach (string type in keys(resistances) + keys(resistance_bonuses))
   {
      resistances[type] = resistances[type] + resistance_bonuses[type];
   }

   return resistances;
}

//:FUNCTION set_weakness
// Specifies that for damage of type 'type', the armor class should be decreased by 'amt'
void set_weakness(string type, int amt)
{
   weaknesses[type] = amt;

   if (weaknesses[type] < 1)
   {
      map_delete(weaknesses, type);
   }
}

void set_weaknesses(mapping weak)
{
   foreach (string type, int amount in weak)
   {
      set_weakness(type, amount);
   }
}

//:FUNCTION add_weakness_bonus
// Allows for setting temporary weaknesses
void add_weakness_bonus(string type, int amt)
{
   weakness_bonuses[type] += amt;

   if (weakness_bonuses[type] < 1)
   {
      map_delete(weakness_bonuses, type);
   }
}

void reset_weakness_bonuses()
{
   weakness_bonuses = ([ ]);
}

//:FUNCTION query_weaknesses
// Returns all the weaknesses an armor possesses.
mapping query_weaknesses()
{
   mapping weaknesses = ([ ]);

   foreach (string type in keys(weaknesses) + keys(weakness_bonuses))
   {
      weaknesses[type] = weaknesses[type] + weakness_bonuses[type];
   }

   return weaknesses;
}

//:FUNCTION is_armor
// Returns 1 if the object is a damage_sink.
int is_armor()
{
   return 1;
}

void do_adjust_armor(int amount)
{
   if (test_flag(F_ADJUSTED) || (amount < 1))
   {
      return;
   }

   armor_class += ceil(armor_class * amount / 20.0);
}