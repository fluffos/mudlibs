/**
 * Your very own personal weather...
 */

#include <weather.h>
#include <clothing.h>

#define COMFORTABLE 20

int temperature;
string temperature_str;

int query_wetness() { return 0; }

void add_wetness( int arg ) {}

void set_personal_temp(int i) { temperature = i; }
void adjust_personal_temp(int i) { temperature += i; }
int query_personal_temp() { return temperature; }

string query_temp_str() {
    if( !temperature_str || temperature_str == "")
        return "quite comfortable";
    return temperature_str;
} /* query_temp_str() */

/*
 * This method calculates an object's personal temperature index.
 * All temperatures in here are 20C lower so that comfort is at zero
 * to make calculations easier.
 */
int calc_personal_temp() {
    mixed types;
    object where, *clothes;
    string item, zone, type, *zones;
    int adjustment, room_temp, correction, *enums, tmp;

    if( TO->query_property("dead") ) {
        temperature = 0;
        return 0;
    }

    where = environment();

    // If they're on a horse or somesuch then use that location's
    // temperature info.
    if( !where->query_property("location") &&
        ENV(where) && ENV(where)->query_property("location") )
        where = ENV(where);

    // Figure out the temperature where they are.
    if( where->query_property("location") == "outside")
        room_temp = WEATHER->query_temperature(where) - COMFORTABLE;
    else
        room_temp = 0;

    // Add the warmth of the room.
    room_temp += where->query_property("warmth");
    room_temp -= where->query_property("cooling");

    adjustment = room_temp;

    // Add their personal warmth (from effects or shadows).
    adjustment += TO->query_property("warmth");
    adjustment -= TO->query_property("cooling");

    // Calculate how warm (or cool) their clothing is keeping them.
    clothes = filter( TO->query_wearing(), (: !$1->id("scabbard") &&
                  !$1->id("belt") && !$1->id("backpack") &&
                  !$1->id("glasses") && !$1->id("jewellery") :) );

    zones = ({ });

    foreach( item in clothes ) {
        if( !pointerp( types = item->query_type() ) )
            types = ({ item->query_type() });

        foreach( type in types ) {
            // Find out what zone this clothing type covers.  If it doesn't
            // cover a zone (eg. jewellery) it doesn't give any warmth.
            if( CLOTHING_HANDLER->query_equivilant_type(type) )
                type = CLOTHING_HANDLER->query_equivilant_type(type);

            foreach( zone in CLOTHING_HANDLER->query_zone_names(type) ) {
                if( member_array( zone, zones ) == -1 )
                    zones += ({ zone });

                if( !tmp = item->query_property("warmth") )
                    adjustment++;
                else if( tmp )
                    adjustment += tmp;

                // If it's warm here, then do adjustments for clothing
                // that cools you.
                if( room_temp > 0 )
                    adjustment -= item->query_property("cooling");
            }
        }
    }

    tmp = sizeof(zones);

    // You get a warmth bonus or coolness bonus for each zone covered.
    // This means it's better to cover more of your body when it's cold.
    // It also means you can wear light clothing with less temperature
    // penalties since the warmth & cooling cancel out somewhat.
    if( room_temp < 0 ) {
        adjustment += tmp;
        if( room_temp + tmp > 5 )
            adjustment -= room_temp + tmp - 5;
    } else {
        adjustment -= tmp;
        if( room_temp - tmp < -5 )
            adjustment -= room_temp - tmp + 5;
    }

    // Wetness makes you cooler - so sweating isn't necessarily a bad thing.
    ;
    if( sizeof( enums = (int *)TO->effects_matching("body.wetness") ) )
        adjustment -= sqrt( sqrt( (int)TO->arg_of(enums[0]) ) ) * 2;

    // This hopefully does two things.
    // 1. effectively puts a maximum/minimum on temperature.
    // 2. accounts for the body working to adjust temperature.
    if( temperature > room_temp && room_temp >= 0 || temperature > 5 )
        correction -= temperature / 5 + 5;
    if( temperature < room_temp && room_temp <= 0 || temperature < -5 )
        correction -= temperature / 5 - 5;

#ifdef 0
    /*
     * This factor is not currently used. Depending on how the testing goes
     * it may get put in place.
     */
    // This factor adjusts for when rooms aren't too hot or cold.
    // So if you're not too far off the room temperature,
    // you don't adjust quite so fast.
    if( ( room_temp < 10 && temperature >= 0 ) ||
        ( room_temp > 10 && temperature <= 0 ) ) {
        factor = ABS( room_temp - temperature ) / 10.0;
        if( factor > 1.0 || factor < 0.0 )
            factor = 1.0;
    } else {
        factor = 1.0;
    }

    temperature += to_int( ( adjustment + correction ) * factor );
#endif

    temperature += adjustment + correction;

    // Calculate the temperature string and other effects based
    // on the race of the person.
    temperature_str = (TO->query_race_ob())->temperature_effects(
                       TO, temperature );

    return temperature;

} /* calc_personal_temp() */

/** @ignore yes */
string weather_extra_look() {
    if( stringp( temperature_str ) && temperature_str != "")
        return CAP(TO->HE)+" looks "+temperature_str+".\n";
    return "";
} /* weather_extra_look() */
