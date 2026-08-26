/**
 * This file contains all the code need to handle the types of carrying
 * which npcs tend to involve themselves in.
 * @author Pinkfish
 * @changed Changed query_wearing_hidden() to deal better with items
 * with multiple types - Sandoz, Dec. 2003.
 */

#include <money.h>

object* query_wearing();

/**
 * This method returns the list of types of things which are passed into
 * the array.
 * <p>
 * Two elements in an array is returned, the first element is the list of
 * all of the different types which are worn and the second is the list
 * of types corresponding to each of the inputs.
 * @param things the things to check
 * @return a two element array
 * @see armour_list()
 */
protected varargs mixed query_types_worn( object *things ) {
    int i;
    string *types;
    mixed stuff;

    types = ({ });

    if( !things )
        things = (object *)TO->query_wearing();

    i = sizeof( stuff = (mixed *)things->query_type() );

    while( i-- ) {
        if( stringp( stuff[ i ] ) )
            stuff[ i ] = ({ stuff[ i ] });
        if( !pointerp( stuff[ i ] ) ) {
            printf("%O (%s) has an invalid type.  Please bug report it.\n",
                things[ i ], (string)things[ i ]->query_short() );
            stuff[ i ] = ({"broken"});
        }
        types += stuff[ i ];
    }

    return ({ types, stuff });

} /* query_types_worn() */

/**
 * This method returns the items that are hidden by something on top of
 * them.
 * @param looker the person looking at the items
 * @param things an optional set of things
 * @return the hidden worn types
 */
object* query_wearing_hidden( object looker, object *things ) {
    string *types, *under, under_type;
    object *worn, *ret;
    mixed obj_types;
    int i, j;

    worn = ( !things ? query_wearing() : things );

    obj_types = query_types_worn( worn );
    types = obj_types[0];
    obj_types = obj_types[1];

    ret = ({ });
    i = sizeof(worn);

    while( i-- ) {
        if( worn[i]->query_visible(looker) ) {
            j = sizeof( obj_types[i] );

            // We cycle through each type, and are only hidden if every
            // type is covered. This way jumpers won't cover whole dresses,
            // because the skirt part is still visible. - Sandoz, 2003.
            while( j-- ) {
                under = CLOTHING_H->query_clothing_hiding( obj_types[i][j] );

                if( sizeof(under) ) {
                    foreach( under_type in under ) {
                        if( member_array( under_type, types ) != -1 )
                            obj_types[i] = delete( obj_types[i], j, 1 );
                    }
                }

                // No more visible types left.
                if( !sizeof( obj_types[i] ) ) {
                    ret += ({ worn[i] });
                    break;
                }
            }
        } else {
            ret += ({ worn[i] });
        }
    }

    return ret;

} /* query_wearing_hidden() */

/**
 * This method returns a string list of the armours which the player
 * is wearing.  It will show also modify the list to show only hidden
 * items (items under other items are considered hidden).
 * @param things the things to get the list of armours from
 * @param hidden_only only show the list of hidden objects
 * @see query_types_worn()
 * @see query_living_contents()
 */
protected string armour_list( object *things, int hidden_only, int self ) {
    object* hidden;

    hidden = query_wearing_hidden( TP, things );

    if( hidden_only )
        things = filter( hidden, (: $1->query_visible( TP ) :) );
    else
        things = things - hidden;

    if( !sizeof( things ) )
        return 0;

    // Order them in a reasonable way.
    if( !self )
        things = sort_array( things, (:
            CLOTHING_H->query_clothing_depth($2->query_type())  -
            CLOTHING_H->query_clothing_depth($1->query_type()) :) );

    return query_multiple_short( things );

} /* armour_list() */

/**
 * This method does the inventory of the living objects we all know and
 * love.  It is used in the long description and the inventory commands.
 * @param self are we showing our own inventory
 * @see armour_list()
 * @index inventory
 */
string query_living_contents( int self ) {
    string s;
    string *limbs, *bits, *strs;
    object *carry, *conts, *holding, *arms;
    object money, ob;
    int i, coins, pos;
    mixed fish;

    s = "";
    strs = ({ });

    if( !limbs = TO->query_limbs() )
        limbs = ( TO->query_race_ob() )->query_limbs();

    conts = filter( INV(TO), (: $1->short(0) :) );
    money = present( MONEY_ALIAS, TO );
    i = sizeof( holding = (object *)TO->query_holding() + ({ }) );

    if( !arms = (object *)TO->query_armours() - holding )
        arms = ({ });

    carry = conts - arms - holding - ({ money });

    while( i-- ) {
        if( holding[i] ) {
            bits = ({ limbs[i] });
            ob = holding[i];
            holding[i] = 0;
            while( ( pos = member_array( ob, holding ) ) != -1 ) {
                bits += ({ limbs[pos] });
                holding[pos] = 0;
            }
            strs += ({ ob->a_short()+" ("+
                query_multiple_short( bits, "a", 1 )+")" });
        }
    }

    if( sizeof(strs) )
        s += "$I$+10,+0=%^RED%^Holding%^RESET%^ : "+
             query_multiple_short( strs )+".\n$I$-10,-0=";

    if( sizeof( arms ) ) {
        if( fish = armour_list( arms, 0, self ) )
            s += "$I$+10,+0=%^YELLOW%^Wearing%^RESET%^ : "+fish+
                 ".\n$I$-10,-0=";
        if( self && ( fish = armour_list( arms, 1, self ) ) )
            s += "$I$+10,+0=%^YELLOW%^(under)%^RESET%^ : "+fish+
                 ".\n$I$-10,-0=";
    }

    if( sizeof( carry ) ) {
        if( fish = TO->query_contents( 0, carry, 1 ) ) {
            if( pointerp(fish) )
                s += "$I$+10,+0=%^GREEN%^"+fish[1]+"%^RESET%^: "+
                     fish[0]+"$I$-10,-0=";
            else
                s += "$I$+10,+0=%^GREEN%^Carrying%^RESET%^: "+fish+
                     "$I$-10,-0=";
        }
    }

    if( self && s == "")
        s = "You are empty handed.\n";

    if( self && !TO->check_dark( ENV(TO)->query_light() ) ) {
        s += "Your purse contains "+( money ?
             query_multiple_short( (string *)money->half_short( 1 ) ) :
             "only moths" )+".\n";
    } else {
       if( money )
           coins = (int)money->query_number_coins();
       if( coins ) {
           s += ( self ? "Your" : CAP( (string)TO->HIS ) ) + " purse is ";
           switch( coins ) {
             case 0..10:
               s += "home to only moths!";
             break;
             case 11..100:
               s += "tinkling with coins.";
             break;
             case 101..300:
               s += "bulging with coins.";
             break;
             default:
               s += "fit to burst!";
           }
           s += "\n";
       }
    }

    return s;

} /* query_living_contents() */
