/*--------------------------------------------------------------------------
 * /std/player/bin/rpeers.c  --  The rpeers command.
 *
 * Copyright (C) 1997, 1998 by One Step Beyond.
 * All Rights Reserved.
 * Permission granted for non-commercial use.
 *--------------------------------------------------------------------------
 * CHANGES
 *  06/28/98 [Mica] implemented features.h
 */

#include <msgclass.h>
#include <properties.h>
#include <secure/wizlevels.h>
#include <inetd.h>
#include <daemons.h>
#include <macros.h>
#include <features.h>
#include <i3.h>

string mkstr (int len) {
  string rc, pattern;
  int actlen;

  if (len <= 0) return "";
  pattern = "          ";
  rc = pattern;
  actlen = sizeof(pattern);
  while (actlen < len) rc += rc, actlen *= 2;
  return rc[0..len-1];
}

string ladjust (string str, int len) {
  int actlen;

  if (!str || len <= 0) return 0;
  if ((actlen = sizeof(str)) >= len) return str;
  return str+mkstr(len-actlen);
}

string radjust (string str, int len) {
  int actlen;

  if (!str || len <= 0) return 0;
  if ((actlen = sizeof(str)) >= len) return str;
  return mkstr(len-actlen)+str;
}

int main( string str ) {
  mapping hosts;
  int i;
  mixed muds;
  string res, *k;
  int tech;

  if ( str && ( str == "?" ) ) {
    msg_write( CMSG_GENERIC, "Usage: rpeers [tech].\n" );
    return 1;
  }

  if ( str && ( str == "tech" ) )
    tech = 1;

  res = sprintf( "%|78'-'s\n%|78s\n%|78'-'s\n", "","Intermud peers","" );

  if ( tech )
    res += "Mudname              IP-Number         UDP   Status   Last access\n";
  else
    res += "Mudname               Status   Last access\n";

  res += sprintf( "%|78'-'s\n", "" );

  muds = sort_array(m_indices(hosts = ({mapping})INET_D->query("hosts")), SF(>));
  for (i = 0; i < sizeof(muds); i++) {
    if ( tech )
      res += sprintf( "%-20s %-17s %-5d %s\n",
                      hosts[muds[i]][I2D_HOST_NAME],
                      hosts[muds[i]][I2D_HOST_IP],
                      hosts[muds[i]][I2D_HOST_UDP_PORT],
            (hosts[muds[i]][I2D_HOST_STATUS] ?
	     hosts[muds[i]][I2D_HOST_STATUS] > 0 ?
	     "UP       " + ctime(hosts[muds[i]][I2D_HOST_STATUS])[4..15] :
	     "DOWN     " + ctime(-hosts[muds[i]][I2D_HOST_STATUS])[4..15]
	     : "UNKNOWN" ) );
    else
      res += (ladjust(hosts[muds[i]][I2D_HOST_NAME], 20) + "  " +
            (hosts[muds[i]][I2D_HOST_STATUS] ?
	     hosts[muds[i]][I2D_HOST_STATUS] > 0 ?
	     "UP       " + ctime(hosts[muds[i]][I2D_HOST_STATUS])[4..15] :
	     "DOWN     " + ctime(-hosts[muds[i]][I2D_HOST_STATUS])[4..15]
	     : "UNKNOWN") +
	     "\n");
  }

  res +=
    sprintf( "%|78'-'s\n", " Total number of intermud peers is "+sizeof(muds)+" " );

#ifdef FEATURES_INTERMUD3
  res += "\n";

  muds = ({mixed})I3_TOOL("mudlist")->query_muds();

  k = sort_array( m_indices( muds ), SF(>) );

  res += sprintf( "%|78'-'s\n%|78s\n%|78'-'s\n", "", "Intermud-3 peers", "" );

  if ( tech )
    res += "Mudname                                 Mudlib               Driver     Type\n";
  else
    res += "Mudname                 Status              IP Port Information\n";

  res += sprintf( "%|78'-'s\n", "" );

  for( i = 0; i < sizeof( k ); i ++ ) {
    if ( tech ) {
      res += sprintf( "%-28s %20s %20s %8s\n",
		      k[i][0..24],
		      muds[k[i]][5][0..19],
		      muds[k[i]][7][0..19],
		      muds[k[i]][8][0..7] );
    }
    else {
      res += sprintf( "%-28s %4s %15s %5d %s\n",
		      k[i],
		      (muds[k[i]][0] == -1 ) ? "UP" : "DOWN",
		      muds[k[i]][1],
		      muds[k[i]][2],
		      muds[k[i]][9][0..22] );
    }
  }

  res +=
    sprintf( "%|78'-'s\n", " Total number of intermud-3 peers is "+sizeof(muds)+" " );
#endif

  msg_write(CMSG_GENERIC|MMSG_MORE|MMSG_NOWRAP, res);
  return 1;
}
