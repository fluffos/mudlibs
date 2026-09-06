/*--------------------------------------------------------------------------
 * INETD_CMD_DIR query.c -- The intermud query reply module
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

void udp_query(mapping data) {
  mapping ret;
  
  switch(data[I2H_DATA]) {
  case I2RQ_COMMANDS:
    ret = ({mapping})INET_D->query( I2RQ_HOSTS );
    if (ret[lower_case(data[I2H_NAME])])
      ret = ([ I2H_DATA: implode(ret[lower_case(data[I2H_NAME])][I2D_LOCAL_COMMANDS], ":") ]);
    else
      ret = ([ I2H_DATA: implode(({string *})INET_D->query(I2RQ_COMMANDS), ":") ]);
    break;
  case I2RQ_EMAIL:
    ret = ([ I2H_DATA: GAMESMGR ]);
    break;
  case I2RQ_HOSTS:
    {
      mapping hosts;
      string *list;
      string tmp;
      int i;
      
      tmp = "";
      for(i = sizeof(list = m_indices(hosts = ({mapping})INET_D->query(I2RQ_HOSTS)));
	  i--; ) {
	tmp +=
	  hosts[list[i]][I2D_HOST_NAME] + ":" +
	  hosts[list[i]][I2D_HOST_IP] + ":" +
	  hosts[list[i]][I2D_HOST_UDP_PORT] + ":" +
	  implode(hosts[list[i]][I2D_LOCAL_COMMANDS], ",") + ":" +
	  implode(hosts[list[i]][I2D_HOST_COMMANDS], ",") + ":" +
	  hosts[list[i]][I2D_HOST_STATUS];
	if (i)
	  tmp += "\n";
      }
      ret = ([ I2H_DATA: tmp ]);
      break;
    }
  case I2RQ_INETD:
    ret = ([ I2H_DATA: INETD_VERSION ]);
    break;
  case I2RQ_LIST:
    ret = ([ I2H_DATA: implode( ({ I2RQ_COMMANDS,
				   I2RQ_EMAIL,
				   I2RQ_HOSTS,
				   I2RQ_INETD,
				   I2RQ_LIST,
				   I2RQ_TIME,
				   I2RQ_MUDPORT,
				   I2RQ_VERSION }), ":" ) ]);
    break;
  case I2RQ_MUDPORT:
    ret = ([ I2H_DATA: query_mud_port() ]);
    break;
  case I2RQ_TIME:
    ret = ([ I2H_DATA: ctime(time()) ]);
    break;
  case I2RQ_VERSION:
    ret = ([ I2H_DATA: version()+":"+(({string})LIBVERSION_D->MudlibVersion()) ]);
    break;
  default:
    /* Just ignore it for the time being. */
    return;
  }
  
  INET_D->send_packet( data[I2H_NAME], 
		    ret + ([
			    I2H_REQUEST: I2R_REPLY,
			    I2H_RECIPIENT: data[I2H_SENDER],
			    I2H_ID: data[I2H_ID],
			    I2H_QUERY: data[I2H_DATA]
		    ]) );
}

void create() {
  seteuid(getuid());
}
