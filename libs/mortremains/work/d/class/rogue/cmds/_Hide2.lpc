//_Hide.c started on June 12th, 1997 by Nightmask@Nightfall's Keep
//   This will make the thief class able to slip into the shadows.
#include <mudlib.h>

inherit DAEMON;

#define TPN this_player()->query("cap_name")

int cmd_Hide() {
   object ob;
   int invis;
    ob = this_player();
   invis = (int)ob->query("invisible");
  if (!invis) {
     say(TPN+" fades into the shadows.\n");
     write("You fade into the shadows.\n");
    ob ->set("invisible", 1);
    ob->do_new();
  } else {
    write("You are already hidden!\n");
  }
  return 1;
}
