/**
 * @main
 * This is the standard lightable.  It can be used for candles,
 * lanterns, lamps etc.  It adds the commands "light" and
 * "dowse"/"extinguish" to the player, but no refuelling
 * command.  Holding stuff is handled by /obj/weapon and the
 * ho_ld command.
 * @author Gruper
 * @index lightable
 * @started 11th of May, 1998
 */

#include <fuel_handler.h>

#define HOLD_CMD   "/cmds/living/ho_ld"
#define DEPARTURES "/room/departures"

inherit WEAPON_OBJ;

int max_fuel, fuel, lit, brightness, time, hold;
string empty_mess;
mixed fuel_messages;

int set_lit( int i );

/** @ignore */
void create() {
    ::create();
    add_extra_look(TO);
} /* create() */

/** @ignore */
void init() {
    add_command("light");
    add_command("dowse");
    add_command("extinguish");
} /* init() */

/** @ignore */
varargs string short( int dark ) {
    if( lit && !query_property("just_lit") )
        return "lit " + ::short( dark );
    else
        return ::short( dark );
} /* short() */

/** @ignore */
void out_of_fuel() {
    object env;

    fuel = 0;
    lit = 0;
    set_lit(0);

    FUEL_HANDLER->remove_burner(TO);

    if( !env = environment() )
        return;

    if( living( env ) ) {
        tell_room( ENV(env), poss_short()+" goes out.\n");
    } else {
        tell_room( env, the_short() +" goes out.\n" );
    }

} /* out_of_fuel() */

/** @ignore yes */
int hold_thing() {
    if( !query_wielded() )
        return HOLD_CMD->cmd( ({ TO }) );
    else
        return 1;
} /* hold_thing() */

/** @ignore */
mixed set_holder( object ob, int pos ) {
    // No one is holding it and it requires holding when lit; dowse it.
    if( lit && hold && !ob && ENV(TP) && file_name( ENV(TP) ) != DEPARTURES )
        if( !set_lit( 0 ) ) {
            tell_object( TP, "You extinguish "+the_short()+".\n");
            tell_room( ENV(TP), TP->the_short()+" extinguishes "+
                the_short()+".\n", TP );
        }

    return ::set_holder( ob, pos );

} /* set_holder() */

/**
 * This function is used to light or dowse the lightable.
 * Two properties are checked: unextinguishable means that
 * the lightable cannot be extinguished and unlightable that
 * it cannot be lit.
 * @param i 1 for lit and 0 for unlit
 * @return The current state, 1 for lit, 0 for unlit
 */
int set_lit( int i ) {
    if( !i ) {
        if( !query_property("unextinguishable") ) {
            lit = 0;
            FUEL_HANDLER->remove_burner(TO);
            remove_adjective("lit");
            remove_property("just_lit");
            set_light(0);
            return 0;
        }
    } else {
        if( !query_property("unlightable") && fuel > 0 ) {
            if( lit )
                return 1;

            if( hold && !hold_thing() )
                return 0;

            // Delay for sensible light mess.
            lit = 1;
            add_property("just_lit", 1, 2 );
            FUEL_HANDLER->add_burner(TO);
            add_adjective("lit");
            set_light( brightness );
            return 1;
        }
    }

} /* set_lit() */

/**
 * @return 1 if lit, 0 if unlit
 */
int query_lit() { return lit; }

/** @ignore */
int do_light() {
    if( lit )
        return notify_fail( the_short()+" is already lit.\n");

    if( !fuel )
        return notify_fail( the_short()+" "+empty_mess+"\n");

    if( !set_lit( 1 ) )
        return notify_fail("You cannot light "+the_short()+".\n");

    TP->print_messages();
    add_succeeded_mess("$N $V $D.\n");
    return 1;

} /* do_light() */

/** @ignore */
int do_dowse() {
    if( !lit )
        return notify_fail( the_short()+" is not lit.\n");

    if( set_lit( 0 ) )
        return notify_fail("You cannot extinguish "+the_short()+".\n");

    add_succeeded_mess("$N $V $D.\n");
    return 1;

} /* do_dowse() */

/** @ignore */
int do_extinguish() { return do_dowse(); }

/**
 * This function is used to set the different messages shown
 * depending on how much fuel is left in the lightable.
 * The fuel messages should be on a form suitable to be
 * appended to the_short() +" is lit/not lit.  "
 * The argument msgs can either be an array of strings or an
 * array of string, int pairs.  In the first case, the fuel
 * messages will be evenly spaced.  In the second case, the
 * int is a percentage (fuel_left*100/max_fuel) below which
 * the string will be used.  If no message for 100 is given,
 * it will default to the last string element in the array.
 *
 * @param msgs A mixed array of either strings or string, int pairs
 * @example
 *     set_fuel_messages( ({ "There is almost no fuel left.", 10
 *                           "It is more than halfway empty.", 50,
 *                           "It is not yet halfway empty.", 80,
 *                           "It is almost full.", 100 }) );
 */
