/**
 * This the base shop.  It buys and sells stuff form players.
 * <p>
 * A storeroom must be set for the shop!
 * <p>
 * Original made who knows when.
 * @author Pinkfish
 * @see set_storeroom()
 * @change bil
 * to make the list a lot nicer.
 * @change Pinkfish
 * to give shops types and make them send out
 * reps to sell/buy things from other shops.
 * @change Ceres
 * to add burglable storerooms.
 * @change 23-11-97, Gototh
 * to add buy, sell, list, browse, value,
 * cost_too_muchy and not_worthy functions.
*/

#include <money.h>
#include <move_failures.h>
#include <shop.h>

inherit "/std/shops/inherit/shopkeeper_base";
inherit ROOM_OBJ;

mixed our_storeroom, buy_mess, sell_mess, list_mess, value_mess,
too_costly_mess, not_worthy_mess, browse_mess, open_cond, *other_shops;

int amount_sold, amount_bought, strict_shop, no_steal,
sell_stolen, steal_difficulty, min_amount, max_inventory, sell_large;

mixed shop_type, buy_func, sell_func, value_func, too_costly_func,
cannot_sell_func, browse_func, list_func;

nosave string shoplift_handler;

string original_storeroom;

string shop_list(mixed arr, int detail);
string shop_parse(string str, mixed ob, object client, string money,
  string extra, string which);
string find_free_exit();
int do_buy(object *ob);
int do_list_these(object *obs);
void do_buy_things( object *obs, int cost, object pl );
void do_parse(mixed arr, mixed ob, object client, string money,
  string extra);
object create_mercenary(object rep);
void event_shoplift(object command_ob, object thief, object victim);
object query_store_room();

void create() {
    buy_mess = ({
      "You buy $ob$ for $money$.\n",
      "$client$ buys $ob$.\n"});
    sell_mess = ({
      "You sell $ob$ for $money$.\n",
      "$client$ sells $ob$.\n"});
    list_mess = "$extra$";
    value_mess = "$ob$ is valued at $money$.\n";
    too_costly_mess = "$ob$ is worth too much to be sold here.\n";
    not_worthy_mess = "$ob$ is not worth enough to be sold here.\n";
    browse_mess = "$ob$ costs $money$, it looks like:\n$extra$";
    open_cond = 1;
    other_shops = ({ });
    max_inventory = MAX_INVENTORY;
    min_amount = 50;
    add_help_file("shop");
    ::create();
} /* create() */

/** @ignore yes */
void reset() {
    if( !random(3) ) {
        // This is incremented by shoplifting.
        remove_property("inventory_loss");
    }

    call_out("send_out_reps", 2 );

} /* reset() */

/**
 * This method sets the function to call when buying something.  The
 * function will be called with two elements, the first being the
 * player doing the buying and the second being the array
 * of objects being bought.
 * <p>
 * If the function is a string then the function of that name
 * will be called on the shop, if it is a function pointer
 * then the function pointer will be evaluated.
 * @param func the function to call
 * @see set_sell_function()
 * @see set_value_function()
 * @see set_too_costly_function()
 * @see set_cannot_sell_function()
 * @see set_browse_function()
 * @see set_list_function()
 */
void set_buy_function( mixed func ) {
    if( stringp(func) || functionp(func) )
        buy_func = func;
} /* set_buy_function() */

/**
 * This method sets the function to call when selling something.  The
 * function will be called with two elements, the first being the
 * player doing the selling and the second being the array
 * of objects being sold.
 * <p>
 * If the function is a string then the function of that name
 * will be called on the shop, if it is a function pointer
 * then the function pointer will be evaluated.
 * @param func the function to call
 * @see set_buy_function()
 * @see set_value_function()
 * @see set_too_costly_function()
 * @see set_cannot_sell_function()
 * @see set_browse_function()
 * @see set_list_function()
 */
void set_sell_function( mixed func ) {
    if( stringp(func) || functionp(func) )
        sell_func = func;
} /* set_sell_function() */

/**
 * This method sets the function to call when an item(*s) are being
 * valued.  The
 * function will be called with three elements, the first being the
 * player doing the valueing and the second being the array
 * of objects being valued and the third being the string
 * value of the objects.
 * <p>
 * If the function is a string then the function of that name
 * will be called on the shop, if it is a function pointer
 * then the function pointer will be evaluated.
 * @param func the function to call
 * @see set_sell_function()
 * @see set_buy_function()
 * @see set_too_costly_function()
 * @see set_cannot_sell_function()
 * @see set_browse_function()
 * @see set_list_function()
 */
void set_value_function( mixed func ) {
    if( stringp(func) || functionp(func) )
        value_func = func;
} /* set_value_function() */

/**
 * This method sets the function to call when buying something and it
 * costs too much.  The
 * function will be called with two elements, the first being the
 * player doing the buying and the second being the array
 * of objects which cost too much.
 * <p>
 * If the function is a string then the function of that name
 * will be called on the shop, if it is a function pointer
 * then the function pointer will be evaluated.
 * @param func the function to call
 * @see set_sell_function()
 * @see set_value_function()
 * @see set_buy_function()
 * @see set_cannot_sell_function()
 * @see set_browse_function()
 * @see set_list_function()
 */
void set_too_costly_function( mixed func ) {
    if( stringp(func) || functionp(func) )
        too_costly_func = func;
} /* set_too_costly_function() */

/**
 * This method sets the function to call when selling something
 * which fails for some reason.  The
 * function will be called with two elements, the first being the
 * player doing the selling and the second being the array
 * of objects being sold.
 * <p>
 * If the function is a string then the function of that name
 * will be called on the shop, if it is a function pointer
 * then the function pointer will be evaluated.
 * @param func the function to call
 * @see set_sell_function()
 * @see set_value_function()
 * @see set_too_costly_function()
 * @see set_buy_function()
 * @see set_browse_function()
 * @see set_list_function()
 */
void set_cannot_sell_function( mixed func ) {
    if( stringp(func) || functionp(func) )
        cannot_sell_func = func;
} /* set_cannot_sell_function() */

/**
 * This method sets the function to call when browsing something.  The
 * function will be called with two elements, the first being the
 * player doing the browsing and the second being the array
 * of objects being browsed.
 * <p>
 * If the function is a string then the function of that name
 * will be called on the shop, if it is a function pointer
 * then the function pointer will be evaluated.
 * @param func the function to call
 * @see set_sell_function()
 * @see set_value_function()
 * @see set_too_costly_function()
 * @see set_cannot_sell_function()
 * @see set_browse_function()
 * @see set_list_function()
 */
void set_browse_function( mixed func ) {
    if( stringp(func) || functionp(func) )
        browse_func = func;
} /* set_browse_function() */

