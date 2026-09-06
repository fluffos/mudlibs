#include <const.h>
#include <reports.h>
#include <textdraw.h>

int main( string param ) {
   string curr;
   string location;

   WIZ_CHECK

   if( !param ) {
      notify_fail("This command takes information about the point you want. " +
                  "Then it publishes that to the Gimmie Points forum. Please " +
                  "follow the rules for the forum as denoted by Al.\n");
      return 0;
   }

   foreach( curr: REPORT_PLAYERS ) {
      send_im( curr, "PROGRESS REPORT: " + recolor(param) + "\n" );
   }
#ifdef __MYSQL__
   location = get_location(environment(this_player()));

   FORUM->create_new_thread( FORPOINTS_BOARD_ID, location, param, param );
#endif

   msg("Progress reported! Please make sure to add the numbers of any threads " +
       "related to this bug to the thread.\n");
   return 1;
}
