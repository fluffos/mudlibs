/**
 * This handles all the methods for determining values of coins and
 * the current valid set of coins.   It also handles change calculation.
 * This was written originaly by Pinkfish, reworked significantly by
 * Deutha to add in the multiple currency areas.
 * @see /std/living/money.c
 * @author Pinkfish
 * @changed Fixed up the code that deals with different currency areas.
 * Also added money_array_from_string() and made value_from_string()
 * work properly with different types of currencies.
 * - Sandoz, April 2003.
 */

#define DATA ((class money_data)details[type])

#define __MONEY_CLASS__
#include <money.h>

private mapping values;
private mapping details;
private mapping aliases;
private object parse_cont;

private void add_coin_type( string type, string head_short, string tail_short,
                            string head_long, string tail_long,
                            string material, string plural, string adj,
                            int weight ) {

    DATA = new( class money_data,
                head_short : head_short,
                tail_short : tail_short,
                head_long  : head_long,
                tail_long  : tail_long,
                material   : material,
                plural     : plural,
                adj        : adj,
                weight     : weight );

} /* add_coin_type() */

void create() {
    values = ([
        "default": ({
            "copper", 1,
            "silver", 10,
            "electrum", 100,
            "gold", 2000,
            "platinum", 6000,
            }),
        "calarien": ({
            "Calarien rahn", 1,
            "Calarien tablis", 100,
            "Calarien reaal", 10000,
            }),
        ]);

    details = ([ ]);

    add_coin_type("copper", "heads", "tails",
        "a head", "a tail", "copper", 0, "small", 10 );
    add_coin_type("silver", "heads", "tails",
        "a head", "a tail", "silver", 0, "thin and slighty scratched", 13 );
    add_coin_type("electrum", "heads", "tails",
        "a head", "a tail", "electrum", 0, "slightly scratched", 15 );
    add_coin_type("gold", "heads", "tails",
        "a head", "a tail", "gold", 0, "thin", 18 );
    add_coin_type("platinum", "heads", "tails",
        "a head", "a tail", "platinum", 0, "large and pretty heavy", 20 );

    // Weight a little less than 3 grams.
    add_coin_type("Calarien rahn", "heads", "tails",
        "an ornate number one, imprinted in a grubby surface",
        "a scratched carving of what might be a blooming sunflower",
        "copper", "rahns", "thin and scratched", 5 );
    // Weight a little over 7 grams.
    add_coin_type("Calarien tablis", "heads", "tails",
        "a crudely carved sun", "a delicate waxing moon",
        "silver", "tabli", "slightly scratched", 15 );
    // Weight a little over 12 grams.
    add_coin_type("Calarien reaal", "heads", "tails", "a small imprint of "
        "the Calarien crest along with the words \"1 REAAL\" underneath it",
        "a delicate carving of an eagle, its beak wide open and wings spread "
        "in their full glory", "gold", "reaali", "large and fairly heavy", 25 );

    aliases = ([
        "Calarien rahn"   : ({"rahn"}),
        "Calarien tablis" : ({"tablis"}),
        "Calarien reaal"  : ({"reaal"}),
    ]);

} /* create() */

/**
 * This method returns the mapping containing all the values of the
 * currently valid money types.   The mapping has keys of the domain
 * of the money and has a value of an array.   The array contains
 * alternating name, value pairs.
 * <pre>
 * ([ "default": ({ "brass", 1, "copper", 10, "silver", 100,
 *                  "gold", 2000, "platinum", 6000 }) ])
 * </pre>
 * @return the mapping of values
 * @see query_values()
 * @see query_values_in()
 */
mapping query_all_values() { return copy(values); }

/**
 * This method returns the current set of areas in which types can
 * be found.
 * @return the set of places
 */
string *query_all_places() { return keys(values); }

/**
 * This method returns the values in the default area.
 * This method returns the array as given in the value above.
 * It contains name, value pairs and is for the "default"
 * area.
 * @return the array of values
 * @see query_all_values()
 * @see query_values_in()
 */
mixed *query_values() { return copy( values["default"] ); }

