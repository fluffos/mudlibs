#include <const.h>
#include <object.h>
#include <container.h>
#include <inven.h>
#include <item.h>
#include <desc.h>

int price;
int units;

NAME("price crate")
DISTANT("a crate")
SPECIFIC("the crate")
PLURAL("crates")
ALT_NAME( ({ "crate", "shop crate" }) )
ALT_PLURAL( ({ "price crates", "shop crates" }) )
TASTE( "It tastes a little on the expensive side." )
LOOK( "It's a simple wooden crate.?(HASINV: Sitting in the crate $(ISINV) $(INV).)" )
GETTABLE( 1 )
DROPPABLE( 1 )
WEIGHT( 15000 )

int query_price();

int query_is_buy_box() {
   return query_price() > 0;
}

int query_is_sell_box() {
   return query_price() < 0;
}

int query_price() {
   return price;
}

void set_price( int x ) {
   price = x;
}

int query_units() {
   return units;
}

void set_units( int x ) {
   units = abs(x);
}

string query_look() {
   return ::query_look() + " On the side of the crate is a price tag; " +
      "it currently reads '" + abs(query_price()) + " coins/" + query_units() +
      " (" + (price>0?"selling":"buying") + ")'." +
      ( this_player()->query_name() == environment(environment())->query_owner() ? " You can change the " +
      "price with the command 'use crate'." : "" );
}

// Must explicitly designate the crate as container.
object container_id( string val ) {
   return 0;
}

void on_paint( object painter ) {
   painter->paint( query_x(), query_y(), '#', 3, LAYER_FURNITURE );
}

void price_entry( string x ) {
   int new_price = to_int( x );
   if( !query_to_int_fail() ) {
      price = new_price;
      msg("Price set to " + abs(new_price) + " coins (" + (new_price<0?"buying":"selling") + ").");
   }
   else {
      msg("Price unchanged.");
   }
   msg("How many units per sale at this price? For example, if you want to " + (new_price<0?"buy":"sell") + " 10 wood for 1 coin, enter the price as 1 and the units as 10.");
   shift_interface( "units_entry", "[Enter units to " + (new_price<0?"buy":"sell") + "] " );
}

void units_entry( string x ) {
   int units;

   units = to_int(x);
   if( units <= 0 ) units = 1;
   msg("Units set to " + units);
   set_units( units );
   drop_interface();
}

int on_use() {
   string shop_owner = environment(environment())->query_owner();

   if( shop_owner && shop_owner != this_player()->query_name() ) {
      msg( "You do not own this shop." );
      return 0;
   }
   msg("If you want to SELL items from this create, enter a normal price (i.e. 100).");
   msg("If you want to BUY items that match those in this crate, enter a NEGATIVE price (i.e. -50)");
   add_interface( "price_entry", "[Enter a new price] " );
   return 1;
}

mapping query_aspects() {
   return ([ C_WOOD ]);
}

string *query_alt_name() {
   string *base_alt_name = ::query_alt_name();

   return base_alt_name +
          ({ "buy " + -query_price() + " crate" }) +
          ({ "buy " + -query_price() + "/" + query_units() + " crate" }) +
          ({ "sell " + query_price() + " crate" }) +
          ({ "sell " + query_price() + "/" + query_units() + " crate" }) +
          ({ query_price() + "/" + query_units() + " crate" });
}

void create() {
   ::create();
   set_name("crate");
}
