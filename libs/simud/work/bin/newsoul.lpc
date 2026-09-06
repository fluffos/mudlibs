// May 21, 2002, written by Calidron for Walraven (derived from idea.c)

#include <const.h>
#include <reports.h>
#include <textdraw.h>

int main( string param ) {
   string curr;
   string location;

   // return notify_fail("The database server is giving us troubles, please use the web page to report this "+query_verb()+".\n");

   if( !param )
      return notify_fail("This command is used for suggesting new souls. Please read the help page, help newsoul.\n");

   if( strstr(param, " ") == -1 )
      return notify_fail("Soul suggestions need to have an example of their use with and without a target.");

   foreach( curr: ( REPORT_PLAYERS + REPORT_SOULS ))
      send_im( curr, "NEW SOUL: " + recolor(param) + "\n" );
#ifdef __MYSQL__
   location = get_location(environment(this_player()));

   FORUM->create_new_thread( SOULS_BOARD_ID, location, param, param );
#endif
   log_file( "soul", param + "\n" );

   msg("Thanks for the soul idea. We promise to read it ;-).");
   return 1;
}
