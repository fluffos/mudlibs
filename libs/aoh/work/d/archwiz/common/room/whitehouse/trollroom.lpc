inherit "std/room";

#include <rooms.h>
#include "path.h"

int throw(string str) {
  object what;
  string a;
  if (!str) return 0;
  if (!this_player()) return 0;
  if (sscanf(str,"%s at troll",a)<1) return 0;
  what=present(a,this_player());
  if (!what) {
    write("You don't have that.\n");
    return 1;
    }
  tell_room(this_object(),
    "The troll who is remarkably coordinated, catches the "+
    what->QueryShort()+
    "\nand not having the most discriminating tastes, gleefully eats it.\n");
  what->remove();
  if (what) destruct(what);
  return 1;
}

create() {
  ::create();
  SetIntShort("Cellar of a white house");
  SetIntLong(
"You are in a small room with a narrow passageway leading west. "
"Bloodstains and deep scratches (perhaps made by an axe) mark the walls.\n");
  SetIndoors(1);
  SetBright(-10);
  AddDetail(({"cellar","small room","room"}),#'IntLong);
  AddDetail(({"passageway","way","narrow way","narrow passageway"}),
    "The passageway leads west.\n");
  AddDetail(({"bloodstains","bloodstain","blood","stains","stain"}),
    "There are some fresh ones, but most are old and dry.\n");
  AddDetail(({"scratches","scratch","deep scratches","deep scratch"}),
    "What- or whoever made those scratches: You don't want to meet it.\n");
  AddRoomCmd("throw",#'throw);
  AddExit("west","./cellar");
  AddExit("east","./e_w_passage");
  AddExit("north","./behind_troll");
  AddItem(MONSTER("babytroll"),REFRESH_HOME);
}
