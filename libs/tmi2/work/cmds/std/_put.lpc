// _put.c
// This is kind of a bad hack. The _put command is defined in the container
// object. But you want players to be able to get help on it like any other.
// The solution is to make up this little command file, which traps two
// cases: first, the player using put when he doesn't have any containers;
// and second, the player typing "help put".
// Probably this isn't the best solution, but it's a short quick fix.
// Embarrassingly written by Mobydick@TMI-2, 1-22-92
// Part of the MudOS mudlib. Please retain at least this part of the header
// if you use this code.
 
#include <mudlib.h>
 
inherit DAEMON; 

#define SYNTAX	"Syntax: put [object] into [container]\n"

int help() {
 
   write( SYNTAX + "\n" +
"This command will put the named object into the named container. The\n"+
"container must be open to receive the object.\n"+
"\nSee also: get, open, close, lock, unlock.\n") ;
 
return 1; }

int cmd_put() {
 
   notify_fail("Put what in what?\n");
 
return 0; }
 
