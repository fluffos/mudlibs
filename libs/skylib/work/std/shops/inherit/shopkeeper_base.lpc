/**
 * This inherit adds some support for shopkeeper NPCs for shops.
 * It has a built in 'shopkeeper' variable, that you should
 * assign your NPC to, and which will be used to execute the
 * commands or messages you have set for browsing, buying or
 * listing the goods.
 * @author Sandoz, June 2002.
 * @example
 * void setup() {
 *     <general room code>
 *     ...
 *     set_use_shopkeeper();
 *     set_shopkeeper_buy_cmd( ({"'Thank you for your custom.", "beam"}) );
 *     set_shopkeeper_browse_cmd("'That is one hell of a good item, "
 *         "dontchathink?");
 *     set_shopkeeper_list_cmd("'That's all I've got today.");
 * }
 */

nosave object shopkeeper;
nosave mixed shopkeeper_browse_cmd, shopkeeper_buy_cmd, shopkeeper_list_cmd;
nosave int use_shopkeeper, busy;

private void do_unbusy();

/**
 * This method queries whether or not the shop is open,
 * doing all the checks for the existence of the shopkeeper.
 * It will automatically return 1 if we are not using
 * a shopkeeper at all.  If we are using a shopkeeper
 * and we fail the checks, an appropriate fail message
 * will be added to the player.
 * @return 1 if the shop is open, 0 if not
 */
int check_shopkeeper_open() {
    if( !use_shopkeeper )
        return 1;

    if( shopkeeper && ENV(shopkeeper) == TO )
        return 1;

    if( PO == TP )
        add_failed_mess("There is no-one here to serve you.\n");

    return 0;

} /* check_shopkeeper_open() */

/**
 * This method switches us into shopkeeper mode.
 * This means the shopkeeper will try to say the set
 * list/browse/buy messages when appropriate.
 */
void set_use_shopkeeper() { use_shopkeeper = 1; }

/**
 * This method queries whether or not we are using a shopkeeper.
 * @return 1 if we are using a shopkeeper NPC, 0 if not
 */
int query_use_shopkeeper() { return use_shopkeeper; }

/**
 * This method sets the command the shopkeeper should execute
 * when someone browses our wares.  It can be either a string,
 * an array of strings, or a function pointer.  The array of
 * strings will be executed in the order they are set.
 * @param cmd the command to set as our browse command
 * @example
 * set_shopkeeper_browse_cmd("'A nice piece of armour this.");
 * @example
 * void do_thank_player() {
 *     shopkeeper->init_command("thank "+TP->query_name() );
 * }
 * set_shopkeeper_browse_cmd( (: do_thank_player :) );
 * @example
 * set_shopkeeper_browse_cmd( ({"'A nice piece of armour this.",
 *                              "beam"}) );
 */
void set_shopkeeper_browse_cmd( mixed cmd ) {
    shopkeeper_browse_cmd = cmd;
} /* set_shopkeeper_browse_cmd() */

/**
 * This method returns the shopkeeper browse command.
 * @return the command the shopkeeper will execute when
 * someone browses something from the shop
 */
mixed query_shopkeeper_browse_cmd() { return shopkeeper_browse_cmd; }

/**
 * This method sets the message the shopkeeper should say
 * when someone buys our wares.  It can be either a string,
 * an array of strings, or a function pointer.  The array of
 * strings will be executed in the order they are set.
 * @param cmd the command to set as our buy command
 * @example
 * set_shopkeeper_buy_cmd("'Thank you for your custom.");
 * @example
 * void do_thank_player() {
 *     shopkeeper->init_command("thank "+TP->query_name() );
 * }
 * set_shopkeeper_buy_cmd( (: do_thank_player :) );
 * @example
 * set_shopkeeper_buy_cmd( ({"'Thank you for your custom.", "beam"}) );
 */
void set_shopkeeper_buy_cmd( string cmd ) {
    shopkeeper_buy_cmd = cmd;
} /* set_shopkeeper_buy_cmd() */

/**
 * This method returns the shopkeeper buy command.
 * @return the command the shopkeeper will execute when
 * someone buys something from the shop
 */
mixed query_shopkeeper_buy_cmd() { return shopkeeper_buy_cmd; }

/**
 * This method sets the message the shopkeeper should say
 * when someone lists our wares.  It can be either a string,
 * an array of strings, or a function pointer.  The array of
 * strings will be executed in the order they are set.
 * @param cmd the command to set as our list command
 * @example
 * set_shopkeeper_list_cmd("'Everything I have got is in mint "
 *    "condition, I assure you.");
 * @example
 * void do_thank_player() {
 *     shopkeeper->init_command("thank "+TP->query_name() );
 * }
 * set_shopkeeper_buy_cmd( (: do_thank_player :) );
 * @example
 * set_shopkeeper_buy_cmd( ({"'Everything I have got is in mint "
 *    "condition, I assure you.", "beam"}) );
 */
void set_shopkeeper_list_cmd( string cmd ) {
    shopkeeper_list_cmd = cmd;
} /* set_shopkeeper_list_cmd() */

/**
 * This method returns the shopkeeper list command.
 * @return the command the shopkeeper will execute when
 * someone lists the inventory of the shop
 */
mixed query_shopkeeper_list_cmd() { return shopkeeper_list_cmd; }

/** @ignore yes */
private void do_unbusy() {
    if( shopkeeper )
        shopkeeper->set_chats_off( 0 );
    busy = 0;
} /* do_unbusy() */

/** @ignore yes */
private void exec_shopkeeper_cmd( mixed cmd ) {
    if( use_shopkeeper && !busy && shopkeeper && ENV(shopkeeper) == TO ) {
        if( stringp( cmd ) ) {
            shopkeeper->init_command( cmd );
        } else if( pointerp( cmd ) ) {
            string str;
            int i;
            foreach( str in cmd ) {
                shopkeeper->init_command( str, i );
                i += 2;
            }
            shopkeeper->set_chats_off( busy = 1 );
            call_out( (: do_unbusy :), 2 * sizeof(cmd) );
        } else if( functionp( cmd ) ) {
            evaluate( cmd );
        }
    }
} /* exec_shopkeeper_cmd() */

/** @ignore yes */
protected void do_shopkeeper_browse() {
    return exec_shopkeeper_cmd( shopkeeper_browse_cmd );
} /* do_shopkeeper_browse() */

/** @ignore yes */
protected void do_shopkeeper_buy() {
    return exec_shopkeeper_cmd( shopkeeper_buy_cmd );
} /* do_shopkeeper_buy() */

/** @ignore yes */
protected void do_shopkeeper_list() {
    return exec_shopkeeper_cmd( shopkeeper_list_cmd );
} /* do_shopkeeper_list() */

/** @ignore yes */
mixed stats() {
    return ({
        ({"using shopkeeper", use_shopkeeper }),
        ({"shopkeeper", shopkeeper }),
        ({"shopkeeper busy", busy }),
    });
} /* stats() */
