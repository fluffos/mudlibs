#include <const.h>
#include <reports.h>
#include <textdraw.h>

int main( string param ) {
   string curr;
   string location;

   // return notify_fail("The database server is giving us troubles, please use the web page to report this "+query_verb()+".\n");

   if( !param ) {
      notify_fail("This command is used for reporting bugs. Please read the help page, help bug.\n");
      return 0;
   }

   foreach( curr: REPORT_PLAYERS )
      send_im( curr, "BUG REPORT: " + recolor(param) + "\n" );
#ifdef __MYSQL__
   location = get_location(environment(this_player()));

   FORUM->create_new_thread( BUG_BOARD_ID, location, param, param );
#endif
   log_file( "bug", param + "\n" );

   msg("Bug reported. Visit the web forums to add more detail or see progress.");
   return 1;
}