/**
 * This method sets the function to call when listing something.  The
 * function will be called with two elements, the first being the
 * player doing the listing and the second being the array
 * of objects being listed.
 * <p>
 * If the function is a string then the function of that name
 * will be called on the shop, if it is a function pointer
 * then the function pointer will be evaluated.
 * @param func the function to call
 * @see set_sell_function()
 * @see set_value_function()
 * @see set_too_costly_function()
 * @see set_cannot_sell_function()
 * @see set_browse_function()
 * @see set_list_function()
 */
void set_list_function( mixed func ) {
    if( stringp(func) || functionp(func) )
        list_func = func;
} /* set_list_function() */

/**
 * This sets the message which will be told to the players when
 * they sell something at the shop.  If the parameter is a string
 * then that message is sent to the player and nothing is sent to
 * the other people in the room.  If the message is a two element
 * array, the first element is sent to the player and the second
 * element is sent to the others in the room.  In both these
 * cases the pattersn $ob$ will be replaces with the objects
 * being sold, $client$ will be replaced with the client, $money$
 * will be replaced with the money information, $extra$ will be replaces
 * with any extra information.
 * <p>
 * If the parameter is a function pointer, then this is called with
 * the parameter func(obs, client, money, extra);
 * @param str the message to print
 * @see set_buy_message()
 * @see query_sell_message()
 * @see set_set_value_message()
 * @see set_too_costly_message()
 * @see set_no_worthy_message()
 * @see set_browse_message()
 * @see set_list_message()
 * @example
 * set_sell_message("You sell $ob$ for $money$.\n");
 * @example
 * set_sell_message( ({ "You sell $ob$ for $money$.\n",
 *                      "$client$ sells $ob$.\n"});
 */
void set_sell_message( mixed str ) {
    sell_mess = str;
} /* set_sell_message() */

/**
 * This sets the message which will be told to the players when
 * they buy something at the shop.  If the parameter is a string
 * then that message is sent to the player and nothing is sent to
 * the other people in the room.  If the message is a two element
 * array, the first element is sent to the player and the second
 * element is sent to the others in the room.  In both these
 * cases the pattersn $ob$ will be replaces with the objects
 * being sold, $client$ will be replaced with the client, $money$
 * will be replaced with the money information, $extra$ will be replaces
 * with any extra information.
 * <p>
 * If the parameter is a function pointer, then this is called with
 * the parameter func(obs, client, money, extra);
 * @param str the message to print
 * @see set_sell_message()
 * @see query_buy_message()
 * @see set_set_value_message()
 * @see set_too_costly_message()
 * @see set_no_worthy_message()
 * @see set_browse_message()
 * @see set_list_message()
 * @example
 * set_buy_message("You buy $ob$ for $money$.\n");
 * @example
 * set_buy_message( ({ "You buy $ob$ for $money$.\n",
 *                      "$client$ buys $ob$.\n"});
 */
void set_buy_message( mixed str ) {
    buy_mess = str;
} /* set_buy_message() */

/**
 * This sets the message which will be told to the players when
 * they value something at the shop.  If the parameter is a string
 * then that message is sent to the player and nothing is sent to
 * the other people in the room.  If the message is a two element
 * array, the first element is sent to the player and the second
 * element is sent to the others in the room.  In both these
 * cases the pattersn $ob$ will be replaces with the objects
 * being sold, $client$ will be replaced with the client, $money$
 * will be replaced with the money information, $extra$ will be replaces
 * with any extra information.
 * <p>
 * If the parameter is a function pointer, then this is called with
 * the parameter func(obs, client, money, extra);
 * @param str the message to print
 * @see set_buy_message()
 * @see query_value_message()
 * @see set_set_value_message()
 * @see set_too_costly_message()
 * @see set_no_worthy_message()
 * @see set_browse_message()
 * @see set_list_message()
 * @example
 * set_value_message("$ob$ is valued at $money$.\n");
 * @example
 * set_sell_message( ({ "$ob$ is valued at $money$.\n",
 *                      "$client$ values $ob$.\n"});
 */
void set_value_message( mixed str ) {
    value_mess = str;
} /* set_value_message() */

/**
 * This sets the message which will be told to the players when
 * they buy something at the shop and it costs too much.
 * If the parameter is a string
 * then that message is sent to the player and nothing is sent to
 * the other people in the room.  If the message is a two element
 * array, the first element is sent to the player and the second
 * element is sent to the others in the room.  In both these
 * cases the pattersn $ob$ will be replaces with the objects
 * being sold, $client$ will be replaced with the client, $money$
 * will be replaced with the money information, $extra$ will be replaces
 * with any extra information.
 * <p>
 * If the parameter is a function pointer, then this is called with
 * the parameter func(obs, client, money, extra);
 * @param str the message to print
 * @see set_buy_message()
 * @see query_too_costly_message()
 * @see set_set_value_message()
 * @see set_browse_message()
 * @see set_no_worthy_message()
 * @see set_sell_message()
 * @see set_list_message()
 * @example
 * set_browse_message("$ob$ is worth too much to be sold here.\n");
 * @example
 * set_browse_message( ({ "$ob$ is worth too much to be sold here.\n",
 *                      "$client$ tries to sell the terribly expensive $ob$.\n"});
 */
void set_too_costly_message( mixed str ) {
    too_costly_mess = str;
} /* set_too_costly_message() */

/**
 * This sets the message which will be told to the players when
 * they sell soemthign that is not worth enough at the shop.
 * If the parameter is a string
 * then that message is sent to the player and nothing is sent to
 * the other people in the room.  If the message is a two element
 * array, the first element is sent to the player and the second
 * element is sent to the others in the room.  In both these
 * cases the pattersn $ob$ will be replaces with the objects
 * being sold, $client$ will be replaced with the client, $money$
 * will be replaced with the money information, $extra$ will be replaces
 * with any extra information.
 * <p>
 * If the parameter is a function pointer, then this is called with
 * the parameter func(obs, client, money, extra);
 * @param str the message to print
 * @see set_buy_message()
 * @see query_not_worthy_message()
 * @see set_set_value_message()
 * @see set_too_costly_message()
 * @see set_browse_message()
 * @see set_sell_message()
 * @see set_list_message()
 * @example
 * set_not_worthy_message("$ob$ is not worth enough to be sold here.\n");
 * @example
 * set_not_worthy_message( ({ "$ob$ is not worth enough to be sold here.\n",
 *                      "$client$ tries to sell the rubbishy $ob$.\n"});
 */
void set_not_worthy_message( mixed str ) {
    not_worthy_mess = str;
} /* set_not_worthy_message() */

