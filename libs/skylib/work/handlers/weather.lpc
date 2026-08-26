/**
 * An attempt at a new weather handler for Discworld.
 * Ceres@Discworld 14/4/96
 *
 * Having thought about the way weather works (and Discworlds interesting
 * meteorology) I decided not to try and implement some model of realworld
 * weather. Instead regional variations in weather are handled by
 * regional climate properties. This system will handle diurnal and seasonal
 * variations and that's about it. Hopefully that will make it more
 * understandable, usable and efficient.
 *
 * Basic Operation
 * ---------------
 * The weather is based on weather 'pattern's. The pattern lasts for several
 * hours and is calculated from the 'seasonal' norm and the 'variance'. The
 * 'current' weather will tend towards the pattern weather. The actual weather
 * in a room will depend on the current weather, local modifiers
 * (climate property), diurnal variations and variance.
 *
 * Thus update_pattern() is called once every reboot (for the moment) and
 * update_weather() is called every 5 minutes (UPDATE_SPEED).
 *
 * Decisions
 * ---------
 * Calculation of the general weather has been moved into
 * update_weather. Rather than doing it on a room by room basis everytime
 * someone looks! Instead, local climate controls will be added verbatim to
 * the current global weather. This will improve efficiency massively, but will
 * reduce the overall weather variations.
 *
 * Principles
 * ----------
 * Temperature should go down during winter and during the night.
 * Clouds should increase during the winter.
 * Wind should be higher during autumn and winter (I guess).
 * Rain/sleet/snow will depend on cloud density and temperature.
 * If it's windy and lots of cloud density we might get a thunder storm.
 * Cloud cover should lower temperature as should wind.
 *
 * Changed Jun 3 1996 by Grampa to include weather notifications for rooms.
 * Changed to Dediscify it Shaydz 2001
 */

inherit OBJECT_OBJ;

#include <climate.h>
#include <time.h>

#define FILE_NAME "/save/weather"
#define UPDATE_SPEED 300
#define CYCLE_SPEED  3600
#define DIY 400

// return the difference between two numbers.
#define DIF(x, y) (x > y) ? (x-y) : (y-x)

// this is the basic state of the weather. The local climate properties are
// then applied to these numbers, followed by the time of day and year to
// give us the actual weather right now.

// temp is the temperature in celcius.
// cloud is the amount of cloud cover. 100 is total cloud cover. >100 the
//          cloud gets denser and denser. Denser cloud makes rain more likely.
// windsp is the wind speed in mph.

// underlying temp etc.
int *pattern;

// the current global values of temp etc.
int *current;

// how much global variance do we want?
int *variance;

// only used for statistics printing of seasonal values
nosave int *sstats;

// Rooms to notify about weather changes.
// Keys are rooms, values are notification values.  Used so there will be
// no duplicates.
nosave mapping rooms;

nosave int lastupdate, day;
nosave int sunrise, sunset, toy;
int mooncycle, moonupdate;

void set_day();
void update_pattern();
int calc_actual(object env, int type);
int cloud_index(object env);
int query_rain_type(int temp, int rain);
string sun_direction(int which);

/** @ignore yes */
void setup() {
    set_name("weather");
    set_short("weather controller extraordinaire");
    set_long("The weather controller, at least this one is always right!\n");

    rooms = ([ ]);

    unguarded( (: restore_object, FILE_NAME :) );

    if( !pattern )
        pattern = ({ 0, 0, 0 });
    if( !current )
        current = ({ 0, 0, 0 });
    if( !variance )
        variance = ({ 10, 75, 20 });
    if( !sstats )
        sstats = ({ 0, 0, 0 });

    call_out("update_weather", UPDATE_SPEED );
    set_day();
    update_pattern();

} /* setup() */

/**
 * This method is called by the room object when it is dested.
 * It will delete it from the rooms mapping.
 */
void room_dested() {
    if( PO )
        map_delete( rooms, PO );
} /* room_dested() */

