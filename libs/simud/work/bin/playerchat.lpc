#include <const.h>
#include <reports.h>
#include <textdraw.h>

int main( string param ) {
   string curr;
   string location;

   if( !param ) {
      notify_fail("This command is used for starting Player Chat threads. Please read the help page, help playerchat.\n");
      return 0;
   }

   foreach( curr: REPORT_PLAYERS )
      send_im( curr, "PLAYERCHAT REPORT: " + recolor(param) + "\n" );
#ifdef __MYSQL__
   location = get_location(environment(this_player()));

   FORUM->create_new_thread( PLAYERCHAT_BOARD_ID, location, param, param );
#endif

   msg("Thread started on the Player Chat forum.");
   return 1;
}
