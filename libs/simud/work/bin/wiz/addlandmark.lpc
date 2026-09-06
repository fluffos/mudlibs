

int main( string param ) {
   int x, y;
   string desc;
   object area;

   WIZ_CHECK

   if( !param || sscanf(param, "%d %d %s", x, y, desc) != 3 ) {
      notify_fail( "==> [Format] addlandmark x y description\n" );
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

   area->set_landmark( desc, SMAKE_C(x,y,0) );
   msg("Adding landmark '"+desc+"'");
   return 1;
}