/**
 * Add a room to the list of rooms to notify about weather.  Notifications
 * are an ORed (|) combination of the #defines in /include/climate.h
 * IE: To inform about temperature and rain changes, call
 * weather_notify( room, (NOTIFY_TEMPERATURE | NOTIFY_RAIN) );
 * @param which_room the room to be notified
 * @param notifications a bitmap of notifications
 * @return success or failure (1 or 0)
 */
int weather_notify( object which_room, int notifications ) {
    if( !which_room || notifications < 0 || notifications >
        ( NOTIFY_TEMPERATURE | NOTIFY_CLOUD | NOTIFY_RAIN | NOTIFY_DAY ) ) {
        return 0;
    }

    rooms[which_room] = notifications;
    return 1;

} /* weather_notify() */

/** @ignore yes */
void test_notifications() {
    object room;
    string w;

    foreach( room in keys(rooms) ) {
        w = sprintf("%O notified of %s%s%s%s\n", room,
            ( ( rooms[room] & NOTIFY_TEMPERATURE ) ? "Temperature " : ""),
            ( ( rooms[room] & NOTIFY_CLOUD ) ? "Clouds " : ""),
            ( ( rooms[room] & NOTIFY_RAIN ) ? "Rain " : ""),
            ( ( rooms[room] & NOTIFY_DAY ) ? "Day" : "") );
        write( w );
    }

    write("test_notifications() done\n");

} /* test_notifications() */

/**
 * Find out which day of the Disc (common) year it is.
 * @return the day of the year.
 */
int day_number() {
    return ( time() % SECONDS_PER_YEAR ) / SECONDS_PER_DAY;
} /* day_number() */

/**
 * Find out which minute of the day (0 - 1439) it is.
 * @return the minute.
 */
int minute_number() {
    return ( time() % SECONDS_PER_DAY ) / SECONDS_PER_MINUTE;
} /* minute_number() */

/**
 * Get the appropriate moon string. This is almost completely from the old
 * system. I don't understand the moon.
 * @param env the room to check
 * @return the moon string.
 */
string query_moon_string( object env ) {
    string str;

    if( mooncycle > 10 )
        return "It is night and there is no moon.\n";

    if( calc_actual( env, CLOUD ) > 70 )
        str = "It is night and the %s is hidden by the clouds.\n";
    else
        str = "The land is lit up by the eerie light of the %s.\n";

    return sprintf( str, ({
        "waxing crescent moon",
        "waxing quarter moon",
        "waxing half moon",
        "waxing three quarter moon",
        "waxing gibbous moon",
        "full moon",
        "waning gibbous moon",
        "waning three quarter moon",
        "waning half moon",
        "waning quarter moon",
        "waning crescent moon",
        "no moon",
        "no moon",
        "no moon",
        })[mooncycle] );

} /* query_moon_string() */

/** @ignore yes */
int query_moon_state() {
    if( mooncycle < 6 )
        return mooncycle+1;
    if( mooncycle < 11 )
        return 11 - mooncycle;
    return 0;
} /* query_moon_state() */

/**
 * Find out which phase of the moon we're currently in.
 * @return a string for the phase of the moon.
 */
string query_moon_phase() {
    return ({
        "crescent",
        "quarter",
        "half",
        "three quarter",
        "gibbous",
        "full",
        "gibbous",
        "three quarter",
        "half",
        "quarter",
        "crescent",
        "",
        "",
        "",
        })[mooncycle];

} /* query_moon_phase() */

/**
 * Return which of the 4 seasons we are in.
 * @return spring, summer, autumn or winter.
 */
string query_season() {
    switch( day_number() ) {
    case 81..173:
      return "spring";
    case 174..266:
      return "summer";
    case 267..359:
      return "autumn";
    default:
      return "winter";
    }
} /* query_season() */

/**
 * Return a string for the period of the day
 * @return night, morning, midday, afteroon or evening.
 */
string query_tod() {
    if( minute_number() < sunrise || minute_number() > sunset )
        return "night";

    switch( minute_number() ) {
      case 0..700:
        return "morning";
      case 701..740:
        return "midday";
        break;
      case 741..1080:
        return "afternoon";
        break;
      default:
        return "evening";
    }

} /* query_tod() */

/** @ignore yes */
int query_day() { return day; }

