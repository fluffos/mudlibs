inherit "std/room";

#include "path.h"
#include <moving.h>

int knife,rope;

QueryIntLong() {
  string desc;
  desc="You are in the attic. The only exit are stairs that lead down.\n";
  if (rope) desc=desc+"A large coil of rope is lying in the corner.\n";
  if (knife) desc=desc+"On the table is a nasty-looking knife.\n";
  return desc;
}

int take(string str) {
  object kni;
  if (str!="knife" && str!="rope") return 0;
  if (str=="rope" && rope==0) return 0;
  if (str=="knife" && knife==0) return 0;
  if (str=="rope") {
    write("You take the coil of rope.\n");
    kni=clone_object(OBJ("whrope"));
    if (kni->move(this_player(),M_SILENT)!=ME_OK) {
      write("But as you cannot carry it anymore, you drop it.\n");
      show(this_player()->QueryName()+" tries to take the rope, but as "+
          this_player()->QueryPronoun()+" cannot carry it, it falls down.\n",
	  this_player());
      kni->move(this_object(),M_SILENT);
      }
    rope=0;
    }
  if (str=="knife") {
    write("You take the knife.\n");
    kni=clone_object(WEAPON("whknife"));
    if (kni->move(this_player(),M_SILENT)!=ME_OK) {
      write("But as you cannot carry it anymore, you drop it.\n");
      show(this_player()->QueryName()+" tries to take the knife, but as "+
          this_player()->QueryPronoun()+" cannot carry it, it falls down.\n",
	  this_player());
      kni->move(this_object(),M_SILENT);
      }
    knife=0;
    }
  return 1;
}

create() {
  ::create();
  SetIntShort("Attic of a white house");
  SetIndoors(1);
  SetIntLight(-1);
  AddDetail("table","There is nothing special about the table.\n");
  AddDetail("rope","You see a long coil of rope\n");
  AddDetail("knife","Nasty thing!\n");
  AddDetail(({"attic","room"}),#'IntLong);
  AddDetail(({"stairs","staircase"}),"Just follow it down.\n");
  AddExit("down","./whkitchen");
  AddRoomCmd(({"get","take"}),#'take);
  reset();
}

reset() {
   ::reset();
   rope=1;
   knife=1;
}

