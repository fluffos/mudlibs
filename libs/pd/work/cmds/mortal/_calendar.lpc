//  Calendar Command

#include <daemons.h>
#define ASTRONOMY "/adm/daemon/astronomy_d"
#define MONTHS ({ "Tathsun", "Rikitu", "Fyllun", "Tashiran", "Zalen",\
                  "Ransidal", "Nabanshi", "Klisnal", "Qualtiar", "Virash" })
int cmd_calendar() {
   mapping dat=([]);
   int i, month, day, x;
   string out="", day2;

   i=sizeof(MONTHS);
   while(i--) dat[i]=({"1","2","3","4","5","6","7","8","9","10","11","12","13","14","15","16","17","18","19","20"});
   month=EVENTS_D->query_month(time());
   day=EVENTS_D->query_day_of_month(time()) - 1;
   day2=EVENTS_D->query_day_of_month(time())+"";
   if(!dat[month]) dat[month]=([]);
   dat[month-1][day]="%^BOLD%^%^RED%^"+day2+"%^RESET%^";
   out = "%^BOLD%^%^GREEN%^         Tathsun                   Rikitu                     Fyllun%^RESET%^\n";
   i=0;
   out+= "      "+dat[i][0]+"  "+dat[i][1]+"  "+dat[i][2]+"  "+dat[i][3]+"  "+dat[i][4]+"       ";
   i=1;
   out+= "      "+dat[i][0]+"  "+dat[i][1]+"  "+dat[i][2]+"  "+dat[i][3]+"  "+dat[i][4]+"       ";
   i=2;
   out+= "      "+dat[i][0]+"  "+dat[i][1]+"  "+dat[i][2]+"  "+dat[i][3]+"  "+dat[i][4]+"\n";
   i=0;
   out+= "      "+dat[i][5]+"  "+dat[i][6]+"  "+dat[i][7]+"  "+dat[i][8]+"  "+dat[i][9]+"       ";
   i=1;
   out+= "     "+dat[i][5]+"  "+dat[i][6]+"  "+dat[i][7]+"  "+dat[i][8]+"  "+dat[i][9]+"       ";
   i=2;
   out+= "     "+dat[i][5]+"  "+dat[i][6]+"  "+dat[i][7]+"  "+dat[i][8]+"  "+dat[i][9]+"\n";
   i=0;
   out+= "      "+dat[i][10]+" "+dat[i][11]+" "+dat[i][12]+" "+dat[i][13]+" "+dat[i][14]+"      ";
   i=1;
   out+= "      "+dat[i][10]+" "+dat[i][11]+" "+dat[i][12]+" "+dat[i][13]+" "+dat[i][14]+"      ";
   i=2;
   out+= "      "+dat[i][10]+" "+dat[i][11]+" "+dat[i][12]+" "+dat[i][13]+" "+dat[i][14]+"\n";
   i=0;
   out+= "      "+dat[i][15]+" "+dat[i][16]+" "+dat[i][17]+" "+dat[i][18]+" "+dat[i][19]+"      ";
   i=1;
   out+= "      "+dat[i][15]+" "+dat[i][16]+" "+dat[i][17]+" "+dat[i][18]+" "+dat[i][19]+"      ";
   i=2;
   out+= "      "+dat[i][15]+" "+dat[i][16]+" "+dat[i][17]+" "+dat[i][18]+" "+dat[i][19]+"\n\n";
//  Second Row
   out += "%^BOLD%^%^GREEN%^         Tashiran                   Zalen                    Ransidal%^RESET%^\n";
   i=3;
   out+= "      "+dat[i][0]+"  "+dat[i][1]+"  "+dat[i][2]+"  "+dat[i][3]+"  "+dat[i][4]+"       ";
   i=4;
   out+= "      "+dat[i][0]+"  "+dat[i][1]+"  "+dat[i][2]+"  "+dat[i][3]+"  "+dat[i][4]+"       ";
   i=5;
   out+= "      "+dat[i][0]+"  "+dat[i][1]+"  "+dat[i][2]+"  "+dat[i][3]+"  "+dat[i][4]+"\n";
   i=3;
   out+= "      "+dat[i][5]+"  "+dat[i][6]+"  "+dat[i][7]+"  "+dat[i][8]+"  "+dat[i][9]+"       ";
   i=4;
   out+= "     "+dat[i][5]+"  "+dat[i][6]+"  "+dat[i][7]+"  "+dat[i][8]+"  "+dat[i][9]+"       ";
   i=5;
   out+= "     "+dat[i][5]+"  "+dat[i][6]+"  "+dat[i][7]+"  "+dat[i][8]+"  "+dat[i][9]+"\n";
   i=3;
   out+= "      "+dat[i][10]+" "+dat[i][11]+" "+dat[i][12]+" "+dat[i][13]+" "+dat[i][14]+"      ";
   i=4;
   out+= "      "+dat[i][10]+" "+dat[i][11]+" "+dat[i][12]+" "+dat[i][13]+" "+dat[i][14]+"      ";
   i=5;
   out+= "      "+dat[i][10]+" "+dat[i][11]+" "+dat[i][12]+" "+dat[i][13]+" "+dat[i][14]+"\n";
   i=3;
   out+= "      "+dat[i][15]+" "+dat[i][16]+" "+dat[i][17]+" "+dat[i][18]+" "+dat[i][19]+"      ";
   i=4;
   out+= "      "+dat[i][15]+" "+dat[i][16]+" "+dat[i][17]+" "+dat[i][18]+" "+dat[i][19]+"      ";
   i=5;
   out+= "      "+dat[i][15]+" "+dat[i][16]+" "+dat[i][17]+" "+dat[i][18]+" "+dat[i][19]+"\n\n";
//  Second Three
   out += "%^BOLD%^%^GREEN%^         Nabanshi                   Klisnal                  Qualtiar%^RESET%^\n";
   i=6;
   out+= "      "+dat[i][0]+"  "+dat[i][1]+"  "+dat[i][2]+"  "+dat[i][3]+"  "+dat[i][4]+"       ";
   i=7;
   out+= "      "+dat[i][0]+"  "+dat[i][1]+"  "+dat[i][2]+"  "+dat[i][3]+"  "+dat[i][4]+"       ";
   i=8;
   out+= "      "+dat[i][0]+"  "+dat[i][1]+"  "+dat[i][2]+"  "+dat[i][3]+"  "+dat[i][4]+"\n";
   i=6;
   out+= "      "+dat[i][5]+"  "+dat[i][6]+"  "+dat[i][7]+"  "+dat[i][8]+"  "+dat[i][9]+"       ";
   i=7;
   out+= "     "+dat[i][5]+"  "+dat[i][6]+"  "+dat[i][7]+"  "+dat[i][8]+"  "+dat[i][9]+"       ";
   i=8;
   out+= "     "+dat[i][5]+"  "+dat[i][6]+"  "+dat[i][7]+"  "+dat[i][8]+"  "+dat[i][9]+"\n";
   i=6;
   out+= "      "+dat[i][10]+" "+dat[i][11]+" "+dat[i][12]+" "+dat[i][13]+" "+dat[i][14]+"      ";
   i=7;
   out+= "      "+dat[i][10]+" "+dat[i][11]+" "+dat[i][12]+" "+dat[i][13]+" "+dat[i][14]+"      ";
   i=8;
   out+= "      "+dat[i][10]+" "+dat[i][11]+" "+dat[i][12]+" "+dat[i][13]+" "+dat[i][14]+"\n";
   i=6;
   out+= "      "+dat[i][15]+" "+dat[i][16]+" "+dat[i][17]+" "+dat[i][18]+" "+dat[i][19]+"      ";
   i=7;
   out+= "      "+dat[i][15]+" "+dat[i][16]+" "+dat[i][17]+" "+dat[i][18]+" "+dat[i][19]+"      ";
   i=8;
   out+= "      "+dat[i][15]+" "+dat[i][16]+" "+dat[i][17]+" "+dat[i][18]+" "+dat[i][19]+"\n\n";
   out += "%^BOLD%^%^GREEN%^         Virash%^RESET%^\n";
   i=9;
   out+= "      "+dat[i][0]+"  "+dat[i][1]+"  "+dat[i][2]+"  "+dat[i][3]+"  "+dat[i][4]+"\n";
   out+= "      "+dat[i][5]+"  "+dat[i][6]+"  "+dat[i][7]+"  "+dat[i][8]+"  "+
     dat[i][9]+"       %^BOLD%^%^GREEN%^The current date is%^RESET%^: "+
     EVENTS_D->query_day_name(time())+", "+EVENTS_D->query_month_name(time())+" "+
     (day+1)+", "+EVENTS_D->query_year(time())+"\n";

   out+= "      "+dat[i][10]+" "+dat[i][11]+" "+dat[i][12]+" "+dat[i][13]+
     " "+dat[i][14]+"\n";

   out+= "      "+dat[i][15]+" "+dat[i][16]+" "+dat[i][17]+" "+dat[i][18]+" "+dat[i][19]+"\n";
   write("\n"+out);
   return 1;
}

void help() {
  message("help",
    "Syntax: <calendar>\n\n"
    "This will show you a calendar of "+mud_name()+".\n\n"
    "The world of "+mud_name()+" has a flow of time as follows:\n"
    "20 seconds per minute,\n"
    "60 minutes per hour,\n"
    "20 hours per day,\n"
    "5 days per week,\n"
    "4 weeks per month,\n"
    "and 10 months per year.\n\n"
    "Each second of real time is also one second of mud time, "
    "so one real day is a little over three mud days.",
    this_player() );
}