/**
 * This method returns percentage of light.
 * It should be dependant on the base amount of light, day or night time
 * and cloud cover.
 * @param the room
 * @return a percentage
 */
int query_darkness( object env ) {
    int result, cloud;

    result = 10;

    if( day == 10 )
        return 100;

    if( mooncycle <= 10 ) {
        if( mooncycle < 6 )
            result += mooncycle * 10;
        else
            result += ( 5 - ( mooncycle % 6 ) ) * 10;
    }

    // now reduce this for cloud cover
    if( ( cloud = cloud_index(env) ) > 0 )
        result -= cloud_index(env) / 15;
    if( result < 0 )
        result = 0;

    if( day > 0 )
        result += ( 100 - result ) / ( 10 - day );

    return result;

} /* query_darkness() */

/** @ignore yes */
int calc_actual( object env, int type ) {
    int *clim;

    if( !env )
        return current[type];

    if( clim = (int *)env->query_property("climate") )
        return current[type] + clim[type];

    return current[type];

} /* calc_actual() */

/** @ignore yes */
int temperature_index( object env ) {
    int temp, tod, j;

    temp =  calc_actual( env, TEMP );

    // add diurnal variations to temperature

    // gives us a number between 0 (midday) and 10 (night)
    tod = 10 - day;

    // subtract from the temperature dependant on time of day and variance.
    temp -= variance[TEMP] * tod / 10;

    // lower temperature dependant on cloud cover
    j = sqrt( current[CLOUD] );

    if( j < 0 )
        j = 0;

    // when its cold clouds tend to raise the temperature at night
    // when its hot clouds tend to decrease the temperature during the day
    if( temp < 10 && tod == 10 )
        temp += j;
    else if( temp > 10 && !tod )
        temp -= j;

    // lower temperature dependant on wind speed
    if( ( j = sqrt(current[WINDSP]) ) > 0 )
        temp -= j;

    return temp;

} /* temperature_index() */

/** @ignore yes */
int cloud_index(object env) { return calc_actual( env, CLOUD ); }

/** @ignore yes */
int rain_index( object env ) {
    int rain;

    rain = calc_actual( env, CLOUD ) - ( calc_actual( env, TEMP ) / 2 ) - 100;

    return ( rain > 0 ? rain : 0 );

} /* rain_index() */

/**
 * Return a temperature string equating to the temperature passed
 * @param int The temperature in Celcius
 * @return string a temperature string.
 */
string temp_string( int temp ) {
    switch( temp ) {
      case 51..1000: return "incredibly, unbelievably hot";
      case 46..50: return "amazingly hot";
      case 41..45: return "damn hot";
      case 36..40: return "very hot";
      case 31..35: return "hot";
      case 26..30: return "reasonably hot";
      case 23..25: return "very warm";
      case 20..22: return "warm";
      case 16..19: return "pleasantly warm";
      case 13..15: return "cool";
      case 10..12: return "slightly chilly";
      case 7..9: return "chilly";
      case 4..6: return "very chilly";
      case 1..3: return "cold";
      case -3..0: return "very cold";
      case -10..-4: return "freezing cold";
      case -20..-11: return "damn cold";
      case -30..-21: return "dangerously cold";
      case -50..-31: return "incredibly, unbelievably cold";
    }

} /* temp_string() */

/** @ignore yes
 * creates the weather string which is put into room descs.
 */
