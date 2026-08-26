// Last edited by deforce on 11-14-2009
inherit CMD;

int get_duration();

void main(string arg)
{
   object this_body = this_body();

   if (this_body->query_guild_level("assassin"))
   {
      if (strlen(arg) && (arg == "off"))
      {
         if (this_body->has_buff("/d/buffs/silent_movement"))
         {
            this_body->cancel_buff("/d/buffs/silent_movement");
         }
         else
         {
            write("You are not moving around silently.\n");
         }

         return;
      }

      if (!this_body->has_learned_skill("silent movement"))
      {
         write("You have not learned how to move silently.\n");
      }
      else if (this_body->has_skill_delay())
      {
         write("You are too busy to concentrate on moving silently.\n");
      }
      else if (this_body->has_special_skill_delay("silent movement"))
      {
         write("You need to wait " + convert_time(this_body->has_special_skill_delay("silent movement")) + " before you can move silently again.\n");
      }
      else
      {
         if (!arg)
         {
            if (this_body->has_buff("/d/buffs/silent_movement"))
            {
               write("You are currently moving around silently.\n");
            }
            else
            {
               this_body->add_skill_delay(4);

               if (this_body->test_skill("silent move", (this_body->query_guild_level("assassin") * 10)))
               {
                  load_object("/d/buffs/silent_movement");
                  this_body->add_buff(new("/d/buffs/silent_movement", get_duration()));

                  this_body->add_special_skill_delay("silent movement", 120);
               }
               else
               {
                  write("You fail to move silently.\n");
               }
            }
         }
      }
   }
   else
   {
      out("Only assassins know how to move silently.\n");
   }
}

int get_duration()
{
   object this_body = this_body();
   int level = this_body->query_guild_level("assassin");
   int rank = this_body->query_skill("silent move") / 100;

   return 10 + ((level / 5) * 4) + (rank * 6);
}