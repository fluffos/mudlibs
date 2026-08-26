/**
 * Auction Room Inheritable
 * This room will give you everything you need to make an auction
 * room.
 * @author Terano
 * @started 3 October, 1998
 * @changed 24 March, 1999 Many exciting things. Terano.
 */

#include <money.h>
#include <move_failures.h>
#include <mail.h>

#define CASE "/obj/misc/case"
#define LOT_ID "lot number"
#define COLOUR_ID "colour code"

#define AUCTION_PLAYER_NAME 0
#define AUCTION_PLAYER_BID 1


#define COLOURS ({ "red", "orange", "yellow", "blue", "green", "indigo",\
  "violet", "crimson", "puce", "emerald", "ochre", "tangerine", "aquamarine",\
  "silver", "gold", "copper", "lilac" })
#define NO_COLOURS sizeof( COLOURS )

nosave inherit ROOM_OBJ;  //Why save all those evil room variables?
inherit "/global/player/auto_load";

class lot_details {
    string seller;
    int expiration_time;
    int reserve_price;
    mapping bids;
    int lot_id;
    mixed *lot_autoload;
    mixed *current_bid;
    string *auto_bids;
    string desc;
}

class lot_details *lots = ({ }); //Array of lots
class lot_details *expired_lots = ({ });
mapping payments = ([ ]); //Stored as ([ "name": amount ]);
int lot_count;

nosave string *used_colours = ({ });
nosave string currency = "default";
nosave string location;
nosave string *case_desc = ({ });
nosave object *cases = ({ });
nosave int admin_cost = 2000; //defaults to AM$5
nosave float commission = ( 5.0/100.0 ); //Default to 5%

void save_file();
void load_file();
void load_inv();
void set_location( string loc );
void set_currency( string cur );
void set_admin_cost( int value );
void set_commission( int percent );
void set_case_desc( string *bits );

int do_deposit( object *things, int auction_time, string time_type,
  string res_price );
int do_bid( string offer, object *boxes );
int do_collect( string pattern );
int do_list();
int do_withdraw( object *cases );
int do_describe( object *cases, string int_desc );

void remove_lot( object _case );
void end_auction( string name, object *items, int cost,
  string location, int status );

void adjust_money( int amount, object player );

mixed *query_min_bid( object _case );

void check_lots();

void create() {
    do_setup++;
    ::create();
    do_setup--;

    if ( !do_setup ) {
        TO->setup();
        TO->reset();
    }
    add_extra_look( TO );

    call_out( "load_file", 1 ); //To give time for location data to be restored
    call_out( "load_inv", 2 ); //To give time for save data to be restored
    call_out( "check_lots", 5 );
}

void init() {

    TP->add_command( "bid", TO,
      "<string> {on|for} <indirect:object:here>",
      (: do_bid( $4[0], $1 ) :) );

    TP->add_command( "collect", TO,
      ({ "successful bids", "money", "expired lots",
        "all" }),
      (: do_collect( $5 ) :) );

    TP->add_command( "deposit", TO,
      "<indirect:object:me> for <number> "
      "{minute|hour|day} auction" ,
      (: do_deposit( $1, $4[1], $4[2], "" ) :) );
    TP->add_command( "deposit", TO,
      "<indirect:object:me> for <number> "
      "{minute|hour|day} "
      "auction with [a] reserve price of <string>",
      (: do_deposit( $1, $4[1], $4[2], $4[3] ) :) );

    TP->add_command( "list", TO, "" );
    TP->add_command( "withdraw", TO,
      "<indirect:object> from auction",
      (: do_withdraw( $1 ) :) );

    TP->add_command( "scrawl", TO,
      "<string> on <indirect:object>",
      (: do_describe( $1, $4[0] ) :) );
}

/**
 * This function allows an object to deposit an item for auction,
 * Things are the items to auction, auction length is the length in seconds,
 * function_cb and object_cb are function names and object paths to allow a
 * call back to be scheduled for when the auction is over, res price is
 * the reserve price and int_desc is a description that will be written on
 * the case.
 */
