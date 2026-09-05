/*
 * global/server/time
 *
 * This file provides several functions for those files which want to know
 * the mudtime, moontime etc. resp. some nice time strings.
 *
 * This file is also the server for the TU_<x>'s defined in <timedep.h>.
 */

// in september 2000 the local time ran into an overflow and produced
// negative values.  we decided to proclaim a new `age' of the mud and
// set the local time back to 0.  the following macros return the current
// age to let the code know in which age we are.  they must be changed by
// hand whenever a new age is proclaimed.  we did not want to automize
// this because we think that proclaiming a new age should be done in
// accordance to events instead of passing time.
//                                      Alfe 00-Sep-11
//
// for the next time when this happens, get_tz_offset() and query_age()
// have to be adapted.
//                                      Coogan, 05-Nov-01
//
// Coogan, 17-Mar-2009: third age, Sun Mar 15 11:30:00 2009 (1237113000)


#pragma strong_types

#include <timezone.h>
#include <server.h>
#include <libs.h>
#include <time_units.h>
#include <time_defs.h>
#include <time.h>
#include <timedep.h>

#define SE_SHARED "etc/shared"

inherit "basic/time";
inherit "basic/create";


private varargs int get_tz_offset(int t) {
  if (!t)
    t = efun::time();
  switch (t) {
  // 658200000: 10-Nov-1990, Tub opened. No time earlier than that.
  // take care: the '-1' is used for query_phase_of_moon().
  case         0 ..  658199999: return         -1;
  case 658200000 ..  699999999: return          0;
  case 700000000 ..  968680799: return  700000000;
  case 968680800 .. 1237112999: return  968680800;
  default                     : return 1237113000;
  }
  NO_WARN_MISSING_RETURN;  // Coogan, 26-Mar-2011
}

varargs int query_time(int t) {
  if (t)  // real result of an earlier efun::time()
    return (t - get_tz_offset(t)) << TZ_SHIFT;
  return (efun::time() - TZ_OFFSET) << TZ_SHIFT;
}

varargs int query_day_time(int t) {
  return query_time(t) % ONE_DAY;
}

varargs int query_age(int t) {  // Coogan, 13-Sep-00
  if (!t)
    t = efun::time();
  switch (t) {
    case         0 ..  699999999: return 0;
    case 700000000 ..  968680799: return 1;  // TZ_OFFSET may change
    case 968680800 .. 1237112999: return 2;
    default:                      return 3;
  }
  NO_WARN_MISSING_RETURN;  // Coogan, 26-Mar-2011
}

varargs int query_moon_time(int t) {
  return query_time(t) % MOONDAY;
}

varargs int query_phase_of_moon(int t) {
  if (get_tz_offset(t) == -1)  // this is already mudtime
    return ((t % ONE_DAY) * 360 / ONE_DAY + 360 -
            (t % MOONDAY) * 360 / MOONDAY) % 360;
  return (query_day_time(t)  * 360 / ONE_DAY + 360 -
          query_moon_time(t) * 360 / MOONDAY) % 360;
}

int convert_moon(int phase) {
  switch (phase) {
  case 169 .. 191:
    return FULL_MOON;
  case 192 .. 348:
    return WANING_MOON;
  case 349 .. 360:
  case 000 .. 011:
    return NEW_MOON;
  case 012 .. 168:
    return WAXING_MOON;
  }
  NO_WARN_MISSING_RETURN;  // Coogan, 26-Mar-2011
}

int query_moon(int phase) {
  return convert_moon(query_phase_of_moon());
}

varargs string query_moon_string(int t) {
  switch(query_phase_of_moon(t)) {
  case 169 .. 191:
    return "full moon";
  case 192 .. 348:
    return "waning moon";
  case 349 .. 360:
  case 000 .. 011:
    return "new moon";
  case 012 .. 132:
    return "waxing moon";
  case 133 .. 156:
    return "waxing moon which will be full moon soon";
  case 157 .. 168:
    return "waxing moon which is almost full moon";
  }
  NO_WARN_MISSING_RETURN;  // Coogan, 26-Mar-2011
}

