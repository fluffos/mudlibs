#define WHO find_player( "insp" )
#define TELL(x) if(WHO) tell_object(WHO, x + "\n");

/* File    : ping_a.c
 * Creator : Pinkfish@Discworld
 *         : Grendel@Tmi-2
 * When    : 93-08-15
 *
 * This file is part of the tmi mudlib.  Please keep this header intact.
 *
 * This protocol is used to answer a ping request from another mud.
 */
#include <uid.h>
#include <mudlib.h>
#include <net/dns.h>
#include <net/macros.h>

inherit DAEMON;

// Someone has answered our ping of them.
void
incoming_request(mapping info)
{
    if(!ACCESS_CHECK(previous_object())) return;

    // set the name in the network master
    if (info["NAME"] && info["NAME"] != Mud_name())   {
	   DNS_MASTER->set_mud_info( htonn(info["NAME"]), info);
       // If there's mail to send out, do it now!
       MAIL_Q -> check_for_mail( info["NAME"], 3 );
    }

}

// set our uid
void
create()
{
    seteuid(ROOT_UID);
}


