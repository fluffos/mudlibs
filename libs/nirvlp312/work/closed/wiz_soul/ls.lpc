#include <security.h>

#pragma strict_types
#pragma save_types

int
new_list_files(string path) {
  string str;

log_file("WSOUL", ctime()+": /closed/wiz_soul/ls.c called (player: "+(string)this_player()->query_real_name()+") by "+object_name(previous_object())+".\n");
  if(this_player()->query_level() < EXPLORE)
    return 0;
  str = resolv_path((string)this_player()->get_path(), path);
  if (str == "/players") {
    write("You can't ls in /players.\n");
    return 1;
  }
  ls(str);
  return 1;
}
