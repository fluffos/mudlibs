#pragma strict_types
// Apr 17, 1996 Hazard - Added event inform

#include <standard.h>
#include <cmd.h>
inherit CMD_BASE;

void setup(){

position = 1;
}



protected int cmd(string str, object me) {
  string *filenames, text, dest, *fnames;
  int loop, fs;

  if (this_player(1) != this_player()) return 0;

  if(!str) {
    notify_fail("Usage : cp file [file|dir...]\n");
    return 0;
  }
  fnames = explode(str, " ");
  filenames = this_player()->get_files(implode(fnames[0..sizeof(fnames) -2], "/"));
  if(!sizeof(filenames)) {
    notify_fail("Usage : cp file [file|dir...]\n");
    return 0;
  }
  dest = fnames[sizeof(fnames) - 1];
  dest = this_player()->get_path(dest);
   if(!dest) {
    write("No destination\n");
    return 1;
  }
  for(loop = 0; loop < sizeof(filenames); loop++) {
    str = filenames[loop];
    text = read_file(str);
    if(!text) {
      write("No such file : " + str + "\n");
      continue;
    }
    fs = file_size(dest);
    if(fs == -2) {
      string *names;

      names = explode(str, "/");
      fs = file_size(dest + "/" + names[sizeof(names) - 1]);
      if(fs != -1) {
        write("file exists " + dest + "/" + names[sizeof(names) - 1] + "\n");
        continue;
      }
      write_file(dest + "/" + names[sizeof(names) - 1], text);
  event(users(), "inform", this_player()->query_cap_name()
                 +" copies "+str+" to "+dest+"", "file");
    }
    else {
      if(fs != -1) {
        write("File exists : " + dest + "\n");
        continue;
      }
      write_file(dest, text);
  event(users(), "inform", this_player()->query_cap_name()
                 +" copies "+str+" to "+dest+"", "file" );
    }
  }
  write("Ok.\n");
  return 1;
} /* cp_file() */


