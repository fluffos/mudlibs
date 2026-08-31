//     /adm/simul_efun/time.c
//      from the Nightmare mudlib
//      simul_efuns for the Nightmare mudlib time setup
//      created by Descartes of Borg 04 April 1993

#include <daemons.h>

int query_night() {
 return ((string)EVENTS_D->query_time_of_day() == "night");
 }

string day(int x) { return (string)EVENTS_D->query_day_name(x); }

int date(int x) {
    int week, datum;

    week = (int)EVENTS_D->query_week(x);
    datum = (int)EVENTS_D->query_day(x);
    return (5*(week-1)+datum);
}

string month(int x) { return (string)EVENTS_D->query_month_name(x); }

int year(int x) { return (int)EVENTS_D->query_year(x); }

int minutes(int x) { return (int)EVENTS_D->query_minutes(x); }

string season(int x) {
    int mon;

    mon = (int)EVENTS_D->query_month(x);
    switch(mon) {
        case 1: return "winter";
        case 2: if(date(x) < 16) return "winter"; else return "spring";
        case 3:
        case 4: return "spring";
        case 5: if(date(x) < 6) return "spring"; else return "summer";
        case 6: return "summer";
        case 7: if(date(x) < 16) return "summer"; else return "autumn";
        case 8:
        case 9: return "autumn";
        case 10: return (date(x) < 6 ? "autumn" : "winter");
        default: return "error";
    }
}

int hour(int x) { return (int)EVENTS_D->query_hour(x); }

int gmt_time(int time, string zone) {
   int a, b;
   mixed offset;
   if(!zone) zone="EST";
   if(zone[0..0] == "+" || zone[0..0] == "-") {
     if(sscanf(zone[1..], "%d:%d", a, b)==2) offset = to_float(a)+to_float("0."+b); else
     offset = to_int(zone[1..]);
     switch(zone[0..0]) {
       case "+":
         time += (offset * 3600);
         break;
       case "-":
         time -= (offset * 3600);
         break;
     }
     time = to_int(time);
   } else
   switch(zone) {
     case "CST":
       time -= 3600;
       break;
     case "SA":
       time += 50400;
       break;
     case "EST":
       return time;
       break;
     case "MST":
       time -=  7200;
       break;
    case "PST":
      time -= 10800;
      break;
    case "HST":
      time -= 18000;
      break;
    case "MT":
      time += 32400;
      break;
    default:
      time = time;
      break;
   }
   return (int)time;
}

varargs string query_season(int x) {
   if(!x) x=time();
   return EVENTS_D->query_season();
}

