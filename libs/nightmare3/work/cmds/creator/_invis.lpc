//      /bin/dev/_invis.c
//      from the Nightmare mudlib
//      created by Descartes of Borg october 1992

#include <std.h>

inherit DAEMON;

varargs int cmd_invis(string str)
{
   if((int)this_player()->query_invis()) {
	notify_fail("You are already invisible.\n");
	return 0;
    }
    this_player()->set_invis(1);
    message("my_action", "You fade into the shadows.", this_player());
   return 1;
}

void help()
{
    write("Syntax: <invis>\n\nMakes you invisible to players of lower levels in all circumstances.\n");
}
