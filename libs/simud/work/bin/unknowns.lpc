/*
 * Coded by : Zarylse
 * Date     : 2003-10-03
 * Desc     : Displays the descriptions of the people you have not been
 *            introduced to, and the names or descriptions of the people you
 *            have not introduced yourself to.
 */

int main() {
   int known, wizard = ( this_player()->query_level() >= WIZLEVEL );
   object who, *players;
   string buf1 = "";  // players who you don't know
   string buf2 = "";  // players who don't know you

   // creates an array of players, besides this_player
   players = filter_objects( all_inventory(environment(this_player())), "query_is_player" );
   players -= ({ this_player() });
   if ( !sizeof(players) ) {
      msg( "There is no one else here!" );
      return 1;
   }

   // loops through each player in the room
   foreach( who : players ) {
      known = this_player()->query_recognize( who->query_name() );

      // adds players who you don't know to buf1
      if ( !known ) {
         buf1 += " ~CBRT*~CDEF " + who->query_distant();
         if ( wizard ) buf1 += " ~CDRK(" + capitalize(who->query_name()) + ")~CDEF";
         buf1 += "\n";
      }

      // adds players who don't know you to buf2
      if ( !who->query_recognize(this_player()->query_name()) ) {
         buf2 += " ~CBRT*~CDEF " + (known ? capitalize(who->query_name()) : who->query_distant());
         if ( wizard && !known ) buf2 += " ~CDRK(" + capitalize(who->query_name()) + ")~CDEF";
         buf2 += "\n";
      }
   }

   set_listener( this_player() );
   this_player()->msg_local( "~CACT~Name ~verblook around for people ~pron ~verbrecognize.~CDEF" );

   // if everyone knows everyone, give only one message
   if ( !strlen(buf1 + buf2) ) {
      msg( "You already know everyone here, and vice versa." );
      return 1;
   }

   if ( strlen(buf1) ) msg( "~CTITPeople here that you don't know:~CDEF\n" + buf1 );
   else msg( "You already know everyone here.\n" );

   if ( strlen(buf2) ) msg( "~CTITPeople here that don't know you:~CDEF\n" + buf2 );
   else msg( "Everyone here already knows you." );

   return 1;
}
