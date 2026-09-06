#include <const.h>
#include <wizard.h>
inherit "/battle/weapon";

main(string param)
{
   object ob;
   string obname;
   int current;

   WIZ_CHECK

   if(!param)
   {
      msg("==> [Format] wrepair <object>");
      return 1;
   }

   ob = find_thing(param);
   obname=ob->query_name();
   current = ob->query_broken();

   if(!ob)
   {
      notify_fail("==> [Error] Unable to locate object "+param+"\n");
      return 0;
   }

   if(!query_weapon(ob))
   {
      notify_fail("==> [Error] This ain't a weapon!\n");
      return 0;
   }

   if(current==0)
   {
      notify_fail("==> [Error] That "+param+" isn't broken...\n");
      return 0;
   }

   if(current==1)
   {
      set_target(ob);
      this_player()->msg_local("~CBRT~Name ~verbwave ~poss fingers over the broken "+obname+" with a look of " + (this_player()->query_level() < ADMLEVEL ? "extreme concentration" : "practiced ease")+ " and ~targ ~vertis mended before your eyes!~CDEF");
      ob->set_condition(0);
      msg("==> "+capitalize(param)+" repaired successfully.");
      return 1;
   }
}
