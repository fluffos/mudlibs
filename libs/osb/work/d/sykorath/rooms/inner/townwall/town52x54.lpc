/*
 * part of the townwall
 *
 * last changes:
 * [m] 26 jan 98 - first version
 */

#include <properties.h>
#include <regions.h>
#include <coordinates.h>
#include <moving.h>
#include <skills.h>
#include <sykorath.h>

inherit TOWNWALL;

//****************
// search handling
//****************
int OnSucceedSearchingStone() {
  write("You found a small inscription. Try to read it!\n");
  return 1;
}
int OnFailSearchingStone() {
  write("Nothign of interest is here, just dirt.\n");
  return 1;
}
int OnSucceedSearchingPile() {
  write("You found a small inscription. Try to read it!\n");
  return 1;
}
int OnFailSearchingPile() {
  write("Uhh you got dirty fingers.\n");
  return 1;
}

//******************
// get/take handling
//******************
int cmd_gettake(string str) {
  if (!str) return 0;
  if (present(str)) return 0;
  if (sizeof(regexplode(norm_id(str),
    "^(the|a|an|[ ])*(dirty)*[ ]*pile(of dirt)*$"))==3) {
    write("The dirt rans through your fingers.\n");
    show(NAME+" tries to get the pile of dirt, but fails.\n");
    return 1;
  }
  return 0;

}

//*******
// create
//*******
create() {
  string pile,stone;
  ::create();
  SetIntShort("Inside the townwall");
  SetIntLong(
    "You are inside the townwall. The passage inside it leads further to "
    "the northeast and southwest. A pile of dirt is on the ground.\n");

  SetIndoors(1);
  SetCoordinates( ({ ({520,540,5}), C_SYKORATH }));
  SetRegion(REGION_CITY);

  /* details */
  AddVItem( ([
    P_IDS:  ({"townwall"}),
    P_ADS:  ({"inside"}),
    P_LONG: #'IntLong ]) );
  AddVItem( ([
    P_IDS:  ({"passage"}),
    P_LONG: "The passage has an exit to the northeast and another one "
            "to the southwest.\n" ]) );
  pile=AddVItem( ([
    P_IDS:  ({"pile","dirt","pile of dirt"}),
    P_ADS:  ({"dirty"}),
    P_LONG: "Looks as someone has moved the dirt to this side. Perhaps "
            "there is something valueable hidden in the pile?\n" ]) );
  AddVItem( ([
    P_IDS:  ({"side"}),
    P_ADS:  ({"this"}),
    P_LONG: "The pile of dirt is laying there.\n" ]) );
  AddVItem( ([
    P_IDS:  ({"ground"}),
    P_ADS:  ({"dirty"}),
    P_LONG: "The ground is a little bit dirty, but you can see the stones "
            "of the townwall through the dirt.\n" ]) );
  stone=AddVItem( ([
    P_IDS:  ({"stone","stones"}),
    P_ADS:  ({"normal"}),
    P_LONG: "Just normal stones, as usually used to build a townwall.\n",
    P_READ_MSG: "You read (written with blood):\n"
                "  Da ger  ahead!\n" ]) );
  AddVItem( ([
    P_IDS:  ({"inscription"}),
    P_ADS:  ({}),
    P_LONG: "The inscription was hidden under the dirt!\n",
    P_READ_MSG: "You read (written with blood):\n"
                "  Da ger  ahead!\n" ]) );

  /* commands */
  AddSkill(SK_SEARCH,"pile",50,pile);
  AddRoomCmd("get", "cmd_gettake");
  AddRoomCmd("take","cmd_gettake");
  AddSkill(SK_SEARCH,"stone",50,stone);

  /* exits */
  AddExit("northeast","./town54x52");
  AddExit("southwest","./town50x56");

  Set(P_INT_WIZMSG,
    "%^RED%^add something special, add details!%^RESET%^\n"
    "then remove this message :)\n"
  );
}

