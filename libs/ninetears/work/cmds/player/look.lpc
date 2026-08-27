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
   return "mirar [a] [<objeto>]";
}

string query_short_help()
{
   return "Returns verbose description of an object or (default) the "+
      "place where you are.";
}

int cmd (string arg, object me)
{
   object here, *ob;
   int i, dark, he_visto_algo=0;
   string ret;

   here = environment(me);

   if (!here)
   {
      notify_fail("Estas en el limbo... intentas mirar a algo "+
         "pero te resulta imposible.\n");
      return 0;
   }
   if(me->query_property("BLIND"))
   {
      notify_fail("Estas ciego, no puedes ver nada!\n");
      return 0;
   }

   dark = me->check_dark((int)here->query_light());
   if (!arg || !stringp(arg) || arg == "")
   {
      if (me->query_creator()) write(file_name(here)+"%^RESET%^\n");
      write(here->long(0, dark));
      me->adjust_time_left(-LOOK_TIME);
      return 1; /* blame evan */
   }

   sscanf(arg, "a %s", arg);

   ob = find_match (arg, ({ me, here }) );
   ret = "";
   me->adjust_time_left(-DEFAULT_TIME);
   if (sizeof(ob))
   {
      if (pointerp(ob))
      {
         for (i=0;i<sizeof(ob);i++)
         {
            if (ob[i]->query_hidden() && ob[i] != me)
            	continue;
            he_visto_algo++;
            ret += ob[i]->long(arg, dark);
            me->adjust_time_left(EXAMINE_ITEM_TIME);
         }
      }
      else
      {
      	if (!ob->query_hidden() && (object) ob != me) {
      	 he_visto_algo++;
         ret += ob->long(arg, dark);
         me->adjust_time_left(EXAMINE_ITEM_TIME);
	}
      }
      if (he_visto_algo) {
      me->more_string(ret, "Mirar");
      return 1;
      } // asko de hack :P
   }

   notify_fail("Hmm, no crees que "+arg+" este aqui.\n");
   return 0;
}
