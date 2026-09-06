/*
 * Changes  : [2003-10-12] Zarylse
 *              - sets the "teleport_back" env var, for use with back.c
 *              - added comments, standardized formatting
 */

#include <const.h>
#include <wizard.h>

int main(string param) {
   object dest;
   int enter_flag;

   WIZ_CHECK

   if ( !param )
      return notify_fail( "==> [Format] goto <destination>[!]\n" );

   // moves player INSIDE the destination
   if ( param[<1] == '!' ) {
      enter_flag = 1;
      param = param[..<2];
   }

   dest = find_thing( param );
   if ( !dest )
      return notify_fail( "==> [Error] Cannot find location '" + param + "'\n" );

   // sets the "teleport_back" env var, used by /bin/wiz/back.c
   this_player()->set_env_var( "teleport_back", get_location(environment(this_player())) );

   // moves the player inside the destination
   if( dest->query_is_living() )
      this_player()->set_coord( dest->query_x(), dest->query_y(), 0 );

   // sets up target, needed by the grammar code
   set_target( this_player() );

   // moves the player into the same environment as the destination
   if ( !enter_flag && !dest->query_long() && !dest->query_is_room() )
      dest = environment( dest );

   // actually moves the player, calls any customized teleport message, and
   // checks that the new location is valid
   this_player()->move_player( dest, "teleport" );
   this_player()->validate_position();
   "/bin/look"->main();

   return 1;
}
