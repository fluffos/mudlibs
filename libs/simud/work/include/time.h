/*** Include this file when playing with the localtime() func. ***/

#define TM_SEC		0	// Seconds (0..59)
#define TM_MIN		1	// Minutes (0..59)
#define TM_HOUR		2	// Hours (0..23)
#define TM_MDAY		3	// Day of the month (1..31)
#define TM_MON		4	// Month (0..11)
#define TM_YEAR		5	// Year (4 digit)
#define TM_WDAY		6	// Day of the week (Sun = 0)
#define TM_YDAY		7	// Day of the year (0..365)
#define TM_ISDST	8	// is daylight savings time or not?

#define TM_WDAY_STR	({"sunday","monday","tuesday","wednesday",\
			  "thursday","friday","saturday"})
#define TM_MON_STR	({"january","february","march","april","may","june",\
			  "july","august","september","november","december"})