/**
 * This sets the message which will be told to the players when
 * they browse something at the shop.  If the parameter is a string
 * then that message is sent to the player and nothing is sent to
 * the other people in the room.  If the message is a two element
 * array, the first element is sent to the player and the second
 * element is sent to the others in the room.  In both these
 * cases the pattersn $ob$ will be replaces with the objects
 * being sold, $client$ will be replaced with the client, $money$
 * will be replaced with the money information, $extra$ will be replaces
 * with any extra information.  In the case oif a browse the
 * extra information is the long description of the object.
 * <p>
 * If the parameter is a function pointer, then this is called with
 * the parameter func(obs, client, money, extra);
 * @param str the message to print
 * @see set_buy_message()
 * @see query_browse_message()
 * @see set_set_value_message()
 * @see set_too_costly_message()
 * @see set_no_worthy_message()
 * @see set_sell_message()
 * @see set_list_message()
 * @example
 * set_browse_message("$ob$ costs $money$, it looks like:\n$extra$");
 * @example
 * set_browse_message( ({ "$ob$ costs $money$, it looks like:\n$extra$",
 *                      "$client$ browses $ob$.\n"});
 */
void set_browse_message( mixed str ) {
    browse_mess = str;
} /* set_browse_message() */

/**
 * This sets the message which will be told to the players when
 * they list something at the shop.  If the parameter is a string
 * then that message is sent to the player and nothing is sent to
 * the other people in the room.  If the message is a two element
 * array, the first element is sent to the player and the second
 * element is sent to the others in the room.  In both these
 * cases the pattersn $ob$ will be replaces with the objects
 * being sold, $client$ will be replaced with the client, $money$
 * will be replaced with the money information, $extra$ will be replaces
 * with any extra information.  In the case of a list,
 * the extra information *is* the list.
 * <p>
 * If the parameter is a function pointer, then this is called with
 * the parameter func(obs, client, money, extra);
 * @param str the message to print
 * @see set_buy_message()
 * @see query_buy_message()
 * @see set_set_value_message()
 * @see set_too_costly_message()
 * @see set_no_worthy_message()
 * @see set_browse_message()
 * @see set_list_message()
 * @example
 * set_list_message("$extra$.\n");
 * @example
 * set_list_message( ({ "You list $ob$ for $money$.\n",
 *                      "$client$ lists $ob$.\n"});
 */
void set_list_message( mixed str ) {
    list_mess = str;
} /* set_list_message() */

/**
 * This sets the conditons which the shop will be open during.  If this
 * is set to an integer the shop will always be in that state, so
 * if you set the open condition to 0, it would always be closed.
 * If it is set to a string, then that function will be called on
 * this object to test to see if it is open.  If it iset to
 * function pointer, the function pointer will be evaluated.  If it
 * is set to an array, the first element specifies the object and the
 * second specifies the function to call.
 * @see query_open_condition()
 * @see test_open()
 */
void set_open_condition( mixed str ) {
    open_cond = str;
} /* set_open_condition() */

/**
 * This method sets the no steal property.  If a shop is set
 * as no steal, then it cannot be shoplifted.
 * @param i the new value of the no_steal property
 * @see set_steal_difficulty()
 * @see query_no_steal()
 * @see set_sell_stolen()
 */
void set_no_steal( int i ) {
    no_steal = i;
} /* set_no_steal() */

/**
 * This method sets the difficulty at which to steal stuff from
 * this shop.
 * @see set_no_steal()
 * @see set_sell_stolen()
 * @see query_steal_difficulty()
 * @param i the new value for the steal difficulty
 */
void set_steal_difficulty( int i ) {
    steal_difficulty = i;
} /* set_steal_difficulty() */

/**
 * This method sets the shop as a place which will receive and
 * sell stolen goods.  It automaticly sets the no_steal property
 * to 1.
 * @see set_no_steal()
 * @see set_steal_difficulty()
 * @see query_sell_stolen()
 * @param i the new value for the stolen property
 */
void set_sell_stolen( int i ) {
    sell_stolen = i;
    no_steal = 1;
} /* set_sell_stolen() */

/**
 * This method sets the shop to sell very large objects. ie. If a player
 * cannot carry items they are placed in the room for the player rather
 * than not being sold to the player.
 */
void set_sell_large( int i ) { sell_large = i; }

/**
 * This method returns the current sell message of the shop.
 * @see set_sell_mess()
 * @return the current sell message of the shop
 */
mixed query_sell_mess() { return sell_mess; }

/**
 * This method returns the current list message of the shop.
 * @see set_list_mess()
 * @return the current list message of the shop
 */
mixed query_list_mess() { return list_mess; }

/**
 * This method returns the current value message of the shop.
 * @see set_value_mess()
 * @return the current value message of the shop
 */
mixed query_value_mess() { return value_mess; }

/**
 * This method returns the current too costly message of the shop.
 * @see set_too costly_mess()
 * @return the current too costly message of the shop
 */
mixed query_too_costly_mess() { return too_costly_mess; }

/**
 * This method returns the current not worthy message of the shop.
 * @see set_not worthy_mess()
 * @return the current not worthy message of the shop
 */
mixed query_not_worthy_mess() { return not_worthy_mess; }

/**
 * This method returns the current buy message of the shop.
 * @see set_buy_mess()
 * @return the current buy message of the shop
 */
mixed query_buy_mess() { return buy_mess; }

/**
 * This method returns the current browse message of the shop.
 * @see set_browse_mess()
 * @return the current browse message of the shop
 */
mixed query_browse_mess() { return browse_mess; }

/**
 * This method returns the current open conditon of the shop.
 * @see set_open_conditon_mess()
 * @return the current open condition message of the shop
 */
mixed query_open_condition() { return open_cond; }

/**
 * This method returns the current no steal property.
 * @see set_no_steal_mess()
 * @return the current no steal properyt of the shop
 */
int query_no_steal() { return no_steal; }

/**
 * This method returns the current steal difficulty of the shop.
 * @see set_steal_difficulty_mess()
 * @return the current steal difficulty message of the shop
 */
int query_steal_difficulty() { return steal_difficulty; }

/**
 * This method returns the shop lift response handler for the shop.
 * This allows the shop to respond in someway to someone shop
 * lifting stuff, like the heavys in Ankh-Morpork.
 * @returns the shop lift response handler
 * @see set_shoplift_response_handler()
 * @see set_no_steal()
 * @see set_sell_stolen()
 * @see set_steal_difficulty()
 */
string query_shoplift_response_handler() { return shoplift_handler; }

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
    return match_objects_for_existence( str, ({ query_store_room() }) );
} /* query_shop_lift_items() */

/**
 * This method turns the objects into real objects (if that is
 * nessessary, it is not with a normal shop).
 * @param ob the object to turn into a normal object
 */
object shoplift_success( object ob ) {
    return ob;
} /* shoplift_success() */

