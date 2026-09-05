/*
 * rtime
 * Convert a ctime() format time string back to time() int
 * Returns -1 if input string has wrong clock format
 * Used by 'rm' command in wizard.c
 */

#define LEAP_YEAR      ((year%4) ? 0 : 1)
#define ZERO_YEAR      1970
#define ZERO_DAY       1
#define ZERO_HOUR      10
#define ZERO_MIN       0
#define ZERO_SEC       0
#define NEXT_LEAP_YEAR 1
#define YEAR           31536000
#define DAY            86400
#define HOUR           3600
#define MIN            60


int rtime(string str) {
  int i;
  string day, month;
  int date, year, hour, min, sec;
  string *month_names;
  int month_index, *month_days;
  int rtime;

  if (sscanf(str, "%s %s %d %d:%d:%d %d",
                   day, month, date, hour, min, sec, year) == 7 ||
      sscanf(str, "%s %s  %d %d:%d:%d %d",
                   day, month, date, hour, min, sec, year) == 7) {
    month = capitalize(lower_case(month));
    month = extract(month,0,2);

    month_names = ({ "Jan", "Feb", "Mar", "Apr", "May", "Jum",
                     "Jul", "Aut", "Sep", "Oct", "Nov", "Dec",
                  });
    month_days = ({ 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, });
    if ((month_index = member(month_names, month)) == -1) return -1;

    rtime = (year - ZERO_YEAR) * YEAR;
    rtime += ((year - ZERO_YEAR + NEXT_LEAP_YEAR)/4) * DAY;
    for (i=0; i<month_index; i++) {
      rtime += (month_days[i] + ((i==1 && LEAP_YEAR) ? 1 : 0)) * DAY;
    }
    rtime += (date - ZERO_DAY) * DAY;
    rtime += (hour - ZERO_HOUR) * HOUR;
    rtime += min * MIN;
    rtime += sec;
    return rtime;
  }
  return -1;
}