varargs string weather_string( object env, string obscured ) {
    int temp, cloud, wind, rain, rt;
    int *warray;
    string str;

    if( !env )
        return 0;

    temp = temperature_index(env);
    cloud = cloud_index(env);
    wind = calc_actual(env, WINDSP);
    rain = rain_index(env);

    if( function_exists("room_weather", env ) &&
        !catch( warray = (int *)env->room_weather( temp, cloud, wind,
        rain ) ) ) {
        temp = warray[0];
        cloud = warray[1];
        wind = warray[2];
        rain = warray[3];
    }

    rt = query_rain_type( temp, rain );

    str = "It is "+add_a(temp_string(temp))+" "+query_season()+" "+
          query_tod()+" with ";

    switch( wind ) {
      case -1000..5: str += "almost no wind"; break;
      case 6..10: str += "a gentle breeze"; break;
      case 11..15: str += "a steady breeze"; break;
      case 16..20: str += "a strong breeze"; break;
      case 21..30: str += "a steady wind"; break;
      case 31..40: str += "gusty winds"; break;
      case 41..50: str += "strong winds"; break;
      case 51..60: str += "gale-force winds"; break;
      case 61..1000: str += "storm-force winds"; break;
      default: str += "no wind at all"; break;
    }

    if( !obscured ) {
        if( rain )
            str += ", ";
        else
            str += " and ";

        switch( cloud ) {
          case -1000..5: str += "a beautifully clear sky"; break;
          case 6..10: str += "a few high level cirrus clouds"; break;
          case 11..25: str += "scattered puffy clouds"; break;
          case 26..40: str += "some puffy clouds"; break;
          case 41..60: str += "many puffy clouds"; break;
          case 61..80: str += "medium cloud cover"; break;
          case 81..110: str += "dense cloud cover"; break;
          case 111..130: str += "packed cloud cover"; break;
          case 131..160: str += "thick black clouds"; break;
          case 161..1000: str += "thick heavy storm clouds"; break;
        }
    }

    if( rain ) {
        str += " and ";
        switch( rain ) {
          case -1000..20: str += "light"; break;
          case 21..40:
            if( wind < 20 )
                str += "steady";
            else
                str += "driving";
          break;
          case 41..60:
            str += "heavy"; break;
          case 61..500:
            if( rt == 3 )
                str += "torrential";
            else
                str += "very heavy";
          break;
        }
        str += " "+({"", "snow", "sleet", "rain"})[rt];
    }

    if( obscured )
        str += ".  "+obscured;

    if( rain > 20 && wind > 30 ) {
        if( obscured )
            str += ".\nPeals of thunder echo overhead";
        else
            str += ".\nPeals of thunder and streaks of lightning rend the "
                "sky";
    }

    return str;

} /* weather_string() */

/** @ignore yes */
int next_update() {
    return lastupdate + UPDATE_SPEED;
} /* next_update() */

/** @ignore yes */
void dest_me() {
    unguarded( (: save_object, FILE_NAME :) );
    ::dest_me();
} /* dest_me() */

/** @ignore yes */
int query_rain_type( int temp, int rain ) {
    int type;

    if( rain > 0 )
        switch(temp) {
          case -1000..-2: type = 1; break;
          case -1..3: type = 2; break;
          case 4..1000: type = 3; break;
        }
    else
        type = 0;

    return type;

} /* query_rain_type() */

/**
 * Find out if its snowing in a given room.
 * @param env the room
 * @return 1 or 0 for true or false.
 */
int query_snowing( object env ) {
    int *warray;

    if( function_exists("room_weather", env ) &&
        !catch( warray = (int *)env->room_weather( temperature_index(env),
        cloud_index(env), calc_actual(env, WINDSP), rain_index(env) ) ) ) {
        return query_rain_type( warray[0], warray[3] ) == 1;
    }

    return query_rain_type( temperature_index(env), rain_index(env)) == 1;

} /* query_snowing() */

/**
 * Find out if its raining in a given room.
 * @param env the room
 * @return 1 or 0 for true or false.
 */
int query_raining( object env ) {
    int *warray;

    if( function_exists("room_weather", env ) &&
        !catch( warray = (int *)env->room_weather( temperature_index(env),
        cloud_index(env), calc_actual(env, WINDSP), rain_index(env) ) ) ) {
        return query_rain_type( warray[0], warray[3] ) > 1;
    }

    return query_rain_type( temperature_index(env), rain_index(env) ) > 1;

} /* query_raining() */

/**
 * Find out the temperature of a given room.
 * @param env the room
 * @return a temperature in Celcius
 */
int query_temperature(object env) {
    int *warray;

    if( function_exists("room_weather", env ) &&
        !catch( warray = (int *)env->room_weather( temperature_index(env),
        cloud_index(env), calc_actual(env, WINDSP), rain_index(env) ) ) ) {
        return warray[0];
    }

    return temperature_index(env);

} /* query_temperature() */

