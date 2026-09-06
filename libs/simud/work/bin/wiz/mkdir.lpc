#include <const.h>

main(str) {
   WIZ_CHECK

   if(!str) {
     notify_fail("==> [Format] mkdir directory\n");
     return 0;
   }

   str = this_player()->make_path_absolute(str);

   if( mkdir(str) )
      msg("==> [Notice] Directory "+str+" created");
   else
      msg("==> [Error] Could not create directory.");
   return 1;
}