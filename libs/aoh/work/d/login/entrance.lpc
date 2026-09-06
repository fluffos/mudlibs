//---------------------------------------------------------------------------
// Startup room for new players in OSB
//
// (c) Softbyte@OSB 10nov97
// [Softbyte] 10nov97   : Creation and basic functions
// [Mordrid]  13dec97   : Ship description
// [Tune]     09mar98   : bits and pieces
// [Tune]     20Apr99   : added the Instant option
//
// TODO:  Details and long description
//
//---------------------------------------------------------------------------


#include <rooms.h>
#include <regions.h>
#include <coordinates.h>
#include <properties.h>
#include <string.h>

inherit "/std/room";

public varargs void create(int repl)
{
  ::create();
  SetIntShort("Entering One Step Beyond");
  SetIntLong(
    "                      %^BOLD%^%^WHITE%^Welcome to OSB%^RESET%^\n"
    "\n"
    "As your sight comes back into focus, "
    "you notice you aren't where you were a moment "
    "ago. You see brown walls surrounding you, slightly "
    "spherical towards the top and bottom. You begin to wonder "
    "if you are trapped in a hot dog. Knowing this can't be the answer, "
    "you decide to explore and see where it takes you.\n"
    "\n"
    "To enter OSB, please select one of the following ways to create a character:\n\n"+

    ({string})L_STRING->wrap(
    "%^BOLD%^%^WHITE%^normal%^RESET%^   "
      "You already have some experience in playing muds "
      "and want to quickly create your character, and be able to influence "
      "the generation of your character to a large degree.\n",
   72, 9) +
   ({string})L_STRING->wrap(
   "%^BOLD%^%^WHITE%^newbie%^RESET%^   "
      "You are a newcomer to MUDs, or have little experience playing "
      "them, and would like some help during the character setup, plus "
      "some information about how to get started here.\n",
    72, 9) +
   ({string})L_STRING->wrap(
   "%^BOLD%^%^WHITE%^instant%^RESET%^  "
      "You'd rather jump right in and start playing than be bothered by "
      "the finer details of character generation. Use this alternative "
      "to automatically create a character.\n",
    72, 9) +
  "\n"
  "Please type 'normal', 'newbie' or 'instant' to proceed.\n");

  SetIndoors(1);
  SetIntLight(50);
  Set(P_REGION,REGION_DREAM);
  Set(P_TEMPERATURE,20);
  Set(P_COORDINATES,({ ({0,0,0}),C_LOGIN }) );

  AddExit("normal","./advanced/race");
//  AddExit("normal","./normal/race");
  AddExit("instant", "./easy/instant");
  AddExit("newbie", "/p/newbie/creation/room01");
  //AddRoomCmd("newbie", "do_easy");

 Set(P_INT_SMELL, "You smell something that seems to be .... sea water.\n");
 AddDetail(({"wall","walls","brown walls","brown wall"}),"At first glance the walls appear to be that of a hot dog, yet something tells you they are more like a dark wood.\n");

}

int do_easy()
{
   write("Sorry, that is not implemented yet. Our apologies.\n");
   return 1;
}
