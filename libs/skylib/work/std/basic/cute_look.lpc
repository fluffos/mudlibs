/**
 *
 * This object handles all the inventory listing for rooms, when long() is
 * called.
 * It should convert like this: ({ /w/terano/womble#1234, /std/object#1324,
 * /global/creator#2523 }) into "Lady Midnite is standing here.\nA key and a
 * womble are floating happily.\n"
 *
 * @author Lynscar
 * @change Deutha
 * Added in support for the one_short, the_short stuff.  Also added
 * in the 'last' stuff I think.
 * @change Pinkfish
 * Added in support for positions.
 * @change Terano
 * Rewrote removing all the foreachs, and getting rid of chicken and last
 * variables. Should be much nicer now.
 */

#include <position.h>

// Comment me out to use the old process_non_living() code.
#define NEW_PROCESS_NON_LIVING 1

mixed *process_living( object *int_livings );
string process_non_living( object *int_non_livings, int start );

/**
 * This method returns a string contents of description of the container.
 * NB: TP is _not_ included in the array if (s)he is present.
 * The ignore_living flag tells us if we should process living
 * objects as different or not.  If we do not process them as
 * different (as you do in room descriptions), then this flag should
 * be 0.  This is so that living objects can be kept an an
 * inventory of a player without stuff it up.  ie: Pets.
 * @param start the start message before the contents
 * @param things the things to give the message for
 * @param ignore_living treat livings differently
 * @return a string contents description
 */
varargs string query_contents( string start, object *things,
                               int ignore_living ) {
    object *livings = ({ }), *non_livings = ({ });
    mixed *bits;
    string return_string = "";
    int groups;

    // Sort into living and non-living
    if( stringp( start ) )
        return_string = start;

    if( !arrayp( things ) ) {
        things = TO->find_inv_match( "", TP );
        things -= ({ TP });
        things = filter( things, (: ENV( $1 ) == TO :) );
    }

    if( !sizeof( things ) )
        return "";

    if( !ignore_living ) {
        livings = filter( things, (: living( $1 ) :) );
        non_livings = things - livings;
    } else
        non_livings = things;

    // Process the livings
    if( sizeof( livings ) ) {
        bits = process_living( livings );
        return_string += bits[ 0 ];
        groups = bits[1];
    }

    // Process the non-livings
    if( sizeof( non_livings ) )
        return_string += process_non_living( non_livings, groups );

    // Return the built string - Yay!
    if( return_string == "" )
        return return_string;
    else
        return  return_string = TP->colour_event("inventory", "") +
        return_string[0..<2] + "%^RESET%^\n";
} /* query_contents() */

/** @ignore yes */
/* Internally process living objects and return a string. */
mixed *process_living( object *int_livings ) {
    int i;
    mapping positions = ([ ]);
    object live_temp;
    string my_pos, int_ret_string = "", *all_positions, current_pos, ministring;

    foreach( live_temp in int_livings ) {
        if( undefinedp( my_pos = live_temp->query_position_short() ) )
            my_pos = POSITION_DEFAULT;
        if( undefinedp( positions[ my_pos ] ) )
            positions[ my_pos ] = ({ live_temp });
        else
            positions[ my_pos ] += ({ live_temp });
    }

    // Sort into positions
    // For each position, build a ministring and add it
    all_positions = keys( positions );
    i = 0;
    foreach( current_pos in all_positions ) {
        if( i == 0 ) {
            ministring = "$C$$M$";
        } else {
            ministring = "$M$";
        }

        foreach( live_temp in positions[ current_pos ] ) {
            if( !live_temp->query_visible( TP ) ) {
                continue;
            }
            ministring += live_temp->a_short();
        }

        /* If more than one living */
        if( !positions[current_pos][0]->query_position_dont_use_is_are()) {
            if( sizeof( positions[ current_pos ] ) > 1 ||
                positions[ current_pos ][0]->group_object() ) {
                if( positions[ current_pos ][0]->query_position_multiple() ) {
                    ministring += "$M$ are each " + current_pos;
                } else {
                    ministring += "$M$ are " + current_pos;
                }
            } else {
                ministring += "$M$ is " + current_pos;
            }
        } else {
            ministring += "$M$ " + current_pos;
        }

        switch( current_pos ) {
        case SITTING:
        case STANDING:
        case KNEELING:
        case SWIMMING:
        case LYING:
        case MEDITATING:
        case CROUCHING:
            ministring += " here";
        default:
            i++;
            if( i < sizeof(all_positions) - 1 )
                ministring += ", ";
            else if( i < sizeof(all_positions) )
                ministring += " and ";
            else
                ministring += ".\n";
            int_ret_string += ministring;
            continue;
        }
    }
    return ({ int_ret_string, sizeof( all_positions ) }) ;
} /* process_living() */

/** @ignore */
string process_non_living( object *non_livings, int start ) {
    mapping positions;
    string position, here, *room_items;
    object *items, item, *bulk;
    int i;

    if( !sizeof(non_livings) )
            return "";

    here = TO->query_property( "here" );

    if( !here )
        return query_multiple_short( non_livings ) + ".\n";

    positions = unique_mapping( non_livings,
        (: $1->query_property( "there" ) :) );

    if ( positions[ 0 ] ) {
        positions[ here ] = positions[ 0 ];
        map_delete( positions, 0 );
    }

    i = start;
    room_items = ({ });

    foreach( position, items in positions ) {
        bulk = ({ });
        foreach( item in items ) {
            if ( item->query_continuous() && item->query_how_many() > 1 &&
                item->query_property("determinate") != "some " ) {
                // How do we make sure this all gets arranged properly...?
                room_items += ({ item->a_short() + " are " + position });
            }
            else {
                bulk += ({ item });
            }
        }

        if ( sizeof( bulk ) ) {
            room_items += ({ "$M$" + implode( bulk->a_short(), "" ) +
                "$M$ " + "$V$" + i + "=is,are$V$ " + position });
        }

        i++;
    }
    return "$C$" + query_multiple_short( room_items ) + ".\n";
} /* process_non_living() */

/**
 * This method prints out the contents of the object matching.
 * @param word the string to match
 */
void list_contents( string words ) { write( query_contents( words ) ); }

/** @ignore */
int query_last() {
    log_file( "CUTELAST", "(%s) %s called query_last.\n",
      ctime( time() ), file_name( TO ) );
    return 0;
} /* query_last() */

/** @ignore */
void adjust_last( int wibble ) {
    log_file( "CUTELAST", "(%s) %s called adjust_last.\n",
      ctime( time() ), file_name( TO ) );
    return;
} /* adjust_last() */
