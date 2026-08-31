#include <std.h>
#include <dragonevent.h>

#define SAY(x) message("info", x, this_object())

inherit DRAG_ROOMS"py/fallbase";

void create() {
  ::create();
  set_long("You are surrounded by tall trees and shrubbery. There is a circular dirt clearing below you.");
}

void heart_beat() {
  ::heart_beat();
  if(!player()) return;

  //time triggers
  switch(beats()) {
    case 1:
      SAY("The trees whiz past you!");
      break;
    case 3:
      SAY("The ground rushes up to meet you!");
      break;
    case 5:
      SAY("%^RED%^You splatter against the ground.");
      if(!harm_player(player(), player()->query_max_hp()*150)) return;
  }
}
