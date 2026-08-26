// When the daemon is restarted, we check the current clock time, and
// we set the game time appropriately. The GAME_START_TIME gives the
// beginning of the Universe in clock time: the other defines give
// the beginning of the Universe in game time. The daemon gets the
// current time from the driver and sets the current game time correctly.

#define START_TIME 0
#define START_DATE 1
#define START_MONTH 0
#define START_YEAR 100

// The given GAME START TIME is, in human units, 0:00:00, Jan 1, 1990.

#define START_GAME_TIME 631170000

// The file where the phases of the day are stored.

#define DAY_PHASE_FILE "/adm/etc/daytime.data"
#define NUM_DAY_PHASES 8

// The file where the weather data is stored.

#define WEATHER_FILE "/adm/etc/weather.data"
#define NUM_WEATHER 6

// The file where the names and lengths of the months are stored.

#define MONTH_FILE "/adm/etc/yeardates.data"
#define NUM_MONTHS 6

// The file for the moon phases.

#define MOON_FILE "/adm/etc/moon.data"
#define NUM_MOON_PHASES 8
#define MOON_PERIOD 28			// days

// The length of the day and the year in cycles. These need to match
// up to the phase lengths in DAY_PHASE_FILE and the length of the
// months in MONTH_FILE.
// As set up originally, the day is 2 hours and the year is 360 hours
// or 180 game days, or 15 real days.

#define DAY_LENGTH 7200
#define YEAR_LENGTH 1296000
