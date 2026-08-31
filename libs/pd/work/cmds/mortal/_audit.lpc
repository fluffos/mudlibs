#include <std.h>

inherit DAEMON;

int cmd_audit(string str)
{
 if (!str) return notify_fail("audit what?\n");
 if (str=="attempts") {
  if (file_size("/failed/"+this_player()->query_name())==-1)
    return notify_fail("You do not have any hack attempts.\n");
   write(read_file("/failed/"+this_player()->query_name()));
   return 1;
 }
 write("No such thing.\n");
 return 1;
}

int help()
{
 write("Command: audit\nSyntax: audit [what]\nWhat can be:\n"
       "attempts - see the attempts to your account with failed passwords");
}
