#include <std.h>

#define IMMORTAL_HALL "/d/nopk/immortal_hall/adv_inner"
// was previously /d/nopk/standard/adv_inner

inherit DAEMON;

int cmd_wizlounge() {
  write("You are teleported to the immortal hall.");
  this_player()->move_player(IMMORTAL_HALL);
  return 1;
}
