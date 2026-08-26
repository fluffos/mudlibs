/**
 * Auction Room Inheritable
 * This room will give you everything you need to make an auction room
 * @author Terano
 * @started 3 October, 1998
 */

#include <money.h>
#include <move_failures.h>
#define SAVEPATH location
#define CASE "/obj/misc/case"

inherit "/std/room/basic_room";
inherit "/global/auto_load";

class lot_details {  string seller; mixed *current_bid; 
                     int expiry_time; mapping all_bids; }

mapping lots = ([ ]);
//Stored as ([ "lot id": ({ auto_loading string, lot_details }), ])
mapping payments = ([ ]);
//Stored as ([ "name": amount ])

nosave string currency = "default";
nosave string location;
nosave string *case_desc = ({ });
nosave object *cases = ({ });
nosave int admin_cost = 2000; //Defaults to $5 AM
nosave float commission = (5/100);  //Defaults to 5%

int do_deposit( object *things, int auction_time, string time_type  );
int do_bid( string offer, object *boxs );
int do_collect( object *boxs, string pattern );
void save_file();
void load_file();
void load_inv();
void set_location( string loc );
void set_currency( string cur );
void set_admin_cost( int value );
void set_commission( int percent );
void set_case_desc( string *bits );
void adjust_money( int amount, object player );

void create() {
    do_setup++;
    ::create();
    do_setup--;

    if ( !do_setup ) {
        this_object()->setup();
        this_object()->reset();
    }
    call_out( "load_file", 2 ); //To give time for location data to be restored
    call_out( "load_inv", 4 ); //To give time for save data to be restored
}

void init() {
    this_player()->add_command( "bid", this_object(),"<string> on <indirect:object:here>",
      (: do_bid( $4[0], $1 ) :) );
    this_player()->add_command( "collect", this_object(), ({ "<indirect:object:here>", "money" }),
      (: do_collect( $1, $5 ) :) );
    this_player()->add_command( "deposit", this_object(), "<indirect:object> for <number>"
      " {minute|hour|day} auction",
      (: do_deposit( $1, $4[1], $4[2] ) :) );
}

int do_deposit( object *things, int auction_time, string time_type ) {

    object *auctioned = ({ });
    object *unauctionable = ({ });
    object box;
    class lot_details temp;
    int finishtime;

    if ( auction_time < 0 ) {
        add_failed_mess( this_object(), "That's not a valid length.\n" );
        return 0;
    }

    switch( time_type ) {
    case "minute": finishtime = time() + ( auction_time * 60 );
        break;
    case "hour":  finishtime = time() + ( auction_time * 60 * 60 );
        break;
    case "day":  finishtime = time() + ( auction_time * 60 * 60 * 24 );
        break;
    default: return 0;
    }

    box = clone_object( CASE );

    auctioned = filter_array( things,
      (: $1->move( $(box) ) == MOVE_OK :) );

    unauctionable = things - auctioned;

    if ( sizeof( unauctionable ) ) {
        auctioned->move( this_player() );
        this_player()->add_failed_mess( this_object(),
          "You can't $V $I.\n", unauctionable );
        return 0;
    }

    box->add_property( "lot_code", finishtime ); 

    temp = new( class lot_details, seller: this_player()->query_name(), 
      current_bid: allocate(2),
      expiry_time: finishtime, all_bids: ([ ]) );

    lots[ finishtime ] = ({ create_auto_load( ({ box }), 0 ), temp }); 
    box->move( this_object() );
    box->add_extra_look( this_object() );
    box->add_property("there", "against a wall");
    if ( sizeof( case_desc) ) box->setup_case( case_desc );
    save_file();

    this_player()->add_succeeded_mess( this_object(), "$N $V $I for "+ 
      add_a( query_num( auction_time, 5000 ) ) + " " + time_type + " auction.\n",
      auctioned );
    return 1;
}

int do_bid( string offer, object *boxs ) {

    object box;
    int value, lot_number;
    class lot_details current_lot;

    if ( sizeof( boxs ) > 1 ) {
        this_player()->add_failed_mess( this_object(), "You can only $V on one case at "
          "a time.\n" );
        return 0;
    }

    box = boxs[0];

    lot_number = box->query_property( "lot_code" );

    if ( undefinedp( lots[ lot_number ] ) ) return 0;

    if (time() > lot_number ) {
        this_player()->add_failed_mess( this_object(), "The bidding on this " 
          "item is finished.\n" );
        return 0;
    }

    current_lot = lots[ lot_number ][1];

    value = MONEY_HAND->value_from_string( offer, currency );
    if ( this_player()->query_value_in( currency ) < value ) {
      this_player()->add_failed_mess( "You don't have that much.\n" );
      return 0;
    }

    if ( sizeof( current_lot->current_bid ) && current_lot->current_bid[1] > value ) {
        this_player()->add_failed_mess( this_object(), 
          "Someone else has already bid more then that.\n");
        return 0;
    }

    current_lot->all_bids[ this_player()->query_name() ] = value;
    current_lot->current_bid[0] = this_player()->query_name();
    current_lot->current_bid[1] = value;

    this_player()->add_succeeded_mess(this_object(),
      "$N $V "+ offer +" for "+ query_multiple_short( all_inventory( box ) ) +".\n" );
    save_file();
    return 1;

}


