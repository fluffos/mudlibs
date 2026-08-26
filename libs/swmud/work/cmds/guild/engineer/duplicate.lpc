inherit VERB_OB;

#include <move.h>
#include <toolbox.h>

void duplicate_armor(object thing);
void duplicate_blaster(object thing);
void duplicate_weapon(object thing);

void do_duplicate_obj(object thing)
{
   if (thing->is_living())
   {
      if (thing == this_body())
      {
         write("There's only enough room in the universe for one of you.\n");
      }
      else
      {
         write(capitalize(thing->short()) + " is one of a kind, you wouldn't want to take that away from " + thing->query_objective() + " would you?\n");
      }

      return;
   }

   if (thing->is_armor())
   {
      int rank = this_body()->query_skill("duplicate") / 100;
      int spec = this_body()->query_guild_specialization_rank("engineer", "armor");
      int rank_spec = (rank + spec) < 0 ? 0 : (rank + spec);
      int required_parts = thing->query_armor_class() * (300 - (rank_spec * 10)) / 100;
      int found_parts = check_toolboxes_for_parts("armor", required_parts);

      if (found_parts < required_parts)
      {
         write("You need " + (required_parts - found_parts) + " more armor parts to duplicate " + thing->the_short() + ".\n");
         return;
      }
   }
   else if (thing->is_blaster())
   {
      int rank = this_body()->query_skill("duplicate") / 100;
      int spec = this_body()->query_guild_specialization_rank("engineer", "blasters");
      int rank_spec = (rank + spec) < 0 ? 0 : (rank + spec);
      int required_parts = thing->query_weapon_class() * (300 - (rank_spec * 10)) / 100;
      int found_parts = check_toolboxes_for_parts("blaster", required_parts);

      if (found_parts < required_parts)
      {
         write("You need " + (required_parts - found_parts) + " more blaster parts to duplicate " + thing->the_short() + ".\n");
         return;
      }
   }
   else if (thing->is_weapon() && !thing->is_lightsaber())
   {
      int rank = this_body()->query_skill("duplicate") / 100;
      int spec = this_body()->query_guild_specialization_rank("engineer", "weapons");
      int rank_spec = (rank + spec) < 0 ? 0 : (rank + spec);
      int required_parts = thing->query_weapon_class() * (300 - (rank_spec * 10)) / 100;
      int found_parts = check_toolboxes_for_parts("weapon", required_parts);

      if (found_parts < required_parts)
      {
         write("You need " + (required_parts - found_parts) + " more weapon parts to duplicate " + thing->the_short() + ".\n");
         return;
      }
   }
   else
   {
      write("You can only duplicate melee weapons, blasters and armor.\n");
      return;
   }

   this_body()->add_skill_delay(8);

   if (this_body()->test_skill("duplicate", this_body()->query_guild_level("engineer") * 20))
   {
      if (thing->is_armor())
      {
         duplicate_armor(thing);
      }
      else if (thing->is_blaster())
      {
         duplicate_blaster(thing);
      }
      else if (thing->is_weapon() && !thing->is_lightsaber())
      {
         duplicate_weapon(thing);
      }
   }
   else
   {
      this_body()->simple_action("$N $vfail to duplicate the $o.", thing);
   }
}

void do_duplicate()
{
   write("Duplicate what?\n");
}

void duplicate_armor(object thing)
{
   int level = this_body()->query_guild_level("engineer");
   int rank = this_body()->query_skill("duplicate") / 100;
   int spec = this_body()->query_guild_specialization_rank("engineer", "armor");
   int rank_spec = (rank + spec) < 0 ? 0 : (rank + spec);
   int amount = level + (rank_spec * 5);
   int required_parts = thing->query_armor_class() * (300 - (rank_spec * 10)) / 100;
   object duplicate = clone_object(base_name(thing));
   mapping resistances = duplicate->query_resistances();
   mapping weaknesses = duplicate->query_weaknesses();
   int armor_class = duplicate->query_armor_class();
   int durability = duplicate->query_durability();

   if (amount > 100)
   {
      amount = 100;
   }

   foreach (string type in keys(resistances))
   {
      resistances[type] = to_int(ceil(resistances[type] * amount / 100.0));
   }

   foreach (string type in keys(weaknesses))
   {
      weaknesses[type] = to_int(ceil(weaknesses[type] * amount / 100.0));
   }

   armor_class = to_int(ceil(armor_class * amount / 100.0));
   durability = to_int(ceil(durability * amount / 100.0));

   duplicate->set_resistances(resistances);
   duplicate->set_weaknesses(weaknesses);
   duplicate->set_armor_class(armor_class);
   duplicate->set_durability(durability);
   duplicate->set_max_durability(durability);

   if (amount > random(100))
   {
      if (remove_parts_from_toolboxes("armor", required_parts) == required_parts)
      {
         this_body()->simple_action("$N $vstudy " + thing->the_short() + " carefully, and $vmanage to construct something almost identical.");

         if (duplicate->move(this_body()) == MOVE_NO_ROOM)
         {
            duplicate->move(environment(this_body()));
         }
      }
   }
   else
   {
      int damage_percent = 100 - amount;
      int damage = ceil((thing->query_durability() - 1) * damage_percent / 100.0);

      thing->decrease_durability(damage);

      this_body()->simple_action("$N $vattempt to study " + thing->the_short() + ", and $vend up damaging it.");
   }
}

