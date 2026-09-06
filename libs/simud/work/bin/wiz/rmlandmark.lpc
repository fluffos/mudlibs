

int main( string param ) {
   int x, y;
   string desc;
   object area;

   WIZ_CHECK

   if( !param ) {
      notify_fail( "==> [Format] rmlandmark description" );
      return 0;
   }

   area = environment(this_player());
   if( !area ) return 0;
   if( !area->query_is_landmark() )
      area = environment(area);
   if( !area->query_is_landmark() ) {
      notify_fail("You don't seem to be somewhere that allows adding landmarks.\n");
      return 0;
   }

   if( !area->query_landmark(desc) ) {
      notify_fail("No such landmark.\n");
      return 0;
   }
   area->remove_landmark( desc );
   msg("Removing landmark '"+desc+"'");
   return 1;
}