/**
 * This method sets the shop lift response handler for the shop.
 * This allows the shop to respond in someway to shop lifting
 * stuff, like the heavies in Ankh-Morpork.  The function
 * 'handle_shoplift' will be called on the handler when the
 * shop lift is attempted.  It will be passed two arguments
 * the first is the thief, the second is the room being
 * shoplifted.  This can be set to  afucntion pointer
 * which will be evaluated and passed in two arguemtns
 * when  a shoplift occurs.
 * @see query_shoplift_response_handler()
 * @see set_no_steal()
 * @see set_sell_stolen()
 * @see set_steal_difficulty()
 * @param word the new shop lift response handler
 */
void set_shoplift_response_handler( string word ) {
    shoplift_handler = word;
} /* set_shoplift_response_handler() */

/**
 * This method sets the minimum value of items that can be sold here.
 * @see query_min_amount()
 */
void set_min_amount( int i ) { min_amount = i; }

/**
 * This method sets the maximum number of inventory items this shop will
 * take before it starts to refuse to purchase items from players and
 * deleting items from its inventory.
 * The default for this is defined as MAX_INVENTORY in shop.h
 */
void set_max_inventory( int i ) { max_inventory = i; }

/**
 * This method tests to see if the shop is actually open.
 * @return non-zero if the shop is open
 * @see set_open_condition()
 * @see query_open_condition()
 */
int test_open() {
    if( !check_shopkeeper_open() )
        return 0;
    if( stringp(open_cond) )
        return (int)call_other( TO, open_cond );
    if( intp(open_cond) )
        return open_cond;
    if( functionp(open_cond) )
        return evaluate(open_cond);
    return (int)call_other( open_cond[0], open_cond[1] );
} /* test_open() */

/** @ignore yes */
void init() {
    string room;

    ::init();
    if( stringp(our_storeroom) ) {
        room = our_storeroom;
    } else if( our_storeroom ) {
        room = file_name(our_storeroom);
    } else {
        tell_room( TO, "Oh dear, we don't seem to have a storeroom.\n");
    }
    add_command("sell", "<indirect:object:me>");
    add_command("buy", "<indirect:object:"+room+">");
    add_command("list", "[all]");
    add_command("list", "<indirect:object:"+room+">",
                     (: do_list_these($1) :));
    add_command("browse", "<indirect:object:"+room+">");
    add_command("value", "<indirect:object:me>");
} /* init() */

/**
 * This method returns the maximum value oif an object that can
 * be sold here.
 * @see query_min_amount()
 * @return the maximum amount
 * @see /handlers/money_handler.c
 */
int query_max_amount() { return MAX_AMOUNT; }

/**
 * This method returns the minimum value oif an object that can
 * be sold here.
 * @see query_max_amount()
 * @return the minimum amount
 * @see /handlers/money_handler.c
 */
int query_min_amount() { return min_amount; }

/**
 * This method returns the value of the object in this shop.
 * @return the value of the object here
 * @param thing the thing to value
 * @param sell are we selling it?
 * @see query_max_amount()
 * @see query_min_amount()
 */
varargs int query_value( object thing, int sell ) {
    return (int)thing->query_value_at(TO);
} /* query_value() */

/**
 * This returns the amount of money you can sell and object for,
 * which is less than the amount it will be sold for in the shop later.
 * @param n the value to scale
 * @return the sell value
 */
int scaled_value( int n ) {
    int profit;

    profit = 5 + to_int( sqrt( to_float( n / 5 ) ) );
    if( profit > MAX_PROFIT )
        profit = MAX_PROFIT;

    return n * ( 100 - profit ) / 100;

} /* scaled_value() */

/**
 * This method does the actual selling.
 * @param in_obs the objects to sell
 * @return 1 on success, 0 on failure
 */
int do_sell(object *in_obs) {
    int amt, total_amt;
    string place;
    object money, *obs, *selling, *cannot, *stolen, storeob, ob;
    mixed m_array;

    if( !test_open() )
        return 0;

    obs = filter( in_obs, (: !$1->query_keep() :) );
    if( !sizeof(obs) ) {
        TP->add_failed_mess( TO, "All of $I you previously decided to "
            "keep.\n", in_obs );
        return 0;
    }

    in_obs = TP->query_holding() + TP->query_armours();
    cannot = filter(obs, (: member_array( $1, $2 ) != -1 :), in_obs );
    if( sizeof(cannot) ) {
        obs -= cannot;
        tell_object( TP, "You decide not to sell "+
            query_multiple_short( cannot, "the")+", because you are wearing "
            "or holding $V$0=it,them$V$.\n");
    }

    // If there are more items in the storeroom than max_inventory allows
    // return a failure message.
    if( objectp(our_storeroom) ) {
        storeob = our_storeroom;
    } else {
        our_storeroom->rabbit_away();
        storeob = find_object(our_storeroom);
    }
    if( sizeof( INV(storeob) ) > max_inventory ) {
        TP->add_failed_mess( TO, "Sorry, the shop is full up and isn't "
            "buying items!\n", ({ }) );
        call_out("tidy_inventory", random(20) );
        return 0;
    }

    if( sizeof(obs) > MAX_OBS ) {
        write("The shopkeeper can't cope with all those objects.\n");
        obs = obs[0..MAX_OBS - 1];
    }
    selling = cannot = stolen = ({ });
    place = query_property("place");
    if( !place || place == "" )
        place = "default";

    foreach( ob in obs ) {
        if( !sell_stolen && ob->query_property("stolen") ) {
            stolen += ({ ob });
            continue;
        } else {
            ob->remove_property("stolen");
        }
        if( TO->query_value(ob) > 0 && !ob->do_not_sell() &&
            !TO->do_not_buy(ob) && ( !strict_shop ||
            shop_type == ob->query_property("shop type") ) &&
            ENV(ob) == TP ) {
            if( ob->move(our_storeroom) ) {
                if( ob->short() )
                    cannot += ({ ob });
                continue;
            }
            amt = (int)TO->query_value(ob);
            if( !ob->query_property("sale_value") )
                amt = scaled_value( amt );
            if( amt <= (int)TO->query_max_amount() &&
                amt >= (int)TO->query_min_amount() ) {
                if( shop_type != ob->query_property("shop type") )
                    amt = (amt * 90) / 100;
                total_amt += amt;
                selling += ({ ob });
                ob->being_sold();
            } else {
                if( ob->short() )
                    cannot += ({ ob });
                ob->move(TP);
            }
        } else if( ob->short() ) {
                cannot += ({ ob });
        }
    }
    if( !sizeof(selling) ) {
        if( sizeof(cannot) ) {
            if( stringp(cannot_sell_func) )
                call_other( TO, cannot_sell_func, TP, cannot );
            else if( functionp(cannot_sell_func) )
                evaluate( cannot_sell_func, TP, cannot );
            TP->add_failed_mess( TO, "You cannot sell $I.\n", cannot );
        } else if( sizeof(stolen) ) {
            TP->add_failed_mess( TO, "You cannot sell $I because "+
                ({"it's", "they're"})[query_group(stolen)]+" stolen!\n",
                stolen );
        } else {
            TP->add_failed_mess( TO, "You have nothing to sell.\n", ({ }) );
        }
        return 0;
    }
    if( TO->cannot_afford(total_amt) ) {
        selling->move(TP);
        TP->add_failed_mess( TO, "The shop cannot afford to buy $I from "
            "you.\n", selling );
        return 0;
    }
    amount_sold += total_amt;
    m_array = (mixed)MONEY_H->create_money_array( total_amt, place );
    money = clone_object(MONEY_OBJECT);
    money->set_money_array( m_array );
    if( sizeof(cannot) ) {
        if( stringp(cannot_sell_func) )
            call_other( TO, cannot_sell_func, TP, cannot );
        else if( functionp(cannot_sell_func) )
            evaluate( cannot_sell_func, TP, cannot );
        write("You cannot sell "+query_multiple_short(cannot)+".\n");
        cannot->move(TP);
    }

    if( stringp(sell_func) )
        call_other( TO, sell_func, TP, obs );
    else if( functionp(sell_func) )
        evaluate( sell_func, TP, obs );

    do_parse( sell_mess, selling, TP,
        (string)MONEY_H->money_string(m_array), "");

    if( (int)money->move(TP) != MOVE_OK ) {
        tell_object( TP, "You're too heavily burdened to accept all that "
            "money, so the shopkeeper puts it on the floor.\n");
        money->move(TO);
    }

    TO->made_transaction( -total_amt, selling );
    return 1;

} /* do_sell() */


