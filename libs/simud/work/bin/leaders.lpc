// Verb to list people leading you.

main( str ) {
   object ob;
   int i;

   this_player()->check_leaders();

   ob = this_player()->query_leaders();

   if( ob && sizeof(ob) > 0 ) {
      msg( "~CBRTYou are being lead by:" );
      for( i=0;i<sizeof(ob);i++ )
         if( objectp(ob[i]) )
            msg( "   " + capitalize(ob[i]->query_name()) + "~CDEF" );
      return 1;
   }
   msg( "~CBRTNo one is leading you. Go join a cult or something.~CDEF" );
   return 1;
}