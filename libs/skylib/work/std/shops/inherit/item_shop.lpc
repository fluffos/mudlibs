/**
 * Item shop inherit.
 * @author Pinkfish
 * @change /17/03/00 Aquilo Separated the storing and duplicating of
 * items which was moved to /std/shops/inherit/clone_on_demand
 * @see /std/shops/inherit/clone_on_demand
 */

#include <armoury.h>
#include <money.h>
#include <move_failures.h>

#define INFINITE_LEFT 10000
#define TYPE "item shop type"
#define DISPLAY "display in shop"

inherit "/std/shops/inherit/clone_on_demand";
inherit "/std/shops/inherit/shopkeeper_base";

private nosave int _no_steal;
private nosave int _steal_difficulty;
private nosave string _shoplift_handler;
private nosave function _open_func;
private nosave function _list_func;
private nosave function _browse_func;
private nosave function _buy_func;
private nosave function _sort_func;

int do_word_buy(string str);
int do_word_browse(string str);
int do_buy( object *things );
int do_browse( object *things );
void remove_property(string name);
mixed query_property(string name);

void create() {
    TO->add_help_file("item_shop");
} /* create() */

/** @ignore yes */
void reset() {
    ::reset();
    // This is incremented by shoplifting.
    if( !random( 3 ) )
        TO->remove_property("inventory_loss");
} /* reset() */

mixed switch_extra_properties() { return ({ TYPE, DISPLAY }); }

/**
 * This method tells us if the shop is really a shop or not.
 * @return 1 always
 */
int query_shop() { return 1; }

/**
 * This method returns the items which can potentially be shop lifted
 * with the passed in string.
 * @param str the name for the object to attempt to shop lift
 * @return the array of matching objects
 * @see query_steal_difficulty()
 * @see query_shoplift_response_handler()
 */
object *query_shop_lift_items( string str, object player ) {
    return filter( match_objects_for_existence( str, ({ query_cont() }) ),
        (: query_num_items_left($1) > 0 :) );
} /* query_shop_lift_items() */

/**
 * This method turns the objects into real objects (if that is
 * nessessary, it is not with a normal shop).
 * @param ob the object to turn into a normal object
 */
object shoplift_success( object ob ) {
    object real_ob;

    real_ob = create_real_object(ob);

    return real_ob;

} /* shoplift_success() */

string query_shoplift_response_handler() { return _shoplift_handler; }
void set_shoplift_response_handler( string word ) { _shoplift_handler = word; }

/**
 * This method sets the function to evaluate to detmine if the shop
 * is open or not.
 * @param func the function to evaluate for openness
 * @see query_open_func()
 * @see set_open_condition()
 */
void set_open_func( function func ) { _open_func = func; }

/**
 * This method makes it compatible with the way that the open stuff works in
 * the normal shops.
 * @param func the function to evaluate for openness
 * @see set_open_func()
 * @see query_open_func()
 */
void set_open_condition( function func ) { _open_func = func; }

/**
 * This method returns the function to evaulate to dermine if the
 * shop is open or not.
 * @return the function to use for openess
 * @see set_open_func()
 * @see set_open_condition()
 */
function query_open_func() { return _open_func; }

/**
 * This method sets the function to use when buying something from
 * the shop.  The function will be called with two arguements, the
 * first is the player, the second is the array of objects being
 * bought.
 * @param func the function to set
 * @see set_list_function()
 * @see set_buy_function()
 * @see set_browse_function()
 * @see query_buy_function()
 */
void set_buy_function( function func ) { _buy_func = func; }

/**
 * This method returns the functionto be used when buying something.
 * @return the function to be used when buying something
 * @see query_list_function()
 * @see query_browse_function()
 * @see set_buy_function()
 */
function query_buy_function() { return _buy_func; }