/**
 * This method returns the values in the specified area.
 * It contains name, value pairs and is for the "default"
 * area.
 * @return the array of values
 * @param where the area in which to return the values for
 * @see query_all_values()
 * @see query_values()
 * @see add_type()
 */
mixed query_values_in( string where ) {
    if( !where || where == "")
        where = "default";
    return copy( values[where] );
} /* query_values_in() */

/**
 * This method returns all the details for the current set of
 * coins.   The details are information which is shown when the coin
 * is looked at.   Stuff about heads and tails and things.
 * @return the mapping of details for all coin types
 * @see /include/money.h
 */
mapping query_details() { return copy( details ); }

/**
 * This method returns the details for a specified type of money.
 * It will return a class of the form:
 * <pre>
 * ({ forward short, reverse short,
 *    forward long, reverse long, composition,
 *    plural, adjectives, weight })
 * </pre>
 * @param type the money type to get the details for
 * @see /include/money.h
 */
class money_data query_details_for( string type ) {
    if( DATA )
        return copy(DATA);
    return 0;
} /* query_details_for() */

/**
 * This method returns all the current aliases for the given type
 * of money.
 * @param type the type of money to get the aliases for
 * @return the aliases for the money type
 */
string *query_aliases_for( string type ) {
    string *ret;

    if( !DATA || !DATA->plural )
        ret = ({ "coin" });
    else
        ret = ({ explode( type, " ")[<1] });

    if( aliases[ type ] )
        ret += aliases[ type ];

    return ret;

} /* query_aliases_for() */

/**
 * This method returns the short description of the money type.
 * @param type the money type to get the short description for
 * @return the short description for the money object
 * @see query_main_plural_for()
 */
string query_short_for( string type ) {
    if( !DATA || !DATA->plural )
        return type+" coin";
    return type;
} /* query_short_for() */

/**
 * This method returns the short plural description of the money type.
 * This returns just the one word, like 'coins' or 'talons'.
 * @param type the money type to get the short plural description for
 * @return the short plural description for the money object
 * @see query_main_plural_for()
 */
string query_plural_for( string type ) {
    if( !DATA || !DATA->plural )
        return "coins";
    return DATA->plural;
} /* query_plural_for() */

/**
 * This method returns the main short plural description of the money type.
 * This returns the expanded plural version like 'Ankh-Morpork pennies'.
 * @param type the money type to get the short plural description for
 * @return the short plural description for the money object
 * @see query_plural_for()
 * @see query_short_for()
 */
string query_main_plural_for( string type ) {
    if( !DATA || !DATA->plural )
        return type+" coins";

    return implode( explode( type, " ")[0..<2] + ({ DATA->plural }), " ");

} /* query_main_plural_for() */

/**
 * This method returns the weight of 100 coins of the money type.
 * @param type the money type to get the weight of 100 coins for
 * @return the weight of 100 coins of the specified type
 */
int query_weight_for( string type ) {
    if( !DATA )
        return 10;
    return DATA->weight || 10;
} /* query_weight_for() */

/**
 * This method returns the value of a specified type of money in a certain
 * money area.
 * @param type the type of money to get the value for
 * @param where the money area the money is in
 * @return the integer value of the money
 * @see query_total_value()
 */
varargs int query_value( string type, string where ) {
    int i;

    if( !where || where == "")
        where = "default";

    if( !values[where] )
        return 0;

    if( ( i = member_array( type, values[where] ) ) == -1 )
        return 0;

    return values[where][i+1];

} /* query_value() */

/**
 * This method determines the total value of a specified money array.
 * A money array consists of pairs of values ({ type, number })
 * @param mon_array the array to find the value of
 * @param where the money area to get the value in
 * @return the total value as an integer
 * @see query_value()
 */
varargs int query_total_value( mixed mon_array, string where ) {
    int i, amt;

    if( !where || where == "")
        where = "default";

    for( i = 0; i < sizeof( mon_array ); i += 2 )
        amt += mon_array[ i + 1 ] * query_value( mon_array[ i ], where );

    return amt;

} /* query_total_value() */

