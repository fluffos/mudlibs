//      fake shoot command (in /std/bow.c)
//      this is here for the help/abil()

#include <std.h>
inherit DAEMON;
int abil();

int cmd_shoot(string str)
{
  return 0;
}


void help()
{
  write("Syntax: <shoot [living] [direction]\n\n"+
        "With a bow and arrow, you can shoot your enemy from afar.\n");
}

int abil() {
   if (this_player()->query_skill("ranged") < 20) return 0;
   return 1;
}