/**
 * This method sets the function to use when browseing something from
 * the shop.  The function will be called with two arguements, the
 * first is the player, the second is the array of objects being
 * browsed.
 * @param func the function to set
 * @see set_list_function()
 * @see set_buy_function()
 * @see set_browse_function()
 * @see query_browse_function()
 */
void set_browse_function( function func ) { _browse_func = func; }

/**
 * This method returns the functionto be used when browseing something.
 * @return the function to be used when browseing something
 * @see query_list_function()
 * @see query_browse_function()
 * @see set_buy_function()
 */
function query_browse_function() { return _browse_func; }

/**
 * This method sets the function to use when listing something from
 * the shop.  The function will be called with two arguements, the
 * first is the player, the second is the array of objects being
 * bought.
 * @param func the function to set
 * @see set_list_function()
 * @see set_buy_function()
 * @see set_browse_function()
 * @see query_list_function()
 */
void set_list_function( function func ) { _list_func = func; }

/**
 * This method returns the functionto be used when listing something.
 * @return the function to be used when listing something
 * @see query_buy_function()
 * @see query_browse_function()
 * @see set_list_function()
 */
function query_list_function() { return _list_func; }

/**
 * This method determins if the shop is open.  THis will use the open
 * function to determine this.
 * @param player the player we are seeing if it is open for
 * @return 1 if it is open, 0 if not
 */
private int is_open( object player ) {
    if( !check_shopkeeper_open() )
        return 0;
    if( _open_func )
        return evaluate( _open_func, player );
    return 1;
} /* is_open() */

/**
 * This method sets a function to be used to sort the inventory when it
 * is printed out.
 * @param func the function to use to sort the inventory
 * @see query_sort_function()
 */
void set_sort_function( function func ) { _sort_func = func; }

/**
 * This method returns the function used to sort the inventory of the
 * shop when it is printed out.
 * @return the function to use to sort the inventory
 * @see set_sort_function()
 */
function query_sort_function() { return _sort_func; }

/**
 * Sets this room as being unstealable.
 * @param i 1 if the room is unable to be stolen from
 * @see query_no_steal()
 */
void set_no_steal( int i ) { _no_steal = i; }

/**
 * Queries to see if the room is unstealable.
 * @return 1 for making the room unstealable
 * @see set_no_steal()
 */
int query_no_steal() { return _no_steal; }

/**
 * Sets the steal difficulty of the room.
 * @param i the steal difficulty of the room
 */
void set_steal_difficulty( int i ) { _steal_difficulty = i; }

/**
 * This method returns the steal difficulty of the room.
 * @return the steal difficulty of the room
 */
int query_steal_difficulty(int i) { return _steal_difficulty; }

/** @ignore yes */
void init() {
   if( query_cont() ) {
       add_command("list", "[all]" );
       add_command("browse", "<indirect:object:"+file_name(query_cont())+">");
       add_command("browse", "<word>", (: do_word_browse($4[0]) :) );
       add_command("buy", "<indirect:object:"+file_name(query_cont())+">");
       add_command("buy", "<word>", (: do_word_buy($4[0]) :) );
   }
} /* init() */

private object find_object_from_number( int number ) {
    object *things;

    things = all_inventory( query_cont() );
    if( number >= sizeof( things ) ) {
        add_failed_mess("There is no item with that label.\n");
        return 0;
    }

    if( _sort_func )
        things = sort_array( things, _sort_func );

    return things[number];

} /* find_object_from_number() */

private string letter_name( int letter, object* things ) {
    string bing;

    if( sizeof(things) > 26 ) {
        bing = "AA";
        bing[0] = 'A' + (letter / 26);
        bing[1] = 'A' + (letter % 26);
        return bing;
    }

    bing = "A";
    bing[0] = 'A' + letter;

    return bing;

} /* letter_name() */

private string start_letter() {
    object *things;

    things = INV( query_cont() );

    return letter_name( 0, things );

} /* start_letter() */

private string end_letter() {
    object *things;

    things = INV( query_cont() );

    return letter_name( sizeof(things) - 1, things );

} /* end_letter() */

