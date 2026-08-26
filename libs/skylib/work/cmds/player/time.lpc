/*
 * Original Author Unkown Discworld Creator
 * @Changed Shaydz: changed lots of things.
 */
 
#include <localtime.h>
#include <dst.h>

#define SPECIAL_DAY "/handlers/special_day"

inherit COMMAND_BASE;

mixed *_timezones;

string est_time(){

  int hours = TIME_H->query_hour(time());
  switch (hours)
  {
    case 2..4: return "pre dawn";
    case 5..7: return "around dawn";
    case 8..10: return "morning";
    case 11..13: return "around midday";
    case 14..16: return "afternoon";
    case 17..20: return "around dusk";
    case 21..22: return "night";
    default: return "around midnight";
  }
} /* est_time() */

void create() {
   mixed *time_rubbish;

   time_rubbish = localtime(time());
   _timezones = ({
      "Sydney (Server time)", (10 + AUS_DST) * (60 * 60),
      "Melbourne", (10 + AUS_DST) * (60 * 60),
      "Amsterdam", (CEST_DST +1) * (60 * 60),
      "London", (UK_DST  * 60 * 60),
//      "New Orleans", - (time_rubbish[LT_GMTOFF]+(14*60*60)) + (NO_DST * 60 * 60),
      "Edinburgh", (SCOT_DST * 60 * 60),
     });
} /* create() */

mixed cmd( string word ) {
   mixed *time_rubbish;
   int i;
   string mess;


   time_rubbish = localtime(time());
   /* Figure out the gmt time. */
   
   mess = "";
   mess += "You estimate the mud time to be " + est_time() + ".\n";
   if(creatorp(TP)){
      mess += "On "+mud_name()+", it is "+mudtime(time())+".\n\n";

      for (i = 0; i < sizeof(_timezones); i += 2) {
         mess += sprintf( "It is %s in %s.\n", ctime(time() + time_rubbish[LT_GMTOFF] +
                                    _timezones[i + 1]), _timezones[i]);
      }
  }
   write(mess);
   return 1;
} /* cmd() */

mixed *query_patterns() {
   return ({ "", (: cmd :) });
} /* query_patterns() */
