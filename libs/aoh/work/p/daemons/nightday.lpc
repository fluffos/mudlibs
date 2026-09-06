/* -------------------------------------------------------------------------
 * DAEMONPATH  nightday.c -- The night/day daemon
 *
 * Copyright (C) 1997 by One Step Beyond.
 * All Rights Reserved.
 * Permission granted for non-commercial use.
 * -------------------------------------------------------------------------
 * 1992-1994  [m]   Creation at Nightfall
 * 21-jun-97  [t]   New time states
 *                  QueryTimeString()
 * 15-jul-97  [t]   QuerySeasonString() + season names
 *                  started moving to external data format
 * 09-nov-97  [t]   little twiddles
 * 06-may-98  [t]   added QueryDate(), QuerySeason()
 * 13-may-99  [t]   Moved the Season Name defines from this 
 *                  file into /sys/nightday.h
 *
 */

#include <config.h>
#include <properties.h>
#include <weather.h>
#include <nightday.h>
#include <channel.h>
#include <daemons.h>

#define THIS              this_object()


inherit "/std/weather";   // central weather functions
inherit "/std/base";      // for the properties


/* ---------------------------------------------------------------------
 *  GetBaseData()
 * ---------------------------------------------------------------------
 *  This initializes the base data. The data is used by the global
 *  nightday object (this) as well as all the client objects.
 *
 *  NOTE: There is no reason to call this function in your own objects.
 *  Please use the other functions to query any information needed.
 * ---------------------------------------------------------------------
 */

public mixed GetBaseData()
{ 
  return ({
    ({ ND_NIGHT, 8580, ND_REL_STATE(ND_NIGHT, MAX_SUNBRIGHT), 0, 0, 0 }),
    ({ ND_PREDAWN, 900, ND_REL_STATE(ND_PREDAWN, MAX_SUNBRIGHT), 0, 0, 0 }),
    ({ ND_DAWN, 600, ND_REL_STATE(ND_DAWN, MAX_SUNBRIGHT), 0, 0, 0 }),
    ({ ND_SUNRISE, 600, ND_REL_STATE(ND_SUNRISE, MAX_SUNBRIGHT), 0, 0, 0 }),
    ({ ND_EARLY_MORNING, 2670, ND_REL_STATE(ND_EARLY_MORNING, 
       MAX_SUNBRIGHT), 0, 0, 0 }),
    ({ ND_LATE_MORNING, 4005, ND_REL_STATE(ND_LATE_MORNING, 
       MAX_SUNBRIGHT), 0, 0, 0 }),
    ({ ND_NOON, 2670, ND_REL_STATE(ND_NOON, MAX_SUNBRIGHT), 0, 0, 0 }),
    ({ ND_EARLY_AFTERNOON, 4005, ND_REL_STATE(ND_EARLY_AFTERNOON, 
       MAX_SUNBRIGHT), 0, 0, 0 }),
    ({ ND_LATE_AFTERNOON, 2670, ND_REL_STATE(ND_LATE_AFTERNOON, 
       MAX_SUNBRIGHT), 0, 0, 0 }),
    ({ ND_SUNSET, 600, ND_REL_STATE(ND_SUNSET, MAX_SUNBRIGHT), 0, 0, 0 }),
    ({ ND_TWILIGHT, 600, ND_REL_STATE(ND_TWILIGHT, MAX_SUNBRIGHT), 0, 0, 0 }),
    ({ ND_EVENING, 900, ND_REL_STATE(ND_EVENING, MAX_SUNBRIGHT), 0, 0, 0 })
  });
}


/* ------------------------------------------------------------------------
 *  InitStates()
 * ------------------------------------------------------------------------
 *  This initializes the global weather data .
 *  statedata is a global variable from /std/weather
 *-------------------------------------------------------------------------
 */

public void InitStates()
{
  // This is the global weather data:
  // ({ state, state length, relative sunbright, sky text, 
  //    change text, window text })

  object weatherobj;
  int x;

  statedata = GetBaseData();
 
  weatherobj = load_object(Query(P_WEATHER_DIR) + 
               Query(P_CURRENT_WEATHER_TYPE) );

  if(!weatherobj)
  {
    CHANNEL_D->SendStr("error", 
      "Error in loading weather description in nightday daemon",1); 
    destruct(THIS);
    return;
  }

  for(x = 0; x < ND_NO_STATES; x++)
  {
    statedata[x][WD_DESC] = ({string})weatherobj->GetSkyMessage(x);
    statedata[x][WD_CDESC] = ({string})weatherobj->GetChangeMessage(x);
    statedata[x][WD_WDESC] = ({string})weatherobj->GetWindowMessage(x);
  }

  destruct(weatherobj);
}


/* ------------------------------------------------------------------------
 *  IsDay()
 * ------------------------------------------------------------------------
 *  Returns true if the current daystate can be considered 'day', false if
 *  it's more or less night.
 * ------------------------------------------------------------------------
 */


