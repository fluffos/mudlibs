
#define __MONEY_CLASS__
#include <money.h>
#include <move_failures.h>
#include <obj_parser.h>

inherit OBJECT_OBJ;

private nosave int no_join;
private nosave int _already_joined;
private mixed money_array;
private nosave string _long;

void create() {
    ::create();
    set_name("coin");
    add_alias( MONEY_ALIAS );
    add_plural("coins");
    set_main_plural("coins");
    add_property("determinate", "");
    add_property("no one", 1 );
    add_property("money", 1 );
    money_array = ({ });
} /* create() */

/** @ignore yes */
int query_merger() { return 1; }

/** @ignore yes */
int query_no_join() { return no_join; }

/** @ignore yes */
int query_already_joined() { return _already_joined; }

/** @ignore yes */
void set_no_join() {
    no_join = 1;
    call_out("merge_coins", 0 );
} /* set_no_join() */

/** @ignore yes */
void reset_no_join() { no_join = 0; }

/**
 * This method returns the number of coins in the object.
 * @return the number of coins
 */
int query_number_coins() {
    int i, tot;

    if( _already_joined )
        return 0;

    for( i = 1; i < sizeof(money_array); i += 2 )
        tot += money_array[ i ];

    return tot;

} /* query_number_coins() */

/**
 * This method fixes up the weight of the money object to be what it should
 * be.
 */
void fixup_money_weight() {
    float total;
    int i;

    for( i = 0; i < sizeof(money_array); i += 2 )
        total += money_array[ i + 1 ] *
                 MONEY_H->query_weight_for( money_array[ i ] ) / 100.0;

    if( total < 1 )
        set_weight( 1 );
    else
        set_weight( to_int(total) );

} /* fixup_money_weight() */

/** @ignore yes */
int group_object() { return query_number_coins() > 1; }

/**
 * This method goes through the coins and sets up all the adjectives
 * and plurals it needs to.
 */
void check_adjectives() {
    int i;
    string *bits, *aliases;

    set_adjectives( ({ }) );
    set_aliases( ({ }) );
    set_plurals( ({ }) );

    if( !sizeof(money_array) ) {
        _already_joined = 0;
        move("/room/rubbish");
        _already_joined = 1;
        return;
    }

    add_alias(MONEY_ALIAS);

    for( i = 0; i < sizeof(money_array); i += 2 ) {
        aliases = MONEY_H->query_aliases_for( money_array[ i ] );
        bits = explode( lower_case( money_array[ i ] ), " ");

        if( sizeof(bits) > 1 ) {
            add_adjective( bits[0..<2] );
            if( sizeof( bits = explode( money_array[ i ], " ") - bits ) )
                add_adjective( bits );
        } else if( member_array( bits[0], aliases ) == -1 ) {
            add_adjective( bits[0] );
        }

        add_alias( aliases );
        add_plural( MONEY_H->query_plural_for( money_array[ i ] ) );

    }

    add_plural("coins");

} /* check_adjectives() */

/** @ignore yes */
mixed query_money_array() {
    return ( !_already_joined ? money_array : ({ }) );
} /* query_money_array() */

/** @ignore yes */
varargs int adjust_money( mixed amount, string type, int internal ) {
    int i, ret;

    if( pointerp( amount ) ) {
        for( i = 0; i < sizeof(amount); i += 2 )
            adjust_money( amount[ i + 1 ], amount[ i ], 1 );
        fixup_money_weight();
        return 1;
    }

    if( !stringp(type) || !intp(amount) || _already_joined )
        return 0;

    short_d = _long = 0;

    if( ( i = member_array( type, money_array ) ) == -1 ) {
        string *aliases, *bits;

        aliases = MONEY_H->query_aliases_for(type);
        bits = explode( lower_case( type ), " ");

        if( sizeof(bits) > 1 ) {
            add_adjective( bits[0..<2] );
            if( sizeof( bits = explode( type, " ") - bits ) )
                add_adjective( bits );
        } else if( member_array( bits[0], aliases ) == -1 ) {
            add_adjective( bits[0] );
        }

        add_alias( aliases );
        add_plural( lower_case( MONEY_H->query_plural_for(type) ) );
        money_array += ({ type, amount });
        ret = 1;

    } else {
        money_array[ i + 1 ] += amount;
        if( money_array[ i + 1 ] <= 0 ) {
            money_array = delete( money_array, i, 2 );
            if( find_call_out("check_adjectives") == -1 )
                call_out("check_adjectives", 0 );
            ret = 0;
        } else {
            ret = 1;
        }
    }

    if( !internal )
        fixup_money_weight();

    if( ret )
        return money_array[ i + 1 ];

    return 0;

} /* adjust_money() */

