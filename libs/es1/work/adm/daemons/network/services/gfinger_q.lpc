/* File    : gfinger_q.c
 * Creator : Pinkfish@Discworld
 *         : Grendel@Tmi-2
 * When    : 93-08-15
 *
 * This file is part of the tmi mudlib.  Please keep this header intact.
 *
 * This protocol is a request for information about a user at another mud.
 */
#include <uid.h>
#include <daemons.h>
#include <mudlib.h>
#include <net/dns.h>
#include <net/macros.h>

inherit DAEMON;

#define WHO find_player( "insp" )
#define TELL(x)	if(WHO) tell_object(WHO, x)

// Finger a wiz on another mud.
void
send_gfinger_q(string mud, string wiz, object them)
{
  mapping minfo;

  if(!ACCESS_CHECK(previous_object())) return;

  if (!them)
    them = this_player();
  if (mud == Mud_name())
    return ;
  // make sure we have an entry for the recipient
  minfo = (mapping) DNS_MASTER->query_mud_info(mud);
  if (!minfo)
    return ;
  // send the finger
  DNS_MASTER->send_udp(minfo["HOSTADDRESS"], minfo["PORTUDP"],
   sprintf( "@@@%s||NAME:%s||PORTUDP:%d||" +
		"%s" +
		"ASKWIZ:%s@@@\n",
			DNS_GFINGER_Q, Mud_name(), udp_port(),
		(strlen(wiz) ? "PLAYER:" + wiz + "||" : ""),
		(string) them -> query( "name" ) ) );
}

void
incoming_request(mapping info)
{
  string reply;

  if( info["NAME"] && info["PORTUDP"] )
    {
      if (info["NAME"] == Mud_name())
	return ;

      // if we don't have a record of the mud get it
      if (!DNS_MASTER->dns_mudp(info["NAME"]))
	PING_Q->send_ping_q(info["HOSTADDRESS"], info["PORTUDP"]);

      // send the finger reply
   if( info["PLAYER"] && strlen( info["PLAYER"] ) )
        reply = (string)FINGER_D->finger_user(lower_case(info["PLAYER"]));
     else
        reply = (string) FINGER_D -> finger_all();
TELL( sprintf( "%O\n", reply ) );

      DNS_MASTER->send_udp(info["HOSTADDRESS"], info["PORTUDP"],
	      sprintf("@@@%s||NAME:%s||PORTUDP:%d||ASKWIZ:%s||MSG:%s@@@\n",
		      DNS_GFINGER_A, Mud_name(), udp_port(),
		      info["ASKWIZ"], reply));
    }
}

void
create()
{
  seteuid(ROOT_UID);
}


