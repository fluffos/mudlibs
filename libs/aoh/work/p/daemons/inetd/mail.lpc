/*--------------------------------------------------------------------------
 * INETD_CMD_DIR mail.c -- The intermud mail reply module
 *
 * Copyright (C) 1997 by One Step Beyond.
 * All Rights Reserved.
 * Permission granted for non-commercial use.
 *
 * Originally written by Alvin@Sushi (udp mail v1.0)
 *--------------------------------------------------------------------------
 */

#include <inetd.h>
#include <daemons.h>

void udp_mail(mapping data) {
  if(!member(data,I2H_RECIPIENT) || !data[I2H_RECIPIENT]) {
    log_file( INETD_LOG_FILE, "Invalid udp_mail packet. No Recipient.\n");
    return;
  }

  if( ! ({int})MAILER_D->query_recipient_ok(data[I2H_RECIPIENT])) {
    INET_D->send_packet( data[I2H_NAME],
		      ([
			I2H_REQUEST: I2R_REPLY,
			I2H_RECIPIENT: data[I2H_SENDER],
			UDPM_STATUS: UDPM_STATUS_UNKNOWN_PLAYER,
			UDPM_WRITER: data[UDPM_WRITER],
			UDPM_SPOOL_NAME: data[UDPM_SPOOL_NAME],
			I2H_ID: data[I2H_ID],
			I2H_DATA:
			"Reason: Unknown player \""+
			capitalize(data[I2H_RECIPIENT])+
			"\"\n\nINCLUDED MESSAGE FOLLOWS :-\n\n"+
			"Subject: "+data[UDPM_SUBJECT]+"\n"+data[I2H_DATA]
      ]) );

    return;
  }

  MAILER_D->deliver_mail(
			 data[I2H_RECIPIENT],
			 data[UDPM_WRITER]+"@"+data[I2H_NAME],
			 data[UDPM_SUBJECT],
			 data[I2H_DATA]
  );

  INET_D->send_packet(data[I2H_NAME],
		   ([
		     I2H_REQUEST: I2R_REPLY,
		     I2H_RECIPIENT: data[I2H_SENDER],
		     UDPM_STATUS: UDPM_STATUS_DELIVERED_OK,
		     UDPM_WRITER: data[UDPM_WRITER],
		     UDPM_SPOOL_NAME: data[UDPM_SPOOL_NAME],
		     I2H_ID: data[I2H_ID],
		     I2H_DATA: data[I2H_RECIPIENT]
		    ])
		   );
}

void create() {
  seteuid(getuid());
}
