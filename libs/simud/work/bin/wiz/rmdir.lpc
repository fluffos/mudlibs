#include <const.h>

main(str) {
   WIZ_CHECK

   if(!str) {
     notify_fail("==> [Format] rmdir directory\n");
     return 0;
   }

   str = this_player()->make_path_absolute(str);

   if( !file_exists(str) && file_size(str) != -2 )
      msg("==> [Notice] " + str + " does not exist.");
   else if( file_size(str) != -2 )
      msg("==> [Notice] " + str + " is not a directory.");
   else if( rmdir(str) )
      msg("==> [Notice] Directory "+str+" removed.");
   else
      msg("==> [Error] Could not remove directory. Is it empty?");
   return 1;
}
