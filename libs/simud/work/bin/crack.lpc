#include <const.h>

int main( string param ) {
   string a, b;

   if( !param ) {
      notify_fail("Crack what?\n");
      return 0;
   }

   if( sscanf(param, "%s into %s", a, b) ) {
      object ob, *src_list, dest, *list;
      int action_ok;

      list = all_present( a, this_player() );
      if( !list ) list = all_present( a, environment(this_player()) );
      if( !list ) {
         notify_fail("I don't understand what you're trying to crack.\n");
         return 0;
      }
      src_list = list;

      list = all_present( b, this_player() );
      if( !list ) list = all_present( b, environment(this_player()) );
      if( !list ) {
         notify_fail("I don't understand what you're trying to crack it into.\n");
         return 0;
      }
      dest = list[0];

      // list of all the things that cracked...
      list = ({ });
      action_ok = 0;
      foreach( ob: src_list ) {
         int flag;

         flag = ob->on_crack( dest );
         if( !(flag & MOVE_SILENCE_FLAG) && ob )
            list += ({ ob });
         if (flag & MOVE_OK_FLAG )
            action_ok = 1;
      }

      if( !action_ok ) {
         notify_fail( "You can't crack that.\n" );
         return 0;
      }
      if( sizeof(list) ) {
         set_target(dest);
         this_player()->msg_local( "~CACT~Name ~verbcrack "+inventory_string(list)+" into ~targ.");
      }
      return 1;
   }
}