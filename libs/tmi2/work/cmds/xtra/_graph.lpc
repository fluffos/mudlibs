// _graph.c
// Prints graphs of MUD usage.
// All this does is call the relevant function in the usage daemon.
// See that file for better information.

// Mobydick, 6-7-93

#include <daemons.h>

#include <mudlib.h>

inherit DAEMON ;

int help() ;

#define ARGS ({ "mem", "cpu", "obs", "users" })

int cmd_graph (string str) {

	string flag, tmp ;

	if (!str) return help() ;
	if (sscanf(str,"%s %s",flag,tmp)==2 && flag == "-r") {
		str = tmp ;
	}
	if (member_array(str,ARGS)==-1) {
		notify_fail ("Supported args are mem, cpu, obs, and users.\n");
		return 0 ;
	}
	if (flag && flag=="-r") {
		USAGE_D->print_data(str) ;
		return 1 ;
	}
	USAGE_D -> graph(str) ;
	return 1 ;
}

int help() {
	write ("Usage: graph [-r] [mem|cpu|obs|users]\n\n"+
"The graph commands shows the history of the MUD's use of various\n"+
"things. It currently supports four arguments: mem, which shows\n"+
"memory use: cpu, which shows CPU use: obs, which shows the number\n"+
"objects loaded: and users, which shows the number of users logged\n"+
"in. The printed graph shows the history of the average number of\n"+
"the selected argument.\n" +
"Every two minutes, a daemon process checks the levels of the four\n"+
"variables and adds those levels to a running total. Every hour, the\n"+
"average level is computed and added to the graph. Bar 20, on the right\n"+
"hand side of the graph, is the last hour's usage, and previous bars\n"+
"are the use of previous hours, up to 20 hours before.\n"+
"The -r flag can be added: this will cause the command to print the\n"+
"raw data instead of graphing it.\n") ;
	return 1 ;
}
