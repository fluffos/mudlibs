/*
 * part of the inner city
 * former place for the courthouse, now just only a tent there
 *
 * last changes:
 * [m] 25 jan 98 - first version
 */

#include <properties.h>
#include <moving.h>
#include <regions.h>
#include <coordinates.h>
#include <ansi.h>
#include <skills.h>
#include <sykorath.h>

inherit SY_STREET;

//***************
// Skill handling
//***************
int OnSucceedSearchingTent() {
  write("You search the outside of the tent. But maybe it is better to "
        "search inside of it?\n");
  return 1;
}

int OnFailSearchingTent() {
  write("You found nothing while searching the tent.\n");
  return 1;
}

//*******
// enter?
//*******
int cmd_enter(string str) {
  if (!str) return 0;
  if (sizeof(regexplode(norm_id(str),
    "^(the|a|an|[ ])*(small )*tent$"))==3) {
    TP->move(INNER("tent"),M_SPECIAL,({
        "enters the small tent",
        "arrives from the outside",
        "enter the small tent"
        }));
    return 1;
  }
  return 0;
}

//*******
// create
//*******
create() {
  string vitem;
  ::create();
  SetIntShort("A tent");
  SetIntLong(
    "This place was the buildplace of the former courthouse. But this one "
    "is burned down in the great war. Noone has rebuilt it it. You see just "
    "a small tent standing here.\n");

  SetIndoors(0);
  SetCoordinates( ({ ({600,560,0}), C_SYKORATH }));
  SetRegion(REGION_CITY);

  SetMap("inner");

  /* details */
  AddVItem( ([
    P_IDS:  ({"courthouse","house"}),
    P_ADS:  ({"former"}),
    P_NOGET: "The house is a bit too heavy to get!\n",
    P_LONG: "The courthouse is burned down some years ago. There is nothing "
            "left of it.\n" ]) );
  AddVItem( ([
    P_IDS:  ({"place","buildplace"}),
    P_LONG: #'IntLong ]) );
  AddVItem( ([
    P_IDS:  ({"war"}),
    P_ADS:  ({"great"}),
    P_LONG: "Nothing remains on this great war.\n" ]) );
  vitem=AddVItem( ([
    P_IDS:  ({"tent"}),
    P_ADS:  ({"small"}),
    P_NOGET: "As you try to get the tent, someone comes out of the tent, "
             "looks angrily at you and vanishes into the tent again.\n",
    P_LONG: "A small tent is standing here. You wonder what it is for?! "
            "Perhaps you can enter it?\n" ]) );

  /* commands */
  AddRoomCmd("enter","cmd_enter");
  AddSkill(SK_SEARCH,"tent",50,vitem);

  /* Exits */
  AddExit("south","./mainplazan");
  AddExit("tent", "./tent");

  Set(P_INT_WIZMSG,
    "%^RED%^add something special, add details!%^RESET%^\n"
    "then remove this message :)\n"
  );
}

