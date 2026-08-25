// A quick hack by Beek
// 9/3/94 amidst much driver anguish

#include <std.h>

#define MIN 60
#define HOUR (60 * MIN)
#define DAY  (24 * HOUR)
#define WEEK ( 7 * DAY)

inherit DAEMON;

int cmd_uptime() {
    int tm = uptime();
    string str = "Nightmare has been up for %^ORANGE%^";
    int x;

    if (x = (tm / WEEK)) {
        str += x + "w ";
        tm -= x * WEEK;
    }
    if (x = (tm / DAY)) {
        str += x +"d ";
        tm -= x * DAY;
    }
    if (x = (tm / HOUR)) {
        str += x + "h ";
        tm -= x * HOUR;
    }
    if (x = (tm / MIN)) {
        str += x + "m ";
        tm -= x * MIN;
    }
    if (tm) {
        str += tm + "s ";
    }
    str = str[0..-2] + "%^RESET%^.";
    write(str);
    return 1;
}

void help() {
    write("Syntax: uptime\n\nReports how long Nightmare has been up.\n");
}
