#include <const.h>
#include <reports.h>
#include <textdraw.h>

int main( string param ) {
   string curr;
   string location;

   // return notify_fail("The database server is giving us troubles, please use the web page to report this "+query_verb()+".\n");

   if( !param ) {
      notify_fail("This command is used for telling us your bright ideas. Please read the help page, help idea.\n");
      return 0;
   }

   foreach( curr: REPORT_PLAYERS )
      send_im( curr, "IDEA: " + recolor(param) + "\n" );
#ifdef __MYSQL__
   location = get_location(environment(this_player()));

   FORUM->create_new_thread( IDEA_BOARD_ID, location, param, param );
#endif
   log_file( "idea", param + "\n" );

   msg("Thanks for the idea. We promise to read it before we tell you why we don't like it. ;-)");
   return 1;
}
