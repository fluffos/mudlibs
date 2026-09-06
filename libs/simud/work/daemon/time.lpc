#include <const/climate.h>
#include <sys/rtlimits.h>

/** An object that passes the time. This is also a good
 * place to put any daemons that are easiest to trigger
 * outside of a centralized managing object.
 */

// "CDEF":"[070", "CREF":"[100", "CHLP":"[060",
// "CCOM":"[140", "CBRT":"[150", "CEMO":"[100",
// "CLAB":"[140", "CACT":"[100", "CTIT":"[110",
// "CDRK":"[080", "CSC1":"[040", "CSC2":"[120",
// "CSC3":"[060", "CSC4":"[140", "CSC5":"[150",
// "CMA1":"[060", "CMA2":"[100", "CMA3":"[070",
// "CMA4":"[110", "CMA5":"[140" ]);

// An abbreviation
#define C(x, y) "/obj/ansi"->set_code( x, y );

int boot_time;

void set_color_scheme( int scheme ) {
   // Daytime
   if( scheme == 0 ) {
      C("CDEF", "[070"); C("CREF", "[100"); C("CHLP", "[060");
      C("CCOM", "[140"); C("CBRT", "[150"); C("CEMO", "[100");
      C("CLAB", "[140"); C("CACT", "[100"); C("CTIT", "[110");
      C("CDRK", "[080"); C("CSC1", "[040"); C("CSC2", "[120");
      C("CSC3", "[060"); C("CSC4", "[140"); C("CSC5", "[150");
      C("CMA1", "[060"); C("CMA2", "[100"); C("CMA3", "[070");
      C("CMA4", "[110"); C("CMA5", "[140");
   }
   // Sunset
   if( scheme == 1 ) {
      C("CDEF", "[030"); C("CREF", "[110"); C("CHLP", "[030");
      C("CCOM", "[110"); C("CBRT", "[150"); C("CEMO", "[090");
      C("CLAB", "[110"); C("CACT", "[110"); C("CTIT", "[090");
      C("CDRK", "[080"); C("CSC1", "[080"); C("CSC2", "[010");
      C("CSC3", "[090"); C("CSC4", "[110"); C("CSC5", "[150");
      C("CMA1", "[080"); C("CMA2", "[010"); C("CMA3", "[050");
      C("CMA4", "[090"); C("CMA5", "[110");
   }
   // Night-time
   if( scheme == 2 ) {
      C("CDEF", "[060"); C("CREF", "[150"); C("CHLP", "[060");
      C("CCOM", "[140"); C("CBRT", "[140"); C("CEMO", "[140");
      C("CLAB", "[120"); C("CACT", "[070"); C("CTIT", "[140");
      C("CDRK", "[040"); C("CSC1", "[040"); C("CSC2", "[120");
      C("CSC3", "[060"); C("CSC4", "[140"); C("CSC5", "[150");
      C("CMA1", "[080"); C("CMA2", "[040"); C("CMA3", "[060");
      C("CMA4", "[140"); C("CMA5", "[100");
   }
   // Morning
   if( scheme == 3 ) {
      C("CDEF", "[080"); C("CREF", "[020"); C("CHLP", "[060");
      C("CCOM", "[060"); C("CBRT", "[070"); C("CEMO", "[020");
      C("CLAB", "[060"); C("CACT", "[020"); C("CTIT", "[030");
      C("CDRK", "[040"); C("CSC1", "[040"); C("CSC2", "[120");
      C("CSC3", "[060"); C("CSC4", "[140"); C("CSC5", "[150");
      C("CMA1", "[060"); C("CMA2", "[100"); C("CMA3", "[070");
      C("CMA4", "[110"); C("CMA5", "[140");
    }
// Another scheme I was looking at for morning...
//   if( scheme == 3 ) {
//      C("CDEF", "[080"); C("CREF", "[050"); C("CHLP", "[070");
//      C("CCOM", "[130"); C("CBRT", "[150"); C("CEMO", "[070");
//      C("CLAB", "[130"); C("CACT", "[150"); C("CTIT", "[130");
//      C("CDRK", "[040"); C("CSC1", "[040"); C("CSC2", "[120");
//      C("CSC3", "[060"); C("CSC4", "[140"); C("CSC5", "[150");
//      C("CMA1", "[060"); C("CMA2", "[100"); C("CMA3", "[070");
//      C("CMA4", "[110"); C("CMA5", "[140");
//   }
}