/**
 * This method determines whether or not a given object is a creator object
 * and should be in this shop or not.
 * @param ob the object to check
 * @return 1 if the object is not allowed, 0 if it is.
 */
int creator_object( object ob ) {
    string path;

    if( file_name( ob )[0..2] == "/w/" )
        return 1;

    if( ( path = ob->query_property( "virtual name" ) ) &&
        path[0..2] == "/w/" )
        return 1;

    return 0;

} /* creator_object() */

/**
 * This method does the actual buying.
 * @param obs the objects to buy
 * @return 1 on success, 0 on failure
 */
int do_buy( object *obs ) {
    int i, amt, ob_amt, total_cost;
    string place;
    object money, *to_buy, *cannot, *too_much;
    object *creator_obs;

    if( !test_open() )
        return 0;

    if( sizeof(obs) > MAX_OBS ) {
        write("The shopkeeper can't cope with all those objects.\n");
        obs = obs[0..MAX_OBS-1];
    }

    creator_obs = filter( obs, (: creator_object( $1 ) :) );
    if( sizeof( creator_obs ) && file_name()[0..2] != "/w/" ) {
        tell_object( TP, "You cannot buy "+
            query_multiple_short( creator_obs, "the" )+" because they "
            "shouldn't be in the game!\n");
        obs -= creator_obs;
    }

    to_buy = too_much = cannot = ({ });
    place = query_property("place");
    if( !place || place == "" )
        place = "default";

    if( !money = present( MONEY_ALIAS, TP ) ) {
        if( stringp( too_costly_func ) )
            call_other( TO, too_costly_func, TP, obs );
        else if( functionp(too_costly_func) )
            evaluate( too_costly_func, TP, obs );
        TP->add_failed_mess( TO, "You have no money.\n", obs );
        return 0;
    }

    amt = (int)money->query_value_in(place);
    if( place != "default" )
        amt += (int)money->query_value_in("default");

    while( i < sizeof(obs) ) {
        ob_amt = (int)TO->query_value( obs[i], 1 );
        if( ob_amt > amt ) {
            if( obs[i]->short() )
                too_much += ({ obs[i] });
            obs = delete( obs, i, 1 );
            continue;
        }
        if( obs[i]->move(TP) ) {
            if( !sell_large ) {
                if( obs[i]->short() )
                    cannot += ({ obs[i] });
                i++;
                continue;
            } else {
                obs[i]->move(TO);
            }
        }
        amt -= ob_amt;
        total_cost += ob_amt;
        to_buy += ({ obs[i] });
        i++;
    }
    amount_bought += total_cost;
    if( sizeof(cannot) )
        TP->add_failed_mess( TO, "You cannot pick up $I.\n", cannot );
    if( sizeof(too_much) ) {
        if( stringp(too_costly_func) )
            call_other( TO, too_costly_func, TP, cannot );
        else if( functionp(too_costly_func) )
            evaluate( too_costly_func, TP, cannot );
        TP->add_failed_mess( TO, "$I $V$0=costs,cost$V$ too much.\n",
            too_much );
    }
    if( !sizeof(to_buy) )
        return 0;
    do_buy_things( to_buy, total_cost, TP );
    do_shopkeeper_buy();
    return 1;
} /* do_buy() */

/** @ignore yes */
void do_buy_things( object *obs, int cost, object pl ) {
    int i, j;
    string place;
    object money, change;
    mixed m_array, p_array;

    place = query_property("place");
    if( !place || place == "" )
        place = "default";


    if( !money = present( MONEY_ALIAS, pl ) ) {
        if( stringp(too_costly_func) )
            call_other( TO, too_costly_func, TP, obs );
        else if( functionp(too_costly_func) )
            evaluate( too_costly_func, TO, obs );
        TP->add_failed_mess( TO, "You don't have any money.\n", obs );
        return 0;
    }

    change = clone_object(MONEY_OBJ);
    m_array = (int)MONEY_H->create_money_array( cost, place );

    for( i = 0; i < sizeof(m_array); i += 2 ) {
        p_array = (mixed)MONEY_H->make_payment( m_array[i],
                  m_array[i + 1], money, place );
        if( !pointerp(p_array) )
            continue;
        for( j = 0; j < sizeof(p_array[0]); j += 2 )
            money->adjust_money( -p_array[0][j + 1], p_array[0][j] );
        change->adjust_money( p_array[1] );
    }

    do_parse( buy_mess, obs, pl, (string)MONEY_H->money_string(m_array), "");

    if( stringp(buy_func) )
        call_other( TO, buy_func, pl, obs );
    else if( functionp(buy_func) )
        evaluate( buy_func, pl, obs );

    if( (int)change->move(pl) != MOVE_OK ) {
        tell_object( pl, "You are too heavily burdened to accept your "
            "change, so the shopkeeper puts it on the floor.\n");
        change->move(TO);
    }

    TO->made_transaction( cost, obs );

} /* do_buy() */

