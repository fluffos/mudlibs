//#pragma save_binary
 
//	File	:  /cmds/std/_ping.c
//	Creator	:  Zazz@WizMud  (04/93)
//	Updated	:  Watcher@TMI  (04/09/93) to modulize for TMI system.
//
//	A simple version of ping to see if a site is active.

#include <mudlib.h>
#include <net/daemons.h>
 
inherit DAEMON ;
 
#define SYNTAX	"Syntax: ping [mud name]\n"
 
cmd_ping( string str ) {
   object ps;
   int flag;

   notify_fail( SYNTAX );
   if(!str || str == "")  return 0;
 
   call_other(PING, "???");		//  Make sure server is loaded
   ps = find_object( PING );
 
   if(!ps) {
      write("Sorry.  The ping server is down right now.\n");
      return 1;
   }

   str = lower_case(str);
 
   write("Trying " + capitalize(str) + " ...\n");
 
   if( flag = ps->ping_request( str ) ) 
      write("Ping in progress.\n");
   else if (flag == 0) {
      notify_fail("Remote mud not on current mudlist.\n");
	return 0;
   }
   else {
      write("Ping unable to connect due to local socket difficulties.\n");
   }
   return 1;
}

int help() {
 
   write( SYNTAX + "\n" +
    "This command \"pings\" the named mud, indicating whether that mud is\n" +
    "active or not, with some associated statistics.\n");
 
return 1; }
 