/**
 * This method converts a money array into a string so it can be displayed.
 * @param mon_array the money array to convert into a string
 * @see money_value_string()
 */
string money_string( mixed mon_array ) {
    int i;
    string ret;

    if( !sizeof(mon_array) )
        return "nothing";

    ret = "";

    while( i < sizeof(mon_array) ) {
        if( !mon_array[ i + 1 ] )
            mon_array = delete( mon_array, i, 2 );
        else
           i += 2;
    }

    for( i = 0; i < sizeof(mon_array); i += 2 ) {
        ret += query_num(mon_array[ i + 1 ])+" ";

        if( mon_array[ i + 1 ] == 1 )
            ret += query_short_for( mon_array[ i ] );
        else
            ret += query_main_plural_for( mon_array[ i ] );

        if( i == sizeof(mon_array) - 4 )
            ret += " and ";
        else if ( i != sizeof(mon_array) - 2 )
            ret += ", ";
    }

    return ret;

} /* money_string() */

/**
 * This method creates a money array from a certain value in a particular
 * money area. A money array consists of ({ type, number }) pairs in an
 * array.   ie: ({ "brass", 12, "copper", 24 }).
 * @example
 * place = query_property("place");
 * if (!place) {
 *      place = "default";
 * }
 * mon_array = create_money_array( 1000, place);
 * @param value the value to get the money array for
 * @param where the money area to get the value in
 * @return a money array for the value in the area
 * @see money_value_string()
 */
varargs mixed create_money_array( int value, string where ) {
    int i, amt;
    mixed mon_array;

    if( !where || where == "")
        where = "default";

    if( !value )
        return ({ });

    mon_array = ({ });

    for( i = sizeof( values[ where ] ) - 2; i >= 0; i -= 2 ) {
        if( value >= values[ where ][ i + 1 ] ) {
            mon_array += ({ values[ where ][ i ], amt = value /
                            values[ where ][ i + 1 ] });
            value -= amt * values[ where ][ i + 1];
        }
    }

    return mon_array;

} /* create_money_array() */

/**
 * This method returns a string which is based on the value of
 * the money in a certain money area.
 * @param value the value to get the string for
 * @param where the place to get the string for
 * @return a string of the money value in the certain money area
 * @see create_money_array()
 * @see money_string()
 * @see value_from_string()
 */
varargs string money_value_string( int value, string where ) {
    if( !where || where == "")
        where = "default";

    if( value < 0 )
        return "negative "+money_string( create_money_array( -value, where ) );

    return money_string( create_money_array( value, where ) );

} /* money_value_string() */

/**
 * @ignore yes
 * This method is used both by value_from_string() and
 * money_array_from_string(). If the flag argument is 0, then it
 * will return the overall value of the money in the input string.
 * If the flag argument is 1, then it will parse the input string
 * and return it as a money array, if the flag is greater than 1,
 * then it will return on partial matches.
 */