/**
 * Find out the cloud cover of a given room.
 * @param env the room
 * @return an open ended percentage. Greater than 100 means heavier cover.
 */
int query_cloud( object env ) {
    int *warray;

    if( function_exists("room_weather", env ) &&
        !catch( warray = (int *)env->room_weather( temperature_index(env),
        cloud_index(env), calc_actual(env, WINDSP), rain_index(env) ) ) ) {
        return warray[1];
    }

    return cloud_index(env);

} /* query_cloud() */

/**
 * Find out the wind speed in a given room.
 * @param env the room
 * @return the wind speed in miles per hour.
 */
int query_windsp( object env ) {
    int *warray;

    if( function_exists("room_weather", env ) &&
        !catch( warray = (int *)env->room_weather( temperature_index(env),
        cloud_index(env), calc_actual(env, WINDSP), rain_index(env) ) ) ) {
        return warray[2];
    }

    return calc_actual( env, WINDSP );

} /* query_windsp() */

/** @ignore yes */
int calc_variance( int type, int seasonal ) {
    int diff, ret;

    diff = seasonal - pattern[type];
    if( diff < 0 )
        ret = -random( -diff * 2 );
    else
        ret = random( diff * 2 );

    if( random(2) )
        ret += random( variance[type] );
    else
        ret -= random( variance[type] );

    return ret;

} /* calc_variance() */

/**
 * Find out when sunrise will be on a given day of the year.
 * @param doy Day of the Discworld common year.
 * @return sunrise time (in seconds past midnite).
 */
int query_sunrise( int doy ) {
    int tmp;

    tmp = ( doy < ( DIY / 2 ) ) ? doy : ( DIY / 2 ) - ( doy % ( DIY / 2 ) );
    // 6am is the base sunrise time.
    return ( 6 * MINUTES_PER_HOUR ) + ( 100 - tmp );

} /* query_sunrise() */

/**
 * Find out when sunset will be on a given day of the year.
 * @param doy Day of the Discworld common year.
 * @return sunset time (in seconds past midnite).
 */
int query_sunset( int doy ) {
    int tmp;

    tmp = ( doy < ( DIY / 2 ) ) ? doy : ( DIY / 2 ) - ( doy % ( DIY / 2 ) );
    // 8pm is the base sunset time.
    return ( 20 * MINUTES_PER_HOUR ) - ( 100 - tmp );

} /* query_sunset() */

// basic system is for a 6am sunrise and 6pm sunset.
// Days get longer until midsummer and shorter after it.
// I guess it's not really sunrise or sunset it's when it gets dark/light.
/** @ignore yes */
void set_day() {
    int min, tmp;

    // Time of year. Climbs to 200 at mid-summer and then falls to year end
    tmp = day_number(); // The number of the day.
    min = minute_number(); // The minute of the day.
    sunrise = query_sunrise( tmp );
    sunset  = query_sunset( tmp );

    if( min <= sunrise || min >= sunset )
        day = 0;
    else {
        // as it nears sunrise or sunset the light should fail so have the day
        // value drop in the last 100 minutes.
        if( min > sunrise && min < sunrise + 30 )
            day = (min-sunrise) / 3;
        else if( min < sunset && min > sunset - 30 )
            day = (sunset-min) / 3;
        else
            day = 10;
        if( day < 1 )
            day = 1;
    }

} /* set_day() */

/**
 * @ignore yes
 * Change the current weather of type TYPE so that it becomes more
 * like the pattern.
 */
void migrate( int type ) {
    int diff;

    diff = pattern[type] - current[type];
    if( diff > variance[type] / 2 )
        diff = variance[type] / 2;

    if( diff < 0 )
        current[type] -= random(random(-diff));
    else
        current[type] += random(random(diff));

} /* migrate() */

int check_umbrella( object ob ) {
    return ( ob ? (int)ob->query_property("umbrella") : 0 );
} /* check_umbrella() */

/**
 * @ignore yes
 * Send weather events to users.
 */
