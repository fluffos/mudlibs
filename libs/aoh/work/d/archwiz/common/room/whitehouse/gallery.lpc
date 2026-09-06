inherit "/std/room";
#include <rooms.h>
#include <moving.h>
#include "path.h"

int sword;

QueryIntLong() {
  string desc;
  desc="You are in an art gallery. Most of the paintings which were here have been "
"stolen by vandals with exceptional taste. The vandals left through the door "
"to the north.\n";
  if (sword) desc=desc+"Fortunately, there is still one chance for you to be a vandal, "
"for at the far wall is a work of unparalleled beauty.\n";
  return desc;
}

int do_take(string str) {
  object ob;
  if ((str!="work") && (str!="picture") && (str!="painting")) return 0;
  if (sword==0) return 0;
  ob=clone_object(OBJ("picture"));
  if (ob->move(this_player(),M_SILENT)!=ME_OK) {
    write("It's much too heavy for you.\n");
    ob->remove();
    if (ob) destruct(ob);
    return 1;
    }
  write("You take the valueable work.\n");
  show(this_player()->QueryName()+" takes the valueable work.\n");
  sword=0;
  return 1;
}

create() {
 ::create();
 SetIntShort("Art gallery");
 SetIndoors(1);
 AddDetail(({"walls","wall"}),
   "If you are lucky there might be a picture left.\n");
 AddDetail("passage","You can see some light coming from above.\n");
 AddDetail(({"work","painting","picture"}),
  "It looks valueable.\n");
 AddDetail(({"broken door","door"}),
   "Those vandals must have left there as the door is broken.\n");
 AddExit("north","./crawl");
 AddRoomCmd(({"get","take"}),#'do_take);
 reset();
}

reset() {
   ::reset();
   sword=1;
}