/** @ignore yes */
void set_money_array( mixed new_array ) {
    short_d = _long = 0;
    money_array = new_array;
    fixup_money_weight();

    if( find_call_out("check_adjectives") == -1 )
        call_out("check_adjectives", 0 );

} /* set_money_array() */

/** @ignore yes */
string *half_short( int full ) {
    int i;
    string *retval;

    retval = ({ });

    for( i = 0; i < sizeof(money_array); i += 2 ) {
        if( money_array[ i + 1 ] < 1 )
            continue;

        if( !full && ( money_array[ i + 1 ] > 12 ) ) {
            retval += ({ "some "+
                MONEY_H->query_main_plural_for( money_array[ i ] ) });
            continue;
        }

        if( money_array[ i + 1 ] == 1 ) {
            retval += ({ "one "+
                MONEY_H->query_short_for( money_array[ i ] ) });
            continue;
        }

        retval += ({ money_array[ i + 1 ] +" "+
                MONEY_H->query_main_plural_for( money_array[ i ] ) });

    }

    return retval;

} /* half_short() */

/** @ignore yes */
string short( int dark ) {
    string *retval;

    if( short_d )
        return short_d;

    retval = half_short( 0 );

    if( !sizeof( retval ) )
        return 0;

    if( sizeof( retval ) == 1 )
        short_d = retval[ 0 ];
    else
        short_d = query_multiple_short( retval );

    return short_d;

} /* short() */

/** @ignore yes */
string long( string word, int dark ) {
    int i;
    class money_data details;

    if( dark < -1 )
        return "It is too dark to see anything about the coins.\n";
    if( dark > 1 )
        return "It is too bright to see anything about the coins.\n";

    if( _long )
        return _long;

    if( !sizeof( money_array ) )
        return "This is some money that isn't money.\n";

    _long = "";

    for( i = 0; i < sizeof(money_array); i += 2 ) {
        details = MONEY_H->query_details_for( money_array[i] );
        _long += "Wrought from "+details->material+", the ";

        if( money_array[i+1] == 1 )
            _long += details->adj+" "+
                MONEY_H->query_short_for( money_array[i] )+" shows ";
        else
            _long += query_num( money_array[i+1] )+" "+details->adj+" "+
                MONEY_H->query_main_plural_for( money_array[i] )+" show ";

        _long += details->head_long+" on the reverse, and "+
                 details->tail_long+" on the obverse.\n";
    }

    return _long;

} /* long() */

/** @ignore yes */
string query_long_details( string word, int dark, object looker ) {
    if( dark < -1 )
        return "It is too dark to see anything about the coins.\n";
    if( dark > 1 )
        return "It is too bright to see anything about the coins.\n";
    return long( word, dark );
} /* query_long_details() */

/**
 * This method creates a new money object from the current object.  It uses
 * the current objects values to make the money and removes the values from
 * the coins.
 * @param number the number of coins to remove
 * @param type the type of coins to remove
 * @return the new money object
 */
private object new_money_object( int number, string type, object money ) {
    int i;

    if( !sizeof( money_array ) || _already_joined )
        return 0;

    if( !type || type == "" )
        return 0;

    if( ( i = member_array( type, money_array ) ) == -1 )
        return 0;

    if( number > money_array[ i + 1 ] )
        return 0;

    if( !money )
        money = clone_object(MONEY_OBJ);

    money->set_no_join();

