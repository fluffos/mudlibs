/*
// The new more command.
// Much more efficient, we hope.
*/

//This is basically cat -- Tlaloc. Should show line numbers of code and give it one page at a time...

#include <std.h>

inherit DAEMON;

int cmd_more(string str) {
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
