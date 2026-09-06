#include "path.h"
#include <moving.h>

inherit "/std/room";

int bone;

bones() {
  object ob;
  if (!this_player()) return 0;
  if (bone) return "You see nothing special about the bones.\n";
  show(this_player()->QueryName()+" searches the bones and finds a skull.\n",
    this_player());
  see("You search through the bones and find a nice skull.\n");
  ob=clone_object("/std/thing");
  ob->SetShort("a skull");
  ob->SetLong("This is an evilly grinning skull of a long decayed pirate.\n");
  ob->SetIds(({"bone","skull"}));
  ob->SetAds(({"pirate","old","decayed"}));
  ob->SetValue(2);
  ob->SetWeight(500);
  if (ob->move(this_player(),M_GET)!=ME_OK) {
    write("The skull is too heavy so you drop it.\n");
    ob->move(this_object(),M_DROP);
    }
  bone=1;
  return "";
}

create() {
  ::create();
  SetIntShort("a cave");
  SetIntLong(
"You're in a cave with walls that seem to absorb the light. Bones of some "
"long decayed pirates lie here.\n");
  SetIndoors(1);
  SetBright(0);
  AddDetail("cave",QueryIntLong());
  AddDetail(({"wall","walls"}),"The walls seem to absorb the light.\n");
  AddDetail(({"ceiling","ground","floor"}),"It doesn't look too special.\n");
  AddDetail(({"decayed bone","decayed bones","bone","bones"}),#'bones);
  AddExit("northeast","./incave2");
  AddExit("southeast","./incave4");
  reset();
}

reset() {
  ::reset();
  bone=0;
}