/**
 * This method lists all the objects in stock.
 * @return 1 on succes, 0 on failure
 * @param do_list_these()
 */
int do_list() {
    object ob;

    if( !test_open() )
        return 0;

    if( objectp(our_storeroom) ) {
        ob = our_storeroom;
    } else {
        if( original_storeroom ) {
            our_storeroom = load_object( original_storeroom );
            ob = our_storeroom;
        } else {
            add_failed_mess("Please notify a creator: the storeroom for "
                "this shop cannot load or has gone missing.\n");
            return 0;
        }
    }

    if( stringp(list_func) )
        call_other( TO, list_func, TP );
    else if( functionp(list_func) )
        evaluate( list_func, TP );

    do_parse( list_mess, ({ TO }), TP, "", shop_list( INV(ob), 0 ) );
    do_shopkeeper_list();
    return 1;

} /* do_list() */

/**
 * This method lists only the specified objects.
 * @return 1 on success, 0 on failure
 * @see do_list()
 */
int do_list_these( object *obs ) {
    if( !test_open() )
        return 0;

    do_parse( list_mess, ({ TO }), TP, "", shop_list( obs, 1 ) );
    do_shopkeeper_list();
    return 1;

} /* do_list_these() */

/**
 * This method is called when the player is browseing stuff.
 * @param obs the objects to browse
 * @return 1 on success, 0 on failure
 */
int do_browse( object *obs ) {
    int value;
    string place;
    object ob;

    if( !test_open() )
        return 0;

    place = query_property("place");
    if( !place || place == "" )
        place = "default";

    if( stringp(browse_func) )
        call_other( TO, browse_func, TP, obs );
    else if( functionp(browse_func) )
        evaluate( browse_func, TP, obs );

    foreach( ob in obs ) {
        value = (int)TO->query_value( ob, 1 );
        do_parse( browse_mess, ({ ob }), TP,
            (string)MONEY_H->money_value_string(value, place),
            (string)ob->long() );
    }

    do_shopkeeper_browse();
    return 1;

} /* do_browse() */

/**
 * This method is called when the player is valueing stuff.
 * @param obs the objects to value
 * @return 1 on success, 0 on failure
 */
int do_value(object *obs) {
    int val;
    int total;
    string place;
    object ob;

    if( !test_open() )
        return 0;

    place = query_property("place");
    if( !place || place == "" )
        place = "default";

    foreach( ob in obs ) {
        if( ob->do_not_sell() || TO->do_not_buy(ob) ||
            ENV(ob) != TP || ( strict_shop &&
            ( shop_type != (string)ob->query_property("shop type") ) ) ) {
            val = 0;
        } else {
            val = (int)TO->query_value(ob);
            if( shop_type != (string)ob->query_property("shop type") )
                val = (val * 90) / 100;
        }
        val = scaled_value(val);
        total += val;
        if( val > (int)TO->query_max_amount() ) {
            do_parse( too_costly_mess, ({ ob }), TP, "",
                (string)ob->do_not_sell() );
        } else if( val < (int)TO->query_min_amount() ) {
            do_parse( not_worthy_mess, ({ ob }), TP, "",
                (string)ob->do_not_sell() );
        } else {
            do_parse( value_mess, ({ ob }), TP,
                (string)MONEY_H->money_value_string( val, place ),
                (string)ob->do_not_sell() );
            if( stringp(value_func) ) {
                call_other( TO, value_func, TP, obs,
                    MONEY_H->money_string( MONEY_H->create_money_array(
                    val, place ) ) );
            } else if( functionp(value_func) ) {
                evaluate( value_func, TP, obs,
                    MONEY_H->money_string( MONEY_H->create_money_array(
                    val, place ) ) );
            }
        }
    }

    if( sizeof(obs) > 1 )
        write("This gives you a total value of "+
              MONEY_H->money_value_string(total, place)+".\n");

    return 1;

} /* do_value() */

/**
 * This method creates the list for the shop.
 * @param arr the array of objects to list
 * @param detail display them in detail?
 * @return the string list
 */
string shop_list( mixed arr, int detail ) {
    int j, value;
    string s, mon, place, *shorts;
    object *list;
    mapping inv, costs;
    mixed ind, item;

    list = ( pointerp(arr) ? arr : INV(TO) );

    // Only keep track of things with shorts.
    inv = ([ ]);

    foreach( item in list ) {
        s = (string)item->short();
        if( !s || !TO->query_value( item, 1 ) )
            continue;
        if( !stringp(s) )
            s = "get a creator for this one!";
        if( inv[s] )
            inv[s] += ({ item });
        else
            inv[s] = ({ item });
    }

    // Okay, print it.
    s = "";
    shorts = keys(inv);
    if( !sizeof(shorts) ) {
        return ( detail ? "The shop is all out of what you wanted." :
                          "The shop is totally out of stock." )+"\n";
    }

    s = "You find on offer:\n";
    place = query_property("place");
    if( !place || place == "" )
        place = "default";

    foreach( item in shorts ) {
        ind = inv[item];
        switch( sizeof(ind) ) {
        case 1:
          s += "Our very last " + item;
        break;
        case 2..5 :
          s += CAP( query_num( sizeof(ind), 0 )+" "+
               (string)ind[0]->query_plural() );
        break;
        default:
          s += ( detail ? CAP( query_num( sizeof(ind), 0 ) ) :
                 "A large selection of" )+" "+(string)ind[0]->query_plural();
        }
        if( detail ) {
            costs = ([ ]);
            for( j = 0; j < sizeof(ind); j++ ) {
                value = (int)TO->query_value( ind[j], 1 );
                mon = (string)MONEY_H->money_value_string( value, place );
                if( !costs[mon] )
                    costs[mon] = ({""+(j + 1)});
                else
                    costs[mon] += ({""+(j + 1)});
            }
            if( sizeof(costs) == 1 ) {
                s += " for "+keys(costs)[0];
                if( sizeof(values(costs)[0]) > 1 ) {
                    s += " each.\n";
                } else {
                    s += ".\n";
                }
            } else {
                s += ":-\n";
                foreach( mon in keys(costs) )
                    s += "  [#"+implode(costs[mon], ",")+"] for "+mon+".\n";
            }
        } else {
            s += ".\n";
        }
    }

    return s;

} /* shop_list() */

/**
 * This method sets the current store room associated with
 * the shop.  This is important!  A shop needs a storeroom.
 * @param ob the storeroom to set
 * @example
 * set_store_room(PATH+"store_room");
 */
void set_store_room( mixed ob ) {
    if( stringp(ob) ) {
        original_storeroom = ob;
        our_storeroom = find_object(ob);
        if( !our_storeroom )
            our_storeroom = load_object(ob);
    } else
        our_storeroom = ob;
} /* set_store_room() */