int automated_deposit( object *things, int auction_length,
  string function_cb, string object_cb,
  int res_price, string int_desc ) {
    string colour;
    object box;
    class lot_details temp;

    string *avail_colours = COLOURS - used_colours;


    if ( !sizeof( avail_colours ) )
        return -1; //No Space

    if ( !sizeof( things ) || auction_length < 0 )
        return -2; //Invalid Param

    if ( !objectp( load_object( object_cb ) ) )
        return -3; //Invalid callback ob

    colour = avail_colours[ random( sizeof( avail_colours ) ) ];
    lot_count ++;

    box = clone_object( CASE );
    box->add_property( LOT_ID, lot_count );
    box->add_property( COLOUR_ID, colour );
    things->move( box );
    box->add_adjective( colour );

    temp = new( class lot_details, seller: "Auto", reserve_price: res_price,
      expiration_time: time() + auction_length, bids: ([ ]),
      lot_id: lot_count, current_bid: allocate( 2 ),
      lot_autoload: create_auto_load( ({ box }), 0 ),
      auto_bids: ({ function_cb, object_cb }), desc: int_desc );

    lots += ({ temp });

    box->move( TO );
    box->add_extra_look( TO );
    box->add_property( "there", "sitting in the center of the room" );
    box->set_short( colour + " case" );

    cases += ({ box });

    if ( sizeof( case_desc ) ) box->setup_case( case_desc );

    return lot_count;

}//End automated_deposit

int do_deposit( object *things, int auction_time,
  string time_type, string res_price ) {

    string *avail_colours = COLOURS - used_colours;
    string colour;
    object *auctioned = ({ });
    object *unauctionable = ({ });
    object box;
    class lot_details temp;
    int finishtime, value = 0;

    if ( auction_time <= 0 || ( time_type == "day" && auction_time > 10 )
      || ( time_type == "minute" && auction_time > 59 ) ||
      ( time_type == "hour" && auction_time > 23 ) ) {
        TP->add_failed_mess( TO,
          "That's not a valid length.\n" );
        return 0;
    }

    if ( sizeof( res_price ) ) {
        value = MONEY_HAND->value_from_string( res_price, currency );

        if ( value == 0 ) {
            TP->add_failed_mess( TO,
              res_price +" isn't a valid reserve price.\n" );
            return 0;
        }
    }

    if ( !sizeof( avail_colours ) ) {
        TP->add_failed_mess( TO, "The auction house "
          "doesn't have any display cases left to auction your item.\n" );
        return 0;
    }

    colour = avail_colours[ random( sizeof( avail_colours ) ) ];

    switch( time_type ) {
    case "minute":
        finishtime = time() + ( auction_time * 60 );
        break;
    case "hour":
        finishtime = time() + ( auction_time * 60 * 60 );
        break;
    case "day":
        finishtime = time() + ( auction_time * 60 * 60 * 24 );
        break;
    default:
        return 0;
    }

    box = clone_object( CASE );

    auctioned = filter_array( things,
      (: $1->move( $(box) ) == MOVE_OK :) );

    unauctionable = things - auctioned;

    if ( sizeof( unauctionable ) ) {
        auctioned->move( TP );
        TP->add_failed_mess( TO,
          "You can't $V $I.\n", unauctionable );
        return 0;
    }

    lot_count ++;
    used_colours += ({ colour });

    box->add_property( LOT_ID, lot_count );
    box->add_property( COLOUR_ID, colour );

    temp = new( class lot_details, seller: TP->query_name(),
      reserve_price: value, expiration_time: finishtime,
      bids: ([ ]), lot_id: lot_count, current_bid: allocate( 2 ),
      lot_autoload: create_auto_load( ({ box }), 0 ),
      auto_bids: ({ }), desc: "" );

    lots += ({ temp });

    box->move( TO );
    box->add_extra_look( TO );
    box->add_property("there", "sitting in the center of the room");
    box->set_short( colour + " case" );
    box->add_adjective( colour );
    cases += ({ box });

    if ( sizeof( case_desc ) ) box->setup_case( case_desc );

    save_file();

    if ( strlen( res_price ) )
        TP->add_succeeded_mess( TO, "$N $V $I for "+
          add_a( query_num( auction_time, 5000 ) ) + " " + time_type +
          " auction, with a reserve price of "+
          MONEY_HAND->money_value_string( value, currency ) +".\n",
          auctioned );
    else
        TP->add_succeeded_mess( TO, "$N $V $I for a "+
          query_num( auction_time, 5000 ) + " " + time_type +
          " auction, with no reserve price.\n", auctioned );

    return 1;

}

