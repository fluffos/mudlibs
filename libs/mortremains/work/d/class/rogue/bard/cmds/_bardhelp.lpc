#include <rogues.h>
#include <mudlib.h>

#define BARD "/d/class/bard/"

 int cmd_bardhelp(string str) {
  if (!str) str = "index";

  if (this_player()->more(BARD+"help/"+str) != 1) {
    write("Type thelp index.\n");
    return 1;
  }
return 1;
}
