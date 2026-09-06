/*--------------------------------------------------------------------------
 * INETD_CMD_DIR locate.c -- The intermud locate reply module
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

void udp_locate(mapping data) {
  mapping ret;
  object ob;

  ret = ([
	  I2H_REQUEST: I2R_REPLY,
	  I2H_RECIPIENT: data[I2H_SENDER],
	  I2H_ID: data[I2H_ID],
	  I2H_USER: data[I2H_USER],
	  I2H_VERBOSE: data[I2H_VERBOSE],
	  ]);

  if ( data[I2H_DATA] &&
       (ob = find_player(data[I2H_DATA])) &&
       interactive(ob) &&
       !({int})ob->QueryInvis() ) {
    ret[I2H_FOUND] = 1;
    ret[I2H_DATA] = "locate@" + LOCAL_NAME + ": " + ({string})ob->Short() + "\n";
  }
  else
    ret[I2H_DATA] =
      "locate@" + LOCAL_NAME + ": No such player: " + data[I2H_DATA] + "\n";
  INET_D->send_packet(data[I2H_NAME], ret);
}

void create() {
  seteuid(getuid());
}