int do_list() {

    object _case;

    if ( !sizeof( cases ) ) {
        TP->add_failed_mess( TO, "There are "
          "no cases to peruse at the moment.\n" );
        return 0;
    }

    printf( "Items currently for auction:\n" );
    foreach( _case in cases ) {
        if ( !objectp( _case ) ) continue;
        printf( "  %s: %s.\n", capitalize( _case->query_short() ),
          capitalize("/global/events"->convert_message(
              query_multiple_short(all_inventory( _case ) ) ) ) );
    }

    return 1;

}

int do_bid( string offer, object *boxes ) {

    object box;
    int value, temp_lot_id;
    class lot_details *filtered_lots;
    class lot_details current_lot;


    if ( sizeof( boxes ) > 1 ) {
        TP->add_failed_mess( TO,
          "You can only $V on one case at "
          "a time.\n" );
        return 0;
    }

    box = boxes[0];

    if ( member_array( box, cases ) == -1 ) {
        TP->add_failed_mess( TO,
          "$I isn't being auctioned here.\n", ({ box }) );
        return 0;
    }

    temp_lot_id = box->query_property( LOT_ID );

    filtered_lots = filter( lots, (: $1->lot_id == $(temp_lot_id) :) );

    if ( sizeof( filtered_lots ) != 1 ) {
        printf( "Please inform a creator, there are %d records to "
          "match this case.\n", sizeof( filtered_lots ) );
        return 1;
    }

    current_lot = filtered_lots[0];

    if ( time() > current_lot->expiration_time ) {
        TP->add_failed_mess(TO,
          "The bidding on this item is finished.\n" );
        return 0;
    }

    value = MONEY_HAND->value_from_string( offer, currency );

    if ( value == 0 ) {
        TP->add_failed_mess( TO,
          offer +" isn't worth anything here.\n" );
        return 0;
    }

    if ( TP->query_value_in( currency ) < value ) {
        TP->add_failed_mess( TO, "You don't "
          "have that much.\n" );
        return 0;
    }

    if ( current_lot->reserve_price != 0 &&
      value < current_lot->reserve_price ) {
        TP->add_failed_mess( TO,
          "The reserve price for this lot is "+
          MONEY_HAND->money_value_string(
            current_lot->reserve_price,
            currency ) +".\n" );
        return 0;
    }

    if ( sizeof( current_lot->current_bid ) &&
      current_lot->current_bid[ AUCTION_PLAYER_BID ] >= value ) {
        TP->add_failed_mess(TO,
          "Someone else has already bid more than "
          "that.\n");
        return 0;
    }

    if ( sizeof( current_lot->current_bid ) &&
      ( ( value - current_lot->current_bid[ AUCTION_PLAYER_BID ] ) <
        ( current_lot->current_bid[ AUCTION_PLAYER_BID ] / 20 ) ) ) {
        TP->add_failed_mess( TO, "You must bid 5% "
          "more then the current bid.\n" );
        return 0;
    }

    current_lot->bids[ TP->query_name() ] = value;
    current_lot->current_bid[0] = TP->query_name();
    current_lot->current_bid[1] = value;

    TP->add_succeeded_mess(TO, "$N $V "+ offer +" for "+
      query_multiple_short(all_inventory(box)) +
      ".\n" );

    save_file();
    return 1;
}

