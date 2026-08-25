#include "udp.h"
/*
 * They have answered our remote who question.
 */
void incoming_request(mapping info) {
  object ob;

  if (stringp(info["PORTUDP"]) && stringp(info["HOSTADDRESS"])) {
    if (info["NAME"] == mud_name())
      return ;
    if (!NAMESERVER_CD->query_mud_info(info["NAME"]))
      PING_Q->send_ping_q(info["HOSTADDRESS"], info["PORTUDP"]);
    if (!(ob = find_player(lower_case(info["ASKWIZ"]))))
      return ;
    tell_object(ob, "rwho@"+info["NAME"]+":\n"+info["RWHO"]);
  }
} /* incoming_request() */

void create() {
  seteuid(getuid());
} /* create() */
