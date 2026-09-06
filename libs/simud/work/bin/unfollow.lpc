// To unfollow verb.  Stops following ppl.

int main( string str ) {
   object *ob;
   int i;

   if( !str ) {
      msg( "~CBRTStop following whom?~CDEF" );
      return 1;
   }

   str = lower_case( str );

   this_player()->check_leaders();

   if( str == this_player()->query_name() ) {
      msg( "~CBRTYour mind makes a futile effort to separate itself from your body!~CDEF" );
      return 1;
   }

   ob = this_player()->query_leaders();

   set_actor(this_player());
   set_listener(this_player());
   for( i=0;i<sizeof(ob);i++ ) {
      if( ob[i]->id(str) || str == "all" ) {
         set_target(ob[i]);
         this_player()->remove_leader( ob[i] );
         ob[i]->remove_follower( this_player() );
         msg( "~CBRT~Name ~verbstop following ~targ around.~CDEF" );
         if (environment(this_player()) == environment(ob[i]))
            msg_object( ob[i], "~CBRT" + capitalize(this_player()->query_name()) + " has stopped hounding your every step.~CDEF" );
         return 1;
      }
   }

   msg( "~CBRTRight. You stop following that imaginary friend of yours...~CDEF" );

   return 1;
}
