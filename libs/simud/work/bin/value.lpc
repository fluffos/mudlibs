#include <const.h>

int main(string param) {

  object tg;


   if( !param ) {
      notify_fail( "What would you like to know the value of?\n" );
      return 0;
   }

  if( param == "coin" || param == "coins" ) {
     notify_fail("You cannot value coins.\n");
     return 0;
  }

   tg = single_present( param, this_player() );

   if( living(tg) ) {
      notify_fail( "Living things are priceless...\n" );
      return 0;
   }

   if( !tg && single_present( "shopkeeper", environment(this_player()) ) ) {
      tg=single_present( param, find_living("shopkeeper") );
   }

   if( !tg ) {
      notify_fail( "That object does not exist.\n" );
      return 0;
   }

   if( tg->query_value() == 0 ) {
      notify_fail( "That object is worthless.\n" );
      return 0;
   }

   msg_object( this_player(), "~CACTThe value of the " + tg->query_name() + " is " + tg->query_value() + " coins.  The shopkeeper will buy one for half.~CDEF" );
   return 1;
}
