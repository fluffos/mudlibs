/*
 * Coded by : Zarylse
 * Date     : 2003-10-12
 * Notes    : Teleports you back to the room you were previously in.
 */

#include <const.h>

int main() {
   string loc;

   WIZ_CHECK

   loc = this_player()->query_env_var( "teleport_back" );

   if ( !loc )
      return notify_fail( "==> [Error] You must use goto once before you can go back.\n" );

   call_other( "/bin/wiz/goto", "main", loc );

   return 1;
}
