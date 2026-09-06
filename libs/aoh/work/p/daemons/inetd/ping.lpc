/*--------------------------------------------------------------------------
 * INETD_CMD_DIR ping.c -- The intermud ping reply module
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

void udp_ping(mapping data) {
  INET_D->send_packet( data[I2H_NAME], 
		    ([
		      I2H_REQUEST: I2R_REPLY,
		      I2H_RECIPIENT: data[I2H_SENDER],
		      I2H_ID: data[I2H_ID],
		      I2H_DATA: LOCAL_NAME + " is alive.\n"
		     ]) 
		    );
}

void create() {
  seteuid(getuid());
}
