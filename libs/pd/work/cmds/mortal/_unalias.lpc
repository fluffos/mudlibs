/*
// The wonderful unalias command.
*/

#include <std.h>

inherit DAEMON;

int cmd_unalias(string str)
{
   object act_ob;
   mapping alias;

   if(!str)
      return notify_fail("Remove which alias?\n");

   act_ob = this_player();
   alias = (mapping)act_ob->query_aliases();

   if(!alias[str])
   {
      write("Alias '"+str+"' not found.\n");
      return 1;
   }

   write("Alias "+str+" ("+alias[str]+") removed.\n");
   act_ob->remove_alias(str);
   return 1;
}

void help()
{
  load_object("/cmds/mortal/_alias")->help();
}
