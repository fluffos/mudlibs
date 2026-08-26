inherit CMD;

void main(string arg)
{
   object this_body = this_body();

   if (this_body->query_guild_level("merchant") || this_body->query_guild_level("smuggler"))
   {
      if (!this_body->has_learned_skill("haggling"))
      {
         write("You have not learned how to haggle.\n");
      }
      else
      {
         if (arg == "on")
         {
            this_body->set_toggle("haggle", "on");

            out("You will now haggle.");
         }
         else if (arg == "off")
         {
            this_body->set_toggle("haggle", "off");

            out("You will no longer haggle.");
         }
         else
         {
            mixed toggle = this_body->query_toggle("haggle");

            if (toggle == "on")
            {
               out("You are set to haggle.");

               return;
            }
            else if (toggle == "off")
            {
               out("You are not set to haggle.");

               return;
            }

            this_body->set_toggle("haggle", "off");

            out("You are not set to haggle.");
         }
      }
   }
   else
   {
      write("Only merchants and smugglers know how to haggle.\n");
   }
}