private mixed int_money_from_string( string str, string where, int flag ) {
    mixed types, bits, ret;

    if( !where )
        where = "default";

    if( !types = values[where] )
        return 0;

    str = lower_case(str);
    bits = explode( replace( str, ({" and ", ",", " & ", ","}) ), ",");
    bits = map( bits, (: explode( $1, " ") - ({""}) :) );

    if( flag )
        ret = ({ });

    for( int i = 0; i < sizeof(types); i += 2 ) {
        string type, plural, *adj, *alias;

        type = types[i];

        if( sizeof( alias = aliases[type] ) ) {
            adj = explode( lower_case(type), " ")[0..<2];
            plural = DATA->plural;
        } else {
            alias = ({"coin"});
            adj = explode( lower_case(type), " ");
            plural = "coins";
        }

        for( int j = 0; j < sizeof(bits); j++ ) {
            string *bit, *match;
            int number;

            if( !sizeof( bit = bits[j] ) ) {
                bits = delete( bits, j--, 1 );
                continue;
            }

            if( sscanf( bit[0], "%d", number ) == 1 ) {
                // Nothing but a number, or a negative number specified.
                if( number < 1 || !sizeof( bit = bit[1..] ) ) {
                    bits = delete( bits, j--, 1 );
                    continue;
                }

                if( number == 1 )
                    match = alias;
                else
                    match = ({ plural });

            } else {
                number = 1;
                match = alias;
            }

            // Let's not match on a mere "1 coin".
            if( sizeof( bit ) == 1 ) {
                switch( bit[0] ) {
                  case "coin":
                  case "coins":
                    bits = delete( bits, j--, 1 );
                    continue;
                  default:
                }
            }

            // No match on the name/alias.
            if( member_array( bit[<1], match ) == -1 )
                continue;

            if( sizeof(bit) > 1 ) {
                int k, fail;

                fail = 0;
                k = sizeof(bit) - 1;

                while( k-- ) {
                    // Invalid adjective in the input string.
                    // No match.
                    if( member_array( bit[k], adj ) == -1 ) {
                        fail = 1;
                        break;
                    }
                }

                if( fail )
                    continue;
            }

            // Everything matched.
            if( flag ) {
                int k;

                if( ( k = member_array( type, ret ) ) == -1 )
                    ret += ({ type, number });
                else
                    ret[k+1] += number;

            } else {
                ret += number * types[i+1];
            }

            bits = delete( bits, j--, 1 );

        }
    }

    switch( flag ) {
      case 0 :
      case 1:
        return ret;
      default:
        // Do not accept partial matches with a flag greater than 1.
        if( !sizeof(bits) )
            return ret;
        return 0;
    }

} /* int_money_from_string() */

/**
 * This method attempts to find a money value from a string.  It will
 * attempt to do fuzzy matching of the type.  This means it will match on
 * partial matches, this could lead to somewhat weird behaviour...  So it
 * goes.
 * @param str the string to find the value of
 * @see money_value_string()
 * @see money_array_from_string()
 * @example
 * // This will tell us the integer money value of the string.
 * write( MONEY_H->value_from_string("1 dollar and 12 pence",
 *                                   "Ankh-Morpork"));
 */
int value_from_string( string str, string where ) {
    return int_money_from_string( str, where, 0 );
} /* value_from_string() */

/**
 * This method attempts to create a money array from a string.  It will
 * attempt to do fuzzy matching of the type.  This means it will match on
 * partial matches, this could lead to somewhat weird behaviour.
 * @param str the string to find the value of
 * @param where the currency area to get the money array for
 * @param flag if the flag is set, then we will return 0 on a partial match
 * @see money_value_string()
 * @see value_from_string()
 * @example
 * MONEY_H->money_array_from_string("12 Calarien rahns and 37 tabli",
 *                                  "calarien");
 */
mixed money_array_from_string( string str, string where, int flag ) {
    return int_money_from_string( str, where, flag ? 2 : 1 );
} /* money_array_from_string() */

/**
 * This method calculates the change of a certain value from a
 * given money array.   This makes sure that the change does not include
 * money that does not actually exist.
 * @param value the value of the change to calculate
 * @param mon_array the money array to determine the change from
 * @return the money array containing the change to use
 * @see make_payment()
 * @see pay_amount_from()
 */
mixed calc_change( int value, mixed *mon_array ) {
    int i, num;
    mixed ret;

    ret = ({ });

    for( i = sizeof( mon_array ) - 2; i >= 0; i -= 2 ) {
        if( value >= mon_array[ i + 1 ] ) {
            num = value / mon_array[ i + 1 ];
            value = value % mon_array[ i + 1 ];
            ret += ({ mon_array[ i ], num });

            if( !value )
                return ret;
        }
    }

    return ret;

} /* calc_change() */

/**
 * This method makes a payment from a money array.  It returns the
 * depleted money array, the amount taken out and the change
 * needed.  If the type is not set, then the best fit for the value
 * is found from the array.
 * <p>
 * The return array is formated as:<br>
 * ({ depleted_money_array, change, taken_from })<br>
 * The change is an integer value.
 * @param type the type of money to take out
 * @param value the amount of the type to take out
 * @param mon_array the money array to use
 * @param where the money area
 * @param use_default allow the use of the default money type
 * @return the return array as formated above
 */