void duplicate_blaster(object thing)
{
   int level = this_body()->query_guild_level("engineer");
   int rank = this_body()->query_skill("duplicate") / 100;
   int spec = this_body()->query_guild_specialization_rank("engineer", "blasters");
   int rank_spec = (rank + spec) < 0 ? 0 : (rank + spec);
   int amount = level + (rank_spec * 5);
   int required_parts = thing->query_weapon_class() * (300 - (rank_spec * 10)) / 100;
   object duplicate = clone_object(base_name(thing));
   mapping damage_types = duplicate->query_damage_types();
   int durability = duplicate->query_durability();

   if (amount > 100)
   {
      amount = 100;
   }

   foreach (string type in keys(damage_types))
   {
      damage_types[type] = to_int(ceil(damage_types[type] * amount / 100.0));
   }

   durability = to_int(ceil(durability * amount / 100.0));

   duplicate->set_damage_types(damage_types);
   duplicate->set_durability(durability);
   duplicate->set_max_durability(durability);

   if (amount > random(100))
   {
      if (remove_parts_from_toolboxes("blaster", required_parts) == required_parts)
      {
         this_body()->simple_action("$N $vstudy " + thing->the_short() + " carefully, and $vmanage to construct something almost identical.");

         if (duplicate->move(this_body()) == MOVE_NO_ROOM)
         {
            duplicate->move(environment(this_body()));
         }
      }
   }
   else
   {
      int damage_percent = 100 - amount;
      int damage = ceil((thing->query_durability() - 1) * damage_percent / 100.0);

      thing->decrease_durability(damage);

      this_body()->simple_action("$N $vattempt to study " + thing->the_short() + ", and $vend up damaging it.");
   }
}

void duplicate_weapon(object thing)
{
   int level = this_body()->query_guild_level("engineer");
   int rank = this_body()->query_skill("duplicate") / 100;
   int spec = this_body()->query_guild_specialization_rank("engineer", "weapons");
   int rank_spec = (rank + spec) < 0 ? 0 : (rank + spec);
   int amount = level + (rank_spec * 5);
   int required_parts = thing->query_weapon_class() * (300 - (rank_spec * 10)) / 100;
   object duplicate = clone_object(base_name(thing));
   mapping damage_types = duplicate->query_damage_types();
   int durability = duplicate->query_durability();

   if (amount > 100)
   {
      amount = 100;
   }

   foreach (string type in keys(damage_types))
   {
      damage_types[type] = to_int(ceil(damage_types[type] * amount / 100.0));
   }

   durability = to_int(ceil(durability * amount / 100.0));

   duplicate->set_damage_types(damage_types);
   duplicate->set_durability(durability);
   duplicate->set_max_durability(durability);

   if (amount > random(100))
   {
      if (remove_parts_from_toolboxes("weapon", required_parts) == required_parts)
      {
         this_body()->simple_action("$N $vstudy " + thing->the_short() + " carefully, and $vmanage to construct something almost identical.");

         if (duplicate->move(this_body()) == MOVE_NO_ROOM)
         {
            duplicate->move(environment(this_body()));
         }
      }
   }
   else
   {
      int damage_percent = 100 - amount;
      int damage = ceil((thing->query_durability() - 1) * damage_percent / 100.0);

      thing->decrease_durability(damage);

      this_body()->simple_action("$N $vattempt to study " + thing->the_short() + ", and $vend up damaging it.");
   }
}

mixed can_duplicate_obj()
{
   if (this_body()->query_guild_level("engineer"))
   {
      if (!this_body()->has_learned_skill("duplicating"))
      {
         return "You have not learned how to duplicate something.\n";
      }
      else if (this_body()->get_target())
      {
         return "You are unable to duplicate something while in combat.\n";
      }
      else if (this_body()->has_skill_delay())
      {
         return "You are too busy to duplicate something.\n";
      }
   }
   else
   {
      return "Only engineers know how to duplicate something.\n";
   }

   return 1;
}

mixed can_duplicate()
{
   if (!this_body()->query_guild_level("engineer"))
   {
      return "Only engineers know how to duplicate something.\n";
   }

   return 1;
}

void create()
{
   add_rules( ({ "", "OBJ" }) );
}