mixed *query_bid_info( object _case ) {

    int temp_lot_id;
    class lot_details *filtered_lots;

    if ( member_array( _case, cases ) == -1 )
        return 0;

    temp_lot_id = _case->query_property( LOT_ID );
    filtered_lots = filter( lots, (: $1->lot_id == $(temp_lot_id) :) );

    if ( sizeof( filtered_lots ) != 1  )
        return 0;

    return ({ ( ( filtered_lots[0]->current_bid[ AUCTION_PLAYER_BID ] ) ?
        filtered_lots[0]->current_bid[ AUCTION_PLAYER_BID ] :
        filtered_lots[0]->reserve_price ), currency,
      filtered_lots[0]->expiration_time - time() });

}

void adjust_money( int amount, object player ) {
    object money;

    if ( amount < 0 ) { //Taking money
        player->pay_money(MONEY_HAND->create_money_array(-amount, currency ));
        return;
    }
    money = MONEY_HAND->create_money_array( amount, currency );
    player->adjust_money( money, currency );
}

void load_file() {

    if ( !stringp( location ) ) return;
    if ( file_size( location +".o" ) < 0 ) return;
    unguarded( (: restore_object, location :) );
    return;

}

void save_file() {

    if ( !stringp( location ) ) return;
    unguarded( (: save_object, location :) );
    return;
}

void check_lots() {

    object _case;
    mixed *info;

    call_out( "check_lots", 60 );

    if ( !sizeof( cases ) ) return;

    foreach( _case in cases ) {
        info = query_bid_info( _case );

        if ( !arrayp( info ) || info[2] < 0 )
            remove_lot( _case );
    }
}

/**
 * Function that is called when bidding expires on an item,
 * mask it if you want to do something interesting.
 * Remember to put in ::remove_lot though, otherwise auctions will not end!
 */
void remove_lot( object _case ) {

    class lot_details *temp_lots, lot;

    int temp_lot_id = _case->query_property( LOT_ID );

    cases -= ({ _case });
    temp_lots = filter( lots, (: $1->lot_id == $(temp_lot_id) :) );

    foreach( lot in temp_lots ) { //Do call backs on auto items
        if ( sizeof( lot->auto_bids ) ) {
            call_other( lot->auto_bids[1], lot->auto_bids[0], temp_lot_id,
  stringp( lot->current_bid[ AUCTION_PLAYER_NAME ] ), lot->current_bid[ AUCTION_PLAYER_NAME ], all_inventory( _case ) );
        }
    }

    end_auction( ( sizeof( lot->current_bid[ AUCTION_PLAYER_NAME ] ) ?
        lot->current_bid[ AUCTION_PLAYER_NAME ] :
        lot->seller ),
      all_inventory(_case ),
      lot->current_bid[ AUCTION_PLAYER_BID ],
      query_short(),
      stringp( lot->current_bid[ AUCTION_PLAYER_NAME ] ) );

    lots -= temp_lots;
   if ( lot->seller != "Auto" && !stringp( lot->current_bid[ AUCTION_PLAYER_NAME ] ) )
    expired_lots += temp_lots;
    call_out( (: $(_case)->dest_me() :), 2 );

}

string extra_look( object ob ) {

    class lot_details temp, *temp2;
    mixed bid_info;
    string ret;
    int temp_lot_id;

    if ( member_array( ob, cases ) == -1 ) return "";

    temp_lot_id = ob->query_property( LOT_ID );
    temp2 = filter( lots, (: $1->lot_id == $(temp_lot_id) :) );

    if ( sizeof( temp2 ) != 1 ) return "Not found in lot array!\n";

    temp = temp2[0];

    bid_info = temp->current_bid;

    ret = "";

    if ( !stringp( bid_info[ AUCTION_PLAYER_NAME ] ) ) {
        if ( temp->reserve_price ) {
            ret += "Reserve price is: ";
            ret += MONEY_HAND->money_value_string( temp->reserve_price, currency
);
            ret += ".\n";
        }
        else
            ret += "No bid as of yet.\n";
    }
    else
        ret += "The current bid is "+ MONEY_HAND->money_value_string(
bid_info[1],
          currency ) +
        ", made by "+ capitalize( bid_info[ AUCTION_PLAYER_NAME ] ) +".\n";

    ret += "The bidding on this lot stops at "+ mudtime( temp->expiration_time )+
    ".\n";

    if ( sizeof( temp->desc ) ) {
        ret += "Neatly lettered on the case is: ";
        ret += temp->desc;
        ret += ".\n";
    }
    return ret;
}

