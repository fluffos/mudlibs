// _haven.c
// Removes the caller from the users() array. (And protects vs find_object())
// Part of the TMI Mudlib and now part of Nightmare's as well.
// brought you you by Buddha@TMI
// Security is handled by query_hide() in the master object
// Mobydick added help and stricter argument control, 92-11-25
// Mobydick made it hide the connection object also, 93-02-06
// Pallando removed the connection object stuff for Nightmare 93-05-28
   
#include <std.h>

inherit DAEMON ;

int help() ;

int cmd_haven(string str) {

   int i;

   if (!str || (str!="off" && str!="on")) return help() ;
   if (str=="on") {
	write ("You are now hidden.\n") ;
	previous_object()->hide(1) ;
	return 1 ;
   }
   write ("You become unhidden again.\n") ;
   previous_object()->hide(0) ;
   return 1 ;
}

int help() {
	write ("Usage: haven <on | off>\n\n"+
"This command sets your hidden status. If you are hidden, then you will not\n"+
"appear in the users() efun. This means you will not appear on people\n"+
"or finger, and says in your environment will not reach you, and other\n"+
"similar effects.\n"+
"\nSee also: invis\n") ;
	return 1 ;
}
