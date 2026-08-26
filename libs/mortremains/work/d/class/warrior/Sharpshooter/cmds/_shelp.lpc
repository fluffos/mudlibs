#include <mudlib.h>

#define SS "/d/class/warrior/Sharpshooter/"

inherit DAEMON;

int cmd_shelp(string str) {
  if (!str) str = "index";
  if (TP->more(SS+"help/"+str) != 1) write("There is no help available on that subject.\n") ;
  return 1;
}
