#include <flags.h>
#include <hooks.h>

inherit CMD; 
inherit M_EXIT;

void concentration(object thing, object location, string location_name, object destination, string destination_name);
void assign_flag(int, int);
int test_flag(int);

private mapping translations = ([ "n" : "north", "s" : "south", "e" : "east", "w" : "west", "ne" : "northeast", "nw" : "northwest", "se" : "southeast", "sw" : "southwest", "u" : "up", "d" : "down" ]);

void main(string arg)
{
   object this_body = this_body();
   string thing_name;
   int thing_number = 1;
   int destination_number = 1;
   string location_name;
   string destination_name;

   if (!arg)
   {
      out("Throw what from where to where?\n");

      return;
   }

   if ((sscanf(arg, "%s %d from %s to %s %d", thing_name, thing_number, location_name, destination_name, destination_number) != 5)
      && (sscanf(arg, "%s from %s to %s %d", thing_name, location_name, destination_name, destination_number) != 4)
      && (sscanf(arg, "%s %d from %s to %s", thing_name, thing_number, location_name, destination_name) != 4)
      && (sscanf(arg, "%s from %s to %s", thing_name, location_name, destination_name) != 3))
   {
      out("Usage: throw <thing> from <location> to <destination>\n");

      return;
   }

   if (this_body->query_guild_level("jedi"))
   {
      if (!this_body->has_learned_skill("force throw"))
      {
         out("You have not learned how to throw things with the Force.\n");
      }
      else if (this_body->has_blocked_skill("force throw"))
      {
         out("Your ability to use this command has been disabled.\n");
      }
      else if (this_body->has_skill_delay())
      {
         out("You are too busy to concentrate on manipulating the Force.\n");
      }
      else
      {
         object thing;
         object location;
         object destination;
         int destination_counter = 1;
         int thing_counter = 1;

         if (translations[location_name]) { location_name = translations[location_name]; }
         if (translations[destination_name]) { destination_name = translations[destination_name]; }

         if (location_name == "here")
         {
            location = environment(this_body);
         }
         else if (location_name == "me")
         {
            location = this_body;
         }
         else
         {
            location = load_object(environment(this_body)->query_exit_destination(location_name));
         }

         destination = get_object_number(environment(this_body), destination_name, destination_number);

         if (destination_name == "here")
         {
            destination = environment(this_body);
         }
         else if (destination_name == "me")
         {
            destination = this_body;
         }
         else if (!destination)
         {
            destination = load_object(environment(this_body)->query_exit_destination(destination_name));
         }

         if (!location && (location_name != "here") && (location_name != "me")
               && (member_array(location_name, environment(this_body)->query_exit_directions(0)) == -1))
         {
            out("You don't see a room in that direction to throw something from.\n");
            return;
         }

         if (!destination && (destination_name != "here") && (destination_name != "me")
               && (member_array(destination_name, environment(this_body)->query_exit_directions(0)) == -1))
         {
            out("You don't see a room in that direction to throw something to.\n");
            return;
         }

         if (location && destination)
         {
            thing = get_object_number(environment(this_body), thing_name, thing_number);

            if (!thing)
            {
               if (location_name == "here")
               {
                  out("There doesn't seem to be " + thing_name + (thing_number > 1 ? " " + thing_number : "") + " here.\n");
               }
               else if (location_name == "me")
               {
                  out("You don't seem to have " + thing_name + (thing_number > 1 ?  " " + thing_number : "") + ".\n");
               }
               else
               {
                  out("There doesn't seem to be " + thing_name + " " + (thing_number > 1 ? thing_number : "") + " at " + location->short() + ".\n");
               }

               return;
            }

            if (thing)
            {
               if (thing->is_living())
               {
                  if (thing == this_body())
                  {
                     out("If you want to throw yourself around, you should try jumping.\n");
                  }
                  else
                  {
                     out("You decide that " + thing->the_short() + " wouldn't appreciate being thrown around against " + thing->query_possessive() + " will.\n");
                  }

                  return;
               }

               if (location_name == destination_name)
               {
                  out("You go around shouting that you made " + thing->the_short() + " move, and everyone looks at you like you're crazy.\n");
                  return;
               }

               this_body->add_skill_delay(8);

               concentration(thing, location, location_name, destination, destination_name);
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

void concentration(object thing, object location, string location_name, object destination, string destination_name)
{
   object this_body = this_body();
   int force = this_body->query_for();
   int level = this_body->query_guild_level("jedi");
   int rank = (this_body->query_skill("force throw") + this_body->query_skill("telekinesis")) / 100;
   int spec = this_body->query_guild_specialization_rank("jedi", "telekinesis");
   int weight = thing->query_weight();
   string text = thing->the_short() + " from ";

   if ((weight - (spec * 100)) > (((rank * 5) + (level * 2) + force) * 5))
   {
      write("You don't believe you could throw something that big.\n");
      return;
   }

   if (location == this_body())
   {
      text += "$r to " + destination_name;
   }
   else if (destination == this_body())
   {
      text += location_name + " to $r";
   }
   else
   {
      text += location_name + " to " + destination_name;
   }

   if (this_body->test_skill("force throw", (this_body->query_guild_level("jedi") * 10) + (this_body->query_skill("telekinesis") / 100 * 30) - 300 + this_body->call_hooks("force_focus", HOOK_SUM)))
   {
      int damage = weight * (0.6 + (rank * 0.7)) / 2;

      if (damage < 1) { damage = 1; }

      this_body->test_skill("telekinesis", this_body->query_guild_level("jedi") * 5);

      if (!present("force_throw", this_body))
      {
         load_object("/d/obj/spec_damage");
         new("/d/obj/spec_damage", thing->short(), "force_throw")->move(this_body);
         present("force_throw", this_body)->set_combat_messages("combat-force-throw");
      }
      else
      {
         present("force_throw", this_body)->setup(thing->short(), "force_throw");
      }

      present("force_throw", this_body)->set_death_message("$N was killed by " + thing->a_short() + " thrown through the Force by $N1 at $o1.");

      if (destination->is_adversary())
      {
         this_body->add_event(destination, present("force_throw", this_body), destination->query_random_limb(), ([ "striking" : damage ]), this_body);
         this_body->start_fight(destination);
      }
      else
      {
         this_body->simple_action("$N $vthrow " + text + ".\n", thing);

         foreach (object room_object in all_inventory(destination))
         {
            if (room_object->is_adversary())
            {
               this_body->add_event(room_object, present("force_throw", this_body), destination->query_random_limb(), ([ "striking" : damage ]), this_body);
               this_body->start_fight(room_object);
            }
         }
      }

      this_body->handle_events();

      if (!thing->test_flag(F_BROKEN))
      {
         thing->decrease_durability(random(damage));

         if (destination->is_adversary())
         {
            thing->move(environment(this_body));
         }
         else
         {
            thing->move(destination);
         }
      }
      else
      {
         thing->move(destination->is_adversary() ? environment(destination) : destination);

         tell_environment(thing, capitalize(thing->the_short()) + " is damaged beyond recognition.\n");
         destruct(thing);
      }
   }
   else
   {
      this_body->my_action("$N $vfail to throw " + text + ".\n", thing);
   }
}