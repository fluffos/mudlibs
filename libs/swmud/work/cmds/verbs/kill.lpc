#include <mudlib.h>

inherit VERB_OB;

void do_kill_liv(object thing)
{
   object this_body = this_body();

   if (!thing->is_adversary())
   {
      write("You could find more important things to attack.\n");
      return;
   }

   if (thing != this_body)
   {
      if (!this_body->query_stunned())
      {
         this_body->initiate_combat(thing);
      }
      else
      {
         write("You are stunned and cannot attack.\n");
      }
   }
   else
   {
      write("You should try the 'recreate' command instead.\n");
   }
}

void do_kill_liv_with_obj(object thing, object weapon)
{
   if (!thing->is_adversary())
   {
      write("You could find more important things to attack.\n");
      return;
   }

   this_body()->do_wield_obj(weapon);

   if (thing == this_body())
   {
      write("Now that you know how you want to kill yourself, you should try the 'suicide' command instead.\n");
   }
   else
   {
      do_kill_liv(thing);
   }
}

void do_kill()
{
   if (this_body()->query_target())
   {
      write("You are currently fighting " + this_body()->query_target()->short() + ".\n");
   }
   else
   {
      write("Attack whom?\n");
   }
}

void create()
{
   add_rules( ({ "", "LIV", "LIV with OBJ",  }) );
}