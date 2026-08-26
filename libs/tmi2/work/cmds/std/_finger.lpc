// _finger.c
//
// Written by Huthar. (NOT! By Wayfarer actually!)
// Funny guys, aren't they? Apparently Wayfarer is the real author.
// Robocoder and Mobydick tweaked it on 3-24-93 so that commands of the
//   form "finger mobydick robocoder" would finger each user.

#pragma save_binary

#include <daemons.h>
#include <net/daemons.h>
#include <mudlib.h>
#include <switches.h>
#include <commands.h>

inherit DAEMON;

mapping requests;

void remote_finger(object me, string target, string mud);

void create() {
    seteuid(getuid());
}

int cmd_finger(string str) {
    object ob;
    string tmp1,tmp2,tmp3,tmp4;

    if (!str) {
        this_player()->more(explode(FINGER_D->finger_all(), "\n"));
        return 1;
    }

    if (!sscanf(str, "%s %s", tmp1, tmp2)) {
        tmp1 = str;
        tmp2 = "";
    }

    do {
        if (sscanf(tmp1,"%s@%s", tmp3, tmp4)) {
            /* convert localhost finger to local finger */
                if (tmp4 == "" || tmp4 == mud_name()) {
                    if (!tmp3 || tmp3 == "")
                        this_player()->more(explode(FINGER_D->finger_all(), "\n"));
                    else
                        this_player()->more(explode(FINGER_D->finger_user(lower_case(tmp3)), "\n"));
                } else {
                    if (!tmp3)
                        tmp3 = "" ;
#ifdef INTERMUD
		if( tmp3 == "" )
			return CMD_WHO->cmd_who( "@"+tmp4 );	
                "/adm/daemons/network/I3/finger"->send_finger_req(this_player()->query("name"),tmp3,tmp4);
#else
                write("Sorry, "+mud_name()+" doesn't support intermud communication.\n");
#endif /* INTERMUD */
                }
            } else if (tmp1 && tmp1 != "") {
                this_player()->more(explode(FINGER_D->finger_user(lower_case(tmp1)), "\n"));
        }

        str = tmp2; /* the rest */
        if (!str || !sscanf(str, "%s %s", tmp1, tmp2)) {
            tmp1 = str;
            tmp2 = 0;
            str = 0;
        }
    } while (tmp1);

    return 1;
}

string help() {
    return( @ENDHELP
Syntax: finger [player | (group)]

The finger command is used to print out information about a particular player,
members of a group, or players online.  Information ranges from name and
pseudo, to other data such as position, domain, location, email address,
and login status.

See also: chfn, who
ENDHELP
    );
}
