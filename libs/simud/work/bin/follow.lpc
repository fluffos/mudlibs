// The follow verb.  You know, for annoying people :)

main( string str ) {
   object ob;
   int sw1, sw2;

   if( !str ) {
      msg( "~CBRTFollow whom?~CDEF" );
      return 1;
   }

   str = lower_case( str );

   ob = present( str, environment(this_player()) );
   if( !ob ) {
      msg( "~CBRTDost thou see things I do not?~CDEF" );
      return 1;
   }
   if( ob == this_player() ) {
      msg( "~CBRTFollowing yourself around is sure to be an addictive habit.~CDEF" );
      return 1;
   }

   set_actor(this_player());
   set_target(ob);
   set_listener(this_player());
   if( ob->add_follower(this_player()) && this_player()->add_leader(ob) ) {
      this_player()->msg_local( "~CBRT~Name ~verbstart following ~targ.~CDEF" );
      return 1;
   }

   msg( "~CBRTFollow failed.  Are you already following them perhaps?~CDEF" );
   ob->remove_follower( this_player() );
   this_player()->remove_leader( ob );

   return 1;
}
