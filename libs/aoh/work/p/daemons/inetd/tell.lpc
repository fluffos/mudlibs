/*--------------------------------------------------------------------------
 * INETD_CMD_DIR tell.c -- The intermud tell receive module
 *
 * Copyright (C) 1997 by One Step Beyond.
 * All Rights Reserved.
 * Permission granted for non-commercial use.
 *
 * Originally written by Nostradamus@Zebedee
 * Developed from an original concept by Alvin@Sushi
 *--------------------------------------------------------------------------
 * CHANGES
 * 06/23/98 [Mica] Fixed invisibility bug
 */

#include <inetd.h>
#include <daemons.h>
#include <msgclass.h>
#include <properties.h>

void udp_tell(mapping data) {
  object ob;
  string tmp, tmp2;

  /* Compat with old-style SENDER handling. */
  if (data[I2H_SENDER])
    data[I2H_FROM] = data[I2H_SENDER];

  if ( data[I2H_RECIPIENT] &&
       (ob = find_player(data[I2H_RECIPIENT])) &&
       interactive(ob) ) {
	if (! ({int})INET_D->check_system_field(data, I2S_REPEAT)) {
          if ( ({int})ob->QueryInvis() ) {
	    tmp = LOCAL_NAME + ": No such player: " +
	      capitalize(data[I2H_RECIPIENT]) + "\n";

            tmp2 = " is unaware of telling you: ";
	  } else {
  	    // Player is visible
	    if ( ({int})ob->Query( P_EDITING ) )
	      tmp =
		capitalize( data[I2H_RECIPIENT]) + "@" + LOCAL_NAME +
		" is currently editing, your tell has been buffered.\n\n";
	    else if ( tmp = ({string})ob->Query( P_AWAY ) )
	      tmp =
		capitalize( data[I2H_RECIPIENT]) + "@" + LOCAL_NAME +
		" is away, "+tmp+"\n\n";
	    else
	      tmp = "";

	    tmp +=
	      "You told "+capitalize(data[I2H_RECIPIENT])+"@"+LOCAL_NAME+": " +
	      data[I2H_DATA] + "\n";

            tmp2 = " tells you: ";
	  }

	  msg_object( ob, CMSG_TELL,
		      capitalize(data[I2H_FROM])+"@"+data[I2H_NAME]+
		      tmp2+data[I2H_DATA] + "\n" );

          ob->Set( P_TELL_REPLYTO, ({ data[I2H_FROM]+"@"+data[I2H_NAME] }) );

	  INET_D->send_packet(data[I2H_NAME],
			   ([
			     I2H_REQUEST: I2R_REPLY,
			     I2H_RECIPIENT: data[I2H_SENDER],
			     I2H_ID: data[I2H_ID],
			     I2H_DATA: tmp
			    ])
			   );

	}
    } else
      INET_D->send_packet(data[I2H_NAME], ([
	    I2H_REQUEST: I2R_REPLY,
	    I2H_RECIPIENT: data[I2H_SENDER],
	    I2H_ID: data[I2H_ID],
	    I2H_DATA: LOCAL_NAME + ": No such player: "+
	              capitalize(data[I2H_RECIPIENT]) + "\n"
	]) );
}

void create() {
  seteuid(getuid());
}