private int query_number_from_string( string name ) {
    object *things;
    int pos, sz;

    things = INV( query_cont() );

    if( ( sz = sizeof(things) ) > 26 ) {
        if( strlen(name) != 2 )
            return -1;

        name = lower_case(name);
        if( name[0] < 'a' || name[0] > 'z' )
            return -1;

        if( name[1] < 'a' || name[1] > 'z' )
            return -1;

        pos = ( name[0] - 'a') * 26 + name[1] - 'a';
        if( pos >= sz )
            return -1;

        return pos;

    }

    if( strlen(name) != 1 )
        return -1;

    name = lower_case(name);
    if( name[0] < 'a' || name[0] > 'z' )
        return -1;

    pos = name[0] - 'a';
    if( pos >= sz )
        return -1;

    return pos;

} /* query_number_from_string() */

/**
 * This method returns the cost of the item shop object being talked about.
 * @param thing the thing to get the cost of
 * @return the cost of the thing
 */
int query_cost( object thing ) {
    int cost;
    string place;

    if( !thing )
        return 0;

    if( ENV( thing ) == query_cont() &&
        ( cost = thing->query_property("cost here") ) )
        return cost;

    cost = thing->query_value_at(TO);

    if( !place = query_property("place") )
        return cost;

    // This avoids problems with rounding errors.
    cost = MONEY_H->query_total_value(
           MONEY_H->create_money_array( cost, place ), place );

    if( ENV( thing ) == query_cont() )
        thing->add_property("cost here", cost );

    return cost;

} /* query_cost() */

/** @ignore yes */
int do_list( string str ) {
    int i, left;
    string list, place, display;
    object thing, *listed, *things;

    if( !is_open(TP) )
        return -1;

    place = query_property("place");
    if( !place || place == "")
        place = "default";

    if( !query_cont() ) {
        add_failed_mess("There is nothing to buy here.\n");
        return 0;
    }

    listed = ({ });
    list = "";

    things = INV( query_cont() );

    if( _sort_func )
        things = sort_array( things, _sort_func );

    foreach ( thing in things ) {
        if( !left = query_num_items_left(thing) ) {
            i++;
            continue;
        }

        display = (string)thing->query_property( DISPLAY );

        if( !stringp(display) && thing->short() )
            display = (string)thing->a_short();

        if( display ) {
            list += "$I$6=   "+letter_name( i, things )+": "+display+" for "+
                MONEY_H->money_value_string( TO->query_cost( thing ), place );
            if( left == INFINITE_LEFT )
                list += " (plenty left).$I$0=\n";
            else
                list += " (" + query_num( left, 0 ) +" left).\n";
            listed += ({ thing });
        }
        i++;
    }

    if( list == "") {
        add_failed_mess("There is nothing to buy here.\n");
        return 0;
    }

    list = PLAYER_OBJ->convert_message(list);

    tell_object( TP, "$P$item list$P$"
        "The following items are for sale:\n" + list );

    add_succeeded_mess( ({"", "$N list$s the inventory.\n"}) );

    if( _list_func )
        evaluate( _list_func, TP, listed );

    do_shopkeeper_list();
    return 1;

} /* do_list() */

/** @ignore yes */
int do_word_buy( string str ) {
    object thing;
    int i;

    if( !is_open(TP) )
        return -1;

    if( strlen( str ) <= 2 ) {
        if( ( i = query_number_from_string( str ) ) == -1 ) {
            add_failed_mess("The item label must be from "+
                start_letter()+" to "+end_letter()+".\n");
            return 0;
        }

        if( !thing = find_object_from_number( i ) )
            return 0;

        return do_buy( ({ thing }) );
    }

    return 0;

} /* do_word_buy() */

