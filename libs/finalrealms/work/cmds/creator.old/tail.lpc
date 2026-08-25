#include <standard.h>
#include <cmd.h>
inherit CMD_BASE;

void setup(){

position = 1;
}



protected int cmd(string str, object me) {
    string *filenames;
    int loop;

  if (!str) {
    notify_fail("Tail what file ?\n");
    return 0;
  }
  filenames = this_player()->get_files(str);
  if (!sizeof(filenames)) {
     notify_fail(str + ": No such file.\n");
    return 0;
  }
  for(loop = 0; loop < sizeof(filenames); loop++) {
    str = filenames[loop];
    if(sizeof(filenames) > 1) {
       write("FILE : " + str + "\n");
    }
    if (!tail(str))
      write("No such file.\n");
   }
  return 1;
} /* tail_file() */
 