void do_inform( object who, int old_temp, int old_cloud, int old_rain,
                int old_day ) {
    string str;
    int new_temp, new_cloud, new_wind, new_rain;
    int old_rain_type, new_rain_type;
    int *warray;

    new_temp = temperature_index(environment(who));
    new_rain = rain_index(environment(who));
    new_wind = calc_actual(environment(who), WINDSP);
    new_cloud = cloud_index(environment(who));

    if( function_exists("room_weather", ENV(who) ) &&
        !catch( warray = (int *)ENV(who)->room_weather( new_temp, new_cloud,
        new_wind, new_rain ) ) ) {
        new_temp = warray[0];
        new_cloud = warray[1];
        new_wind = warray[2];
        new_rain = warray[3];
    }

    old_rain_type = query_rain_type(old_temp, old_rain);
    new_rain_type = query_rain_type(new_temp, new_rain);

    str = "";

    // sunrise and set messages.
    // this test not needed, but should improve efficiency.
    if( day != old_day ) {
        if( old_day == 10 && day < 10 )
            str += "The sun starts to set slowly on the eastern horizon.\n";
        if( old_day > day && day < 9 && day > 0 )
            str += "The sun sinks further below the eastern horizon.\n";
        if( old_day > 0 && !day )
            str += "The sun disappears from view below the eastern horizon.\n";
        if( day > 0 && !old_day )
            str += "The western sky starts to lighten as the sun peeks over "
                "the horizon.\n";
        if( day == 10 && old_day < 10 )
            str += "The sun rises above the western horizon and greets you "
                "for a new day.\n";
        if( day > old_day && day < 9 && day > 0 )
            str += "The sun rises further above the western horizon "
                "lightening the sky as morning arrives.\n";
    }

    // clouds hiding the sun messages
    // in the 25-60 region the sun comes and goes quite a lot.
    if( day && old_cloud != new_cloud ) {
        if( old_cloud < 60 && new_cloud > 20 && !( new_cloud % 2 ) )
            str += "The "+query_tod()+" sun disappears behind a cloud.\n";
        else if( old_cloud > 20 && new_cloud < 60 && ( new_cloud % 2 ) )
            str += "The "+query_tod()+" sun peeks out from behind a cloud.\n";
    }

    // rain change messages.
    if( old_rain_type != new_rain_type ) {
        str += ({"", "It has stopped snowing", "It has stopped sleeting",
                 "It has stopped raining"})[old_rain_type];
        if( old_rain_type && new_rain_type )
            str += " and started ";
        else if( new_rain_type )
            str += "It has started ";
        str += ({"", "snowing", "sleeting", "raining"})[new_rain_type]+".\n";
    } else if( new_rain_type > 0 )
        str += "The "+({"", "snow", "sleet", "rain"})[new_rain_type]+
            " continues to fall.\n";

    // get them wet.
    if( new_rain_type )
        if( ( !sizeof( filter( who->query_holding(), "check_umbrella", TO ) ) &&
            !sizeof( filter( who->query_wearing(), "check_umbrella", TO ) ) ) ||
            !random(50) ) {
            if( !creatorp(who) && !who->query_property("no wet") )
                who->add_effect("/std/effects/other/wetness",
                    ( ( new_rain * new_rain_type ) / 2 ) *
                    ( UPDATE_SPEED / 60 ) );
        }

    // tell them the output
    if( str != "")
        tell_object( who, who->colour_event("weather", "%^ORANGE%^")+
            str+"%^RESET%^");

} /* do_inform() */

/**
 * @ignore yes
 * 0 for sunrise, 1 for sunset.
 */
string sun_direction( int which ) {
    switch(((time()+(SECONDS_PER_YEAR * which)) % (SECONDS_PER_YEAR*2)) /
        SECONDS_PER_DAY) {
    case 0..174:
      return "eastern";
    case 175..225:
      return "western";
    case 226..574:
      return "southern";
    case 575..625:
      return "northern";
    default:
      return "eastern";
    }
} /* sun_direction() */

/** @ignore yes */
void notify_room( object what, int has_changed ) {
    if( !objectp(what) )
        return;

    // The room will have to query the changes, but it will know WHAT has
    // changed by ORing has_changed.  IE: If
    // (has_changed | NOTIFY_TEMPERATURE) == 1 then temperature has changed.
    // If it == 0, temperature has not changed.
    what->event_weather( has_changed );

} /* notify_room() */

