/*--------------------------------------------------------------------------
 * INETD_CMD_DIR reply.c -- The intermud reply receive module
 *
 * Copyright (C) 1997 by One Step Beyond.
 * All Rights Reserved.
 * Permission granted for non-commercial use.
 *
 * Originally written by Nostradamus@Zebedee
 * Developed from an original concept by Alvin@Sushi
 *--------------------------------------------------------------------------
 */

#include <inetd.h>
#include <daemons.h>
#include <msgclass.h>

#ifndef DATE
#define DATE	ctime(time())[4..15]
#endif

void udp_reply(mapping data) {
  object ob;

  if ( ({int})INET_D->check_system_field(data, I2S_TIME_OUT ) ) {
    if (data[I2H_SENDER]) {
      if ( stringp(data[I2H_SENDER]) &&
	   (ob = find_player( data[I2H_SENDER])) ) {
	      msg_object( ob, CMSG_GENERIC,
			  "\ninetd: " + capitalize(data[I2H_REQUEST]) +
			  " request to " +
			  (data[I2H_RECIPIENT] ?
			   capitalize(data[I2H_RECIPIENT])+"@"+data[I2H_NAME] :
			   data[I2H_NAME]) +
			  " timed out.\n");
      }
      else if ( objectp(ob = data[I2H_SENDER]) || (ob = find_object(data[I2H_SENDER])) )
	      ob->udp_reply(data);
    }
    return;
  }

  if (data[I2H_RECIPIENT]) {
    /* If recipient is a player name, pass the message to them. */
    if ( stringp(data[I2H_RECIPIENT]) &&
	 (ob = find_player(data[I2H_RECIPIENT])) ) {
      msg_object( ob, CMSG_GENERIC|MMSG_MORE|MMSG_NOWRAP,
		  "\n" + data[I2H_DATA] );
    }
    /* Otherwise send it to udp_reply() in the recipient. */
    else if (objectp(ob) || (ob = find_object(data[I2H_RECIPIENT])))
      ob->udp_reply(data);

    return;
  }

  /* ignore anything else */
}

void create() {
  seteuid(getuid());
}
