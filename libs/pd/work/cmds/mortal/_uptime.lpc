#include <std.h>

#define MIN 60
#define HOUR (60 * MIN)
#define DAY  (24 * HOUR)

inherit DAEMON;

int cmd_uptime()
{
    int tm = uptime();
    string str = "Primal Darkness has been up for ";
    int x;

    if ((x = (tm / DAY))>0)
    {
	if (x==1) str += x +" Day ";
	else str += x +" Days ";
	tm -= x * DAY;
    }
    if ((x = (tm / HOUR))>0)
    {
	if (x==1) str += x + " hour, ";
	else str += x + " Hours, ";
	tm -= x * HOUR;
    }
    if ((x = (tm / MIN))>0)
    {
	if (x==1) str += x + " Minute ";
	else str += x + " Minutes ";
	tm -= x * MIN;
    }
    if (tm>0)
    {
	if (tm==1) str += tm + " Second";
	else str += tm + " Seconds";
    }
    str += ".";
    write(str);
    return 1;
}

void help()
{
    write("Syntax: <uptime>\n"
      "This command reports how long Primal Darkness has "
      "been up.\n");
}