mixed make_money_array_payment( string type, int value, mixed mon_array,
                                string where, int use_default ) {

    int i, j, num, total, cur_match;
    string mon_name;
    mixed poss_values, ret;

    // Figure out the money type.
    if( !where || where == "")
        where = "default";

    // See if the money is there and it's all easy.
    if( type ) {
        if( ( i = member_array( type, mon_array ) ) != -1 ) {
            if( value <= mon_array[ i + 1 ] ) {
                mon_array[ i + 1] -= value;
                return ({ ({ type, value }), 0, mon_array });
            }
        }

        // Damn, its not easy.  Figure out the real value and see if we can
        // get it out of the arrays.
        value = value * query_value( type, where );
    }

    // Check to make sure the total is ok.
    total = query_total_value( mon_array, where );
    if( use_default  &&  where != "default")
        total += query_total_value( mon_array, "default");

    // If the value is more than the total...
    if( value > total )
        return 0;

    // Get the possible values.
    poss_values = ({ });
    if( where != "default" && use_default )
        poss_values += values["default"];

    poss_values += values[ where ];

    ret = ({ });

    // This attempts an exact match of coins.
    for( i = ( sizeof( poss_values ) - 2 ); i >= 0; i -= 2 ) {
        j = member_array( poss_values[ i ], mon_array );
        if( j != - 1 ) {
            if ( poss_values[ i + 1 ] <= value ) {
                num = value / poss_values[ i + 1 ];

                if( num > mon_array[ j + 1 ] )
                    num = mon_array[ j + 1 ];

                mon_array[ j + 1] -= num;
                value -= num * poss_values[ i + 1 ];
                ret += ({ poss_values[ i ], num });

                if( !value )
                    return ({ ret, value, mon_array });
            }
        }
    }

    // No exact match...
    // Now we need to figure out how much change to give.
    // Zoom through the array finding which one has the closest match.
    cur_match = value + 10000000;

    for( i = 0; i < sizeof(poss_values); i +=2 ) {
        j = member_array( poss_values[ i ], mon_array );
        if( j != -1 && mon_array[j+1] > 0 &&
            poss_values[i+1] >= value &&
            poss_values[i+1] - value <= cur_match - value ) {
            cur_match = poss_values[i+1];
            mon_name = poss_values[i];
        }
    }

    if( mon_name ) {
        j = member_array( mon_name, mon_array );
        i = member_array( mon_name, poss_values );
        mon_array[j+1] -= 1;
        value = poss_values[i+1] - value;
        ret += ({ poss_values[ i ], 1 });
    } else {
        return 0;
    }

    return ({ ret, value, mon_array });

} /* make_money_array_payment() */

/**
 * This method makes a payment of a particular amount in a particular
 * money area.   Please note that player or living objects can double
 * as money objects in this circumstance.  The first element of the
 * payment array is the values which should be used to take off
 * the player, the second element is the change needed to be payed
 * back.
 * @param type the type of money to pay in
 * @param value the number of the type to pay
 * @param thing the thing which is doing the payment (money object)
 * @param where the money area the payment will occur in
 * @return the payment array
 * @see pay_amount_from()
 * @see calc_change()
 */
varargs mixed make_payment( string type, int value, object thing,
                            string where ) {
    mixed mon_array, stuff;

    if( !type )
        return 0;

    mon_array = copy( thing->query_money_array() );

    stuff = make_money_array_payment( type, value, mon_array, where, 1 );
    if( !stuff )
        return stuff;

    if( stuff[MONEY_PAY_CHANGE] )
        return ({ stuff[MONEY_PAY_RETURN],
                  calc_change( stuff[MONEY_PAY_CHANGE], values[where] ) });

    return ({ stuff[MONEY_PAY_RETURN], stuff[MONEY_PAY_CHANGE] });

} /* make_payment() */

/**
 * This method makes a payment from a specified money object.
 * @param value the amount to pay
 * @param money the money object to pay from
 * @param where the money area the payment occurs in
 * @return the change object
 * @see make_payment()
 * @see calc_change()
 */
