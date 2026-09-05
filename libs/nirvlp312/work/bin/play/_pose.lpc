#include <ansi.h>
/* 05/16/06 Earwax: daemonized this from player.c */

#include <security.h>

int cmd_pose(string arg) {
  int spell_points;
  int level;

  level = (int)this_player()->query_level();
  spell_points = (int)this_player()->query_sp();
  if (level >= 15) {
    if (spell_points >= 15 && !this_object()->checkNM()) {
      write("You send a ball of fire into the sky.\n");
      this_player()->checked_say((string)this_player()->query_name() + " makes a magical gesture.\n");
      shout("A ball of "+HIR+"FIRE"+NORM+" explodes in the sky.\n");
      if (level < EXPLORE)
        this_player()->add_spell_point(-15);
    }
    else {
      write("You are too low on power.\n");
    }
    return 1;
  }
  return 0;
}