void load_inv() {
    class lot_details temp_lot;
    object _case;
    string colour;

    if ( !sizeof( lots ) ) return;
    foreach( temp_lot in lots ) {
        if ( temp_lot->expiration_time < time() ) {
            expired_lots += ({ temp_lot });
            lots -= ({ temp_lot });
            continue;
        }
        cases += load_auto_load_to_array( temp_lot->lot_autoload, TP );
    }

    foreach( _case in cases ) {
        colour = _case->query_property( COLOUR_ID );
        _case->add_adjective( colour );
        _case->set_short( colour + " case" );
        _case->add_property( "there", "sitting in the center of the room" );
        used_colours += ({ colour });
    }

    call_out( (: cases->add_extra_look( TO ) :), 2 );
    call_out( (: cases->move( TO ) :), 2 );
}

void dest_me() {
    save_file();
    if ( sizeof( cases ) ) cases->dest_me();
    ::dest_me();
}

void set_save_path( string path ) { location = path; }
void set_currency( string cur ) { currency = cur; }
void set_admin_cost( int value ) { admin_cost = value; }
void set_commission( int percent ) { commission = percent/100.0; }
void set_case_desc( string *bits ) { case_desc = bits; }
class lot_details *query_lots() { return lots; }
class lot_details *query_expired_lots() { return expired_lots; }
mapping query_payments() { return payments; }