    short_d = _long = 0;

    // First we need to remove stuff from our array and update the weight,
    // because otherwise add_weight() will not work in our container.
    // If we adjust the weight of the newly created object first, we will
    // end up with broken local weights in containers.
    // This only happens with full containers or burdened players.
    // - Sandoz.
    money_array[ i + 1 ] -= number;
    fixup_money_weight();

    // This fixes up the weight of the new object as well.
    money->adjust_money( number, type );

    // Only now we try to move it, if it fails, move it to our room.
    // This should help prevent broken local weights as well.
    if( money->move( environment() ) ) {
        object env, who;

        if( env = ENV( who = environment() ) ) {
            object tmp;

            // Let's move us to the room, and give a message to
            // the player whose inventory we are in.
            while( tmp = ENV( env ) ) {
                if( interactive(env) )
                    who = env;
                env = tmp;
            }

            money->move(env);

            tell_object( who, "Oh dear, "+money->the_short()+" refuse to fit "
                "in "+environment()->the_short()+" any more and find their "
                "way to "+env->the_short()+".\n");
        }
    }

    if( money_array[ i + 1 ] < 1 ) {
        // Remove the adjective right away so that we won't match on it again.
        remove_adjective( money_array[ i ] );
        money_array = delete( money_array, i, 2 );
        if( find_call_out("check_adjectives") == -1 )
            call_out("check_adjectives", 0 );
    }

    return money;

} /* new_money_object() */

/**
 * This method merges two coin object together.  Or attempts to anyway.
 * This will occur whenever a coin object moves.
 * @return the merged coin object
 */
object merge_coins() {
    object money;

    remove_alias(MONEY_ALIAS);

    if( environment() )
        money = present( MONEY_ALIAS, environment() );

    if( objectp( money ) && money != TO && !_already_joined ) {
        // First move us to the rubbish room to update the local weight of the
        // container, then adjust the money array on the target money object.
        // Otherwise we may end up with bad local weights again.
        // - Sandoz.
        set_no_join();
        move("/room/rubbish");
        _already_joined = 1;
        money->adjust_money( money_array );
        return money;
    } else {
        add_alias( MONEY_ALIAS );
    }

    return TO;

} /* merge_coins() */

/** @ignore yes */
varargs int move( mixed dest, string messin, string messout ) {
    int i;

    if( _already_joined )
        return MOVE_INVALID_DEST;

    i = ::move( dest, messin, messout );
    if( i != MOVE_OK )
        return i;

    if( file_name( environment() ) == "/room/rubbish" || no_join )
        reset_no_join();
    else
        merge_coins();

    return MOVE_OK;

} /* move() */

/** @ignore yes */
public varargs mixed find_best_fit( mixed word, int flag ) {
    int i, best, best_rating, rating;
    string against, *words, *arr;

    if( !word || word == "")
        return 0;

    if( stringp(word) )
        words = explode( lower_case( word ), " ") - ({"coin", "coins"});
    else
        words = word;

    if( flag )
        arr = ({ });

    best = -1;

    for( i = 0; i < sizeof( money_array ); i += 2 ) {
        rating = 0;
        against = "X "+lower_case( replace( money_array[ i ] +" "+
            MONEY_H->query_plural_for( money_array[ i ] ), " coins", "") )+" X";

        foreach( word in words ) {
            if( sscanf( against, "%*s "+lower_case(word)+" %*s") == 2 )
                rating++;
        }

        if( flag && rating >= best_rating )
            arr += ({ money_array[i] });

        if( rating > best_rating ) {
            best_rating = rating;
            best = i;
            if( flag )
                arr = ({ money_array[i] });
        }
    }

    if( flag )
        return arr;

    return best;

} /* find_best_fit() */

/** @ignore yes */
object query_parse_id( mixed arr ) {
    int i;
    string *bits;
    object money;

    if( arr[ 0 ] < 0 || !sizeof( money_array ) )
        return 0;

