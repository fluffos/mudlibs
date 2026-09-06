#include <inven.h>
#include <object.h>
#include <item.h>
#include <desc.h>
#include <quantity.h>
#include <const.h>

/** Sort of a simplified liquid, useful for resources. The number of units is given
 * more precisely than liquids.
 */

WEIGHT( 1000 ) // Weight of 1000 units, in grams
BULK( 1000 )   // Bulk of 1000 units, in ml
GETTABLE( 1 )
DROPPABLE( 1 )

void create() {
   ::create();
/* OBJEDIT { */
   set_quantity( 1 );
/* } OBJEDIT */
}

string query_distant() {
   if( quantity == 1 )
      return "one " + query_unit() + " of "+ ::query_distant();
   else
      return rough_amount(quantity) + " " +  ::query_distant();
}

string query_specific() {
   if( quantity == 1 )
      return "one " + query_unit() + " of "+ ::query_specific();
   else
      return rough_amount(quantity) + " " + ::query_specific();
}

int query_weight() {
   if( query_quantity() < 1000 )
      return ::query_weight() * query_quantity() / 1000;
   else
      // Numerical overflow adjustment
      return (::query_weight() / 50) * (query_quantity() / 20);
}

int query_bulk() {
   if( query_quantity() < 1000 )
      return ::query_bulk() * query_quantity() / 1000;
   else
      // Numerical overflow adjustment
      return (::query_bulk() / 50) * (query_quantity() / 20);
}

string query_default_unit() {
   return "unit";
}

string query_default_units() {
   return this_object()->query_default_unit() + "s";
}
