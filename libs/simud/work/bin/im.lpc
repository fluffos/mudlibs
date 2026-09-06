#include <const.h>

main( string str ) {
   object ob;
   string who, msg;

   if ( !str )
      return notify_fail( "Whom would you like to instant message?\n" );

   if ( sscanf(str, "%s %s", who, msg) != 2 )
      who = str;

   who = lower_case( who );

   if( !legal_filename(who) )
      return notify_fail( "That is not a legal name for a character.\n" );

   if( !sizeof(get_dir(PLAYER_DIR+who+".o")) )
      return notify_fail( "There is no one named " + capitalize(who) + ".\n" );

   if ( msg ) {
      call_other( "/secure/mail_daemon", "mail_send_im", who, this_player()->query_cap_name(), msg+"\n" );
      msg( "You have sent your message to " + capitalize(who) + "." );
      return 1;
   }

   ob = clone_object("/obj/mailmsg");
   //msg("This is the mail reader.");
   if( who ) {
       ob->set_tstr( "instant" );
       ob->set_tstr2( who );
   }
   ob->move(this_player());
   return 1;
}
