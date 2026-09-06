/*--------------------------------------------------------------------------
 * /std/player/bin/rlocate.c  --  The rlocate command.
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

/* these defines are currently unused, we might add them later
 * V_FAILS will report failed locates
 * V_TIME_OUTS will report timeouts
 * the value needs to |ed to the I2H_VERBOSE field of the data sent
 * - old intermud only
 */

#define V_FAILS         1
#define V_TIME_OUTS     2

int main(string str) {
  mapping data;
  string * muds;
  int i;

  if (!str || str == "" || str == "?") {
    notify_fail("Usage: rlocate <username>\n");
    return 0;
  }

#ifdef FEATURES_INTERMUD3
  /* do locate for intermud-3 */
  I3_TOOL("locate")->send_locate_request( str );
#endif

  /* do locate for old intermud */
  data = ([
           I2H_REQUEST: I2R_LOCATE,
           I2H_SENDER: this_object(),
           I2H_USER: ({string})this_player()->Query(P_REALNAME),
           I2H_VERBOSE: 0,
           I2H_DATA: lower_case(str)
  ]);

  muds =
    m_indices( ({mapping})INET_D->query( I2RQ_HOSTS ) ) - ({ lower_case( LOCAL_NAME ) });

  for(i = sizeof(muds); i--; ) {
    if (({mixed})INET_D->query( I2RQ_VALID_REQUEST, I2R_LOCATE, muds[i]))
      INET_D->send_packet( muds[i], data, 1 );
  }

  msg_write( CMSG_GENERIC, "Locate requests sent.\n");

  return 1;
}

/* this function handles the replies from the old intermud daemon
 */

void udp_reply(mapping data) {
  object ob;

  if (!stringp(data[I2H_USER]) || !(ob = find_player(data[I2H_USER])))
    return;
  if (!(data[I2H_VERBOSE] & V_FAILS) && !data[I2H_FOUND])
    return;
  if (!(data[I2H_VERBOSE] & V_TIME_OUTS) &&
      ({int})INET_D->check_system_field(data, I2S_TIME_OUT))
    return;
  if (({int})INET_D->check_system_field(data, I2S_TIME_OUT))
    msg_object(ob, CMSG_GENERIC|MMSG_MORE, "locate@" + data[I2H_NAME] + ": Timed out.\n");
  else
    msg_object(ob, CMSG_GENERIC|MMSG_MORE, data[I2H_DATA] );
}
