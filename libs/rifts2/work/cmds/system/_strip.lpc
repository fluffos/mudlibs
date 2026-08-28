//     Strips ^Ms from files so that you can code offline on a pc,
//     which adds them to the ends of lines.
//
//     DarkeLIB 0.1
//     Diewarzau 10/24/95

#include <std.h>

inherit DAEMON;

int cmd_strip(string str) {
  string path, *files, *tmp, t_file;
  int i, j;
  object who;

  if(!str)
    return notify_fail("Usage: strip <file-name>\n");
  seteuid(getuid(who = previous_object()));
  path = resolv_path((string)who->get_path(), str);
  if(file_size(path) == -2)
    return notify_fail(path + " is a directory.\n");
  if(!sizeof(files = (string *)who->wild_card(path)))
    files = ({ path });
  i = sizeof(files);
  t_file = "/open/"+(string)this_player()->query_name()+".strip";
  while(i--) {
    switch(file_size(files[i])) {
    case -1:
      write(files[i] + ": Does not exist.");
      continue;
      break;
    case -2:
      write(files[i] + ": Directory.");
      continue;
      break;
    default:
      tmp = explode(read_file(files[i]), "\n");
      if(file_exists(t_file)) rm(t_file);
      for(j = 0; j < sizeof(tmp); j++)
	write_file(t_file, replace_string(tmp[j], sprintf("%c", 13), "") + "\n");
      rm(files[i]);
      cp(t_file, files[i]);
      write(files[i] + ": Stripped of ^M.");
      break;
    }
  }
  write("...Done...");
  return 1;
}

void help() {
  message("help",
"Usage: strip <file-name>    (wild cards supported)\n"
"\nStrips ^M's from files.  These annoying characters are introduced by PC "
"editors when coding offline.  Stripping files after uploading will allow "
"you to code with your favorite PC editor.\n",
this_player());
}
