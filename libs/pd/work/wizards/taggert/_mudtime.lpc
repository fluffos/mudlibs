#include <daemons.h>
#include <std.h>
inherit DAEMON;
string query_time(int time);
int cmd_mudtime() {
    string day, name, year, month, blah, str, pm, grr, left;
    int real, boot, hr, min;

    str = ctime(time());
    boot = (int)EVENTS_D->query_next_reboot(time());
    month = (string)EVENTS_D->query_month_name(time());
    year = (string)EVENTS_D->query_year(time());
    name = (string)EVENTS_D->query_day_name(time());
    day = (string)EVENTS_D->query_day(time());
    hr = EVENTS_D->query_hour(time());
    min =  EVENTS_D->query_minutes(time());
    blah = ordinal(EVENTS_D->query_day(time()));
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

    write("%^BLUE%^-=-=-=-%^CYAN%^Primal Darkness%^BLUE%^-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-%^RESET%^\n");
    write("    It is currently "+hr+":"+grr+pm+" on "+name+" the "+day+blah+" of "+month+".\n");
    write("    Current mud time is "+str+". (PST)\n");
    write("    The next reboot is "+ctime(boot)+". (PST)\n\n    "+left+"\n");
    write("%^BLUE%^-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-%^RESET%^\n");
    return 1;
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
    write("Nightshade's da coolest.");
}
