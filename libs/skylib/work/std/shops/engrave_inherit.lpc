/**
 * This is a small inheritable to allow places to do engraving.  Put a
 * piece of code in the init function which calls the engrave_init()
 * function.
 * @example
 * inherit "/std/room/basic_room";
 * inherit "/std/shops/engrave";
 *
 * void init() {
 *    basic_room::init();
 *    engrave_init();
 * } /\* init() *\/
 * @author Macchirton
 * @see set_engraving_language()
 * @see query_engraving_language()
 * @see set_style();
 * @see query_style()
 * @see set_letter_cost()
 * @see query_letter_cost()
 * @see set_engrave_shopkeeper()
 * @see query_engrave_shopkeeper()
 * @change 17th of May 1998 Pinkfish
 * Turned into an inheritable base and reworked to make it work with
 * add_command correctly.
 * @changed 21/03/01 Shiannar - Fixed bizzare behaviour of engrave_objects().
 * @changed 23/09/02 Sandoz - Made the shopkeeper code and a few more things work.
 */

#define ENGRAVE_PROP "engraveable"

private int letter_cost, use_shop_keeper;
private object shop_keeper;
private string language, style;

void create() {
    TO->add_help_file("engrave");
    letter_cost = 200;
    style = "neat engraved letters";
    language = "common";
} /* create() */

/**
 * This method sets the language messages will be engraved in.
 * The default language is common.
 * @param str the language to engrave in
 * @see query_engraving_language()
 */
void set_engraving_language( string str ) {
    if( !LANGUAGE_H->query_language_written(str) )
        error("The language "+str+" is not a valid written language.\n");
    language = str;
} /* set_engraving_language() */

/**
 * This method returns the language messages are engraved in.
 * @return the language messages are engraved in
 * @see set_engraving_language()
 */
string query_engraving_language() { return language; }

/**
 * This method sets the writing style for engravings.
 * The default is "neat engraved letters".
 * @param str the string to set as the style of the engravings
 * @see query_style()
 */
void set_style( string str ) { style = str; }

/**
 * This method returns the style messages will be engraved in.
 * @return the style we engrave in
 * @see set_style();
 */
string query_style() { return style; }

/**
 * This method sets the cost of engraving one letter.
 * @param i the cost to set
 * @see query_letter_cost()
 */
void set_letter_cost( int i ) { letter_cost = i; }

/**
 * This method returns the cost of engraving 1 letter.
 * @return the cost of engraving 1 letter
 * @see set_letter_cost()
 */
int query_letter_cost() { return letter_cost; }

/**
 * Sets the shop keeper for the engraving shop.  If the shop keeper is
 * not set then it will not be checked for.  If it is checked it will be
 * checked for the existance of.  Make sure to check for the shopkeeper's
 * existance each reset, and clone him when needed.
 * @param ob the shop keeper to test for
 * @see query_engrave_shopkeeper()
 */
void set_engrave_shopkeeper( object ob ) {
    use_shop_keeper = 1;
    shop_keeper = ob;
} /* set_engrave_shopkeeper() */

/**
 * This method returns the currently ste shop keeper for the engraving shop.
 * @return the shop keeper
 * @see set_engrave_shopkeeper()
 */
object query_engrave_shopkeeper() { return shop_keeper; }

/**
 * This method is called when a living object is attempted to be engraved.
 * This should be overridden in the inheritable to print out the
 * message you wish to say.  If this function returns 1 then the
 * default failed message is not used.
 * @param liv the living objects
 * @return 0 use default fail mesasage, 1 override default fail message
 * @see do_engrave()
 */
protected int engrave_living( object *obs ) {
    return 0;
} /* engrave_living() */

/**
 * This method is called if the objects in question are unable to be
 * engraved.
 * This should be overridden in the inheritable to print out the
 * message you wish to say.  If this function returns 1 then the
 * default failed message is not used.
 * @param obs the objects which could not be engraved.
 * @return 0 use default fail mesasage, 1 override default fail message
 * @see do_engrave()
 */
protected int engrave_wrong_items( object *obs ) {
    return 0;
} /* engrave_wrong_items() */

/**
 * This method is called if the player does not have enough money to
 * complete the engraving.
 * This should be overridden in the inheritable to print out the
 * message you wish to say.  If this function returns 1 then the
 * default failed message is not used.
 * @param obs the objects which were unable to be engraved
 * @param cost the cost of the objects to be engraved
 * @return 0 use default fail mesasage, 1 override default fail message
 * @see do_engrave()
 */
protected int engrave_no_money( object *obs, int cost ) {
    return 0;
} /* engrave_no_money() */

/**
 * This method is called when the engrave is successful.
 * This should be overridden in the inheritable to print out the
 * message you wish to say.  If this function returns 1 then the
 * default success message is not used.
 * @see do_engrave()
 */
protected int engrave_objects( object *obs, int cost ) {
    return 0;
} /* engrave_objects() */

/** @ignore yes */
private int engravable_item( object ob ) {
    string type;

    type = ob->query_property("shop type");

    return type == "jewellers" || type == "armoury" ||
           ob->query_property(ENGRAVE_PROP) == 1;

} /* engravable_item() */

/**
 * This method does the actual engraving.
 * @param things the things to get engraved.
 * @param message the message to engarve on the objects
 * @see engrave_init()
 */
protected int do_engrave( object *things, string message ) {
    int cost;
    string str, place;
    object *liv, *engravable;

    if( use_shop_keeper && ( !shop_keeper || ENV(shop_keeper) != TO ) ) {
        add_failed_mess("There is no-one here to engrave $I for you.\n",
            things );
        return 0;
    }

    liv = filter( things, (: living($1) :) );
    if( sizeof(liv) && !engrave_living(liv) ) {
        add_failed_mess("You cannot engrave messages on $I, because they are "
            "living things.\n", liv );
    }

    if( !sizeof( things -= liv ) )
        return 0;

    if( !sizeof( engravable = filter( things, (: engravable_item :) ) ) ) {
        if( !engrave_wrong_items( things ) )
            add_failed_mess("You cannot engrave anything on $I.\n", things );
        return 0;
    }

    place = TO->query_property("place") || "default";

    str = implode( explode( message, " ") - ({ 0, ""}), "");
    cost = strlen(str) * letter_cost * sizeof(engravable);

    if( TP->query_value_in( place ) < cost ) {
        if( !engrave_no_money( engravable, cost ) )
            add_failed_mess("You don't have enough money to engrave $I, you "
                "need "+MONEY_H->money_value_string( cost, place )+".\n",
                engravable );
        return 0;
    }


    TP->pay_money( MONEY_H->create_money_array( cost, place ), place );
    engravable->add_read_mess( message, style, language );
    add_succeeded_mess("");

    if( !engrave_objects( engravable, cost ) )
        add_succeeded_mess( ({"You engrave the message \""+message+"\" into "
            "$I for "+MONEY_H->money_value_string( cost, place )+".\n",
            "$N get$s $I engraved with a message.\n"}), engravable );

    return 1;

} /* do_engrave() */

/**
 * This method should be called in the inheriting room's init function.  IUt
 * will setup the commands to allow the object to be engraved.
 * @see do_engrave()
 */
void init() {
    add_command("engrave", "<string> on <indirect:object:me>",
        (: do_engrave( $1, $4[0] ) :) );
} /* init() */

/** @ignore yes */
mixed stats() {
    return ({
        ({"letter cost", letter_cost }),
        ({"using shopkeeper", use_shop_keeper }),
        ({"shopkeeper", shop_keeper }),
        ({"engraving language", language }),
        ({"engraving style", style }),
    });
} /* stats() */