string query_day_of_week( int day ) {
   switch( day % 7 ) {
      case 0: return "Solju";
      case 1: return "Lunju";
      case 2: return "Duju";
      case 3: return "Moyju";
      case 4: return "Pluju";
      case 5: return "Etwaju";
      case 6: return "Creiju";
   }
   return 0;
}

int query_elven_day_of_month( int day ) {
   day %= 365;
   switch( day ) {
      case 0..30: return day + 1;
      case 31..58: return day - 30;
      case 59..89: return day - 58;
      case 90..119: return day - 89;
      case 120..150: return day - 119;
      case 151..180: return day - 150;
      case 181..211: return day - 180;
      case 212..242: return day - 211;
      case 243..272: return day - 242;
      case 273..303: return day - 272;
      case 304..333: return day - 303;
      case 334..364: return day - 333;
   }
   return 0;
}

/// Uses the W_ constants for seasons. Use climate.h to get these.
int query_season( int day ) {
   switch( day % 365 ) {
      default: return W_WINTER;
      case 59..150: return W_SPRING;
      case 151..242: return W_SUMMER;
      case 243..333: return W_FALL;
   }
   return 0;
}

string query_elven_month( int day ) {
   switch( day % 365 ) {
      case 0..30: return "Narvinye";
      case 31..58: return "Nenime";
      case 59..89: return "Sulime";
      case 90..119: return "Viresse";
      case 120..150: return "Lotesse";
      case 151..180: return "Narie";
      case 181..211: return "Cermie";
      case 212..242: return "Urime";
      case 243..272: return "Yanannie";
      case 273..303: return "Narquelie";
      case 304..333: return "Hisime";
      case 334..364: return "Ringare";
   }
   return 0;
}

string query_time_of_day() {
   int base_time;
   int minutes, hours, pm;

   base_time = time();
   minutes = (base_time % (DAY_LENGTH / 24)) / (DAY_LENGTH / 1440);
   hours = (base_time % DAY_LENGTH) / (DAY_LENGTH / 24);
   if( hours >= 12 ) pm = 1;
   hours %= 12;
   if( hours == 0 ) hours = 12;

   return hours + ":" + (minutes < 10?"0":"") + minutes + (pm?" p.m.":" a.m.");
}

string query_date( int day ) {
   string ord_day;

   if( !day ) day = time() / DAY_LENGTH;
   ord_day = (string) query_elven_day_of_month(day);
   switch( ord_day ) {
      case "1": case "21": case "31": ord_day += "st"; break;
      case "2": case "22": ord_day += "nd"; break;
      case "3": case "23": ord_day += "rd"; break;
      default : ord_day += "th"; break;
   }

   return query_day_of_week(day) + ", the " + ord_day + " of " + query_elven_month(day) + " in the year " + (day / 365);
}

int query_day_num() {
   return time() / DAY_LENGTH;
}

/** \return Approximately the amount of time until the next (game)
 * hour strikes, which is two minutes of real-life time. It adds two
 * seconds to help with daemon stability.
 */
int query_time_until_hour() {
   return (DAY_LENGTH / 24) + 2 - (time() % (DAY_LENGTH / 24));
}

int query_hour() {
   return (time() % DAY_LENGTH) / (DAY_LENGTH / 24);
}

void update_colors() {
   int hour;

   call_out("update_colors", query_time_until_hour() );

   hour = query_hour();
   if( hour == 05 ) set_color_scheme( 3 );
   if( hour == 07 ) set_color_scheme( 0 );
   if( hour == 17 ) set_color_scheme( 1 );
   if( hour == 19 ) set_color_scheme( 2 );
}

/** Initializes the time object. This should happen when the MUD boots.
 * Since the time object is used to keep track of uptime, updating
 * it and reloading it will have a similar effect to resetting the uptime.
 */
void create() {
   debug("loading time daemon...");
   update_colors();
   boot_time = "/secure/master"->query_hold_var();
   if( !boot_time )
      boot_time = time();
   debug("  boot_time = "+boot_time);
   call_out("update_colors", query_time_until_hour() );
   load_object("/daemon/playerwipe");
   load_object("/daemon/escheat");
   set_heart_beat( 1 );
}

int query_boot_time() {
   return boot_time;
}

int query_moon_phase() {
   // 42480 minutes = 29.5 days (in rl it's about half a day), and 10620 is
   // a quarter of that.
   return (time() % (42480 * 2)) / (10620 * 2);
}

string destructor( object ob ) {
   "/secure/master"->set_hold_var( boot_time );
   return 0;
}
