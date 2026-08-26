// Adversary's natural armor
#include <hooks.h>

inherit CLASS_EVENT_INFO;

mixed call_hooks(string, int);
int query_jedi_armor_class();

private nosave int armor_bonus;
private nosave mapping body_resistances = ([ ]);
private nosave mapping body_resistance_bonuses = ([ ]);
private nosave mapping body_weaknesses = ([ ]);
private nosave mapping body_weakness_bonuses = ([ ]);

//:FUNCTION query_armor_class
// Query the current armor class of an object.  Higher is better.
int query_armor_class()
{
   object this_ob = this_object();

   return to_int(floor(this_ob->query_primary_level() * this_ob->query_con_pure() / 250.0));
}

//:FUNCTION query_max_armor_class
// Query the maximum armor class of an object.  Higher is better.
int query_max_armor_class()
{
   return query_armor_class();
}

//:FUNCTION query_jedi_armor_class
// Query a Jedi's armor class, based on jedi defense
int query_jedi_armor_class()
{
   object this_ob = this_object();

   if (this_ob->query_guild_level("jedi") && this_ob->has_learned_skill("jedi defense"))
   {
      int rank = this_ob->query_skill("jedi defense") / 100;
      int spec = this_ob->query_guild_specialization_rank("jedi", "defense");
      int alignment = this_ob->query_jedi_alignment();
      float armor = this_ob->query_for_pure() * this_ob->query_guild_level("jedi");

      if (spec <= 0) { spec = this_ob->query_guild_specialization_rank("jedi", "sense"); }

      if (alignment > 0)
      {
         armor = (armor / (500.0 - (rank * 25.0)) * rank / 10.0) + spec;

         return armor > 0 ? to_int(ceil(armor)) : 1;
      }

      armor = (armor / (750.0 - (rank * 25.0)) * rank / 10.0) + spec;

      return armor > 0 ? to_int(floor(armor)) : 0;
   }

   return 0;
}

//:FUNCTION query_durability
// Query the current durability of an object.  Higher is better.
int query_durability()
{
   return 100;
}

//:FUNCTION query_max_durability
// Query the current maximum durability of an object.  Higher is better.
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

//:FUNCTION set_armor_bonus
// Set an overall modifier of armor class on the object.  The bonus
// does not get saved, so should only be used for temporary bonuses. (i.e. buffs)
void set_armor_bonus(int bonus)
{
   armor_bonus = bonus;
}

void add_armor_bonus(int value)
{
   armor_bonus += value;
}

int query_armor_bonus()
{
   return armor_bonus;
}

class event_info sink_modify_event(class event_info evt)
{
   object this_ob = this_object();
   int damage_before_sink = event_damage(evt);
   int armor_class = query_armor_class() + armor_bonus;

   if (!mapp(evt->data) || evt->weapon->id("force_reflect")) { return evt; }

   if (this_ob->query_guild_level("jedi") && this_ob->has_learned_skill("jedi defense"))
   {
      int jedi_alignment = this_ob->query_jedi_alignment();

      armor_class += query_jedi_armor_class();

      this_ob->test_skill("jedi defense", jedi_alignment * (jedi_alignment < 0 ? -10 : 20));
   }

   foreach (string type in keys(evt->data))
   {
      int effective_armor_class = armor_class;

      if (effective_armor_class > evt->data[type])
      {
         effective_armor_class = evt->data[type];
      }

      effective_armor_class -= (body_weaknesses[type] + body_weakness_bonuses[type]);
      effective_armor_class += (body_resistances[type] + body_resistance_bonuses[type]);

      if (effective_armor_class > evt->data[type])
      {
         effective_armor_class = evt->data[type];
      }
      else if (effective_armor_class < 0)
      {
         effective_armor_class = 0;
      }

      evt->data[type] -= random(effective_armor_class + 1);
   }
/*
//   if (wizardp(this_ob) && && (damage_before_sink > evt->data[1]))
   if (damage_before_sink > event_damage(evt))
   {
      tell(this_ob, "(Your natural armor adjusted damage from " + damage_before_sink + " to " + event_damage(evt) + ")\n");
   }
*/
   return evt;
}

//:FUNCTION is_armor
// Returns 1 if the object is a damage_sink.
int is_armor()
{
   return 1;
}

//:FUNCTION set_resist
// Specifies that for damage of type 'type', the armor class should be increased by 'amt'
void set_resist(string type, int amt)
{
   body_resistances[type] = amt;

   if (body_resistances[type] < 1)
   {
      map_delete(body_resistances, type);
   }
}

//:FUNCTION set_resistances
// Set all the resistances an armor possesses.
void set_resistances(mapping x)
{
   foreach (string type in keys(x))
   {
      set_resist(type, x[type]);
   }
}

//:FUNCTION add_resistance_bonus
// Allows for setting temporary resistances
void add_resistance_bonus(string type, int amt)
{
   body_resistance_bonuses[type] += amt;

   if (body_resistance_bonuses[type] < 1)
   {
      map_delete(body_resistance_bonuses, type);
   }
}

//:FUNCTION query_resistances
// Returns all the resistances an armor possesses.
mapping query_resistances()
{
   mapping resistances = ([ ]);

   foreach (string type in keys(body_resistances) + keys(body_resistance_bonuses))
   {
      resistances[type] = body_resistances[type] + body_resistance_bonuses[type];
   }

   return resistances;
}

//:FUNCTION set_weakness
// Specifies that for damage of type 'type', the armor class should be decreased by 'amt'
void set_weakness(string type, int amt)
{
   body_weaknesses[type] = amt;

   if (body_weaknesses[type] < 1)
   {
      map_delete(body_weaknesses, type);
   }
}

//:FUNCTION set_weaknesses
// Set all the weaknesses an armor possesses.
void set_weaknesses(mapping weak)
{
   foreach (string type in keys(weak))
   {
      set_weakness(type, weak[type]);
   }
}

//:FUNCTION add_weakness_bonus
// Allows for setting temporary weaknesses
void add_weakness_bonus(string type, int amt)
{
   body_weakness_bonuses[type] += amt;

   if (body_weakness_bonuses[type] < 1)
   {
      map_delete(body_weakness_bonuses, type);
   }
}

//:FUNCTION query_weaknesses
// Returns all the weaknesses an armor possesses.
mapping query_weaknesses()
{
   mapping weaknesses = ([ ]);

   foreach (string type in keys(body_weaknesses) + keys(body_weakness_bonuses))
   {
      weaknesses[type] = body_weaknesses[type] + body_weakness_bonuses[type];
   }

   return weaknesses;
}