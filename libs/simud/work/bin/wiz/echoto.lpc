#include <const.h>

main(string str) {
   object targ;
   string targ_name;
   string message;

   WIZ_CHECK

   if(!str || sscanf(str, "%s %s", targ_name, message) != 2 ) {
      notify_fail("==> [Format] echoto person [message]\n");
      return 0;
   }

   targ = find_living( targ_name );
   if( !targ ) {
      notify_fail("==> [Error] No such target\n");
      return 0;
   }

   msg("(To "+capitalize(targ->query_name())+"): ~[110"+message+"~[070");
   msg_object(targ, "~[110"+message+"~[070");
   return 1;
}