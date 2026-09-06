/*--------------------------------------------------------------------------
 * /std/player/bin/who.c  --  The rwho command.
 *
 * Copyright (C) 1997, 1998 by One Step Beyond.
 * All Rights Reserved.
 * Permission granted for non-commercial use.
 *--------------------------------------------------------------------------
 * CHANGES
 *  06/28/98 [Mica] implemented features.h
 */

#include <inetd.h>
#include <daemons.h>
#include <properties.h>
#include <msgclass.h>
#include <features.h>
#include <i3.h>

int main(string str) {
  string msg, tmp;

  if (!str || str == "" || str == "?") {
    notify_fail("Usage: rwho <mudname>\n");
    return 0;
  }

#ifdef FEATURES_INTERMUD3
  if ( tmp = ({string})I3_TOOL("mudlist")->mud_find( str ) ) {
    I3_TOOL("who")->send_who_request( tmp );
  }
  else
#endif
       if (msg = ({string})INET_D->send_packet(str,
                                  ([
                                    I2H_REQUEST: "who",
                                    I2H_SENDER: ({string})this_player()->Query(P_REALNAME)
                                   ]), 1)) {
    msg_write( CMSG_GENERIC, msg );
    return 1;
  }

  msg_write( CMSG_GENERIC, "Request sent.\n");

  return 1;
}
