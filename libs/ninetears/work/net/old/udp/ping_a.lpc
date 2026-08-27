#include "udp.h"
/*
 * Someone has answered our ping of them.
 */
void incoming_request(mapping info) {
  if (info["NAME"] && info["NAME"] != mud_name()) {
    NAMESERVER_CD->set_mud_info(info["NAME"], info);
  "/net/udp/mail_q"->check_for_mail(info["NAME"], 3);
  }
} /* incoming_request() */

void create() {
  seteuid(getuid());
} /* create() */
