
#include <properties.h>
#include <ansi.h>
#include <macros.h>
#include <moving.h>

#define AB(x)   ANSI_BOLD + x + ANSI_NORMAL

inherit "/std/room";

int continue1();
int x_back();


varargs void create()
{
  ::create();
  SetIntShort("HP and SP");
  Set(P_INT_LONG,
   "We're at the end of the introduction now. If you feel ready to "
   "step into the world of One Step Beyond, continue north. If you'd "
   "like to change your gender, race, et cetera, you can go back "
   "now.\n");

  AddRoomCmd("back", "x_back");
  AddExit("north", #'continue1 /*'*/);
  AddExit("south","./room13");

  SetIndoors(1);

}

int x_back()
{
  write("No not type 'back' - I mean go south ...\n");
  return 1;
}

int continue1()
{
  TP->move("/p/newbie/creation/falling", M_SILENT);
  find_object("/p/newbie/creation/falling")->step1();
  return 1;
}


