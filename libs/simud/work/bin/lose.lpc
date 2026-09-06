
// The lose verb.  To lose annoying people :P

main( string str ) {
   object ob;
   int i;

   if( !str ) {
      msg( "~CBRTLose whom?~CDEF" );
      return 1;
   }

   str = lower_case( str );

   this_player()->check_followers();

   if( str == this_player()->query_name() ) {
      msg( "~CBRTYou become very, very confused for a moment....~CDEF" );
      return 1;
   }

   ob = this_player()->query_followers();

   for( i=0;i<sizeof(ob);i++ ) {
      if( ob[i]->query_name() == str ) {
         this_player()->remove_follower( ob[i] );
         ob[i]->remove_leader( this_player() );
         msg( "~CBRTYou manage to lose " + capitalize(ob[i]->query_name()) + " with some evasive movements.~CDEF" );
         msg_object( ob[i], "~CBRT" + capitalize(this_player()->query_name()) + " has managed to evade your pursuit.~CDEF" );
         return 1;
      }
   }

   msg( "~CBRTThat's great, really.  Perhaps you should convince them to follow you first?~CDEF" );

   return 1;

}