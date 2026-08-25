/*
// The new more command.
// Much more efficient, we hope.
*/

#include <std.h>

inherit DAEMON;

int cmd_more(string str) {
    if(!(int)this_player()->query_env("NO_CLEAR"))
    message("info", "\n%^INITTERM%^", this_player());
  return (int)this_player()->more(str);
}

int help()
{
  write( @EndText
Syntax: more <filename>
Effect: Uses the user's built in pager to list to your screen the
        contents of the file named <filename>
See also: less, cat, head, tail
EndText
  );
  return 1;
}
