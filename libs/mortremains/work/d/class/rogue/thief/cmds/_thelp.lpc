#include <rogues.h>
#include <mudlib.h>

#define THIEF "/d/class/rogue/"

int cmd_thelp(string str) {
  if (!str) str = "index";

  if (this_player()->more(THIEF+"help/"+str) != 1) {
    write("Type thelp index.\n");
    return 1;
  }
return 1;
}
