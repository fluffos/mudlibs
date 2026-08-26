inherit CMD; 
inherit M_EXIT;

void storm_room(object room, int floor, int ceiling, int rounds);
void concentration(object room);
void damage_everything(object room, int damage);

private mapping translations = ([ "n" : "north", "s" : "south", "e" : "east", "w" : "west", "ne" : "northeast", "nw" : "northwest", "se" : "southeast", "sw" : "southwest", "u" : "up", "d" : "down" ]);
object this_body;
object this_room;

void main(string arg)
{
   this_body = this_body();

   if (!arg)
   {
      out("Create a Force storm where?\n");

      return;
   }

   if (this_body->query_guild_level("jedi"))
   {
      if (!this_body->has_learned_skill("force storm"))
      {
         out("You have not learned how to create Force storms.\n");
      }
      else if (this_body->has_skill_delay())
      {
         out("You are too busy to concentrate on manipulating the Force.\n");
      }
      else if (this_body->has_special_skill_delay("force storm"))
      {
         write("You need to wait " + convert_time(this_body->has_special_skill_delay("force storm")) + " before you can create another Force storm.\n");
      }
      else
      {
         object room;

         if (translations[arg]) { arg = translations[arg]; }

         if (member_array(arg, environment(this_body)->query_exit_directions(0)) == -1)
         {
            out("You don't see a room in that direction.\n");
            return;
         }

         room = load_object(environment(this_body)->query_exit_destination(arg));

         if (room)
         {
            int alignment = this_body->query_jedi_alignment();
            int max_alignment = this_body->query_max_jedi_alignment();

            this_body->simple_action("$N $vconcentrate on creating a Force storm in " + room->short() + "...\n");

            this_body->adjust_jedi_alignment(alignment < 0 ? -10 : (max_alignment - 1) * -1);

            this_room = environment(this_body);

            call_out("concentration", 8, room);

            this_body->add_skill_delay(12);
         }
         else { out("You don't see a room in that direction.\n"); }
      }
   }
   else
   {
      out("Only Jedi know how to manipulate the Force.\n");
   }
}

void concentration(object room)
{
   int alignment;

   if (this_room != environment(this_body))
   {
      tell(this_body, "Your concentration has been broken!\n");

      return;
   }

   alignment = this_body->query_jedi_alignment();

   if (this_body->test_skill("force storm", alignment * (alignment < 0 ? -5 : -20)))
   {
      int level = this_body->query_guild_level("jedi");
      int force = this_body->query_for();
      int rank = this_body->query_skill("force storm") / 100;
      int spec = this_body->query_guild_specialization_rank("jedi", "destruction");
      int rank_spec = (rank + spec) < 0 ? 0 : (rank + spec);
      int floor = level * force * rank_spec / 500;
      int ceiling = level * rank_spec * force * force / 20000;
      int rounds = 1 + (level / 20) + (level / 30) + (level / 50);
      int delay = 600 - ((level + rank) * 2) - (spec * 12);

//      this_body->simple_action("$N $vcreate a Force storm in " + room->short() + ", with " + floor + " min and " + ceiling + " max damage, lasting " + rounds + " rounds.\n");

      this_body->add_special_skill_delay("force storm", delay);

      storm_room(room, (floor > 0 ? floor : 1), (ceiling > level ? ceiling : level), rounds);
   }
   else
   {
      this_body->simple_action("$N $vlose focus.\n");
   }
}

void storm_room(object room, int floor, int ceiling, int rounds)
{
   string nearby_message;
   int amount = floor + random(ceiling - floor + 1);

   if (rounds > 1)
   {
      nearby_message = "A Force storm rages nearby.\n";

      call_out("storm_room", 12, room, floor, ceiling, rounds - 1);
   }
   else
   {
      nearby_message = "A Force storm rages nearby, and subsides.\n";
   }

   tell_from_outside(room, "A Force storm rages throughout the area!\n");

   foreach (string exit in room->query_exit_directions(0))
   {
      tell_from_outside(room->query_exit_destination(exit), nearby_message);
   }

   damage_everything(room, amount);

   if (rounds == 1) { tell_from_outside(room, "The Force storm subsides.\n"); }
}

void damage_everything(object room, int damage)
{
   if (!present("force_storm", this_body))
   {
      load_object("/d/obj/spec_damage");
      new("/d/obj/spec_damage", "Force storm", "force_storm")->move(this_body);
      present("force_storm", this_body)->set_death_message("$N was killed by a Force storm created by $N1 at $o1.");
   }

   foreach (object thing in all_inventory(room))
   {
      if (thing->is_adversary())
      {
         this_body->add_event(thing, present("force_storm", this_body), "none", ([ "unstoppable" : damage ]), this_body);

         this_body->start_fight(thing);
         this_body->handle_events();
      }
   }
}