int do_collect( object *boxs, string pattern) {

    int amount;
    object box, *collected, *things;
    int lotid;
    class lot_details temp;

    if ( pattern == "money" ) {

        if ( undefinedp( payments[ this_player()->query_name() ] ) ) {
            this_player()->add_failed_mess( this_object(), "You aren't owed any money!\n" );
            return 0;
        }

        amount =  payments[ this_player()->query_name() ];
        adjust_money( amount - ( amount * commission ), this_player() );

        printf( "You recieve %s, minus %s comission.\n", 
          MONEY_HAND->money_value_string( amount, currency ),
          MONEY_HAND->money_value_string( (amount/20), currency ) );

        map_delete( payments, this_player()->query_name() );

        this_player()->add_succeeded_mess( this_object(), "$N $V some money from $D.\n" );
        save_file();
        return 1;
    }

    if ( sizeof( boxs ) > 1 ) {
        this_player()->add_failed_mess( this_object(), "You can only $V one case at "
          "a time.\n" );
        return 0;
    }

    box = boxs[0];
    things = all_inventory( box );
    lotid = box->query_property( "lot_code" );
    if ( undefinedp( lots[ lotid ] ) ) 
        return notify_fail( "Something screwed up, please bug rep this room.\n" );
    temp = lots[ lotid ][1];


    if ( lotid > time() ) {
      this_player()->add_failed_mess( this_object(), "The auction isn't over yet.\n" );
      return 0;
    }

    if ( sizeof( temp->current_bid ) && 
         temp->current_bid[0] != this_player()->query_name() ) {
        this_player()->add_failed_mess( this_object(), "You aren't entitled to this lot!\n");
        return 0;
    } 

    if ( !sizeof( temp->current_bid ) ) { //No bidders

      if ( this_player()->query_name() != temp->seller ) {
          this_player()->add_failed_mess( this_object(), 
            "You aren't entitled to this lot!\n");
          return 0;
      } 

      adjust_money( -admin_cost, this_player() );
      collected = filter_array( things,
         (: $1->move( this_player(), "$N is given to you." ) == MOVE_OK :) );

      if ( sizeof( things - collected ) ) {
         write( "However you can't carry "+
           query_multiple_short( things - collected ) 
           +" and it is put on the ground instead.\n" );
         ( things - collected )->move( this_object() );
      }

      this_player()->add_succeeded_mess( this_object(), "$N pays the administration "
        "fee and $V $I.\n", things );
      box->move( "/room/rubbish" );
      map_delete( lots, lotid );
      save_file();
      return 1;
    }

    amount = temp->current_bid[1];

    if ( this_player()->query_value_in( currency ) < amount ) {
        this_player()->add_failed_mess( this_object(), "It will cost you "+
          MONEY_HAND->money_value_string( amount, currency ) +" to collect "
          "your items.\n" );
        return 0;
    }

    adjust_money( -amount, this_player() );
    collected = filter_array( things,
       (: $1->move( this_player(), "$N is given to you." ) == MOVE_OK :) );

    if ( sizeof( things - collected ) ) {
       write( "However you can't carry "+
         query_multiple_short( things - collected ) 
         +" and it is put on the ground instead.\n" );
       ( things - collected )->move( this_object() );
    }

    this_player()->add_succeeded_mess( this_object(), "$N pays the bid "
      "and $V $I.\n", things  );
    if (!undefinedp( payments[ temp->seller ] ) ) 
        payments[ temp->seller ] += amount;
    else payments[ temp->seller ] = amount;

    box->move( "/room/rubbish" );
    map_delete( lots, lotid );
    save_file();
    return 1;

}


void load_file() {

    if ( !stringp( location ) ) return;
    if ( file_size( SAVEPATH +".o" ) < 0 ) return;
    unguarded( (: restore_object, SAVEPATH :) );
    return;

}

void save_file() {
    if ( !stringp( location ) ) return;
    unguarded( (: save_object, SAVEPATH :) );
    return;
}

string extra_look( object ob ) {

    class lot_details temp;
    mixed bing;
    string ret;

    if ( ob == this_object() && query_auto_loading() ) 
      return "Cases are being wheeled into the room.\n";

    if ( ob->query_name() != "case" ) return "";
    if ( undefinedp( lots[ ob->query_property( "lot_code" ) ] ) ) return "";

    temp = lots[ ob->query_property( "lot_code" ) ][1];
    bing = temp->current_bid;

    if ( !stringp( bing[0] ) ) ret = "No bid as of yet.\n";
    else ret = "The current bid is "+ MONEY_HAND->money_value_string( bing[1],
      currency ) +".\n";

    return ret + "The bidding on this lot stops at "+
      mudtime( ob->query_property( "lot_code" ) );
}

void load_inv() {
    mixed key;
    mixed data;

    if ( !sizeof( lots ) ) return;
    foreach( key,data in lots ) {
        cases += load_auto_load_to_array( data[0], this_player() );
    }
    call_out( (: cases->add_extra_look( this_object() ) :), 10 );
    call_out( (: cases->move( this_object() ) :), 10 );
}

void dest_me() {

    save_file();
    if ( sizeof( cases ) ) cases->dest_me();
    ::dest_me();

}

void set_save_path( string path ) { location = loc; }
void set_currency( string cur ) { currency = cur; }
void set_admin_cost( int value ) { admin_cost = value; }
void set_commission( int percent ) { commission = percent/100; }
void set_case_desc( string *bits ) { case_desc = bits; }
mapping query_lots() { return lots; }
mapping query_payments() { return payments; }

void adjust_money( int amount, object player ) {
object money;

  if ( amount < 0 ) { //Taking money
    player->pay_money( MONEY_HAND->create_money_array( amount, currency ),
                       currency );
    return;
  }
  money = MONEY_HAND->create_money_array( amount, currency );
  player->adjust_money( money, currency );
}  
