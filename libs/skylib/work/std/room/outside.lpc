
#include <weather.h>

inherit ROOM_OBJ;

nosave int day_light;
nosave int current_day;
nosave int next_weather_update;
nosave object sunlight;
nosave string weather_str;

int set_light( int number );

/** @ignore yes */
void set_light_change( string s ) { add_property("light change", s ); }

/** @ignore yes */
string query_light_change() { return query_property("light change"); }

void create() {
    do_setup++;
    ::create();
    do_setup--;

    set_light(80);
    set_room_size(25);

    add_property("location", "outside");
    add_property("here", "on the ground");

    if( !do_setup ) {
        TO->setup();
        TO->reset();
    }

} /* create() */

/** @ignore yes */
int query_light() {
    int new_light;

    new_light = ( day_light * (int)WEATHER->query_darkness(TO) ) / 100;

    if( new_light != query_my_light() )
        ::set_light(new_light);

    return ::query_light();

} /* query_light() */

/**
 * This method returns the current level of day light in the room.  The
 * day light is the light level the room is set to if there was full sun
 * and no darkness at all.  Mostly a percentage of this is calculated
 * in the query_light() method.
 * @return the current daylight level
 */
int query_day_light() { return day_light; }

/** @ignore yes */
int set_light( int number ) {
    ::set_light(number);
    day_light = number;
} /* set_light() */

/** @ignore yes */
string long( string word, int dark ) {
    int day_time;
    string ret, obscure;

    // No point reinventing the wheel...
    ret = ::long( word, dark );
    day_time = (int)WEATHER_H->query_day();

    if( day_time != current_day && query_light_change() )
        call_other( TO, TO->query_light_change(), current_day );

    obscure = TO->query_weather_obscured( day_time );

    if( !day_time && !obscure )
        ret = (string)WEATHER->query_moon_string() + ret;

    if( time() > next_weather_update ) {
        weather_str = WEATHER_H->weather_string( TO, obscure )+".\n";
        next_weather_update = (int)WEATHER->next_update();
    }

    return replace( ret, "$weather$",
        TP->colour_event("weather", "%^ORANGE%^")+weather_str+"%^RESET%^");

} /* long() */

/** @ignore yes */
string get_sunlight_desc() {
    int daylight;

    daylight = TO->query_my_light();

    if( daylight < 30 )
        return "The light here is currently quite dim.\n";

    return "What do you want to look at the light for?  You can get a "
           "migraine from it, you know.\n";

} /* get_sunlight_desc() */

/** @ignore yes */
object *find_inv_match( string word, object looker ) {
    int daylight;

    if( word == "sunlight" || word == "daylight") {
        daylight = TO->query_my_light();
        // Nighttime - kill the light object as well.
        if( !daylight ) {
            if( sunlight ) {
                remove_hidden_object(sunlight);
                sunlight->dest_me();
                sunlight = 0;
            }
            return ::find_inv_match( word, looker );
        }

        if( !sunlight ) {
            sunlight = clone_object(OBJECT_OBJ);
            sunlight->set_name("sunlight");
            sunlight->set_weight(0);
            sunlight->reset_get();
            sunlight->add_alias("daylight");
            sunlight->set_long( (: get_sunlight_desc :) );
            add_hidden_object(sunlight);
        }
    }

    return ::find_inv_match( word, looker );

} /* find_inv_match() */

/** @ignore yes */
void dest_me() {
  if( sunlight )
      sunlight->dest_me();
  ::dest_me();
} /* dest_me() */

/** @ignore yes */
mixed stats() {
    return ::stats() + ({ ({"day light", day_light, }) });
} /* stats() */
