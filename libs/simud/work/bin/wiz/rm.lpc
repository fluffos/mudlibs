#include <const.h>

main(string str)
{
   string destination;
   WIZ_CHECK

   if( !str ) {
      notify_fail("==> [Format] rm filename\n");
      return 0;
   }

   str = this_player()->make_path_absolute(str);

   if( !file_exists(str) ) {
      notify_fail("==> [Error] File "+str+" does not exist.\n");
      return 0;
   }

   // Empty files get a "real" remove.
   if( file_size(str) == 0 ) {
      rm( str );
   }

   if( !query_write_access(str, this_player()) ) {
      notify_fail("==> [Error] Access denied.\n");
      return 0;
   }

   if( file_size(RM_DIR) != -2 ) {
//      debug("True rm for "+str);
      rm(str);
   }
   else {
      destination = RM_DIR + implode( explode(str, "/"), "~_" ) + "~";
//      debug("rm destination is "+destination);
      if( file_size(destination) >= 0 ) rm( destination );
      if( rename(str, destination) != 0 ) {
         if( !rm(str) ) {
            notify_fail("==> [Error] Could not remove file\n");
            return 0;
         }
      }
   }

  msg("==> [Notice] File " + str + " removed.");
  return 1;
}
