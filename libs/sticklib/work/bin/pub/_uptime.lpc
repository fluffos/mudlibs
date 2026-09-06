#include <cmd.h>
#include <std_lib>

#define	MASTER_OB	"/secure/master"
varargs nomask int
uptime_cmd(string str, object me)
{
    string z;
    int adj, t;

    if (!me && !(me = this_player())) return 0;

    if (str) {
	z = lower_case(str);

	if ((adj = member(
	      ({ "bst", "alst", "yst", "pst", "mst", "cst", "est",
		"ast", "gmt", "cet", "eet" }), z))
	  == -1)
	    return notify_fail(
	      "Usage: uptime [time zone] (check 'help uptime' for zones)\n"),0;

	//  That's for EET
	//	adj = (3600 * ({-13,-12,-11,-10,-9,-8,-7,-6,-2,-1,0})[adj]);
	// This is for CST
	adj = (3600 * ({-5,-4,-3,-2,-1,0,1,2,3,4,5})[adj]);

    } else {
	z = "CST";
	adj = 0;
    }

    me -> tell_me(
      "============================================================================\n\
It is now          : " + ctime(time() + adj) + " " + z + "\n\
Last reboot was at : " + ctime(time() - query_uptime() + adj)
      +" " + z + ", " + secs2sstring(query_uptime()) + " ago\n\
============================================================================"
    );

    return 1;
}
