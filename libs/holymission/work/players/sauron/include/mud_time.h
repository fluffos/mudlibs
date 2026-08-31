#ifndef __MUDTIME_H__

#define __MUDTIME_H__

// General time calculation defs.
// The CONV def is calculated such that, at the moment when the RL time
// (according to the mud) is "Sat Jan  1 00:00:00 2000", the mud time will
// be "Sat Jan  1 00:00:00 1500". Note also that mud time passes by four
// times as fast as RL time.

#define FACTOR		4		// Number of mud secs per RL sec.
#define LENGTH_DAY	86400/FACTOR	// Length of one mud day.
#define LENGTH_HOUR	3600/FACTOR	// Length of one mud hour.
#define LENGTH_MINUTE	60/FACTOR	// Length of one mud minute.

#define YEAR_2000	946681200	// Value of time() at beginning
                                        // of year 2000.
#define CONV		710010900	// Conversion value to make
                                        // ctime() give the correct
                                        // output. Calculation is:
                                        // YEAR_2000 * (FACTOR-1)/FACTOR.

// Defs for the 'phase' fo the day. Used by time_of_day() etc...
#define DAY		0
#define MORNING		1
#define EVENING		2
#define NIGHT		3

// Defs for the season. Used by query_season() etc...
#define WINTER		1
#define SPRING		2
#define SUMMER		3
#define AUTUMN		4

// Defs for the standard light events.
#define DAWN		(5*LENGTH_HOUR)
#define SUNRISE		(6*LENGTH_HOUR)
#define SUNSET		(18*LENGTH_HOUR)
#define DUSK		(19*LENGTH_HOUR)

varargs mixed query_season(int iFlag);

/*
 * These four functions return the mud-times at which the different
 * light-changing events occur. The times vary based on season.
 */

int dawn() {
    switch(query_season()) {
        case WINTER:
            return DAWN+LENGTH_HOUR;
            break;
        case SUMMER:
            return DAWN-LENGTH_HOUR;
            break;
        default:
            return DAWN;
            break;
    }
}

int sunrise() {
    switch(query_season()) {
        case WINTER:
            return SUNRISE+LENGTH_HOUR;
            break;
        case SUMMER:
            return SUNRISE-LENGTH_HOUR;
            break;
        default:
            return SUNRISE;
            break;
    }
}

int sunset() {
    switch(query_season()) {
        case WINTER:
            return SUNSET-LENGTH_HOUR;
            break;
        case SUMMER:
            return SUNSET+LENGTH_HOUR;
            break;
        default:
            return SUNSET;
            break;
    }
}

int dusk() {
    switch(query_season()) {
        case WINTER:
            return DUSK-LENGTH_HOUR;
            break;
        case SUMMER:
            return DUSK+LENGTH_HOUR;
            break;
        default:
            return DUSK;
            break;
    }
}

/*
 * This function actually calculates the time of day. The optional flag
 * can be used to control the return value as follows:
 *   flag
 *   ----
 *     0        The value represents the number of mud seconds since
 *              midnight for that mud day.
 *     1        The value will return an integer relating to the 'phase'
 *              of the day (morning, day, evening or night).
 *     2+       The value is used by the mud_time() function to create a
 *              string representation of the mud time.
 */

varargs int time_of_day(int iFlag) {
    int iTime;

    if(iFlag == 1) {
        iTime = time_of_day();
        if(iTime >= sunrise() && iTime < sunset())
            return DAY;
        else if(iTime >= dawn() && iTime < sunrise())
            return MORNING;
        else if(iTime >= sunset() && iTime < dusk())
            return EVENING;
        else if(iTime >= dusk() || iTime < dawn())
            return NIGHT;
    }
    else {
#if 0
        iTime = time()-(TIME_DIFF*LENGTH_HOUR);
#endif
        if(iTime < CONV)
            return 0;
        else {
            iTime -= CONV;
            iTime *= FACTOR;
            if(!iFlag)
                iTime %= LENGTH_DAY;

            return iTime;
        }
    }
}

/*
 * This function returns a string representation of the mud-time,
 * including month, date and year.
 */

string mud_time() {
    string sRet;
    int iTime;

    iTime = time_of_day(2);
    if(!iTime)
        return "Unknown";
    else {
        sRet = ctime(iTime);
        if(sRet[<3..<3] == "9")
            sRet[<3..<3] = "4";
        else
            sRet[<4..<3] = "15";
        return sRet;
    }
}

/*
 * The next five functions handle the current season. The season is
 * found by looking at the string representation of the current time.
 */

varargs mixed query_season(int iFlag) {
    switch(mud_time()[4..6]) {
        case "Dec":
        case "Jan":
        case "Feb":
            if(iFlag == 2)
                return "Winter";
            else if(iFlag)
                return "winter";
            else
                return WINTER;
            break;
        case "Mar":
        case "Apr":
        case "May":
            if(iFlag == 2)
                return "Spring";
            else if(iFlag)
                return "spring";
            else
                return SPRING;
            break;
        case "Jun":
        case "Jul":
        case "Aug":
            if(iFlag == 2)
                return "Summer";
            else if(iFlag)
                return "summer";
            else
                return SUMMER;
            break;
        case "Sep":
        case "Oct":
        case "Nov":
            if(iFlag == 2)
                return "Autumn";
            else if(iFlag)
                return "autumn";
            else
                return AUTUMN;
            break;
        default:
            return 0;
            break;
    }
}

int query_winter() {
    return query_season() == WINTER;
}

int query_spring() {
    return query_season() == SPRING;
}

int query_summer() {
    return query_season() == SUMMER;
}

int query_autumn() {
    return query_season() == AUTUMN;
}

/*
 * The last four functions are really just convenience functions for
 * checking the current day 'phase'.
 */

int query_day() {
    return time_of_day(1) == DAY;
}

int query_morning() {
    return time_of_day(1) == MORNING;
}

int query_evening() {
    return time_of_day(1) == EVENING;
}

int query_night() {
    return time_of_day(1) == NIGHT;
}

#endif // __MUDTIME_H__
