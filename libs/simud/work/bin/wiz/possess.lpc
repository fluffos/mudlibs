#include <const.h>

int main( string str ) {
   object ob;

   if( this_player()->query_level() < WIZLEVEL ) {
      msg("==> [Error] Access denied");
      return 0;
   }

   if( !str ) {
      msg("==> [Format] possess creature");
      return 1;
   }

   ob = find_living( str );
   if( !ob ) {
      msg("==> [Error] Could not find that creature.");
      return 1;
   }

   if( ob->query_level() <= this_player()->query_level() ) {
      if( !"/obj/possess"->possess( ob ) )
         msg("Something seems to have gone wrong. Maybe the object you're trying to possess is not coded for it.");
   } else {
      msg("==> [Error] Access denied (level).");
   }

   return 1;
}
