#include <const.h>

main(str) {
   object player;

   if( this_player()->query_level() < WIZLEVEL ) {
      notify_fail("==> [Error] Access denied\n");
      return 0;
   }

   if( !str ) player = this_player();
   else
      player = find_player(str);
   if( player ) {
      msg("==> [Trace] "+player->query_cap_name()+" is connected from " +
          query_ip_number(player) + " ("+query_ip_name(player)+")");
      return 1;
   }
   else {
      notify_fail("==> [Error] Could not find that player.\n");
      return 0;
   }
}