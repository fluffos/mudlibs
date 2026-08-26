/*
// _qload.c -- queries the load in terms of commands and compiled lines/sec
*/

#include <mudlib.h>

inherit DAEMON ;

int cmd_qload(string str)
{
    write(query_load_average() + "\n");
    return 1;
}

int help() {
	write ("Usage: qload\n\n"+
"The qload command tells you the average number of commands executed\n"+
"per second and the average number of code lines compiled per second\n"+
"over the last little period of time.\n") ;
	return 1 ;
}
