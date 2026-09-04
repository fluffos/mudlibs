/*
 * TLBB MUDLIB
 * $Header: /home/mud/cvsroot/tlbbmud/tlbb/tlbb_mudlib/include/net/httpdconf.h,v 1.3 2000/08/12 05:30:36 mud Exp $
 */
 
// Windf@TLBB add the player authentication check

#ifndef __HTTPDCONF_H
#define __HTTPDCONF_H

#define PATH_WWW(x) ("/www/" + x)
#define PROTECT_DIR ({\
	PATH_WWW("auth"), \
	})

#define PROTECT_FILE ({\
	PATH_WWW("channel/join_channel.html"), \
	PATH_WWW("gateways/j_channel"), \
	})

int check_path(string filename)
{
	int i;

	if(pointerp(PROTECT_FILE))
		for(i=0; i<sizeof(PROTECT_FILE); i++)
		{
			if(filename == PROTECT_FILE[i])
				return 0;

			if((strsrch(filename, "/www/gateways") != -1)
			&& (strsrch(filename, PROTECT_FILE[i]) != -1))
				return 0;
		}

	return 1;
}

#define WWW_CHANNEL "/www/gateways/l_channel"

#endif /* __HTTPDCONF_H */
