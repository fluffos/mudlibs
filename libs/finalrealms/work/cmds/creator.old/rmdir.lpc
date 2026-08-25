#include <standard.h>
#include <cmd.h>
inherit CMD_BASE;

void setup(){

position = 1;
}



protected int cmd(string str, object me) {
   string *filenames;
   int fsize, loop;

   if (!str || str == "") {
      notify_fail("Remove what dir?\n");
      return 0;
   }
   filenames = this_player()->get_files(str);

   if (!sizeof(filenames)) {
      notify_fail("No such directory : " + str + "\n");
      return 0;
   }

   for(loop = 0; loop < sizeof(filenames); loop++) {
      str = filenames[loop];
      fsize = file_size(str);
      if (fsize == -1) {
         notify_fail(str + " doesn't exist.\n");

        return 0;
      }
      if (fsize != -2) {
         notify_fail(str + " is not a directory.\n");
         return 0;
      }
      if (!rmdir(str)) {
         notify_fail("Couldn't remove dir : " + str + "\n");
         return 0;
        }
   }
   write("Ok.\n");
   return 1;
} /* removedir() */


