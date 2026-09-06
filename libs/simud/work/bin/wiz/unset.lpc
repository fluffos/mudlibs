#include <const.h>

main(string comm) {
   string who;
   object p;

   WIZ_CHECK

   if(!comm || comm == "") {
      msg("==> [Format] unset var[@player]");
      return 1;
   }

   if(sscanf(comm, "%s@%s", comm, who) == 2) {
      if( this_player()->query_level() < ADMLEVEL ) {
         notify_fail("==> [Error] Access denied\n");
         return 0;
      }
      p = find_player(who);
      if(!p) {
         notify_fail("==> [Error] Could not find that player.\n");
         return 0;
      }
   }
   else p = this_player();

   if(p->remove_env_var(comm))
      msg("==> [Notice] Variable cleared");
   else msg("==> [Error] No variable by that name");

   return 1;
}