/** @ignore yes */
int do_buy( object *things ) {
    int i, cost, value, ret;
    string place;
    object thing, *sold;

    if( !is_open(TP) )
        return -1;

    sold = ({ });

    for( i = 0; i < sizeof(things); i++ ) {
        if( query_num_items_left( things[i] ) <= 0 ) {
            add_failed_mess("The shop is sold out of "+
                things[ i ]->query_plural()+".\n");
            return 0;
        }

        place = query_property("place");
        if( !place || place == "")
            place = "default";

        value = TP->query_value_in( place );
        if( place != "default" )
            value += TP->query_value_in("default");

        if( ( cost = TO->query_cost( things[i] ) ) > value ) {
            add_failed_mess("You cannot afford to buy $I.\n", things[i..i] );
        } else {
            mixed arr, str;
            object ob;

            if( !ob = ( thing = create_real_object( things[i] ) ) ) {
                add_failed_mess("Something has broken, please file a bug "
                    "report.  Thank you.\n");
                return 0;
            }

            ret = 1;
            TP->pay_money( arr = MONEY_H->create_money_array( cost, place ),
                place );

            TO->something_bought( thing, TP, cost );
            if( query_property("package items") )
                thing = TO->package_item( thing );

            str = "You buy $I for "+MONEY_H->money_string(arr);

            if( thing->move(TP) ) {
                thing->move(TO);
                str += ", but unfortunately you cannot pick "+
                    ( query_group(ob) ? "them up, so they are" :
                    "it up, so it is")+ " left "+
                    ( TO->query_property("here") || "on the floor")+
                    " for you";
            }
            add_succeeded_mess( ({ str+".\n", "$N $V $I.\n"}), ({ ob }) );
            sold += ({ thing });
        }
    }

    if( _buy_func )
        evaluate( _buy_func, TP, sold );

    if( ret )
        do_shopkeeper_buy();

    return ret;

} /* do_buy() */

/** @ignore yes */
int do_word_browse( string words ) {
    int i;
    object thing;

    if( !is_open(TP) )
        return -1;

    if( strlen( words ) <= 2 ) {
        if( ( i = query_number_from_string( words ) ) == -1 ) {
            add_failed_mess("The item label must be from "+
                start_letter()+" to "+end_letter()+".\n");
            return 0;
        }

        if( !thing = find_object_from_number( i ) )
            return 0;

        return do_browse( ({ thing }) );
    }

    return 0;

} /* do_browse_word() */

/** @ignore yes */
int do_browse( object *things ) {
    int i, sz, num;
    string place, mess;

    if( !is_open(TP) )
        return -1;

    place = query_property("place");
    if( !place || place == "")
        place = "default";

    mess = "";
    sz = sizeof(things);

    for( i = 0; i < sz; i++ ) {
        object ob;

        if( query_num_items_left( ob = things[i] ) ) {
            mess += ob->the_short()+" is priced at "+
                MONEY_H->money_value_string( TO->query_cost( ob ),
                place )+" and looks like:\n"+ob->long();
            add_succeeded_mess( ({"", "$N $V $I.\n"}), things[i..i] );
            num++;
        }
    }

    if( !num ) {
        add_failed_mess("The shop is sold out of $I.\n", things );
        return 0;
    }

    write("$P$Browse things$P$" + mess );

    if( _browse_func )
        evaluate( _browse_func, TP, things );

    do_shopkeeper_browse();
    return 1;

} /* do_browse() */

/** @ignore yes */
void event_shoplift( object command_ob, object thief, object victim ) {
    if( stringp(_shoplift_handler) ) {
        if( _shoplift_handler != "none")
            _shoplift_handler->handle_shoplift( thief, victim );
    } else if( functionp(_shoplift_handler) ) {
         evaluate( _shoplift_handler, thief, victim );
    } else {
        THEFT_H->handle_shoplift( thief, victim );
    }
} /* event_shoplift() */

/** @ignore yes */
mixed stats() { return clone_on_demand::stats() + shopkeeper_base::stats(); }
