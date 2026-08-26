#include <rogues.h>
#include <mudlib.h>

#define ASSASIN "/d/class/rogue/Assasins/"

int cmd_ahelp(string str) {
  if (!str) str = "index";

  if (this_player()->more(ASSASIN+"help/"+str) != 1) {
    write("Type ahelp index.\n");
    return 1;
  }
return 1;
}
