//#pragma save_binary
// _where.c.
// Shows a player's location.
// Written by Spock@TMI-2, 3-27-93.

#include <mudlib.h>

inherit DAEMON ;
 
int cmd_where(string str)
{
	object obj;

	if(!str)
	{
		write("Usage: where <player>\n");
		return 1;
	}
	obj = find_player(str);
	if(!obj)
	{
		write ("No player by that name logged on.\n") ;
		return 1;
	}
	if (!environment(obj)) {
		write (capitalize(str) + " has a null environment.\n") ;
		return 1 ;
	}
	write(capitalize(str) + " is at " + file_name(environment(obj)));
	write("  (" + environment(obj)->query("short") + ")\n");
	return 1;
}
 
int help()
{
	write(""+
"Usage: where <player>\n"+
"	This command will give you the path and short description of the\n"+
"room where <player> is located.\n");
	return 1;
}
