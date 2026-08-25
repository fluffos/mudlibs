#include "udp.h"
/*
 * They answered our finger request.  Nice of them.
 */
void incoming_request(mapping info) {
  object ob;

  if (info["PORTUDP"] && info["NAME"]) {
    if (info["NAME"] == mud_name())
      return ;
    if (!NAMESERVER_CD->query_mud_info(info["NAME"]))
      PING_Q->send_ping_q(info["HOSTADDRESS"], info["PORTUDP"]);
    ob = find_player(info["ASKWIZ"]);
    if (ob) {
      tell_object(ob, "Finger from "+info["NAME"]+":\n"+info["MSG"]);
    }
  }
} /* incoming_request() */
