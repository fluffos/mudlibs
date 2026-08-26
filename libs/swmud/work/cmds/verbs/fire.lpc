inherit VERB_OB;

void fire_at(object liv)
{
   object this_body = this_body();

   if (!liv->is_adversary())
   {
      write("You could find more important things to fire at.\n");
      return;
   }
   else if (this_body->get_target() && (this_body->get_target() != liv))
   {
      write("You are already in combat.\n");
      return;
   }

   if (liv != this_body)
   {
      if (sizeof(filter_array(this_body->query_weapons(), (: $1->is_blaster() :))))
      {
         write("You are attempting to fire at \"" + liv->short() + "\".\n");

         this_body->start_fight(liv);
      }
      else
      {
         write("You're not wielding a blaster.\n");
      }
   }
   else
   {
      write("You should try the 'recreate' command instead.\n");
   }
}

void find_living(string liv, string dir)
{
   object this_body = this_body();

   if (sizeof(filter_array(this_body->query_weapons(), (: $1->is_blaster() :))))
   {
      mapping translations = ([ "n" : "north", "s" : "south", "e" : "east", "w" : "west", "ne" : "northeast", "nw" : "northwest", "se" : "southeast", "sw" : "southwest", "u" : "up", "d" : "down" ]);
      object dir_room;
      object target;
      int max_range = 0;
      int dir_count = 0;

      if (translations[dir]) { dir = translations[dir]; }

      if (member_array(dir, environment(this_body())->query_exit_directions(wizardp(this_body()))) == -1)
      {
         write("There doesn't appear to be a direction \"" + dir + "\".\n");
         return;
      }

      dir_room = find_object(environment(this_body())->query_exit_destination(dir));

      if (!dir_room)
      {
         write("You don't see anything in direction \"" + dir + "\".\n");
         return;
      }

      foreach (object blaster in filter_array(this_body->query_weapons(), (: $1->is_blaster() :)))
      {
         if (blaster->query_range() > max_range)
         {
            max_range = blaster->query_range();
         }
      }

      if (max_range < 1)
      {
         write("You don't have any blaster range.\n");
         return;
      }

      write("You are attempting to fire at \"" + liv + "\" in direction \"" + dir + "\".\n");

      while ((!target) && (dir_count < max_range))
      {
         foreach (object thing in filter_array(all_inventory(dir_room), (: $1->is_adversary() :)))
         {
            if (member_array(liv, thing->query_id()) > -1)
            {
               target = thing;
               break;
            }
         }

         dir_count++;

         if (member_array(dir, dir_room->query_exit_directions(wizardp(this_body()))) > -1)
         {
            dir_room = find_object(dir_room->query_exit_destination(dir));
         }
         else
         {
            break;
         }

         if (target || !dir_room) { break; }

         if (max_range <= dir_count)
         {
            write("You're not able to aim that far with any equiped weapon.\n");
         }
      }

      if (target)
      {
         write("You found " + target->short() + ".\n");

         fire_at(target);
      }
      else
      {
         write("You didn't find a \"" + liv + "\" you can aim at.\n");
      }

//      this_body->initiate_combat(liv);
   }
   else
   {
      write("You're not wielding a blaster.\n");
   }
}

void do_fire_liv(object liv)
{
   fire_at(liv);
}

void do_fire_at_liv(object liv)
{
   fire_at(liv);
}

void do_fire_wrd_wrd(string liv, string dir)
{
   find_living(liv, dir);
}

void do_fire_at_wrd_wrd(string liv, string dir)
{
   find_living(liv, dir);
}

void do_fire()
{
   write("Fire at whom?\n");
}

void create()
{
   add_rules( ({ "", "LIV", "at LIV", "WRD WRD", "at WRD WRD" }), ({ "shoot" }) );
}