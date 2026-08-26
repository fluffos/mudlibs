/*
// The wonderful unalias command.
// Another giftie from Portals. Moby added this header 4-9-93. Original
// author not known, as is so common. Please leave this header on anyway.
*/

#include <mudlib.h>

inherit DAEMON ;

int cmd_unalias(string str)
{
   object act_ob;
   mapping alias;

   if(!str)
   {
      notify_fail("usage: unalias <alias>\n");
      return 0;
   }

   act_ob = previous_object();
   alias = (mapping)act_ob->query_aliases();

   if(!alias[str])
   {
      write(str+": alias not found.\n");
      return 1;
   }

   write("alias: "+str+" ("+alias[str]+") Removed.\n");
   act_ob->remove_alias(str);
   return 1;
}

int help()
{
   return (int)"/cmds/std/_alias"->help();
}
