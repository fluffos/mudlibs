#include <hooks.h>

inherit VERB_OB;

mixed call_hooks(string, int);

void do_compel_liv_to_wrd_str(object living, string command, string text)
{
   object this_body = this_body();

   if (this_body->query_guild_level("jedi"))
   {
      if (this_body->is_body() && !this_body->has_learned_skill("force compel"))
      {
         write("You have not learned how to compel someone with the Force.\n");
      }
      else if (this_body->has_skill_delay())
      {
         write("You are too busy to concentrate on compelling someone with the Force.\n");
      }
      else
      {
         if (living->is_body())
         {
            write("You don't think " + living->short() + " would appreciate being compelled to " + command + " " + text + ".\n");
            return;
         }

         if (command == "say")
         {
            this_body->add_skill_delay(8);
            living->do_game_command("say " + text);
         }
         else if (command == "emote")
         {
            this_body->add_skill_delay(8);
            living->do_game_command("emote " + text);
         }
         else if (member_array(command, SOUL_D->list_emotes()) > -1)
         {
            this_body->add_skill_delay(8);
            living->do_game_command(command + " " + text);
         }
         else
         {
            write("You don't know how to compel someone to '" + command + " " + text + "'.\n");
         }
      }
   }
   else
   {
      write("Only Jedi know how to compel someone with the Force.\n");
   }
}

void do_compel_liv_to_wrd(object living, string command)
{
   object this_body = this_body();

   if (this_body->query_guild_level("jedi"))
   {
      if (this_body->is_body() && !this_body->has_learned_skill("force compel"))
      {
         write("You have not learned how to compel someone with the Force.\n");
      }
      else if (this_body->has_skill_delay())
      {
         write("You are too busy to concentrate on compelling someone with the Force.\n");
      }
      else
      {
         if (living->is_body())
         {
            write("You don't think " + living->short() + " would appreciate being compelled to " + command + ".\n");
            return;
         }

         if (member_array(command, SOUL_D->list_emotes()) > -1)
         {
            this_body->add_skill_delay(8);
            living->do_game_command(command);
         }
         else
         {
            write("You don't know how to compel someone to '" + command + "'.\n");
         }
      }
   }
   else
   {
      write("Only Jedi know how to compel someone with the Force.\n");
   }
}

void do_compel_liv(object living)
{
   write("Compel " + living->short() + " to do what?\n");
}

void do_compel()
{
   write("Compel whom?\n");
}

void create()
{
   add_rules( ({ "", "LIV", "LIV to WRD", "LIV to WRD STR" }) );
}