varargs int query_hour(int t) {
  return time_val(query_time(t))[TM_HOUR];
}

varargs int query_weekday(int t) {
  return time_val(query_time(t))[TM_WDAY];
}

varargs int query_month(int t) {
  return time_val(query_time(t))[TM_MON];
}

varargs int query_year(int t) {
  return time_val(query_time(t))[TM_YEAR];
}

varargs int query_season(int t) {
  return (((query_month(t) + 10) / 3) % 4);
}

varargs int query_day_of_year(int t) {
  return time_val(query_time(t))[TM_YDAY];
}

varargs int query_day_of_month(int t) {
  return time_val(query_time(t))[TM_MDAY];
}

// the query_tu_* functions are used for timedep-items.
int query_tu_moontime() {
  return query_moon_time();
}

int query_tu_moon() {
  return query_phase_of_moon();
}

int query_tu_month() {
  return query_month();
}

int query_tu_weekday() {
  return query_weekday();
}

int query_boot_time() {
  return SE_SHARED->query_global("boot_time");
}

string *years = ({ "cat", "snake", "bee", "wolf", "goat", "dog",
                   "pig", "cock", "dragon", "turtle", "lion", "rat" });

string query_year_string(int y) {
  return LIB_PARSE->get_ordinal((y / 12) + 1) + " year " +
         "of the " + years[y % 12];
}

varargs string query_day_phase_string(varargs mixed phase) {
  // Coogan, 07-Apr-2003,  moved from  basic/player/command to here
  int i;
  if (sizeof(phase))
    phase = to_int(phase[0]);
  else
    phase = query_day_time();
  for (i=8; i-->0; )
    if (TD_DAY8_WHEN[i] <= phase)
      return TD_DAY8_WHAT[i];
  raise_error("Bad value from localdaytime()\n");
}

varargs string query_time_string(int t) {
  int min;
  int *tv;
  status am;
  string res;
  string past, to;

  tv = time_val(query_time(t))[0..];
  am = (tv[TM_HOUR] < 12);
 
  if (!tv[TM_HOUR])
    past = "midnight";
  else if (tv[TM_HOUR] == 12)
    past = "twelve";
  else
    past = LIB_LANGUAGE->word_number(tv[TM_HOUR] % 12);

  if (tv[TM_HOUR] == 23)
    to = "midnight";
  else
    to = LIB_LANGUAGE->word_number((tv[TM_HOUR] % 12) + 1);

  tv[TM_HOUR] = tv[TM_HOUR] % 12;

  switch (min = ((tv[TM_MIN] / 5) * 5)) {
  case  0: res = past;
           break;

  case  5:
  case 10:
  case 20:
  case 25: res = LIB_LANGUAGE->word_number(min) + " minutes past " + past;
           break;

  case 15: res = "a quarter past " + past;
           break;

  case 30: res = "half past " + past;
           break;

  case 35:
  case 40:
  case 50:
  case 55: res = LIB_LANGUAGE->word_number(60 - min) + " minutes to " + to;
           break;

  case 45: res = "a quarter to " + to;
           break;
  }
  if (strstr(res, "midnight") > -1)
    return res;
  return res + " o'clock in the " +
     (am ? (tv[TM_HOUR] < 6 ? "night"     : "morning") : 
           (tv[TM_HOUR] < 6 ? "afternoon" : "evening"));
}

varargs string query_date_string(int t) {
  return capitalize(WEEKDAYS[query_weekday(t)]) + ", the " +
         LIB_PARSE->get_ordinal(query_day_of_month(t)) + " of " +
         capitalize(MONTHS[query_month(t)]) + " in the " +
         query_year_string(query_year(t));
}

void create() {
  time_val(time());  // to initialize the variables properly
}

