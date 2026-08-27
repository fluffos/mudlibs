/* File    : ping_q.c
 * Creator : Pinkfish@Discworld
 *         : Grendel@Tmi-2
 * When    : 93-08-15
 *
 * This file is part of the tmi mudlib.  Please keep this header intact.
 *
 * This protocol is used to ask another mud for infomation about itself.
 */
#include <uid.h>
#include <mudlib.h>
#include <net/dns.h>
#include <net/macros.h>

inherit DAEMON;

string my_address;
int my_port;

// Someone has ping'd us
void
incoming_request(mapping info)
{
  if(!ACCESS_CHECK(previous_object())) return;

  if(info["NAME"] == Mud_name())
    {
      dns_warning("ping_q::incoming_request: ping from ourselves\n");
      // we pinged ourselves!
      return;
    }

  if (info["PORTUDP"])    {
      // check we have an entry for the sender
      if (!DNS_MASTER->dns_mudp(htonn( info["NAME"]) ))
	     PING_Q->send_ping_q(info["HOSTADDRESS"], info["PORTUDP"]);

      // send a ping answer along with our mud info
      DNS_MASTER->send_udp(info["HOSTADDRESS"], info["PORTUDP"],
			   "@@@"+DNS_PING_A+
			   (string)DNS_MASTER->start_message()+
			   "@@@\n");
     MAIL_Q -> check_for_mail( info["NAME"], 3 );
    }
}

// send a pinq query
void
send_ping_q(string host, mixed port)
{
  if(!ACCESS_CHECK(previous_object())) return;

  DNS_MASTER->send_udp(host, port, "@@@"+DNS_PING_Q+
		       "||NAME:"+Mud_name()+
		       "||PORTUDP:"+udp_port()+
		       "@@@\n");
}

void
create()
{
  seteuid(ROOT_UID);
  my_address = query_host_name();
  my_port = udp_port();
}

