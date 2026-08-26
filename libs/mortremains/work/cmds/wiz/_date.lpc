#include <daemons.h>
#include <mudlib.h>
inherit DAEMON;

int cmd_date(string str) {
    string time_zone, t;
    int datime;

    time_zone = this_player()->getenv("TZONE");
    datime = TIME_D->query_tzone(time_zone);
#ifdef HAS_PRINTF
    if (!datime) {
    	printf("%s\n", ctime(time())); // just print the local time
    } else {
        t = ctime(datime);
	printf("%s %s %s\n", t[0..18], time_zone, t[20..23]);
    }
#else
    if (!datime) {
    	write(ctime(time()) + "\n"); // just print the local time
    } else {
        t = ctime(datime);
	write(t[0..18] + time_zone + t[20..23] + "\n");
    }
#endif
    return 1;
}

int help() {
    write( "Usage: date\n\n\
Prints the current (mud) time.  If you have set the TZONE environment\n\
variable, then the command will report the time in that time zone.\n");
    TIME_D->show_tzone_list();
    return 1;
}
