/* File    : rwho_a.c
 * Creator : Pinkfish@Discworld
 *         : Grendel@Tmi-2
 * When    : 93-08-15
 *
 * This file is part of the tmi mudlib.  Please keep this header intact.
 *
 * This protocol is used to send a reply to a remote who request.
 */
#include <uid.h>
#include <mudlib.h>
#include <net/dns.h>
#include <net/macros.h>

inherit DAEMON;

// They have answered our remote who question.

void
incoming_request(mapping info)
{
  object ob;

  if(!ACCESS_CHECK(previous_object())) return;

  if (stringp(info["PORTUDP"]) && stringp(info["HOSTADDRESS"]))
    {
      if (info["NAME"] == Mud_name())
	return ;
      if (!DNS_MASTER->dns_mudp(info["NAME"]))
	PING_Q->send_ping_q(info["HOSTADDRESS"], info["PORTUDP"]);
      if (!(ob = find_player(lower_case(info["ASKWIZ"]))))
	return ;
//      if( !(last_char( info["RWHO"], "\n" )) )
//		info["RWHO"] += "\n";

	  message( "info", info["RWHO"], ob );
    }
}

void
create()
{
  seteuid(ROOT_UID);
}

