#include "udp.h"
/*
 * We got a startup message.
 */

void incoming_request(mapping info) {
  if (stringp(info["NAME"])) {
/*
 * Tell us about a ping answer.  We then stick them in our
 * known muds list.  Also send a ping query to the mud so it knows about us.
 */
    PING_A->incoming_request(info);
    PING_Q->incoming_request(info);
  }
} /* incoming_request() */

void create() {
  seteuid(getuid());
} /* create() */
