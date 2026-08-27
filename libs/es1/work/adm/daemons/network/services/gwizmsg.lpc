/* File    : gwizmsg.c
 * Creator : Pinkfish@Discworld
 *         : Grendel@Tmi-2
 * When    : 93-08-15
 *
 * This file is part of the tmi mudlib.  Please keep this header intact.
 *
 * This protocol is used to broadcast a channel to other muds.
 */
#include <mudlib.h>
#include <uid.h>
#include <net/macros.h>
#include <net/dns.h>
#include <net/daemons.h>
#include <net/services.h>

inherit DAEMON;

// This is the interface to the intermud channels

void
send_gwizmsg(string channel_id, string source, string msg, int emoted)
{
  string *names;
  int i;
  mapping muds;
  mapping svcs;
  mapping minfo;

  if(!ACCESS_CHECK(previous_object()))
    return;
  muds = (mapping)DNS_MASTER->query_muds();

//  msg = replace_string( msg, "||", "\|\|" );
//  msg = replace_string( msg, "@@@", "\@\@\@" );

  names = keys(muds);
  i = sizeof(names);
  while(i--)
    if (names[i] != Mud_name())
      {
	minfo = muds[names[i]];
    if( !mapp( minfo ) )
	  continue;
	DNS_MASTER->send_udp(minfo["HOSTADDRESS"], minfo["PORTUDP"],
                              "@@@" + DNS_GWIZMSG +
                              "||NAME:" + Mud_name() +
                              "||PORTUDP:" + udp_port() +
                              "||WIZNAME:" + capitalize(source) +
                              "||GWIZ:" + msg +
                              "||CHANNEL:" + channel_id +
                              (emoted?"||EMOTE:1":"") + "@@@\n");
      }
}

void
incoming_request(mapping info)
{
  mapping minfo;
  string tmsg;

  if(!ACCESS_CHECK(previous_object()))
    return;

  if (info["NAME"])
    {
      if (info["NAME"] == Mud_name())
	return ;

      minfo = (mapping) DNS_MASTER->query_mud_info(info["NAME"]);
      if (!minfo || !strlen(info["WIZNAME"])
	  || !DNS_MASTER->dns_mudp(info["NAME"]))
	{
	  /* We don't accept the message.  But ping them anyway. */
	  PING_Q->send_ping_q(info["HOSTADDRESS"], info["PORTUDP"]);
	  return ;
	}
      if (info["HOSTADDRESS"] != minfo["HOSTADDRESS"])
	{
	  if (info["EMOTE"])
	    tmsg = info["WIZNAME"]+"@"+info["NAME"]+" "+info["GWIZ"];
	  else
	    tmsg = info["WIZNAME"]+"@"+info["NAME"]+": "+info["GWIZ"];

	  /* Faked.  sheeze... */
	  dns_log("network/dns_fake",sprintf( "Gwiz: %s\n   msg: %s", 
				      info["HOSTADDRESS"],tmsg));
	  DNS_MASTER->send_udp(info["HOSTADDRESS"], info["PORTUDP"],
				"@@@"+DNS_WARNING+
				"||NAME:"+Mud_name()+
				"||MSG: Fake gwiz msg: "+tmsg+
				"||FAKEHOST:"+info["HOSTADDRESS"]+
				"@@@\n");
	  return;
	}
      INTER_CHAN_D->incoming_channel(info["CHANNEL"], info["WIZNAME"],
				     info["NAME"], info["GWIZ"], info["EMOTE"]);
    } //if (info["NAME"])
}

void
create()
{
    seteuid(ROOT_UID);
}

