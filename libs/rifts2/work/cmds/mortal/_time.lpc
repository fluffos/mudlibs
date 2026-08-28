// A simple command which uses clock.h to return mud time
// Diewarzau 3/16/94

#include <clock.h>

int cmd_time(string str) {
    int year, date;
    int time_sec;
    string tmp;
    string day, month;

    time_sec=time();
    day = DAYS[CURRENT_DAY(time_sec)];
    month = MONTHS[CURRENT_MONTH(time_sec)];
    year = CURRENT_YEAR(time_sec);
    date = CURRENT_DATE(time_sec);
    tmp = sprintf("%02d:%02d:%02d",CURRENT_HOUR(time_sec),
	CURRENT_MINUTE(time_sec),CURRENT_SECOND(time_sec));
    tmp += sprintf(" %s %s %d, %d",day, month, date, year);
    write("The current mud time is: "+tmp+"\n");
    return 1;
}

void help() {
message("help","This command gives the time and date by the Darkemud calendar. "
"See 'help calendar' for more info."
,this_player());
return;
}
