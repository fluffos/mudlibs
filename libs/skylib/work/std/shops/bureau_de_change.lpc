/**
 * This is the standard money changer inheritable.
 * @author Pinkfish
 * @change Deutha
 * Extensive changes to make it work with the new currency system.
 */
#include <money.h>
#include <move_failures.h>

inherit ROOM_OBJ;

int standard, buy_only;
string place;
mapping exchanges;

int do_buy(object *obs, string country);

int query_standard() { return standard; }

void set_standard( int number ) { standard = number; }

int query_buy_only() { return buy_only; }

void set_buy_only() { buy_only = 1; }

string query_place() { return place; }

void set_place( string word ) { place = word; }

mapping query_exchanges() { return exchanges; }

void set_exchanges( mapping map ) { exchanges = map; }

/* Should be in the money handler, really... */
int smallest_in( string place ) {
   int i, smallest;
   mixed *values;
   values = (mixed *)MONEY_HAND->query_values_in( place );
   for ( i = 1; i < sizeof( values ); i += 2 )
      if ( !smallest || ( values[ i ] < smallest ) )
         smallest = values[ i ];
   return smallest;
} /* smallest_in() */

string exchanges_list() {
    int i, value, smallest;
    string list, *places;
    if ( !sizeof( exchanges ) )
         return "There are no exchanges to be made here.";
    list = "";
    places = keys( exchanges );
    for ( i = 0; i < sizeof( places ); i++ ) {
         list += places[ i ] +":\n      $I$+20,+10="+
                  (string)MONEY_HAND->money_value_string( standard, place ) +
                  " will buy: ";
         value = ( exchanges[ places[ i ] ][ 0 ] * standard ) / 100;
         list += (string)MONEY_HAND->money_value_string( value, places[ i ] );
         smallest = smallest_in( places[ i ] );
         while ( ( exchanges[ places[ i ] ][ 1 ] * value ) / 100 < standard )
             value += smallest;
         if ( buy_only ) {
             list += ".$I$-20,-10=";
             if ( i < sizeof( places ) - 1 )
                  list += "\n";
         } else {
             list += ";$I$-20,-10=\n$I$+20,+10=      for "+
                      (string)MONEY_HAND->money_value_string( standard,
                      place ) +", sell: ";
             value = ( 100 * standard ) / exchanges[ places[ i ] ][ 1 ];
             list += (string)MONEY_HAND->money_value_string( value,
                      places[ i ] ) +".$I$-20,-10=";
             if ( i < sizeof( places ) - 1 )
                  list += "\n";
         }
    }
    return list;
} /* exchanges_list() */

void create() {
   do_setup++;
   ::create();
   do_setup--;
   standard = 100;
   place = "default";
   exchanges = ([ ]);
   if ( !do_setup ) {
      this_object()->setup();
      this_object()->reset();
   }
} /* create() */

void init() {
   ::init();
   add_command("buy", "[from] {" + implode(keys(exchanges), "|") +
                               "} with <indirect:object>", (: do_buy($1, $4[0]) :));
   if ( !buy_only ){
      add_command("sell" ,"<indirect:object:me'stuff'>",
                        (:this_object()->sell($1):));
   }
   add_command("list", "", (:this_object()->list():));
} /* init() */

