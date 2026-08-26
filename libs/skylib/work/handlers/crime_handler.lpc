/**
 * This is the crime handler.
 * Keeps track of criminals.
 * By Sandoz, 28th July 2001.
 */

#include <crime.h>

#define CRIME_SAVE_DIR HANDLER_SAVE_DIR "/crime/"
#define CHECK_TIME  (24*60*60) // once a day.

string place;
mapping criminals;  // ([ name : ([ type : times, type : times ]) ])
mapping sentences;  // ([ name : times, name : times ])
mapping place_data; // any additional data for the place
private nosave mapping dying;
private nosave int _callout_id, dying_id;

/**
 * This method will does the callout to the check_arrays function
 * @ignore yes
 */
protected void setup_call_check_arrays( int time ) {
    remove_call_out(_callout_id);
    _callout_id = call_out( "check_arrays", time );
} /* setup_call_check_arrays() */

/** @ignore yes */
private void init_data( string place_name ) {
    place = place_name;
    criminals = ([ ]);
    sentences = ([ ]);
    place_data = ([ ]);
} /* init_data() */

/** @ignore yes */
private int get_data_file( string place_name ) {
    place_name = lower_case(place_name);
    if( place != place_name )
        if( file_size( CRIME_SAVE_DIR + place_name+".o" ) > 0 ) {
            unguarded( (: restore_object, CRIME_SAVE_DIR + place_name :) );
            place = place_name;
            if( !criminals )
                criminals = ([ ]);
            if( !sentences )
                sentences = ([ ]);
            if( !place_data )
                place_data = ([ ]);
        } else {
            init_data( place_name );
            return 0;
        }
    return 1;
} /* get_data_file() */

/** @ignore yes */
private void save_data_file( string place_name ) {
    unguarded( (: save_object, CRIME_SAVE_DIR + lower_case(place_name) :) );
} /* save_data_file() */

/** ignore yes */
void create() {
    /* check the criminals array after 10 minutes from startup */
    setup_call_check_arrays( 600 );
} /* create() */

/**
 * This method checks if the place is a valid place.
 * @param place_name the place to check
 * @return 1 if the place is valid, 0 if not
 */
int valid_place( string place_name ) {
    return ( member_array( lower_case(place_name), ALL_PLACES ) != -1 );
} /* valid_place() */

/**
 * This method if the crime type is valid.
 * @param type the crime type to check
 * @return 1 if the crime type is valid, 0 if not
 */
int valid_crime( int type ) {
    return ( member_array( type, CRIME_TYPES ) != -1 );
} /* valid_crime() */

/** @ignore yes */
string get_player_name( mixed player ) {
    if( objectp(player) )
        return (string)player->query_name();
    else if( stringp(player) )
        return player;
    else
        return 0;
} /* get_player_name() */

/**
 * This method checks if the player is a criminal
 * @param place_name the name of the place to check
 * @param player the name or object of the player to check
 * @return 1 if they're a criminal, 0 if not
 */
int query_criminal( string place_name, mixed player ) {
    string name;
    if( !name = get_player_name(player) )
        return 0;
    get_data_file( place_name );
    return !undefinedp(criminals[name]);
} /* query_criminal() */

/**
 * This method adds a player into the criminals array
 * @param place_name the name of the place to add the criminal in
 * @param player the name or object of the player to add
 * @param type the type of offense.  They have been defined as follows -
 *        VANDALISM  1 - vandalism
 *        THEFT      2 - stealing
 *        SHOPLIFT   3 - shoplifting
 *        SLAUGHTER  4 - killing innocents
 *        RESIST     5 - resisting arrest
 *        GUARDKILL  6 - guard killing
 * @return 1 if successfully added, 0 if not
 * @see "/include/crime.h"
 */
int add_criminal( string place_name, mixed player, int type ) {
    string name;

    if( !valid_place( place_name ) || !intp(type) || !valid_crime( type ) ||
        !( name = get_player_name(player) ) )
        return 0;

    get_data_file( place_name );

    if( undefinedp(criminals[name]) )
        criminals[name] = ([ ]);

    criminals[name][type]++;
    save_data_file( place_name );

    return 1;

} /* add_criminal() */

