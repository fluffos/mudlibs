#include <standard.h>
#include <cmd.h>
inherit CMD_BASE;

void setup(){

position = 1;
}



protected int cmd(string str, object me) {
 string *filenames, err;
 int loop;

  if (!str) {
    notify_fail("Load what ?\n");
    return 0;
  }
  filenames = this_player()->get_cfiles(str);
  if (!sizeof(filenames)) {
    notify_fail("No such object.\n");
    return 0;
  }
  for(loop = 0; loop < sizeof(filenames); loop++) {
    str = filenames[loop];
    if (file_size(str)<0) {
      write(str + ": No such object.\n");
       continue;
    }
    if (err = catch(str->load_up_with_yellow()))
      write("Failed to load "+str+", error: "+err+"\n");
    else
      write("Loaded "+str+"\n");
  }
  write("Ok.\n");
  return 1;
} /* load() */
 
