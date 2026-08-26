#include <hooks.h>

inherit CMD;
inherit M_EXIT;

void concentration(object living, object location, string location_name);

private mapping translations = ([ "n" : "north", "s" : "south", "e" : "east", "w" : "west", "ne" : "northeast", "nw" : "northwest", "se" : "southeast", "sw" : "southwest", "u" : "up", "d" : "down" ]);

void main(string arg)
{
   object this_body = this_body();
   object living;
   string living_name;
   int living_number = 1;
   string location_name;

   if (!arg)
   {
      living = this_body->get_target();

      if (!living)
      {
         out("Stun whom?\n");

         return;
      }
   }
   else
   {
      living = present(arg, environment(this_body));
   }

   if (!living && (sscanf(arg, "%s %d %s", living_name, living_number, location_name) != 3)
      && (sscanf(arg, "%s %s", living_name, location_name) != 2))
   {
      out("Usage: fstun <living> [location]\n");

      return;
   }

   if (this_body->query_guild_level("jedi"))
   {
      if (!this_body->has_learned_skill("force stun"))
      {
         out("You have not learned how to stun living things through the Force.\n");
      }
      else if (this_body->has_skill_delay())
      {
         out("You are too busy to concentrate on manipulating the Force.\n");
      }
      else
      {
         object location;
         int counter = 1;

         if (translations[location_name]) { location_name = translations[location_name]; }

         if (location_name && (member_array(location_name, environment(this_body)->query_exit_directions(0)) == -1))
         {
            out("You don't see a room in that direction.\n");
            return;
         }

         if (!location_name || (location_name == "here"))
         {
            location = environment(this_body);
         }
         else
         {
            location = load_object(environment(this_body)->query_exit_destination(location_name));
         }

         if (location)
         {
            foreach (object location_living in all_inventory(location))
            {
               if (location_living->id(living_name))
               {
                  if (living_number == counter)
                  {
                     living = location_living;
                     continue;
                  }

                  counter++;
               }
            }

            if (!living)
            {
               if (location == environment(this_body))
               {
                  out(title_capitalize(living_name) + (living_number > 1 ? " " + living_number : "") + " doesn't seem to be here.\n");
               }
               else
               {
                  out(title_capitalize(living_name) + (living_number > 1 ? " " + living_number : "") + " doesn't seem to be to the " + location_name + ".\n");
               }

               return;
            }

            if (living)
            {
               if (living == this_body())
               {
                  out("If you want to stun yourself, you should try looking in a mirror.\n");

                  return;
               }

               this_body->adjust_jedi_alignment(this_body->has_buff("/d/buffs/force_focus") ? 2 : 1);
               this_body->add_skill_delay(8);

               concentration(living, location, location_name);
            }
         }
         else { out("There is an unknown problem, please tell a wizard.\n"); }
      }
   }
   else
   {
      out("Only Jedi know how to manipulate the Force.\n");
   }
}

void concentration(object living, object location, string location_name)
{
   object this_body = this_body();
   int force = this_body->query_for();
   int level = this_body->query_guild_level("jedi");
   int rank = this_body->query_skill("force stun") / 100;
   int spec = this_body->query_guild_specialization_rank("jedi", "defense");
   int rank_spec = (rank + spec) < 0 ? 0 : (rank + spec);
   int duration = 4 + (28 * level * force * rank_spec / 100000 * 2);

   if (this_body->test_skill("force stun", (this_body->query_guild_level("jedi") * 10) + (this_body->query_skill("telekinesis") / 100 * 30) - 300 + this_body->call_hooks("force_focus", HOOK_SUM)))
   {
      if (location == environment(this_body))
      {
         this_body->targetted_action("$N $vstun $t through the Force.", living);
      }
      else
      {
         this_body->targetted_action("$N $vstun $t to the " + location_name + " through the Force.", living);
      }

      load_object("/d/buffs/force_stun");
      living->add_buff(new("/d/buffs/force_stun", duration));
      this_body->stop_fight(living, 1);
   }
   else
   {
      if (location == environment(this_body))
      {
         this_body->targetted_action("$N $vfail to stun $t through the Force.", living);
      }
      else
      {
         this_body->targetted_action("$N $vfail to stun $t to the " + location_name + " through the Force.", living);
      }
   }
}