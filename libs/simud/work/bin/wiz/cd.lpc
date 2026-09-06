#include <const.h>

main(str) {
   string newpath;

   WIZ_CHECK

   // If no directory is typed, go to the player's home dir.
   if( !str )
      str = "~";

   newpath = this_player()->make_path_absolute(str);
   if( newpath == "" ) newpath = "/";
   if(!newpath) {
      notify_fail("==> [Error] Invalid path.\n");
      return 0;
   }
   if(!legal_filename(newpath) || file_size(newpath) != -2) {
      notify_fail("==> [Error] Invalid directory: "+newpath+"\n");
      return 0;
   }
   else {
      if( newpath[<1] == '/' && strlen(newpath) > 1 ) newpath = newpath[0..<2];
      this_player()->set_path( newpath );
      "/bin/wiz/pwd"->main();
   }

   return 1;
}