/**
 * This method removes a player from the criminals array
 * @param place_name the name of the place to clear the player's crime ledger
 * @param player the name or object of the player to remove
 * @return 1 if successfully removed, 0 if not
 */
int remove_criminal( string place_name, mixed player ) {
    string name;

    if( !valid_place( place_name ) || !( name = get_player_name(player) ) )
        return 0;

    get_data_file( place_name );

    if( undefinedp(criminals[name]) )
        return 0;

    map_delete( criminals, name );
    save_data_file( place_name );

    return 1;

} /* remove_criminal() */

/** @ignore yes */
void handle_death( string place_name, object killer, object who ) {
    if( !valid_place(place_name) )
        return;

    if( !mapp(dying) )
        dying = ([ ]);

    if( !dying[who] )
        add_criminal( place_name, killer, SLAUGHTER );

    dying[who] = 1;

    if( !dying_id ) {
        dying_id = call_out( function() {
            dying = ([ ]);
            dying_id = 0;
        }, 10 );
    }

} /* handle_death() */

/**
 * This method returns the types of crimes the person has committed
 * @param place_name the name of the place to get the crimes for
 * the player in
 * @param player the name or object of the player to check
 * @return the types of crimes the player has committed
 */
mapping query_crimes( string place_name, mixed player ) {
    string name;

    if( !name = get_player_name(player) )
        return 0;

    get_data_file( place_name );

    return criminals[name];

} /* query_crimes() */

/** @ignore yes */
string parse_num( int number, int times ) {
    if( number == 1 )
        return ( times ? "once" : "one" );
    if( number == 2 )
        return ( times ? "twice" : "two" );
    else
        return query_num(number)+( times ? " times" : "" );
} /* parse_num() */

/**
 * This method returns the types of crimes the person has committed
 * in a nice string format
 * @param place_name the name of the place to get the crime string
 * for the player in
 * @param player the name or object of the player to check
 * @return the types of crimes the player has committed
 */
string query_crime_string( string place_name, mixed player ) {
    mapping crimes;
    string *ret, name;

    if( !name = get_player_name(player) )
        return 0;

    get_data_file( place_name );

    if( undefinedp(criminals[name]) || !sizeof( crimes = criminals[name] ) )
        return 0;

    ret = ({ });

    foreach( int _type in sort_array( keys(crimes), 1 ) ) {
      int i = crimes[_type];
      ret += ({ replace( CRIME_MAP[_type][1], ({
                         "$times$", parse_num( i, 1 ),
                         "$number$", parse_num( i, 0 ),
                         "$s", ( i > 1 ? "s" : "" ) }) ) });
    }

    if( !sizeof(ret) )
        return 0;

    return query_multiple_short( ret );

} /* query_crime_string() */

/**
 * This method raises a player's sentence count in the specified area
 * @param place_name the name of the place to raise the count in
 * @param player the name or object of the player to raise the count for
 * @return 1 if successfully added, 0 if not
 */
int add_sentence( string place_name, mixed player ) {
    string name;

    if( !valid_place( place_name ) || !( name = get_player_name(player) ) )
        return 0;

    get_data_file( place_name );

    sentences[name]++;

    save_data_file( place_name );

    return 1;

} /* add_sentence() */

/**
 * This method nullifies a players' sentence count
 * @param place_name the name of the place to clear the player's count in
 * @param player the name or object of the player to remove
 * @return 1 if successfully removed, 0 if not
 */
int remove_sentences( string place_name, mixed player ) {
    string name;

    if( !valid_place( place_name ) || ( !name = get_player_name(player) ) )
        return 0;

    get_data_file( place_name );

    if( undefinedp(sentences[name]) )
        return 0;

    map_delete( sentences, name );
    save_data_file( place_name );

    return 1;

} /* remove_sentence() */

/**
 * This method returns the sentence count of the player in the
 * specified area
 * @param place_name the name of the place to get the count for
 * @param player the name or object of the player to check
 * @return the types of crimes the player has committed
 */
int query_sentence_count( string place_name, mixed player ) {
    string name;

    if( !name = get_player_name(player) )
        return 0;

    get_data_file( place_name );

    return sentences[name];

} /* query_sentence_count() */

