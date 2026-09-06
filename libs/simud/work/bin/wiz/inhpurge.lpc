// Made separate messages for updated vs nonexistant files,
// and fixed formatting.  -- Zarylse, 2003-09-07
#include <const.h>
#include <wizard.h>

int main(string str) {
   string blah;
   int count;

   WIZ_CHECK

   if ( !str )
      return notify_fail("==> [Format] inhpurge <file>\n");

   foreach(string file: "/daemon/program"->query_inheriters(str) - ({ "/world/world" }) ) {
      destruct(find_object(file));
      count++;
   }

   msg(count + " objects purged.");

   return 1;
}