int do_collect( string pattern) {
    int amount;
    class lot_details lot_pending, *lots_pending = ({ });
    object box, *boxes = ({ }), *items = ({ }), itemsnomove;
    string *names = ({ });


    if ( pattern == "all" ) {
        do_collect( "money" );
        do_collect( "successful bids" );
        do_collect( "expired lots" );
        return 1;
    }

    if ( pattern == "money" ) {
        lots_pending = filter( expired_lots, (: ( $1->seller == $2 ) && (
stringp( $1->current_bid[ AUCTION_PLAYER_NAME ] ) ) :),
TP->query_name() );
        if ( undefinedp( payments[ TP->query_name() ] ) ) {
            if ( sizeof( lots_pending ) ) {
                foreach( class lot_details tempy in lots_pending ) { names += ({
tempy->current_bid[ AUCTION_PLAYER_NAME ] }); }
write( query_multiple_short( names ) +
" must pay for the items they bid on before you can collect "
                  "the money for them!\n" );
                return 0;
            }
        }
        if ( undefinedp( payments[ TP->query_name() ] ) ) {
            TP->add_failed_mess( TO,
              "You aren't owed any money.\n" );
            return 0;
        }
        amount = payments[ TP->query_name() ];
        adjust_money( amount - to_int( amount * commission ), TP );

        printf( "You recieve %s, minus %s commission.\n",
          MONEY_HAND->money_value_string( amount, currency ),
          MONEY_HAND->money_value_string( to_int( amount * commission ),
            currency ) );

        map_delete( payments, TP->query_name() );

        TP->add_succeeded_mess( TO, "$N $V some money from $D.\n" );
        save_file();
        return 1;
    }

    if ( pattern == "successful bids" ) {
        //Items that have expired with the player as the current bid,
        lots_pending = filter( expired_lots,
          (: $1->current_bid[ AUCTION_PLAYER_NAME ] == $2 :),
          TP->query_name() );

        if ( !sizeof( lots_pending ) ) {
            TP->add_failed_mess( TO,
              "You aren't expecting any items.\n" );
            return 0;
        }

        foreach( lot_pending in lots_pending )
        amount += lot_pending->current_bid[ 1 ];

        if ( TP->query_value_in( currency ) < amount ) {
            printf( "You have %d %s waiting, for a total cost of %s.\n"
              "You don't have enough money.\n",
              sizeof( lots_pending ),
              sizeof( lots_pending ) > 1 ? "lots" : "lot",
              MONEY_HAND->money_value_string( amount, currency ) );
            TP->add_failed_mess( TO, "" );
            return 0;
        }

        adjust_money( -amount, TP );

        foreach( lot_pending in lots_pending ) {
            boxes += load_auto_load_to_array( lot_pending->lot_autoload,
              TP );
            if ( undefinedp( payments[ lot_pending->seller ] ) )
                payments[ lot_pending->seller ] =
                lot_pending->current_bid[ AUCTION_PLAYER_BID ];
            else
                payments[ lot_pending->seller ] +=
                lot_pending->current_bid[ AUCTION_PLAYER_BID ];
            expired_lots -= ({ lot_pending });
        }

        foreach( box in boxes )
        items += all_inventory( box );

        printf( "You collect %s.\n", query_multiple_short( items ) );

        itemsnomove = filter( items, (: $1->move( TP ) != MOVE_OK :)
);

        if ( sizeof( itemsnomove ) ) {
            printf( "Unfortunately, you couldn't carry %s and it was left "
              "on the floor for you.\n",
              query_multiple_short( itemsnomove ) );
            itemsnomove->move( TO );
        }
        printf( "You had %d %s waiting, for a total cost of %s.\nYou "
          "hand over the money.\n",
          sizeof( lots_pending ),
          sizeof( lots_pending ) > 1 ? "lots" : "lot",
          MONEY_HAND->money_value_string( amount, currency ) );

        return 1;
    }

    if ( pattern == "expired lots" ) {
        //Items that have expired with the player as the current bid,
        lots_pending = filter( expired_lots,
          (: !stringp( $1->current_bid[ AUCTION_PLAYER_NAME ] ) && $1->seller == $2 :),
          TP->query_name() );

        if ( !sizeof( lots_pending ) ) {
            TP->add_failed_mess( TO, "You aren't expecting "
              "any items.\n" );
            return 0;
        }

        amount = admin_cost * sizeof( lots_pending );

        if ( TP->query_value_in( currency ) < amount ) {
            printf( "You have %d %s waiting, for a total administration "
              "cost of %s.\n"
              "You don't have enough money.\n",
              sizeof( lots_pending ),
              sizeof( lots_pending ) > 1 ? "lots" : "lot",
              MONEY_HAND->money_value_string( amount, currency ) );
            return 0;
        }

        adjust_money( -amount, TP );

        foreach( lot_pending in lots_pending ) {
            boxes += load_auto_load_to_array( lot_pending->lot_autoload, TP );
            expired_lots -= ({ lot_pending });
        }

        foreach( box in boxes )
        items += all_inventory( box );

        printf( "You collect %s.\n", query_multiple_short( items ) );

        itemsnomove = filter( items, (: $1->move( TP ) != MOVE_OK :)
);

        if ( sizeof( itemsnomove ) ) {
            printf( "Unfortunately, you couldn't carry %s and it was "
              "left on the floor for you.\n",
              query_multiple_short( itemsnomove ) );
            itemsnomove->move( TO );
        }

        printf( "You had %d %s waiting, for a total administration "
          "cost of %s.\n"
          "You hand over the money.\n",
          sizeof( lots_pending ), sizeof( lots_pending ) > 1 ?
          "lots" : "lot",
          MONEY_HAND->money_value_string( amount, currency ) );
        return 1;
    }
}