/**
 * @ignore yes
 * Send notifications to rooms.
 */
void do_room_inform( object what, int old_temp, int old_cloud, int old_rain,
                     int old_day, int notifications ) {
    int new_cloud, new_rain, new_wind, new_temp;
    int *warray;
    int has_changed = 0;

    new_temp = temperature_index(what);
    new_cloud = cloud_index(what);
    new_wind = calc_actual(what, WINDSP);
    new_rain = rain_index(what);

    if( function_exists("room_weather", what ) &&
        !catch( warray = (int *)what->room_weather( new_temp, new_cloud,
        new_wind, new_rain ) ) ) {
        new_temp = warray[0];
        new_cloud = warray[1];
        new_wind = warray[2];
        new_rain = warray[3];
    }

    // Look at what's changed, and if the room wishes to be notified of those
    // changes.
    if( day != old_day && (notifications & NOTIFY_DAY) )
        has_changed += NOTIFY_DAY;
    if( old_temp != new_temp && (notifications & NOTIFY_TEMPERATURE) )
        has_changed += NOTIFY_TEMPERATURE;
    if( old_cloud != new_cloud && (notifications & NOTIFY_CLOUD) )
        has_changed += NOTIFY_CLOUD;
    if( old_rain != new_rain && (notifications & NOTIFY_RAIN) )
        has_changed += NOTIFY_RAIN;

    // Now has_changed carries everything that has changed.
    // IE: If the clouds and rain have changed,
    // has_changed = NOTIFY_CLOUD + NOTIFY_RAIN = NOTIFY_CLOUD | NOTIFY_RAIN
    // I like bitwise ORs and ANDs :) - Grampa
    if( has_changed ) {
        // Using a call out to try to avoid bogging down should there be
        // a large amount of rooms who change a lot on weather notifications.
        call_out("notify_room", 1, what, has_changed );
    }
} /* do_room_inform() */

/* Operational Functions (the ones that control everything) */

// set our target underlying temperature, cloudiness etc. for this cycle
// this target is for Ankh-Morpork. Other areas of the Disc set their variance
// from this "norm" by adding a property to the room.
// this function is called once every few hours so it's ok to be longish
/** @ignore yes */
void update_pattern() {
    int toy, seasonal, tmp;

    call_out("update_pattern", CYCLE_SPEED);

    // Time of year. Climbs to 200 at mid-summer and then falls to year end
    tmp = day_number();
    toy = ( tmp < ( DIY / 2 ) ) ? tmp :
                  ( DIY / 2 ) - ( tmp % ( DIY / 2 ) );

    seasonal = ( toy / 6 ) - 5; // gives us a no. between -5 & +28 (celcius)
    sstats[0] = seasonal;
    pattern[TEMP] +=  calc_variance( TEMP, seasonal );

    /* set our target underlying cloud cover for this cycle */

    // a number between -12 (mid summer) and +87 (mid-winter) (%age cover)
    seasonal = ( ( 225 - toy ) / 2 ) - 25;
    sstats[1] = seasonal;
    pattern[CLOUD] += calc_variance( CLOUD, seasonal );

    seasonal = 25 - ( toy / 8 ); // 0-25 based on time of year (mph)
    sstats[2] = seasonal;
    pattern[WINDSP] += calc_variance( WINDSP, seasonal );

    unguarded( (: save_object, FILE_NAME :) );

} /* update_pattern() */

