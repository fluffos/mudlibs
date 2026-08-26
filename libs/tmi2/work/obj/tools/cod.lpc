//  cod:  Call_Out Debugger
//  by:   Archimedes@TMI-2
// Mobydick got sick of seeing them lying around so made it into an
// autoloading object :)  7-1-93, aka Arawn 1 185.

#include <mudlib.h>

inherit OBJECT;

void create()
{
	set("id", ({"cod", "fish"}));
	set("short", "a cod fish");
	set("bulk", 5);
	set("long",
"This is an electronic fish designed to debug call_outs.\n\
For help type \"help cod\".\n");
	set("capacity", 0);
}

int query_auto_load() 
{
	return 1 ;
}

void init()
{
	add_action("list_calls", "calls");
	add_action("help", "help");
}

int list_calls()
{
	int i, s;
	mixed *info;
	string ob;

	info = call_out_info();
	s = sizeof(info);
	i = s;

	printf("%-35s%-20s%-10s%-9s\n", "Object", "Function", "Delay", "Arg's");
	write("------------------------------------------------------------------------------");

	while(i--) {
	  catch(ob = file_name(info[i][0]));
          printf("\n%-35s%-20s%5d", ob, info[i][1], info[i][2]);
	  write("     ");
	  if(objectp(info[i][3]))
	    write(file_name(info[i][3]));
	   else
	    catch(write(info[i][3]));
	}

	write("\n------------------------------------------------------------------------------\n");
	printf("\t\t\t\t%s: %d\n", "Total call_outs", s);

	return 1;
}

int help(string arg)
{
	if(!(arg == "cod" || arg == "fish")) 
		return 0;
	write("\
This device provides information about all pending call_outs.\n\
To view the information, type \"calls\".\n\
\nThe cod, \"Call_Out Debugger\", was written by Archimedes@TMI-2.\n\
Mail him bug reports ;-)\n");
	return 1;
}
