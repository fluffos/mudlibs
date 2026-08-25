#include <standard.h>
#include <cmd.h>
inherit CMD_BASE;

void setup(){

position = 1;
}



protected int cmd(string str, object me) {
    int fsize, pos, loop;
    string *filenames;

  if (this_player(1) != this_player()) return 0;

    if (!str) {
       notify_fail("Usage: rm file [file ...]\n");
       return 0;
    }
    filenames = this_player()->get_files(str);
    if (!sizeof(filenames)) {
        notify_fail("No such file : " + str + "\n");
       return 0;
    }
    for(loop = 0; loop < sizeof(filenames); loop++) {
       string temp;
       str = filenames[loop];
       if(sscanf(str, "%s/.", temp) || sscanf(str, "%s/..", temp)) {
           continue;
       }
       fsize = file_size(str);
        if (fsize == -1) {
          notify_fail("No such file or directory.\n");
          return 0;
       }
       if (fsize == -2) {
          if (!rmdir(str)) {
             notify_fail("Couldn't rm directory: " + str + "\n");
             return 0;
          }
       } else if (!rm(str)) {
           notify_fail("Can't remove file.\n");
          return 0;
       }
    }
    write("Ok.\n");
    return 1;
} /* rm_files() */
 