varargs object pay_amount_from( int value, object money, string where ) {
    int i, j;
    object change;
    mixed m_array, p_array;

    if( !where || where == "")
        where = "default";

    change = clone_object( MONEY_OBJECT );
    m_array = create_money_array( value, where );

    for( i = 0; i < sizeof(m_array); i += 2 ) {
        p_array = make_payment( m_array[ i ], m_array[ i + 1 ], money, where );

        if( !pointerp( p_array ) )
            continue;

        for( j = 0; j < sizeof( p_array[0] ); j += 2 )
            money->adjust_money( -p_array[ 0 ][ j + 1 ], p_array[ 0 ][ j ] );

        if( sizeof( p_array[ 1 ] ) )
            change->adjust_money( p_array[ 1 ] );
    }

    if( !sizeof( change->query_money_array() ) ) {
        change->dest_me();
        return 0;
    }

    return change;

} /* pay_amount_from() */

/**
 * This method creates a money object of a certain value in a certain
 * money area.
 * @param value the value to create the new money object with
 * @param where the area to create the new money object in
 * @return the new money object
 */
varargs object make_new_amount( int value, string where ) {
    object money;

    if( !where || where == "")
        where = "default";

    money = clone_object( MONEY_OBJECT );
    money->set_money_array( create_money_array( value, where ) );

    if( !money->query_value_in( where ) ) {
        money->dest_me();
        return 0;
    }

   return money;

} /* make_new_amount() */

/**
 * This method figures out the legal and illegal tender money from
 * the specified money object in the specified money area.   This method
 * returns a two element array which consists of the legal and illegal
 * tender for the given money area.   ({ legal, illegal })
 * @param money the money object to get the legal tender from
 * @param where the money area the tender is for
 * @return an two element array of objects ({ legal, illegal })
 * @see parse_money()
 */
varargs object *filter_legal_tender( object money, string where ) {
    int i;
    object good, no_good;
    mixed mon_array, poss_values;

    if( !where || where == "")
        where = "default";

    if( !sizeof( mon_array = money->query_money_array() ) ) {
        money->dest_me();
        return ({ 0, 0 });
    }

    if( !( poss_values = values[ where ] ) )
        poss_values = ({ });

    if( where != "default" )
        poss_values += values["default"];

    for( i = 0; i < sizeof(mon_array); i += 2 ) {
        if( member_array( mon_array[ i ], poss_values ) != -1 ) {
            if( !good )
                good = clone_object(MONEY_OBJECT);
            good->adjust_money( mon_array[ i + 1 ], mon_array[ i ] );
        } else {
            if( !no_good )
                no_good = clone_object(MONEY_OBJECT);
            no_good->adjust_money( mon_array[ i + 1 ], mon_array[ i ] );
        }
    }

    money->dest_me();

    if( good && !sizeof( good->query_money_array() ) )
        good->dest_me();

    if( no_good && !sizeof( no_good->query_money_array() ) )
        no_good->dest_me();

    return ({ good, no_good });

} /* filter_legal_tender() */

/**
 * This method determines all the money from the player object and moves
 * it into a container.  It then figured out the legal tender for
 * specified money area and tells the player if the given money is
 * legal tender for the current area.
 * @param words the string to match the money on
 * @param player the player who is attempting the transaction
 * @param place the money area the transaction is taking place
 * @return a money object consisting of the legal tender
 * @see filter_legal_tender()
 */
varargs mixed parse_money( string words, object player, string place ) {
    object thing, *monies, *things;

    things = match_objects_for_existence( words, ({ player }) );
    if( !sizeof(things) )
        return NO_MATCH;

    if( !parse_cont ) {
        parse_cont = clone_object("/std/container");
    } else if( sizeof( INV(parse_cont) ) ) {
        parse_cont->dest_me();
        parse_cont = clone_object("/std/container");
    }

    foreach( thing in things )
        if( thing->query_property("money") )
            thing->move(parse_cont);

    if( !sizeof( things = INV(parse_cont) ) )
        return NO_MONEY;

    monies = filter_legal_tender( things[ 0 ], place );

    if( monies[ 1 ] ) {
        if( monies[ 1 ]->move(player) ) {
            monies[ 1 ]->move( ENV(player) );
            tell_object( player, "Oh dear, you seem to be somewhat "
                "overburdened and fumble "+monies[ 1 ]->the_short()+".\n");
        }

        tell_object( player, monies[ 1 ]->the_short()+
            ( monies[ 1 ]->query_number_coins() == 1 ? " is" : " are")+" not "
            "legal tender here.\n");

        if( !monies[ 0 ] )
            return NO_LEGAL;

    }

    return monies[ 0 ];

} /* parse_money() */

