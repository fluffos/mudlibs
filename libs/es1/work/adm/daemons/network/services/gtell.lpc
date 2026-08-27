/* File    : gtell.c
 * Creator : Pinkfish@Discworld
 *         : Grendel@Tmi-2
 * When    : 93-08-15
 *
 * This file is part of the tmi mudlib.  Please keep this header intact.
 *
 * This protocol is used to convey intermud tells.
 */
#include <mudlib.h>
#include <uid.h>
#include <net/dns.h>
#include <net/macros.h>
#include <net/daemons.h>

inherit DAEMON;

/* Tell to someone on another mud.
 */
void
send_gtell( string mud, string wiz_to, object source, string msg ,string emote)
{
  mapping minfo;
  
  if( !ACCESS_CHECK( previous_object() ) ) return;
  
  if( mud == Mud_name() || !geteuid( source ) ) return;
  
  minfo = ( mapping ) DNS_MASTER -> query_mud_info( mud );
  if( !minfo )
    return;
  
  msg = replace_string( msg, "|", " \b|" );
  msg = replace_string( msg, "@", " \b@" );
  DNS_MASTER -> send_udp( minfo["HOSTADDRESS"], minfo["PORTUDP"],
    "@@@" + DNS_GTELL +
    "||NAME:" + Mud_name() +
    "||PORTUDP:" + udp_port() +
    "||WIZTO:" + wiz_to +
    "||WIZFROM:" + ( string ) source -> query("name") +
    "||MSG:" + msg + "@@@\n" );
}

/* Someone on another mud has sent us a tell.
 */
void
incoming_request( mapping info )
{
  mapping minfo;
  object pl;
  string reply;
  
  if( info["NAME"] && info["PORTUDP"] )
  {
// dont want to tell to ourselves
    if( info["NAME"] == Mud_name() )
      return;
    
// get our info about the sender, ping them if we don't have any
    minfo = ( mapping ) DNS_MASTER -> query_mud_info( info["NAME"] );
    if( !minfo || !DNS_MASTER -> dns_mudp( info["NAME"] ) )
      PING_Q -> send_ping_q( info["HOSTADDRESS"], info["PORTUDP"] );
    
    if( minfo && minfo["HOSTADDRESS"] != info["HOSTADDRESS"] )
    { /* Its been faked! */
      dns_log( "network/dns_fake", "Tell: " + info["WIZFROM"] + "@" + info["NAME"] +
        "(" + info["HOSTADDRESS"] + ") telling " + info["WIZTO"]
        + " " + info["MSG"] + "\n" );
      DNS_MASTER -> send_udp( minfo["HOSTADDRESS"], minfo["PORTUDP"],
        "@@@" + DNS_WARNING +
        "||MSG: Faked gtell message " + info["WIZFROM"] +
        "@" + info["NAME"] + "> " + info["WIZTO"] +
        " " + info["MSG"] +
        "||FAKEHOST:" + info["name"] +
        "@@@\n" );
      return;
    }
    reply = ( string ) TS_D -> tell_user( info["WIZFROM"], info["NAME"],
      info["WIZTO"], info["MSG"] );
    
    
    "/adm/daemons/network/services/affirmation_a"-> send_affirmation_a( info["HOSTADDRESS"],
      info["PORTUDP"], "Gtell@" + Mud_name(),
      info["WIZFROM"], reply, "gtell" );
  } //if (info["NAME"] && info["PORTUDP"])
}