void set_fuel_messages( mixed msgs ) { fuel_messages = msgs; }

/**
 * @return a mapping containing all the different fuel_messages
 */
mixed query_fuel_messages() { return fuel_messages; }

/**
 * Sets the maximum amount of fuel.
 * One fuel unit equals one second of burning time.
 */
void set_max_fuel( int i ) { max_fuel = i; }

/**
 * @return The max amount of fuel the object can contain.
 */
int query_max_fuel() { return max_fuel; }

/**
 * Sets the current amount of fuel.  One fuel unit equals
 * one second of burning time.  If fuel > max_fuel,
 * fuel = max_fuel, so it is important to set max_fuel
 * before fuel.
 */
void set_fuel( int i ) {
    fuel = i;
    if( fuel > max_fuel )
        fuel = max_fuel;
} /* set_fuel() */

/**
 * @return The current amount of fuel.
 */
int query_fuel() { return fuel; }

/**
 * @return String describing how much fuel is left.
 */
string current_fuel_message() {
    mixed messages;
    int fuel_percent, size, i;
    string fuel_string = "";

    if( fuel < 1 )
        return "It "+ empty_mess;

    messages = query_fuel_messages();
    size = sizeof( messages );

    if( !size )
        return "This item needs a creator.  It is broken and lonely.";

    if( size < 2 )
        return messages[0];

    // Multiplying by 99 guarantees <= index.
    fuel_percent = fuel * 99 / max_fuel;

    if( intp( messages[1] ) ) { // Percenatges given
        for( i = 1; i < size; i += 2 ) {
            if( messages[i] > fuel_percent ) {
                fuel_string = messages[i-1];
                break;
            }
        }
        if( fuel_string == "")
            fuel_string = messages[ size - 2 ];
    } else {
        // Percentages not given -> even distribution
        fuel_string = messages[ fuel_percent * size / 100 ];
    }

    return fuel_string;

} /* current_fuel_message() */

/**
 * The empty message is a string used to describe the lightable
 * when it is out of fuel.  It should be on the form
 * "is burnt to a stub." to fit both the_short() +" "+ msg
 * and "It "+ msg.
 */
void set_empty_mess( string msg ) { empty_mess = msg; }

/**
 * @return String empty_mess
 */
string query_empty_mess() { return empty_mess; }

/**
 * The brightness is the number used in set_light(),
 * ie how brightly the lightable shines when lit.
 */
void set_brightness( int i ) { brightness = i; }

/**
 * @return How brightly the object shines when lit
 */
int query_brightness() { return brightness; }

/**
 * @param hands The number of hands required to hold the object when lit
 * Any non-zero value will cause the ho_ld command to be executed,
 * so use set_no_limbs( 2 ) as usual for two-handed weapons.
 * I guess what I'm really trying to say is that a 0 will not require
 * the object to be held and any other value will.
 *
 * In winter darkness<br>
 * Gruper lights a cheerful flame<br>
 * It smells like honey<br>
 */
void set_hold_required( int hands ) { hold = hands; }

/**
 * @return number of hands required to hold object when lit
 */
int query_hold_required() { return hold; }

/** @ignore */
string extra_look() {
    string lit_str;

    if( lit )
        lit_str = "It is lit.  ";
    else
        lit_str = "It is not currently lit.  ";

    return lit_str+current_fuel_message()+"\n";

} /* extra_look() */

/** @ignore */
mixed query_dynamic_auto_load() {
    return ([ "::" : ::query_dynamic_auto_load(),
              "fuel" : fuel,
              "lit" : lit,
           ]);
} /* query_dynamic_auto_load() */

/** @ignore */
void init_dynamic_arg(mapping arg, object bing ) {
    fuel = arg["fuel"];
    ::init_dynamic_arg(arg["::"], bing );
    set_lit(arg["lit"]);
} /* init_dynamic_arg() */

/** @ignore */
void consume_fuel() {
    // By using FUEL_TIME we make sure that 1 unit of fuel = 1 second.
    fuel -= FUEL_TIME;
    if( fuel < 1 )
        out_of_fuel();
} /* consume_fuel() */

/** @ignore */
int query_value() {
    return (int)( ::query_value() * fuel / max_fuel );
} /* query_value() */

/** @ignore */
varargs int move( mixed dest, string messin, string messout ) {
    object destination;

    if( objectp( dest ) )
        destination = dest;
    else
        destination = load_object(dest);

    // This object is entering a place that may be, ah, hostile
    // to open flames, i.e. containers (that are not people) and
    // water rooms.
    if( ( inherits( "/std/container", destination ) &&
        !living( destination ) ) ||
        inherits("/std/uwater", destination ) ||
        inherits("/std/water_inside", destination ) ||
        inherits("/std/water_outside", destination ) ) {
        set_lit( 0 );
    }

    return ::move( dest, messin, messout );

} /* move() */
