/* File    : affirmation_a.c
 * Creator : Pinkfish@Discworld
 *         : Grendel@Tmi-2
 * When    : 93-08-15
 *
 * This file is part of the tmi mudlib.  Please keep this header intact.
 *
 * This protocol is used to confirm tells, and occasionally gwiz.
 */
#include <mudlib.h>
#include <uid.h>
#include <daemons.h>
#include <net/dns.h>
#include <net/macros.h>

inherit DAEMON;

#define WHO find_player("iral")
#define TELL(x) if( WHO ) tell_object( WHO, x + "\n" )

// Affirmation of something.

void
incoming_request(mapping info)
{
  object ob;
  string tmp;

  TELL( "Got: " + sprintf( "%O\n", info ) );
  if(!ACCESS_CHECK(previous_object()))
    return;

  if (!info["NAME"] || info["NAME"] == Mud_name())
    return;

  if (stringp(info["WIZFROM"]) && info["WIZFROM"][0..3] == "GWIZ")    {
      if (!random(10))
	this_object()->send_affirmation(info["HOSTADDRESS"], info["PORTUDP"],
               "Affirmation@"+Mud_name(), "yappo", "We got your "
               "affirmation about Gwiz.\n", "affirmation");
      return ;
    }
  if (info["WIZTO"])    {
      info["MSG"] = replace_string( info["MSG"], "\n", " " );

//     if( last_char( info["MSG"], " " ) )
//       info["MSG"] = info["MSG"][0..-2];


   tmp = sprintf( "%s@%s affirms: ", info["WIZFROM"], info["NAME"] );
    if (ob = find_player(lower_case(info["WIZTO"])))
     message( "channels", 
   wrap( tmp + info["MSG"] ),
         ob );
    }
}

void
send_affirmation_a(string host, string port, string from, string to,
                   string msg, string type) 
{
  if(!ACCESS_CHECK(previous_object()))
    return;

  DNS_MASTER->send_udp(host, port,
                          "@@@"+DNS_AFFIRMATION_A+
                          "||NAME:"+Mud_name()+
                          "||PORTUDP:"+udp_port()+
                          "||WIZTO:"+to+
                          "||WIZFROM:"+from+
                          "||TYPE:"+type+
                          "||MSG:"+msg+"@@@\n");
}

void
create()
{
  seteuid(ROOT_UID);
}