    if( arr[ 0 ] == 0 ) {
        bits = explode( arr[ 1 ], " ");

        if( sizeof(bits) == 1 && bits[ 0 ] == "coins")
            return TO;

        if( member_array( bits[<1], query_plurals() ) == -1 )
            return TO;

        if( ( i = find_best_fit( arr[ 1 ] ) ) == -1 )
            return 0;

        money = new_money_object( money_array[ i + 1 ], money_array[ i ], 0 );
        return money;

    }

    // Not very satisfactory.
    if( ( i = find_best_fit( arr[ 1 ] ) ) == -1 )
        i = 0;

    if( arr[ 0 ] > money_array[ i + 1 ] )
        return 0;

    money = new_money_object( arr[ 0 ], money_array[ i ], 0 );
    return money;

} /* query_parse_id() */

/** @ignore yes */
mixed parse_match_object( string *input, object viewer,
                          class obj_match_context context ) {
    int ret, num, every;
    mixed found;
    object ob;

    if( !sizeof(money_array) )
        return 0;

    if( !ret = ::is_matching_object( input, viewer, context ) )
        return 0;

    if( sizeof(input) == 1 && !context->number_included && !context->ordinal ) {
        if( input[<1] == "coins" || input[<1] == "money" || input[<1] == "all")
            return ({ OBJ_PARSER_MATCH_PLURAL, ({ TO }) });
        if( input[<1] == "coin") {
            // Only one coin.
            if( sizeof( money_array ) == 2 && money_array[ 1 ] == 1 )
                return ({ OBJ_PARSER_MATCH_PLURAL, ({ TO }) });
            // Pick the first coin, any coin...
            if( !num = update_parse_match_context( context, 1, ret ) )
                return 0;
            if( !ob = new_money_object( num, money_array[ 0 ], 0 ) )
                return 0;
            return ({ ret, ({ ob }) });
        }
    }

    every = context->number_included == EVERY_NUM;

    if( sizeof(input) == 1 && input[<1] == "coin") {
        // We matched on "every coin".
        if( every )
            return ({ ret, ({ TO }) });
        // Make it the first random coin.
        input[<1] = money_array[ 0 ];
    }

    if( every || ( !context->number_included && input[<1] == "coins") ) {
        if( sizeof( found = find_best_fit( input, 1 ) ) ) {
            foreach( string str in found ) {
                int i;

                // Lets see how many we have...
                i = member_array( str, money_array );
                num = money_array[ i + 1 ];
                if( num = update_parse_match_context( context, num, ret ) ) {
                    ob = new_money_object( num, str, ob );
                    // Do this so that we keep matching on the rest as well.
                    if( every )
                        context->number_included = EVERY_NUM;
                }
            }
        }

        if( ob )
            return ({ ret, ({ ob }) });
    }

    if( ( found = find_best_fit(input) ) == -1 )
        return 0;

    // Lets see how many we have...
    num = money_array[ found + 1 ];
    if( !num = update_parse_match_context( context, num, ret ) )
        return 0;

    if( !ob = new_money_object( num, money_array[found], 0 ) )
        return 0;

    return ({ ret, ({ ob }) });

} /* parse_match_object() */

/** @ignore yes */
int do_not_sell() { return 1; }

/** @ignore yes */
int query_value() { return 0; }

/** @ignore yes */
int query_value_in( string where ) {
    return MONEY_H->query_total_value( money_array, where );
} /* query_value_in() */

/**
 * This method returns the amount of type of money there is in the array.
 * @param type the type of money to check
 * @return the number of coins of that type
 */
int query_money( string type ){
    int i;

    if( ( i = member_array( type, money_array ) ) == -1 )
        return 0;

    return money_array[i+1];

} /* query_money () */

/** @ignore yes */
mapping query_dynamic_auto_load() {
    if( !_already_joined ) {
        return ([
            "::" : ::query_dynamic_auto_load(),
            "money array" : money_array,
        ]);
    }
} /* query_dynamic_auto_load() */

/** @ignore yes */
void init_dynamic_arg( mapping map ) {
    ::init_dynamic_arg( map["::"] );
    set_money_array( map["money array"] );
} /* init_dynamic_arg() */
