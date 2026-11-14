#include <moving.h>
#include "path.h"

inherit "/std/room";

int jump(string str) {
  if (!str) {return 0;}
  if(lower_case(str)!="down") return (int) notify_fail(
"Jump where?\n") && 0;
  if(!this_player()) return 0;
  this_player()->move(PIRATE("lair"),M_GO,"down");
  return 1;
}

create() {
  ::create();
  SetIntShort("A balcony");
  SetIntLong(
"You are on a balcony above the Dragon's lair. Below sits a huge red "
"dragon which look in anger at you. There is a pile of hay in one "
"corner onto which you may jump down. This seems to be the only exit. "
"Go down and die...\n"
    );
  SetIndoors(1);
  SetBright(0);
  AddDetail(({"balcony"}),QueryIntLong());
  AddDetail(({"lair","dragon's lair"}),
(PIRATE("lair"))->QueryIntLong()+(PIRATE("lair"))->Content());
  AddDetail(({"pile","pile of hay","hay"}),
"You probably will survive to jump down.\n");
  AddDetail(({"dragon","red dragon","huge dragon","huge red dragon"}),
"It is not the oldest dragon in the world, but it looks strong.\n");
  AddDetail(({"floor","ground","ceiling","walls","wall"}),
"You see nothing special.\n");
  AddExit("jump",#'jump);
  HideExit("jump",1);
}