/**
 * This method makes a payment from one person to another.
 * This method figures out what money should be given to the player
 * and what should be taken from the other to make a payment of the
 * correct value in the correct place.
 * @param value the value to pay
 * @param place the place to make the payment in
 * @param payer the person the money is payed from
 * @param payee the person the money is payed to
 * @return two element array, or 0 if it cannot be done
 */
mixed query_person_payments( int value, string place, object payer,
                             object payee ) {
    mixed stuff, mon_array, rabbit;

    mon_array = copy( payer->query_money_array() );

    stuff = make_money_array_payment( 0, value, mon_array, place, 0 );
    if( !stuff )
        return 0;

    if( stuff[MONEY_PAY_CHANGE] ) {
        // Now check to see if we can get the change from the other guy.
        mon_array = copy( payee->query_money_array() );
        rabbit = make_money_array_payment( 0, stuff[MONEY_PAY_CHANGE],
                 mon_array, place, 0 );

        if( !rabbit || rabbit[MONEY_PAY_CHANGE] )
            return 0;

        return ({ stuff[MONEY_PAY_RETURN], rabbit[MONEY_PAY_RETURN] });
    }

    return ({ stuff[MONEY_PAY_RETURN], ({ }) });

} /* query_person_payments() */

/**
 * This returns a list of valid coin types
 * @return an array of valid coin types
 */
string *query_valid_types() {
    string *tmp, *valid_types = ({ });
    mixed elem;
    int i;

    tmp = values( query_all_values() );

    foreach( elem in tmp ) {
        for( i = 0; i < sizeof(elem); i++ ) {
            if( stringp( elem[i] ) )
                valid_types += ({ elem[i] });
        }
    }

    return valid_types;

}/* query_valid_types() */

/**
 * This takes a coin type and returns the place it is associated with.
 * @param type the coin type i.e. "Ankh-Morpork dollar"
 * @return the place i.e. "Ankh-Morpork"
 */
string query_origin_of( string type ) {
    string elem, *places;

    if( member_array( type, query_valid_types() ) == -1 )
        return 0;

    places = query_all_places();

    foreach( elem in places )
        if( member_array( type, query_values_in( elem ) ) != -1 )
            return elem;

} /* query_origin_of() */

/**
 * This converts a currency type's alias (i.e. "royal" ) and returns
 * its 'real' names (i.e. "Ankh-Morpork royal"
 * @param word the alias to find the real name of
 * @return an array of real names, or 0 if it's not a real alias
 */
string *query_aliases_of( string word ) {
    string *types, elem, *aliases = ({ });

    types = query_valid_types();

    foreach( elem in types ) {
        if( member_array( word, query_aliases_for( elem ) ) != -1 )
            aliases += ({ elem });
    }

    return aliases;

} /* query_aliases_of */

/**
 * This returns the value of a currency type.
 * @param type currency type
 * @return an int of the currency type's value
 */
int query_value_of( string type ) {
    if( member_array( type, query_valid_types() ) == -1 )
        return 0;
    return query_value( type, query_origin_of( type ) );
} /* query_value_of() */

/**
 * This returns the smallest unit of currency in this place.
 * @param place The place to query.
 * @return a string of the smallest unit of currency
 */
string smallest_in( string place ) {
    int i, j, smallest;
    mixed values;

    values = query_values_in( place );
    for( i = 1; i < sizeof(values); i += 2 ) {
        if( !smallest || values[i] < smallest ) {
            smallest = values[i];
            j = i;
        }
    }

    return values[j-1];

} /* smallest_in() */
