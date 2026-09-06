int main(string areaname) {
   object env, area;

   WIZ_CHECK

   if( !areaname ) {
      notify_fail("==> [Format] addarea areaname\n");
      return 0;
   }

   env = environment( this_player() );
   if( !env ) {
      notify_fail("==> [Error] You have no environment!\n");
      return 0;
   }

   msg("Creating an area at: "+get_location(env));
   area = clone_object( "/world/area" );
   area->move( env );
   area->set_name(areaname);
   area->set_look("This area, "+areaname+", was created "+ctime(time())+" by "+this_player()->query_cap_name()+".");

   return 1;
}