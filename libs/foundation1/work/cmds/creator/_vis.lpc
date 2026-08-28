//      /bin/dev/_vis.c
//      from the Nightmare mudlib
//      created by Descartes of Borg october 1992

#include <std.h>

inherit DAEMON;

varargs int cmd_vis(string str)
{
   if(!this_player()->query_invis()) {
	notify_fail("You are already visible.\n");
	return 0;
    }
    this_player()->set_invis(0);
    message("my_action", "You step out of the shadows.", this_player());
   return 1;
}


int help()
{
  write( @EndText
Syntax: vis
Effect: Makes you visible if you wern't already.
EndText
  );
  return 1;
}