/** @ignore yes */
int calc_sentence_length( mapping crimes ) {
    int length, tmp, div;

    tmp = SENTENCE_LENGTH_MOD;
    div = SENTENCE_LENGTH_MOD / sizeof(crimes);

    /* descending sort, harder crimes first */
    foreach( int _type in sort_array( keys(crimes), -1 ) ) {
        length += tmp * CRIME_MAP[_type][0] + sqrt( 2 * tmp * crimes[_type] );
        tmp -= div;
    }

    return length;

} /* calc_sentence_lenght() */

/**
 * This method returns the players sentence length based on
 * their criminal ledger in the specified area
 * @param place_name the name of the place to get their sentence
 * length in
 * @param player the name or object of the player to get the
 * sentence length for
 * @return the player's sentence length
 */
int query_sentence_length( string place_name, mixed player ) {
    mapping crimes;
    int length;
    string name;

    if( !name = get_player_name(player) )
        return 0;

    get_data_file( place_name );

    if( undefinedp(criminals[name]) || !sizeof( crimes = criminals[name] ) )
        return 0;

    length = calc_sentence_length( crimes );
    length += 30 * sqrt( sentences[name] );

    return length;

} /* query_sentence_length() */

/**
 * This method checks if the player is a guard killer
 * @param place_name the name of the place to check if the
 * player is a killer in
 * @param player the name or object of the player to check
 * @return 1 if they're a guard killer, 0 if not
 */
int query_killer( string place_name, mixed player ) {
    mapping crimes;
    string name;

    if( !name = get_player_name(player) )
        return 0;

    get_data_file( place_name );

    if( undefinedp(criminals[name]) || !sizeof( crimes = criminals[name] ) )
        return 0;

    return !undefinedp( crimes[GUARDKILL] );

} /* query_killer() */

/**
 * @ignore yes
 * This is used by query_sorted_criminals().
 */
int do_sort( int i, int j ) {
    if( i < j ) return 1;
    if( i > j ) return -1;
    return 0;
} /* do_sort() */

/**
 * This method returns the sorted array of criminals in a
 * specified area
 * @param place_name the name of the place to get the names for
 * @return the sorted array of criminals
 */
string *query_sorted_criminals( string place_name ) {
    string name;
    mixed ret;
    mapping crimes;

    if( !valid_place( place_name ) )
        return 0;

    get_data_file( place_name );

    if( !sizeof(criminals) )
        return 0;

    ret = ({ });

    foreach( name, crimes in criminals )
        ret += ({ ({ name, calc_sentence_length( crimes ) }) });

    return map( sort_array( ret, (: do_sort( $1[1], $2[1] ) :) ), (: $1[0] :) );

} /* query_sorted_criminals() */

/**
 * This method returns all the criminals in the specified place.
 * @param place_name the name of the place to get the
 * criminals' names for
 * @return all current criminals' names
 */
string *query_criminals( string place_name ) {
    get_data_file( place_name );
    return ( sizeof(criminals) ? keys(criminals) : 0 );
} /* query_crimes() */

/**
 * This method deletes the given player by name from all
 * places' criminal arrays.  This should be called by the
 * refresh handler when the player refreshes or is deleted.
 * @param player the player to delete
 * @return 1 if the operation was successful, 0 if it failed
 */
void refresh_criminal( string player ) {
    foreach( string place_name in ALL_PLACES ) {
        remove_criminal( place_name, player );
        remove_sentences( place_name, player );
    }
} /* refresh_criminal() */

/**
 * This method checks to make sure all the criminals still exist.
 * It also removes the invalid criminals.
 */
void check_arrays() {
    remove_call_out( _callout_id );
    setup_call_check_arrays( CHECK_TIME );

    foreach( string place_name in ALL_PLACES ) {
        get_data_file( place_name );
        foreach( string criminal in keys(criminals) )
          if( !criminal || !sizeof(criminal) || !rank( criminal ) )
              map_delete( criminals, criminal );
        save_data_file( place_name );
    }

} /* check_arrays() */

mixed *stats() {
   return ({
          ({ "place", ( place ? place : 0 ) }),
          ({ "total criminals", ( criminals ? sizeof(keys(criminals)) : 0 ) }),
   });
} /* stats() */
