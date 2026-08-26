#include <time.h>

varargs int mud_sec(int i) {
 if(!i) i=time();
return (i/PART_SEC)%SECOND;
}

varargs int mud_min(int i) {
 if(!i) i=time();
 return (i/(PART_SEC*SECOND))%MINUTE;
}

varargs int mud_hour(int i) {
 if(!i) i=time();
 return (i/(PART_SEC*SECOND*MINUTE))%HOUR;
}

varargs int mud_day(int i) {
 if(!i) i=time();
 return (i/(PART_SEC*SECOND*MINUTE*HOUR))%DAY;
}

varargs int mud_month(int i) {
 if(!i) i=time();
 return (i/(PART_SEC*SECOND*MINUTE*HOUR*DAY*WEEK))%MONTH;
}

varargs int mud_year(int i) {
 if(!i) i=time();
 return (i/(PART_SEC*SECOND*MINUTE*HOUR*DAY*WEEK*MONTH));
}

varargs string mud_time(int i) {
 return ""+mud_hour(i)+":"+mud_min()+":"+mud_sec();
}

varargs string mud_date(int i) {
  return ""+DAYS[mud_day(i)]+" the "+ordinal((mud_day(i)+1))+" day of "+MONTHS[mud_month(i)]+" of the year "+mud_year(i);
}

