#include <const.h>
#include <reports.h>
#include <textdraw.h>

int main( string param ) {
   string curr;
   string location;

   // return notify_fail("The database server is giving us troubles, please use the web page to report this "+query_verb()+".\n");

   if( !param ) {
      notify_fail("This command is used for reporting spelling or grammar errors. Please read the help page, 'help typo'.\n");
      return 0;
   }

   foreach( curr: REPORT_PLAYERS )
      send_im( curr, "TYPO: " + recolor(param) + "\n" );
#ifdef __MYSQL__
   location = get_location(environment(this_player()));

   FORUM->create_new_thread( TYPO_BOARD_ID, location, param, param );
#endif
   log_file( "typo", param + "\n" );

   msg("Abuse of the English language is indeed a terrible thing. Thank you for helping to stamp it out.");
   return 1;
}
