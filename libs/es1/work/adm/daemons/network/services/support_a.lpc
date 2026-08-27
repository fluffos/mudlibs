#define WHO find_player("piral")
#define TELL(x) if(WHO) message("info", x + "\n", WHO);

/* File    : support_a.c
 * Creator : Pinkfish@Discworld
 *         : Grendel@Tmi-2
 * When    : 93-08-15
 *
 * This file is part of the tmi mudlib.  Please keep this header intact.
 *
 * This protocol is used to answer a support_q request.
 */
#include <uid.h>
#include <mudlib.h>
#include <net/dns.h>
#include <net/macros.h>

inherit DAEMON;

// We received an answer answer to our 'do you support xx' request.
void
incoming_request(mapping info)
{
  int idx;

  if(!ACCESS_CHECK(previous_object())) return;

  if (stringp(info["PORTUDP"]) && stringp(info["NAME"]))    {
      // don't want requests from ourself
      if (info["NAME"] == Mud_name())
	return ;

      // if we don't have an entry for the mud, then we ping it
      if (!DNS_MASTER->dns_mudp(info["NAME"]))
	PING_Q->send_ping_q(info["HOSTADDRESS"], info["PORTUDP"]);

      if(info["ANSWERID"] && sscanf(info["ANSWERID"], "%d", idx))
	index_call(idx, info);
    }
}

void
create()
{
  seteuid(ROOT_UID);
}

