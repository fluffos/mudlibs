#include "udp.h"
/*
 * They answered our do you support xx request.
 */
void incoming_request(mapping info) {
  object ob;

  if (stringp(info["PORTUDP"]) && stringp(info["NAME"])) {
    if (info["NAME"] == mud_name())
      return ;
    if (!NAMESERVER_CD->query_mud_info(info["NAME"]))
      PING_Q->send_ping_q(info["HOSTADDRESS"], info["PORTUDP"]);
    ob = find_player(info["ANSWERID"]);
    if (info["SUPPORTED"])
      tell_object(ob, info["NAME"]+ " supports "+info["CMD"]+
                      ((info["PARAM"])?"("+info["PARAM"]+")":"")+"\n");
    else
      tell_object(ob, info["NAME"]+ " does not support "+info["CMD"]+
                      ((info["PARAM"])?"("+info["PARAM"]+")":"")+"\n");
  }
} /* incoming_request() */

void create() {
  seteuid(getuid());
} /* create() */
