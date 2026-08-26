// unnickname.c
// Original author unknown. Rather old.
// Now part of the TMI-2 mudlib. Please keep this header attached
// even though it is rather uninformative - Moby added it on 4-9-93 and
// he'd be disappointed if it wasn't here.

#include <config.h>
#include <mudlib.h>

inherit DAEMON ;

int cmd_unnickname (string arg) {
   mapping nicknames;
   object act_ob;
   
   act_ob = previous_object();
   if (!arg) {
      notify_fail ("usage: unnickname \\<nick_name>\n");
      return 0;
   }
   if (!act_ob->query_nickname(arg)) {
      notify_fail("No such nickname defined.\n");
      return 0;
   }
   act_ob->remove_nickname(arg);
   write ("Nickname removed: "+arg+"\n");
   return 1;
}

void help()
{
   write("usage: unnickname \\<nick_name>\n\n" +
   "This command removes the nick_name from you list of nicknames.\n" +
   "NOTE: since the nick_name will be expanded on the line you must escape\n" +
   "it with the '\\' character.\n" +
   "\nEXAMPLE:\n> nickname huth huthar\n> unnickname \\huth\n");
}

