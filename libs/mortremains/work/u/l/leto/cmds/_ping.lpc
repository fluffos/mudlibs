/*
// Ping, by Inspiral@Tabor
// Created 01/01/94
// Based on work by Deathknight@Shadowriver
// This is UDP ping for the DNS System
*/

#include <mudlib.h>
#include <net/dns.h>
#include <net/services.h>
#include <daemons.h>
 
inherit DAEMON;
 
int cmd_ping( string str ) {
    mapping m;
    string svc;
 
    if( !str || str == "" ) 
       return notify_fail( "PING:  ping <mudname>\n" );

 
    m = (mapping) DNS_MASTER->query_mud_info(str);
 
    if (!mapp(m) || !m["HOSTADDRESS"]) {
        return notify_fail ("No such mud.\n");
    }
 
    
    if( !m["PORTUDP"] )
	   m["PORTUDP"] = SRVC_PORT_UDP(m["PORT"]);
   DNS_MASTER -> do_pings( str );
	SUPPORT_Q -> send_support_q( m["HOSTADDRESS"],
		 m["PORTUDP"], "" + time(), this_player() -> query( "name" ) );
    write( "Ping request sent to '" + str + "'.\n" );
    return 1;
}

void support_q_callback( mixed info ) {
  if( !mapp( info ) )
      return;

  message( "info", "Ping response received from " + info["ALIAS"] +
     " in " + (time() - to_int(info["CMD"])) + " seconds.\n",
     find_player( info["PARAM"] ) );
}

int help() {
  write( "Command: ping\n" 
"Syntax : ping <mudname>\n\n"
"This command sends a ping request to the specified mud, and if\n"
"the mud responds, displays an approximate travel time.  Note that\n"
"timeouts and lost requests are not reported back to the user.\n" );
  return 1;
}