public int IsDay()
{
  return -1 == member(({ND_NIGHT, ND_PREDAWN, ND_TWILIGHT, ND_EVENING}), 
               QueryState());
}

/* ------------------------------------------------------------------------
 *  QueryTimeString()
 * ------------------------------------------------------------------------
 *  Returns a string describing the time of day
 * ------------------------------------------------------------------------
 */

public mixed QueryTimeString()
{
  switch (QueryState()) 
  {
    case ND_NIGHT:            return "night";
    case ND_PREDAWN:          return "near dawn";
    case ND_DAWN:             return "dawn";
    case ND_SUNRISE:          return "sunrise";
    case ND_EARLY_MORNING:    return "early morning";
    case ND_LATE_MORNING:     return "late morning";
    case ND_NOON:             return "midday";
    case ND_EARLY_AFTERNOON:  return "early afternoon";
    case ND_LATE_AFTERNOON:   return "late afternoon";
    case ND_SUNSET:           return "sunset";
    case ND_TWILIGHT:         return "twilight";
    case ND_EVENING:          return "evening";
  }
  return 0;
}

/* --------------------------------------------------------------------
 *  QuerySeasonString()
 * --------------------------------------------------------------------
 *  Returns a string with the name of the season
 * --------------------------------------------------------------------
 */

public string QuerySeasonString()
{
  switch( Query(P_SEASON))
  {
     case WINTER: return WINTER_NAME;  break;
     case SPRING: return SPRING_NAME;  break;
     case SUMMER: return SUMMER_NAME;  break;
     case AUTUMN: return AUTUMN_NAME;  break;
  }
  return "";
}

/* --------------------------------------------------------------------
 *  QuerySeason()
 * --------------------------------------------------------------------
 *  Returns an int indicating the season.
 *  defined in /sys/nightday.h:
 *  WINTER 1, SPRING 2, SUMMER 3, AUTUMN 4
 * --------------------------------------------------------------------
 */

public int QuerySeason()
{
  return Query(P_SEASON, 1);
}

/* ------------------------------------------------------------------------
 *   QueryDate()
 * ------------------------------------------------------------------------
 *   Returns an array describing the osb date
 *   Format is:  ({ int day, string "so-called month", string "season" })
 *   looks like ({ 12, "Early", "Great Heat" })
 *
 *   Time in OSB is structured as follows:
 *   3 osb days to every RL day, 4 OSB years to every
 *   RL year. 4 seasons to every OSB year.
 *   Every season has three sections, Early, High and
 *   Late. Average 30 OSB days per season section.
 * ------------------------------------------------------------------------
 */
 
public mixed QueryDate()
{
   int day, hour;
   string cdate, turn, season;
   
   cdate = ctime(time());
   day = (atoi(cdate[8..9]) - 1) * 3;  // nr of osb days up to day before today
   hour = atoi(cdate[11..12]);
   day += (hour/DAY_LENGTH + 1) ;
   
   // returns "early", "high", "late"
   switch( day/31 )
   {
      case 0: turn = "Early";  break;
      case 1: turn = "High";   break;
      case 2: turn = "Late";   break;
   }
   
   season = QuerySeasonString();
   
   return ({ ( day % 31 + 1 ), turn, season });
}

/* ------------------------------------------------------------------------
 *  PRIVATE SeasonName()
 * ------------------------------------------------------------------------
 *  Used internally to calculate the OSB date in correlation to 
 *  the RL date.
 * ------------------------------------------------------------------------
 */
 
private int SeasonName()
{
  switch(ctime()[4..6])
  {

    case "Jan":
    case "May":
    case "Sep": return WINTER;

    case "Feb":
    case "Jun":
    case "Oct": return SPRING;

    case "Mar":
    case "Jul":
    case "Nov": return SUMMER;

    case "Apr":
    case "Aug":
    case "Dec": return AUTUMN;
  }
  return SUMMER;
}

/* -----------------------------------------------------------------------
 *   Create()
 * -----------------------------------------------------------------------
 */

public void create () 
{

  string *wtype;


  if (object_name(THIS) != NIGHTDAY)
  {
    CHANNEL_D->SendStr("error", 
      "Can't inherit or clone the nightday server", 1);
    destruct(THIS);
    return;
  }

  base::create();
  seteuid(getuid(THIS));

  Set(P_WEATHER_DIR, GLOBAL_W_DIR);

  Set(P_WEATHER_TYPES, 
     ([ WINTER: ({ WT_SUN }), 
        SPRING: ({ WT_SUN }), 
        SUMMER: ({ WT_SUN }), 
        AUTUMN: ({ WT_SUN })  ]) ); 


  Set(P_SEASON, SeasonName());

  // The '||({WT_SUN})' serves as a safe-guard in case of init errors.
  wtype = Query(P_WEATHER_TYPES)[SeasonName()] || ({ WT_SUN });
  Set(P_CURRENT_WEATHER_TYPE, random_select(wtype) );
      
  weather::create();
}

/***************************************************************************/



