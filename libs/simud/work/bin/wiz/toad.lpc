int main( string str ) {
   object victim;
   int error, toad = 1;  // defaults to toading
   string verb = "toad";

   WIZ_CHECK

   // checks parameter and target player exist
   if ( !str || !(victim = find_player(str)) )
      return notify_fail( "==> [Format] toad <player>\n" );

   // changes to untoading
   if ( query_verb() == "untoad" ) {
      toad = 0;
      verb = "untoad";
   }

   // check whether victim's toad status will change
   if ( toad == victim->query_toad() ) {
      msg( "==> [Toad] " + capitalize(str) + " is already " + verb + "ed." );
      return 1;
   }

   // sets the victim's toadiness
   error = victim->set_toad( toad );
   if ( error )
      msg( "==> [Error] Could not " + verb + " " + capitalize(str) + "." );

   else
      msg( "==> [Toad] Successfully " + verb + "ed " + capitalize(str) + "." );

   return 1;
}
