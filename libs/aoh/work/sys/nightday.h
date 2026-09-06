#ifndef NIGHTDAY_H
#define NIGHTDAY_H 1

#define NIGHTDAY            DAEMONPATH "nightday"
#define SHORENIGHTDAY       DAEMONPATH "shorenightday"


// --------------------------------------------------------------------
// the day states (plus description and amount of sunlight)
// --------------------------------------------------------------------

#define ND_NIGHT            0   // Full night [0%]
#define ND_PREDAWN          1   // Almost dawn, glow on horizon [10%]
#define ND_DAWN             2   // Morning dawns [20%]
#define ND_SUNRISE          3   // Sun above the horizon [40%]
#define ND_EARLY_MORNING    4   // Almost full light (6am-8am) [70%]
#define ND_PRENOON          4   // Almost full light (6am-8am) [70%]
#define ND_LATE_MORNING     5   // (8am-11am) full light [100%]
#define ND_NOON             6   // Midday, (11am-1pm)
#define ND_DAY              6   // Midday, (11am-1pm)
#define ND_EARLY_AFTERNOON  7   // Still full light (1pm-4pm)
#define ND_POSTNOON         7   // Still full light (1pm-4pm)
#define ND_LATE_AFTERNOON   8   // Late afternoon (4pm-6pm) [70%]
#define ND_PREFALL          8   // Late afternoon (4pm-6pm) [70%]
#define ND_SUNSET           9   // Sun goes down [40%]
#define ND_TWILIGHT         10  // Sun is down, glow on horizon [20%]
#define ND_FALL             10  // Sun is down, glow on horizon [20%]
#define ND_EVENING          11  // Last light fades [10%]
#define ND_PRENIGHT         11  // Sun goes down [40%]

#define ND_NO_STATES 12

// --------------------------------------------------------------------
// Compute an absolute day state <s> into a relative day state of (0..m)
// --------------------------------------------------------------------

#define ND_REL_STATE(s,m) (({0,10,20,40,80,100,100,100,80,40,20,10})[s]*(m)/100)


// --------------------------------------------------------------------
// The TimeMsg property for rooms
// --------------------------------------------------------------------

#define DAY_DEFAULT_MSG    "DayDefaultMsg"
#define NIGHT_DEFAULT_MSG  "NightDefaultMsg"


// --------------------------------------------------------------------
// Seasons
// --------------------------------------------------------------------

#define WINTER              1
#define SPRING              2
#define SUMMER              3
#define AUTUMN              4

// --------------------------------------------------------------------
// Seasons Names
// --------------------------------------------------------------------

#define WINTER_NAME       "Darkfrost"
#define SPRING_NAME       "Awakening"
#define SUMMER_NAME       "Great Heat"
#define AUTUMN_NAME       "Harvest Moons"


// --------------------------------------------------------------------
// for the new-not-yet-installed-i'm-still-playing-with-it w server
// --------------------------------------------------------------------

#define P_WEATHER_TYPES   "WeatherTypes"

// TODO - move this to weather.h

#define WT_SUN                   "sun"
#define WT_RAIN                  "rain"
#define WT_FOG                   "fog"

#define GLOBAL_W_DIR             "/p/daemons/weather/types/"
#define P_WEATHER_DIR            "WeatherDir"
#define P_CURRENT_WEATHER_TYPE   "CurrentWeatherType"
#define P_SEASON                 "Season"

#endif
