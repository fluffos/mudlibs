#include <const.h>

// Verb for keeping objects.

int main( string str ) {
   object env, *list;
   string a, b;
   int i;

   if( !str ) {
      notify_fail("Keep what?\n");
      return 0;
   }

   env = this_player();
   // A little weird to say 'keep the box from my bag' but I don't mind letting it work.
   if( sscanf(str, "%s from %s", a, b) ) {
      list = all_present( b, env );
      if( !list ) list = all_present( b );
      if( !list ) {
         notify_fail("I don't know what you mean by '"+b+"'.\n");
         return 0;
      }
      env = list[0];

      list = all_present( a, env );
   }
   else {
      list = all_present( str, env );
      if( !list ) list = all_present( str );
      if( !list ) {
         notify_fail("I don't know what you mean by '"+str+"'.\n");
         return 0;
      }
   }

   for( i = 0; i < sizeof(list); i++ ) {
     list[i]->set_kept(1);
     if (!list[i]->query_kept()) {
       list = list[..i-1] + list[i+1..];
       i--;
     }
   }

   if (sizeof(list))
     msg("You make a note to yourself to keep " + inventory_string(list) + ".");
   else
     msg("You are unable to keep that.");

   return 1;
}
