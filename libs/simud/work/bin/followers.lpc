// Verb to list people following you.

main( str ) {
   object ob;
   int i;

   this_player()->check_followers();

   ob = this_player()->query_followers();

   if( ob && sizeof(ob) > 0 ) {
      msg( "~CBRTPeople following you into battle: " );
      for( i=0;i<sizeof(ob);i++ )
         if( objectp(ob[i]) )
            msg( "   " + capitalize(ob[i]->query_name()) + "~CDEF" );
      return 1;
   }
   msg( "~CBRTNo one is following you. You loner!~CDEF" );
   return 1;
}