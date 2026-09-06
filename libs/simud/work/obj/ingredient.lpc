inherit "/obj/liquid";
#include <edible.h>

int query_food_value() {
   return ::query_food_value() * query_quantity() / 1000;
}

int query_drink_value() {
   return ::query_drink_value() * query_quantity() / 1000;
}

int on_consume( int max ) {
   int amount_drunk;
   int edible = this_object()->query_is_edible();
   string use_msg;

   // stomach overflow patch from checking edible liquids using drink values
   // gp

   if(
      (
         edible ?
         this_object()->query_food_value() :
         this_object()->query_drink_value()
      ) > max
   ) {
      amount_drunk = (max * 1000) /
         ( edible ? ::query_food_value() : ::query_drink_value());
   } else {
      amount_drunk = query_quantity();
   }

   if (amount_drunk <= 0) {
      return 0;
   }

   add_quantity( -amount_drunk );
   this_player()->add_drink( amount_drunk * ::query_drink_value() / 1000 );
   this_player()->add_food( amount_drunk * ::query_food_value() / 1000 );
   set_target(this_object());
   if( use_msg = this_object()->query_use_msg() )
      this_player()->msg_local( "~CACT" + use_msg + "~CDEF" );
   else
      this_player()->msg_local( "~CACT~Name " + (edible ? "~verbeat" : "~verbdrink") + " ~targ.~CDEF" );

   if( query_quantity() <= 0 )
      destruct( this_object() );

   return 1;
}