int do_buy(object *things, string country) {
   int i, value;
   object store, money, *monies;
   mixed *change;

   if ( country == place ) {
      return notify_fail( "You cannot buy currency from "+ country +" here, "+
            "since you're currently in "+ country +".\n" );
   }
   store = clone_object( "/std/container" );
   for ( i = 0; i < sizeof( things ); i++ )
      if ( things[ i ]->query_property( "money" ) )
         things[ i ]->move( store );
   if ( !sizeof( all_inventory( store ) ) ) {
      store->dest_me();
      return notify_fail( "You can only use money to buy currency here.   "+
            "Sorry.\n" );
   }
   monies = (object *)MONEY_HAND->filter_legal_tender( all_inventory(
         store )[ sizeof( all_inventory( store ) ) - 1 ], place );
   store->dest_me();
   if ( monies[ 1 ] ) {
      write( "Sorry, but you cannot use "+ (string)monies[ 1 ]->short() +" to "+
            "buy currency here.\n" );
      monies[ 1 ]->move( this_player() );
   }
   if ( !monies[ 0 ] ) {
      return notify_fail( "Sorry, but you didn't offer any acceptable money "+
            "to buy currency.\n" );
   }
   value = ( (int)monies[ 0 ]->query_value_in( place ) *
         exchanges[ country ][ 0 ] ) / 100;
   change = (mixed *)MONEY_HAND->create_money_array( value, country );
   if ( !sizeof( change ) ) {
      monies[ 0 ]->move( this_player() );
      return notify_fail( "Sorry, but "+ (string)monies[ 0 ]->short() +" is "+
            "not worth anything in "+ country +".\n" );
   }
   write( "Okay, you bought "+ (string)MONEY_HAND->money_string( change ) +
         " with "+ (string)MONEY_HAND->money_string( (mixed *)monies[ 0 ]->
         query_money_array() ) +".\n" );
   monies[ 0 ]->dest_me();
   money = clone_object( MONEY_OBJECT );
   money->set_money_array( change );
   if ( (int)money->move( this_player() ) != MOVE_OK ) {
      write( "Unfortunately, you're too heavily burdened to accept all that "+
            "money, so it's put on the table for you.\n" );
      money->move( this_object() );
   }
   return 1;
} /* do_buy() */

int sell( object* things ) {
   int i;
   int value;
   int test_val;
   string *places;
   object store_a;
   object store_b;
   object money;
   object *monies;
   mixed *change;

   store_a = clone_object( "/std/container" );

   for ( i = 0; i < sizeof( things ); i++ ) {
      if ( things[ i ]->query_property( "money" ) ) {
         things[ i ]->move( store_a );
      }
   }
   if ( !sizeof( all_inventory( store_a ) ) ) {
      store_a->dest_me();
      return notify_fail( "You can only sell currency here.   Sorry.\n" );
   }
   places = m_indices( exchanges );
   store_b = clone_object( "/std/container" );
   for ( i = 0; i < sizeof( places ); i++ ) {
      monies = (object *)MONEY_HAND->filter_legal_tender( all_inventory(
            store_a )[<1], places[ i ] );
      if (monies[1])   monies[1]->move(store_a);
      test_val = 0;
      /* OK, we need to pull off the provincial coins because they have a
          value of 0 in any other zone, so the player gets ripped off
          if they do "sell coins" and they have a mixture of provincial
          and non-provincial coinage.   Got that?   */
      if (monies[0]   &&   places[i] != "default")   {
         monies = MONEY_HAND->filter_legal_tender(monies[0], "default");
         money = monies[0];
         monies[0] = monies[1];
         monies[1] = money;
      }
      if (monies[0])
          test_val = monies[0]->query_value_in(places[i]) *
                           exchanges[places[i]][1] / 100;
      if (test_val)   {
         value += test_val;
         monies[ 0 ]->move( store_b );
      }
      if ( monies[ 1 ] )
         monies[ 1 ]->move( store_a );
      else
         break;
   }
   if ( money = present( MONEY_ALIAS, store_a ) ) {
      write( "Sorry, but you cannot sell "+ (string)money->short() +" here.\n" );
      money->move( this_player() );
   }
   store_a->dest_me();
   if ( !( money = present( MONEY_ALIAS, store_b ) ) ) {
      store_b->dest_me();
      return notify_fail( "Sorry, but you aren't offering to sell any "+
            "acceptable coinage.\n" );
   }
   change = (mixed *)MONEY_HAND->create_money_array( value, place );
   if ( !sizeof( change ) ) {
      money->move( this_player() );
      store_b->dest_me();
      return notify_fail( "Sorry, but "+ (string)money->short() +" is not "+
            "worth anything in "+ place +".\n" );
   }
   write( "Okay, you sold "+ (string)MONEY_HAND->money_string(
         (mixed *)money->query_money_array() ) +" for "+
         (string)MONEY_HAND->money_string( change ) +".\n" );
   store_b->dest_me();
   money = clone_object( MONEY_OBJECT );
   money->set_money_array( change );
   if ( (int)money->move( this_player() ) != MOVE_OK ) {
      write( "Unfortunately, you're too heavily burdened to accept all that "+
            "money, so it's put on the table for you.\n" );
      money->move( this_object() );
   }
   return 1;
} /* sell() */

int list() {
   write( exchanges_list() +"\n" );
   return 1;
} /* list() */
