#include <rooms.h>;
inherit "/std/room";

create() {
   ::create();
   SetIntShort("A secret room");
   SetIntLong("You are in a secret room of firestone's castle.\n");
   SetIndoors(1);
   AddExit("south","./entr");
   AddItem("/d/archwiz/firestone/kirk",REFRESH_HOME);
}
