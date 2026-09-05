#pragma strong_types

#include <timedep.h>  // Coogan, 27-Apr-98
#include <prop/room.h>
#include <server.h>
#include <light.h>  // Coogan, 21-Apr-99

inherit "basic/timedep";
inherit "basic/namespace";
inherit "basic/create";

private mapping day_lights, season_factors, moon_lights;
private string *td_day8, *td_day2, *td_moon4, *td_year4, *td_sun;
private int last_time, last_daylight;

void create() {
  int i;
#if 0  // these are the original values
  day_lights  = mkmapping(TD_DAY8_WHAT, ({ 1, 5, 20, 70, 100, 70, 20, 5 }));
  moon_lights = mkmapping(TD_MOON4_WHAT,({ 10, 20, 10, 0 }));
  season_factors = mkmapping(TD_YEAR4_WHAT, ({ 10, 11, 10, 9 }));
#else  // I adapted them a bit, and squared them (and the values in
       // <light.h> too - so items don't have too much influence on daylight.
       // Coogan, 02-Jun-99, 05-Nov-99
  day_lights  = mkmapping(TD_DAY8_WHAT, ({ 100, 200, 1200, 4900,
                                           10000, 5100, 1500, 250 }));
  moon_lights = mkmapping(TD_MOON4_WHAT,({ 1000, 4000, 1000, 0 }));
  season_factors = mkmapping(TD_YEAR4_WHAT, ({ 100, 121, 100, 81 }));
#endif
  set_timedep(TD_DAY8_WHEN,  TD_DAY8_WHAT,  td_day8  = TD_DAY8);
  set_timedep(TD_MOON4_WHEN, TD_MOON4_WHAT, td_moon4 = TD_MOON4,TU_MOON);
  set_timedep(TD_YEAR4_WHEN, TD_YEAR4_WHAT, td_year4 = TD_YEAR4,TU_MONTH);
  set_timedep(TD_DAY2_WHEN,  TD_DAY2_WHAT,  td_day2  = TD_DAY2);
  set_timedep(TD_SUN_WHEN,   TD_SUN_WHAT,   td_sun   = TD_SUN);

#ifdef SE_CRON
#if 0
  map(TD_SUN_WHEN,
	    lambda(({ 'when }),
		   ({ #'call_other,
		        SE_CRON,
		        "crontab_add",
		        ({ #'+, 'when, 30*60 }),
		        load_name(this_object()), // Chameloid, 15-Dec-98
		        "announce_change" })));
#else  // this code above added crontab entries without argument for
  // announce_change(). Replaced by the following, Coogan, 24-Feb-2006
  for (i = sizeof(TD_SUN_WHEN); --i > 0; ) {
    DEBUG_POINT("coogan", ({ i }));
    SE_CRON->crontab_add(TD_SUN_WHEN[i] + 30*60,
                         load_name(this_object()),
                         "announce_change",
                         TD_SUN_WHAT[i]);
  }
#endif
#endif
}

void notify_destruct() {        // cleanup, Coogan, 15-Mar-2006
  int i;
  for (i = sizeof(TD_SUN_WHEN); i-->0; ) {
    DEBUG_POINT("coogan", ({ i }));
    SE_CRON->crontab_remove(TD_SUN_WHEN[i] + 30*60,
                            load_name(this_object()),
                            "announce_change");
  }
}

string query_season() {
  return query_timedep(td_year4);
}

string query_daytime() {
  return query_timedep(td_day8);
}

string query_moonphase() {
  return query_timedep(td_moon4);
}

string query_suntime() {
  return query_timedep(td_sun);
}

// varargs and room added, Coogan, 21-Apr-99
varargs int query_daylight(object room) {
  int l;
  mixed f;
  if (time() == last_time)
    l = last_daylight;
  else
    l = (last_time = time()) &&
        last_daylight =
        day_lights[query_daytime()] * season_factors[query_season()] +
        (query_timedep(td_day2) == "night" && moon_lights[query_moonphase()]);
  if (!room)
    return l;

  if (!room->query_property(P_OUTSIDE) && !room->query_property(P_DAYLIGHT))
    return 0;  // !

  if (room->query_property(P_INSIDE)) {               // inside with daylight
    if (room->query_property(P_UNDERGROUND))
      l = (l * LIGHT_F_UNDERGROUND) / 1000;
    else
      l = (l *  LIGHT_F_INSIDE) / 1000;
  } else {                                            // outside
    if (room->query_property(P_VILLAGE) &&            // Coogan, 05-Oct-99
        ((f = SE_TIME->query_day_time()) < 18000 ||   // earlier than 5 a.m.
         f > 72000)) {                                // or later then 8 p.m.
      l = (l * LIGHT_F_VILLAGE) / 1000;               // light from houses
    } else if (f = room->query_property(P_FOREST)) {
      if (f == TE_LIGHT)
        l = (l * LIGHT_F_FOREST_LIGHT) / 1000;
      if (f == TE_NORMAL)
        l = (l * LIGHT_F_FOREST_NORMAL) / 1000;
      if (f == TE_DENSE)
        l = (l * LIGHT_F_FOREST_DENSE) / 1000;
    } else if (f = room->query_property(P_DESERT)) {
      if (f == TE_ICE || f == TE_SNOW)
        l = (l * LIGHT_F_DESERT_ICE) / 1000;
      if (f == TE_SAND)
        l = (l * LIGHT_F_DESERT_SAND) / 1000;
      if (f == TE_ROCK)
        l = (l * LIGHT_F_DESERT_ROCK) / 1000;
    } else if (room->query_property(P_MOUNTAIN)) {    // mountain is ignored,
                                                      // if forest or desert
      l = (l * LIGHT_F_MOUNTAIN) / 1000;
    } else if (room->query_property(P_UNDER_WATER)) { // this excludes
      l = (l * LIGHT_F_UNDER_WATER) / 1000;           // everything else
    }
  }
  return l;
}

#if 1  // Coogan, 11-Apr-02
void announce_change(string suntime) {
  object *rooms;
  rooms = m_indices(mkmapping(map(users(), #'environment) - ({ 0 })));
  filter_objects(rooms, "notify_sun", suntime);
}

#else

varargs void announce_change(string suntime) {
  object *rooms;
  string mp, outside, inside, result;
  switch (suntime = suntime || query_suntime())
  {
  case "sunset":
    outside = "The last rays of the setting sun light up the western "
	      "horizon.\n";
    inside = "Outside, dusk is falling. It is getting darker.\n";
    break;
  case "dawn":
    outside = "A new "+query_season()+"-day dawns slowly in the east.\n";
    inside = "The night outside is slowly losing its darkness. "
	     "A new day is dawning.\n";
    break;
  case "sunrise":
    outside = "The rising sun appears over the eastern horizon, brightening"
	      " the day.\n";
    break;
  case "noon":
    outside = "The sun is reaching its zenith and will soon begin its "
	      "slow descent.\n";
    break;
  case "dusk":
    outside = "Now that the sun has set, it is getting dark much faster.\n";
    break;
  case "night":
    outside = "In the darkness of the night, ";
    switch (mp = query_moonphase())
    {
    case "new":
      outside += "you see that it is new moon.\n";
      break;
    default:
      outside += "a "+mp+" moon is standing in the sky.\n";
      break;
    }
    inside = "Night has fallen outside.\n";
    break;
  }
  // added m_indices(), Coogan, 10-Nov-99
  rooms = m_indices(mkmapping(map(users(),#'environment)-({0})));
  // changed to filter_objects by Ugh Mar-20-02
  filter_objects(rooms,"notify_sun",suntime,outside,inside);
}
#endif