// go through and update the moon and weather stuff.
// this function is called every UPDATE_SPEED seconds.
/** @ignore yes */
void update_weather() {
    int *warray;
    mapping list, roomlist;
    object user, room;

    lastupdate = time();
    call_out("update_weather", UPDATE_SPEED );

    // before we change it work out the weather where the outside players are
    // and store this information for use later.
    list = ([ ]);
    roomlist = ([ ]);
    foreach( user in filter( users(), (: $1 :) ) ) {
        room = ENV(user);
        if( room && room->query_property("location") == "outside") {
            // store the previous weather for a user.
            if( function_exists("room_weather", room ) &&
                !catch( warray = (int *)room->room_weather(
                (int)temperature_index(room), (int)cloud_index(room),
                (int)calc_actual(room, WINDSP), (int)rain_index(room) ) ) ) {
                list[user] = ({ warray[0], warray[1], warray[3], day });
            } else {
                list[user] = ({ (int)temperature_index(room),
                    (int)cloud_index(room), (int)rain_index(room), day });
            }

        }
    }

    // For rooms
    foreach( room in keys(rooms) ) {
        if( !room )
            continue;
        if( function_exists("room_weather", room ) &&
            !catch(warray = (int *)room->room_weather((int)temperature_index(room),
            (int)cloud_index(room), (int)calc_actual(room, WINDSP),
            (int)rain_index(room) ) ) ) {
            roomlist[room] = ({ warray[0], warray[1], warray[3], day });
        } else {
            roomlist[room] = ({ (int)temperature_index(room),
                (int)cloud_index(room), (int)rain_index(room), day });
        }
    }

    // the mooncycle is updated every other day.
    if( ( moonupdate + ( SECONDS_PER_DAY * 2 ) ) < time() ) {
        mooncycle++;         // the moons phase changes each
        mooncycle %= 14;
        moonupdate = time();
    }

    // all current values will migrate towards their pattern values with some
    // randomness thrown in for good measure.

    // calculate the current temperature
    migrate(TEMP);
    migrate(CLOUD);
    migrate(WINDSP);

    // see if the day has changed
    set_day();

    // housekeeping
    unguarded( (: save_object, FILE_NAME :) );

    // send appropriate messages to players who are outside.
    foreach( user in keys(list) ) {
        do_inform( user, list[user][0], list[user][1], list[user][2],
            list[user][3] );
    }

    // send notifications to rooms.
    foreach( room in keys(roomlist) ) {
        do_room_inform( room, roomlist[room][0], roomlist[room][1],
            roomlist[room][2], roomlist[room][3], rooms[room] );
    }

} /* update_weather() */

/* Debugging functions */
/** @ignore yes */
void print_stats(object here) {
    printf("current: %O\n, pattern: %O\n, seasonal: %O\n variance: %O\n",
        current, pattern, sstats, variance );
    printf("Sunrise at: %d:%02d, sunset at: %d:%02d [toy: %d]\n",
        sunrise / 60, sunrise % 60, sunset / 60, sunset % 60, toy );
} /* print_stats() */

/** @ignore yes */
int *query_mooncycle() { return ({ mooncycle, 0 }); }

/** @ignore yes */
void set_variance( int temp, int cloud, int wind ) {
    variance = ({ temp, cloud, wind });
    unguarded( (: save_object, FILE_NAME :) );
} /* set_variance() */

/** @ignore yes */
mixed stats() {
    return ::stats() + ({
      ({ "current temp", current[TEMP], }),
      ({ "current cloud", current[CLOUD], }),
      ({ "current wind speed", current[WINDSP], }),
      ({ "pattern temp", pattern[TEMP], }),
      ({ "pattern cloud", pattern[CLOUD], }),
      ({ "pattern wind speed", pattern[WINDSP], }),
      ({ "seasonal temp", sstats[TEMP], }),
      ({ "seasonal cloud", sstats[CLOUD], }),
      ({ "seasonal wind speed", sstats[WINDSP], }),
      ({ "temp variance", variance[TEMP], }),
      ({ "cloud variance", variance[CLOUD], }),
      ({ "wind speed variance", variance[WINDSP], }),
      ({ "sunrise", sprintf("%d:%02d", sunrise/60, sunrise%60), }),
      ({ "sunset", sprintf("%d:%02d", sunset/60, sunset%60), }),
      ({ "rooms", sizeof(rooms) }),
    });
} /* stats() */

/** @ignore yes */
mapping query_dynamic_auto_load() { return rooms; }

/** @ignore yes */
void init_dynamic_arg( mapping m ) {
    if( mapp(m) )
        rooms = m;
} /* init_dynamic_auto_load() */