int do_withdraw( object *boxes ) {
    object box, *items, *itemsnomove;
    class lot_details *filtered_lots;
    class lot_details current_lot;
    int temp_lot_id;

    if ( sizeof( boxes ) > 1 ) {
        TP->add_failed_mess( TO,
          "You can only $V on one case at "
          "a time.\n" );
        return 0;
    }

    box = boxes[0];

    if ( member_array( box, cases ) == -1 ) {
        TP->add_failed_mess( TO,
          "$I isn't being auctioned here.\n",
          ({ box }) );
        return 0;
    }

    temp_lot_id = box->query_property( LOT_ID );

    filtered_lots = filter( lots, (: $1->lot_id == $(temp_lot_id) :) );

    if ( sizeof( filtered_lots ) != 1 ) {
        printf( "Please inform a creator, there are %d records to "
          "match this case.\n", sizeof( filtered_lots ) );
        return 1;
    }

    current_lot = filtered_lots[0];

    if ( TP->query_name() != current_lot->seller &&
      !creatorp(TP) ) {
        TP->add_failed_mess( TP, "This isn't your "
          "lot to withdraw!\n" );
        return 0;
    }

    lots -= filtered_lots;

    items = all_inventory( box );

    printf( "You collect %s.\n", query_multiple_short( items ) );

    itemsnomove = filter( items, (: $1->move( TP ) != MOVE_OK :) );

    if ( sizeof( itemsnomove ) ) {
        printf( "Unfortunately, you couldn't carry %s and it was "
          "left on the floor for you.\n",
          query_multiple_short( itemsnomove ) ) ;
        itemsnomove->move( TO );
    }
    cases -= ({ box });
    box->dest_me();

    TP->add_succeeded_mess( TO, "" );
    return 1;
}

int do_describe( object *boxes, string int_desc ) {

    object box;
    class lot_details *filtered_lots;
    class lot_details current_lot;
    int temp_lot_id;

    if ( sizeof( boxes ) > 1 ) {
        TP->add_failed_mess( TO,
          "You can only $V on one case at "
          "a time.\n" );
        return 0;
    }

    box = boxes[0];

    if ( member_array( box, cases ) == -1 ) {
        TP->add_failed_mess( TO,
          "$I isn't being auctioned here.\n",
          ({ box }) );
        return 0;
    }

    temp_lot_id = box->query_property( LOT_ID );

    filtered_lots = filter( lots, (: $1->lot_id == $(temp_lot_id) :) );

    if ( sizeof( filtered_lots ) != 1 ) {
        printf( "Please inform a creator, there are %d records to "
          "match this case.\n", sizeof( filtered_lots ) );
        return 1;
    }

    current_lot = filtered_lots[0];

    if ( TP->query_name() != current_lot->seller &&
      !creatorp(TP) ) {
        TP->add_failed_mess( TP, "This isn't your "
          "lot to describe!\n" );
        return 0;
    }

    current_lot->desc = int_desc;

    printf( "You neatly letter %s on the case.\n", int_desc );
    TP->add_succeeded_mess( TO, "" );
    return 1;

}

/**
 * This function is called when an auction ends, it is designed to
 * be masked so you can do something funky, like mail the successful
 * bidder at the end of an auction.
 * @param name The succesful bidders name
 * @param objects The items succesfully bid for
 * @param price The amount paid
 * @param location The short of the location
 * @param status 1 if the item was sold, 0 if it wasn't
 */
void end_auction( string name, object *items, int amount, string location,
  int status  ) {

   if ( !LOGIN_OBJ->test_user( name ) )
     return; //Lets not mail any not real players.

    if ( status ) {
        AUTO_MAILER->auto_mail( name, location, "Your successful purchase!",
          "","Congratulations! You have succesfully purchased "+
          "/global/events"->convert_message( query_multiple_short( items ) ) +
          " with a bid of "+ MONEY_HAND->money_value_string( amount, currency )+
          ".\n\nPlease come and collect your items promptly.\n", 0, 0 );
        return;
    }
    AUTO_MAILER->auto_mail( name, location, "Your unsuccesful sale!",
      "", "Dear "+ name +",\nIt is with some regret that I inform you "
      "that we were unable to sell " +
      "/global/events"->convert_message( query_multiple_short( items ) ) +
      ".\n\nPlease come and collect your items promptly.\n", 0, 0 );
    return;
}

mixed stats() {
    return ::stats() +
    ({ ({ "lots", sizeof(lots) }),
      ({ "expired lots", sizeof(expired_lots) }),
      ({ "payments", sizeof(payments) }),
      ({ "lot count", lot_count }),
    });
}
