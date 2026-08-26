// Wizhall.c - A simple and useful command for wizards.
//   Writen by Cyanide  15 July 1997.

#include <mudlib.h>
#include <config.h>

int cmd_wizhall() {
  write("You step between dimensions...\n");
  say(TPN+" steps between dimensions and dissapears.\n");
  this_player()->move_player(WIZHALL, "SNEAK");
  say(TPN+" appears from between dimensions.\n"); 

  return 1;
}