/** @ignore yes */
void guards( object tp ) {
    object ob;

    if( ENV(tp) != TO && ENV(tp) != our_storeroom )
        return;

    while( !random(6) ) {
        ob = create_mercenary(0);
        ob->move( ENV(tp) );
        ob->attack_ob(tp);
    }
} /* guards() */

/**
 * This method returns the storeroom associated with the shop.
 * @see set_store_room()
 * @return the current store room
 */
object query_store_room() { return our_storeroom; }

/**
 * This method is the major message processing function for
 * the buye messages, sell messages etc.  It handles calling
 * the functions and setting the results back onto the
 * player.
 * @param arr the value of the message
 * @param ob the objects to process
 * @param money the money string
 * @param extra the extra string
 */
void do_parse( mixed arr, object *ob, object client, string money, string extra ) {
    if( stringp(arr) ) {
        TP->show_message("$P$List$P$"+
            TP->convert_message( replace( arr, ({
                "$ob$", query_multiple_short(ob),
                "$client$", TP->short(),
                "$money$", money,
                "$extra$", extra
                }) ) ) );
        TP->add_succeeded_mess( TO, "", ob );
    } else if( functionp(arr) ) {
        evaluate( arr, ob, client, money, extra );
    } else {
        TP->show_message("$P$List$P$"+
            TP->convert_message( replace( arr[0], ({
                "$ob$", query_multiple_short(ob),
                "$client$", TP->short(),
                "$money$", money,
                "$extra$", extra
                }) ) ) );
        TP->add_succeeded_mess( TO, ({ "", replace(arr[1], ({
            "$ob$", "$I", "$client$", "$N", "$money$", money,
            "$extra$", extra }) ) }), ob );
    }
} /* do_parse() */

/** @ignore yes */
string shop_parse( string str, mixed ob, object client, string money,
                   string extra, string which ) {
    if( sizeof(ob) )
        str = replace( str, "$ob$", query_multiple_short( ob, which ) );
    else
        str = replace( str, "$ob$", call_other( ob, which +"_short" ) );

    if( client )
        str = replace( str, "$client$", client->the_short() );

    return replace( str, ({ "$money$", money, "$extra$", extra }) );

} /* shop_parse() */

/**
 * This method adds a shop with shich we will exchange inventories
 * of certain types.  So the main shop can sell off its swords and
 * stuff to the sword shop.
 * @param shop the other shop
 */
void add_other_shop(mixed shop) {
    // Should give a nice string telling us the other room.
    other_shops += ({shop});
} /* add_other_shop() */

/**
 * This method returns the type of the shop.  This conttrols what sort
 * of merchandise the shop will buy and sell.
 * <p>The types of allowed shops are:
 * <ul>
 * <li>  jewelery
 * <li>  armoury
 * <li>  clothes
 * <li>  magic
 * <li>  none set (ie: 0, general type)
 * </ul>
 * @return the shop type
 * @see set_shop_type()
 * @see set_strict_shop()
 */
string query_shop_type() { return shop_type; }

/**
 * This method sets the type of the shop.  This controls what sort of
 * mechandise the shop will buy and sell.
 * <p>The types of allowed shops are:
 * <ul>
 * <li>  jewelery
 * <li>  armoury
 * <li>  clothes
 * <li>  magic
 * <li>  none set (ie: 0, general type)
 * </ul>
 * @see query_shop_type()
 * @see set_strict_shop()
 * @param ty the type of the shop
 */
void set_shop_type( string ty ) { shop_type = ty; }

/**
 * This method sets the strictness of the shop, if the shop is strict
 * it will not deal in items of other types at all.
 * @param i the new strict value
 * @see set_shop_type()
 * @see query_strict_shop()
 */
void set_strict_shop( int i ) { strict_shop = i; }

/**
 * This method returns the structness of the shop, if the shop is strict
 * it will not deal in items of other types at all.
 * @return the current strict value
 * @see set_shop_type()
 * @see set_strict_shop()
 */
int query_strict_shop() { return strict_shop; }

/**
 * This method creates the sales representative which is sent off
 * to exchange goods with other shops.
 * @return the sales representative
 * @see add_other_shop()
 * @see send_out_reps()
 */
object create_rep() {
    object ob;

    ob = clone_object(NPC_OBJ);
    ob->set_name("rep");
    ob->set_short("sales rep");
    ob->add_adjective("sales");
    ob->set_long("This is tall strong looking sales rep.  He "
        "stares at you with bright piercing eyes.\n");
    ob->add_alias("Sales rep alias");
    ob->basic_setup("human", 60, 1 );
    ob->adjust_bon_str(15);
    ob->get_item("dagger", 100 );
    ob->get_item("cloth robe", 100 );
    ob->init_equip();
    ob->add_property("rep type", shop_type );
    INV(ob)->add_property("mine", 1 );

    return ob;

} /* create_rep() */

// Send out the reps.

/**
 * This method checks to see if there are any other shops
 * associated with ours and sends out representatives to them
 * to exchange goods.
 * @see create_rep()
 * @see add_other_shop()
 */
void send_out_reps() {
    int i;
    object ob;

    for( i = 0; i < sizeof(other_shops); i++ ) {
        ob = (object)TO->create_rep();
        ob->add_property("goto destination", other_shops[i]);
        ob->add_property("goto property", "shop");
        ob->move( TO, "$N stride$s determinedly into the room.");
        ob->add_triggered_action("froggy", "goto_destination",
            file_name(TO), "rep_made_it");
    }
} /* send_out_reps() */

/**
 * This method is called onces the representative
 * reaches its destination.
 * @param bing we mkde it ok
 */
void rep_made_it( int bing ) {
    object *obs, rep;
    int i, cost;

    if( !bing ) {
        PO->init_command("'Oh no!  I am utterly lost!");
        PO->init_command("sigh");
        call_out("set_up_return", 5, PO );
        return ;
    }
    rep = present("Sales rep alias", (object)PO->query_current_room() );
    obs = (PO->query_current_room())->query_stock(shop_type) || ({ });

    if( !sizeof(obs) ) {
        TO->none_to_sell();
        call_out("set_up_return", 5, PO );
        return ;
    }
    for( i = 0; i < sizeof(obs); i++ ) {
        if( obs[i] ) {
            cost += (int)TO->query_value( obs[ i ], 1 ) * 2 / 3;
        }
    }
    call_out("do_rep_buy", 5, ({ PO, obs, cost }) );
    cost += (int)TO->query_value(obs[i], 1) * 2 / 3;
    call_out("do_rep_buy", 5, ({ PO, obs, cost }) );
    PO->adjust_value(cost);
} /* rep_made_it() */

