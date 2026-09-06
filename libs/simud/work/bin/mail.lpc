main( string str ) {
   object ob;

   ob = clone_object("/obj/mailmsg");
   if( !ob ) {
      notify_fail( "FATAL ERROR! MailMSG.c not loadable!\n" );
      return 1;
   }

   if( str ) {
      if( !legal_filename(str) ) {
         notify_fail( "<" + str + "> does not appear to be a valid player name.\n" );
         destruct( ob );
         return 0;
      } else {
         msg( "<" + str + "> is valid\n" );
      }
      ob->set_tstr( "mail" );
      ob->set_tstr2( str );
   } else
      msg("This is the mail reader. Type ~CBRT?~CDEF for help, ~CBRTq~CDEF to quit.");

   ob->move(this_player());
   return 1;
}
