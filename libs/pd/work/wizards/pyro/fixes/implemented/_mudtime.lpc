#include <daemons.h>
#include <std.h>
#define MIN 60
#define HOUR (60 * MIN)
#define DAY  (24 * HOUR)

inherit DAEMON;

string query_time(int time);
string parse_time(int time);

int cmd_mudtime() {
    mixed day, name, year, month, blah, str, pm, grr, left, af, day2, mon, hour, y2;
    string timezone, timezoneStr;
    int x, tm = uptime(), gmttime; /* uptime added by wiz */
    mixed boot, hr, min, date, min2, date2;

    if(sscanf(ctime(time()), "%s %s  %d %s %s", day2, mon, date, hour, y2) !=5) 
	sscanf(ctime(time()), "%s %s %d %s %s", day2, mon, date, hour, y2);
    sscanf(hour, "%d:%d:%*s", hour, min2);
    if(hour > 12) af="pm"; else af="am";
    if(hour > 12) hour=hour-12;
    if(hour==0) hour=12;
    if(hour < 10) hour="0"+hour;
    if(date<9) date2="0"+date; else date2=""+date;
    if(min2<10) min2="0"+min2; else min2=min2;
    str=(hour+":"+min2+af+" "+day2+", "+mon+" "+date2);


    boot = (int)EVENTS_D->query_next_reboot(time());
    month = (string)EVENTS_D->query_month_name(time());
    year = (string)EVENTS_D->query_year(time());
    name = (string)EVENTS_D->query_day_name(time());
    day = (string)EVENTS_D->query_day_of_month(time());
    hr = EVENTS_D->query_hour(time());
    min =  EVENTS_D->query_minutes(time());
    blah = ordinal(EVENTS_D->query_day_of_month(time()));
    hr++;

    if(hr > 12) {
	hr = hr - 12;
	pm = "PM";
    }
    else
	pm = "AM";
    if(min < 10)
	grr = "0"+min;
    else
	grr = ""+(string)min;

    left = query_time(boot - time());
    timezone = this_player()->getenv("TZONE");
    if(!timezone || timezone == "") {
      timezone = "EST";
      this_player()->setenv("TZONE", timezone);
    }
    gmttime = gmt_time(time(), timezone);
    if(timezone[0..0] == "+" || timezone[0..0] == "-")
      timezoneStr = "GMT "+timezone;
    else timezoneStr = timezone;
    write("%^BLUE%^+=+=+=+( %^BOLD%^%^WHITE%^Mud Time%^RESET%^%^BLUE%^ )+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=%^RESET%^");
    write("    It is currently "+hr+":"+grr+pm+" on "+name+" the "+day+blah+" of "+month+".");
    write("    Your current time is "+
      parse_time(gmttime)+". ("+timezoneStr+")");
    write("    Current server time is "+str+". (EST)");
    printf("    Primal Darkness has been up for ");
    if ((x = (tm / DAY)) > 0) {
	if (x == 1)
	    printf("%d Day, ", x);
	else
	    printf("%d Days, ", x);
	tm -= x * DAY;
    }
    printf("%d:", (x = (tm / HOUR)));
    tm -= x * HOUR;
    x = tm / MIN;
    if(x < 10)
	printf("0%d.\n", x);
    else
	printf("%d.\n", x);
    write("    The next reboot is "+ctime(gmt_time(boot, timezone))+". ("+timezoneStr+")");
    write("    Primal Darkness reboots every "+EVENTS_D->query_reboot_interval()+" hours.");
    write("%^BLUE%^+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+%^RESET%^\n");
    return 1;
}

string parse_time(int time) {
    mixed day, name, year, month, blah, str, pm, grr, left, af, day2, mon, hour, y2;
    int x, tm = uptime(); /* uptime added by wiz */
    mixed boot, hr, min, date, min2, date2;

    if(sscanf(ctime(time), "%s %s  %d %s %s", day2, mon, date, hour, y2) !=5)
        sscanf(ctime(time), "%s %s %d %s %s", day2, mon, date, hour, y2);
    sscanf(hour, "%d:%d:%*s", hour, min2);
    if(hour > 12) af="pm"; else af="am";
    if(hour > 12) hour=hour-12;
    if(hour==0) hour=12;
    if(hour < 10) hour="0"+hour;
    if(date<9) date2="0"+date; else date2=""+date;
    if(min2<9) min2="0"+min2; else min2=min2;
    str=(hour+":"+min2+af+" "+day2+", "+mon+" "+date2);
    return str;
}

string query_time(int time) {
    int tmp;
    string line;

    line = "";
    if(time < 60) return line;
    tmp = time / 86400;
    if(tmp)
	line += tmp + " day" + (tmp>1 ? "s " : " ");
    tmp = (time%86400)/3600;
    if(tmp) 
	line += tmp + " hour"+(tmp>1 ? "s " : " ");
    tmp = (time%3600)/60;
    if(tmp)
	line += tmp+ " minute"+(tmp>1 ? "s " : " ");
    line += "until reboot.";
    return line;
}

void help() {
    write("Shows current time inside the realm of Primal Darkness. "
      " Also shows real time, next reboot, and date.");
}

