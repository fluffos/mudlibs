/* Do not remove the headers from this file! see /USAGE for more info. */

#include <mudlib.h>

inherit VERB_OB;

int combat_allowed()
{
   if (environment(this_body()) && environment(this_body())->query_combat_forbidden())
   {
      environment(this_body())->combat_forbidden();
      return 0;
   }
   return 1;
}

void do_kill_liv(object ob)
{
   if (combat_allowed())
   {
      if (ob == this_body())
         this_body()->commit_suicide();
      else if (!this_body()->start_fight(ob))
         write(capitalize(ob->short()) + " cannot be attacked, sorry.\n");
      else
      {
         this_body()->targetted_action("$N $vattack $t.", ob);
      }
   }
   else
      write(capitalize(ob->short()) + " cannot be attacked here.\n");
}

void do_kill_liv_with_obj(object liv, object ob)
{
   /* should probably do a wield in here */

   if (combat_allowed())
   {
      if (liv == this_body())
         this_body()->commit_suicide();
      else if (!this_body()->start_fight(liv))
         write(capitalize(liv->short()) + " cannot be attacked, sorry.\n");
      else
      {
         this_body()->targetted_action("$N $vattack $t.", liv);
      }
   }
   else
      write(capitalize(liv->short()) + " cannot be attacked here.\n");
}

void do_kill()
{
   string err;
   if (combat_allowed())
   {
      if (err = this_body()->continue_fight())
      {
         write(err);
      }
   }
}

void create()
{
   add_rules(({
                 "",
                 "LIV",
                 "LIV with OBJ",
             }),
             ({"attack"}));
}