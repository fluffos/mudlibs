// _undescribe.c -- Code to 'undescribe' yourself
// written by Truilkan@TMI - 92/04/26
//

#include <mudlib.h>

inherit DAEMON ;

// cmd_undescribe(string)

int cmd_undescribe(string str)
{
   this_player()->set("long", "");
   return 1;
}

int help() {
	write ("Usage: undescribe\n\n"+
"Undescribe will remove any description you entered using the describe\n"+
"command.\n") ;
	return 1 ;
}
