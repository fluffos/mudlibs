#include <const.h>

int main(string time) {
   int timenum;

   WIZ_CHECK

   if( !time || sscanf(time, "%d", timenum) != 1 ) {
      notify_fail("==> [Format] shutdown minutes\n");
      return 0;
   }

   if( "obj/shut"->shut(timenum) )
      msg("==> [Notice] You told the MUD to shut down.");
   else
      msg("==> [Notice] Already shutting down! A little patience, please.");
   return 1;
}