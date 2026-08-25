//	/bin/user/_date.c
//	from the Nightmare mudlib
//	gives the time for any time zone
//	created by Descartes of Borg 14 december 1992

#include <daemons.h>
#include <std.h>

inherit DAEMON;

int cmd_date(string str) {
    int borg;

    if(!str) str = (string)this_player()->getenv("TZONE");
    borg = (int)TIME_D->query_tzone(str);
    if(!str) write("Current mud time: "+ctime(borg)+"\n");
    else write("Current time "+str+": "+ctime(borg)+"\n");
    return 1;
}

void help() {
    write("Syntax: <date [(timezone)]>\n\n"+
	"Gives you the time.\n"+
	"If you specify a time zone, it will give you the time for that time\n"+
	"zone.  Without specifying, it gives you the time in your\n"+
 "time zone.\n"
 "Other info commands: help, faq, timezone\n"
);
}