/**
 * This method creates a mercenaries to wander along with the
 * sales rep to get the stuff to the destination.
 * @param rep the representative to protect
 * @return the new mercenary
 */
object create_mercenary( object rep ) {
    object ob;
    string nam;

    if( rep ) {
        nam = implode(rep->query_adjectives(), " ")+" "+rep->query_name();
    }
    ob = clone_object(NPC_OBJ);
    ob->set_name("mercenary");
    ob->add_alias("troll");
    ob->add_adjective("troll");
    ob->set_short("troll mercenary");
    ob->set_main_plural("troll mercenaries");
    ob->basic_setup("troll", 200 + random( 200 ), 1 );
    ob->set_long("This is a large, hulking troll.  He looks "
        "quite competent and capable of mashing you with or "
        "without a weapon.\n");
    if( rep ) {
        ob->move(ENV(rep));
        ob->do_command("follow "+nam);
        ob->do_command("protect "+nam);
        ob->add_property("merchant", rep );
    } else {
        ob->get_item("spiked club", 100 );
    }
    ob->add_skill_level("fighting", 300 + random(100) );
    ob->set_natural(1);
    ob->init_equip();
    ob->set_join_fights("The troll mercenary yells something "
        "incomprehensible.\n");
    ob->set_join_fight_type(0); // So they only beat up players.

    return ob;

} /* create_mercenry() */

/* The shop types are:
 *   jewelery
 *   armoury
 *   clothes
 *   magic
 *   none set (ie: 0, general type)
 */
/**
 * This method returns alkl the stock in the shop of various
 * types.  The types are:
 * <ul>
 * <li>  jewelery
 * <li>  armoury
 * <li>  clothes
 * <li>  magic
 * <li>  none set (ie: 0, general type)
 * </ul>
 * @param type the type of stock to return
 * @return the array of objects of the type
 */
object *query_stock(string type) {
    mapping blue;

    blue = (mapping)our_storeroom->query_shop_type_mapping();
    if( !blue[type] )
        return ({ });
    return blue[type];
} /* query_stock() */

/**
 * This method is called when the rep tries to buy stuff.
 * @param bing the stuff to buy
 */
void do_rep_buy( mixed bing ) {
    object rep, *obs;
    int cost;

    rep = bing[0];
    obs = bing[1];
    cost = bing[2];
    rep->adjust_money(cost, "brass");
    rep->query_current_room()->do_buy(obs, cost, rep);
    obs->move( present("Sales rep alias", rep->query_current_room() ) );
    call_out("set_up_return", 5, rep);

} /* do_rep_buy() */

/**
 * This method sets up the rep to return home.
 * @param rep the rep to return home
 */
void set_up_return(object rep) {
    rep->add_property("goto destination", file_name(TO) );
    rep->add_triggered_action("froggy", "goto_destination", TO, "rep_came_back");
} /* set_up_return() */

/**
 * This method is called when the rep gets back home.
 */
void rep_came_back() {
    object *obs, *obs2, rep, ob;

    obs = PO->find_inv_match("all", PO );
    obs2 = ({ });
    foreach( ob in obs ) {
        if( ob->query_property("mine") || ob->query_property("money") )
            continue;
        ob->move(our_storeroom);
        obs2 += ({ ob });
    }

    if( sizeof(obs2) ) {
        tell_room( TO, PO->short()+" puts "+
            query_multiple_short(obs2)+" into the stock.\n");
    }

    rep = present("Sales rep alias", (object)PO->query_current_room() );
    obs = INV(TO);
    obs2 = ({ });

    foreach( ob in obs ) {
        if( (object)ob->query_property("merchant") == rep )
            obs2 += ({ ob });
    }

    if( sizeof(obs2) )
        tell_room( TO, query_multiple_short( obs2 + ({ PO }), "the")+" go "
            "away.\n");
    else
        tell_room( TO, PO->short()+" goes away.\n");

    obs2->dest_me();
    PO->dest_me();

} /* rep_came_back() */

// Used to create guards to protect the shop.

/**
 * This method is yused to handle guards to protect the shop.
 * @param tp the object which is shop lifting
 * @see event_shoplift()
 * @see set_shoplift_handler()
 */
void summon_guards( object tp ) {
    object ob;
    int i;

    if( ENV(tp) != TO )
        return;


    if( !ob = ENV(tp)->create_mercenary(0) )
        return;

    ob->move( TO, "$N charge$s in to protect the shop!");
    ob->attack_ob(tp);
    for( i = 0; i < random(5); i++ ) {
        ob = create_mercenary(0);
        ob->move( TO, "$N charge$s in to protect the shop!");
        ob->attack_ob(tp);
    }
} /* summon_guards() */

/**
 * This method is called when a shop lift is done on the shop.
 * @param command_ob the command object
 * @param thief the theif doing the shop lifting
 * @param victim the victim of the shoplifiting, us I guess :)
 * @see event_shoplift()
 * @see set_shoplift_handler()
 */
void event_shoplift( object command_ob, object thief, object victim ) {
    if( stringp(shoplift_handler) ) {
        if( shoplift_handler != "none" )
            theft_handler->handle_shoplift( thief, victim );
    } else if( functionp(shoplift_handler) )
        evaluate( shoplift_handler, thief, victim );
    else
        THEFT_H->handle_shoplift( thief, victim );
} /* event_shoplift() */

/**
 * This method is used by the shop to tidy up its inventory.
 * It does this by desting objects at random until it has
 * reduced the inventory to 3/4 of its maximum.
 */
void tidy_inventory() {
    object storeob;
    object *inventory;
    int i, inv_to_leave;
    int count;

    inv_to_leave = max_inventory - ( max_inventory / 4 );

    if( objectp(our_storeroom) )
        storeob = our_storeroom;
    else {
        our_storeroom->rabbit_away();
        storeob = find_object(our_storeroom);
    }

    if( sizeof( inventory = INV(storeob) ) < inv_to_leave )
        return;

    while( sizeof(inventory) > inv_to_leave ) {
        i = random( sizeof(inventory) );
        if( inventory[i] )
            inventory[i]->dest_me();
        // safety code.
        if( count++ > 500 )
            break;
        inventory = INV(storeob);
    }

} /* tidy_inventory() */

/** @ignore yes */
void dest_me() {
    if( our_storeroom )
        our_storeroom->dest_me();
    ::dest_me();
} /* dest_me() */

/** @ignore yes */
int query_keep_room_loaded() { return 1; }

/** @ignore yes */
mixed stats() {
    return ::stats()+({
      ({"total sold", amount_sold }),
      ({"total bought", amount_bought }),
      ({"shop type", shop_type }),
      ({"shoplift handler", shoplift_handler }),
      ({"strict shop", strict_shop })
      });
} /* stats() */
