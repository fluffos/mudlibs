// look cmd from player.c, now external. Morgoth 2/Mar/95

#include <standard.h>
#include <cmd.h>
#include <commands.h>

#define DEFAULT_TIME 10
inherit CMD_BASE;
inherit "global/more_string";

void setup()
{
   position = 0;
}

string query_usage()
{
   return "look [at] [<object>]";
}

string query_short_help()
{
   return "Returns verbose description of an object or (default) the "+
      "place where you are.";
}

static int cmd (string arg, object me)
{
   object here, *ob;
   int i, dark;
   string ret;

   here = environment(me);

   if (!here)
   {
      notify_fail("You are in limbo... sorry you can't look at "+
         "anything.\n");
      return 0;
   }
   if(me->query_property("BLIND"))
   {
      notify_fail("You are blind, you cannot see anything!\n");
      return 0;
   }

   dark = me->check_dark((int)here->query_light());
   if (!arg || !stringp(arg) || arg == "")
   {
      if (me->query_creator())
         write(file_name(here)+"\n");
      write(here->long(0, dark));
      me->adjust_time_left(-LOOK_TIME);
      return 1; /* blame evan */
   }

   sscanf(arg, "at %s", arg);

   ob = find_match (arg, ({ me, here }) );
   ret = "";
   me->adjust_time_left(-DEFAULT_TIME);
   if (sizeof(ob))
   {
      if (pointerp(ob))
      {
         for (i=0;i<sizeof(ob);i++)
         {
            ret += ob[i]->long(arg, dark);
            me->adjust_time_left(EXAMINE_ITEM_TIME);
         }
      }
      else
      {
         ret += ob->long(arg, dark);
         me->adjust_time_left(EXAMINE_ITEM_TIME);
      }
      me->more_string(ret, "Look");
      return 1;
   }

   notify_fail("You do not think that the "+arg+" is here.\n");
   return 0;
}

