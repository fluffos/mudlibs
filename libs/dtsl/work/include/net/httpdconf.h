// Windf@TLBB add the player authentication check

#ifndef __HTTPDCONF_H
#define __HTTPDCONF_H

#define PATH_WWW(x) ("/www/" + x)
#define PROTECT_DIR
#define PROTECT_FILE ({\
        PATH_WWW("channel/join_channel.html"), \
        PATH_WWW("cgi-bin/j_channel"), \
        })

int check_path(string filename)
{
        int i;

        if(pointerp(PROTECT_FILE))
                for(i=0; i<sizeof(PROTECT_FILE); i++)
                {
                        if(filename == PROTECT_FILE[i])
                                return 0;

                        if((strsrch(filename, "/www/cgi-bin") != -1)
                        && (strsrch(filename, PROTECT_FILE[i]) != -1))
                                return 0;
                }

        return 1;
}

#define WWW_CHANNEL "/www/cgi-bin/channel"

#endif /* __HTTPDCONF_H */
