//_Walk.c Shadow Walk for High level Thieves.
//   This will make the thief class able to slip into the shadows.
#include <mudlib.h>

inherit DAEMON;

#define TPN this_player()->query("cap_name")

object ob;
int invis;

int cmd_Walk() {
    ob = this_player();
   invis = (int)ob->query("invisible");
  if (!invis) {
      say(TPN+" becomes one with the shadows.\n");
      write("You emerge yourself in the shadows.\n");
    ob ->set("invisible", 1);
    ob->do_new();
  } else {
    write("You are already hidden!\n");
  }
   return 1;
}
