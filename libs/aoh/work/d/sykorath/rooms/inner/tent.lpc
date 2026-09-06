/*
 * the tent on the place of the former courthouse
 *
 * last changes:
 * [m] 08 jan 97 - first version
 */

// TODO: add a gipsy here
// TODO: hide something in the dirt of the ground?!

#include <properties.h>
#include <moving.h>
#include <regions.h>
#include <coordinates.h>
#include <ansi.h>
#include <skills.h>
#include <sykorath.h>

inherit BASEROOM;

//****************
// searching skill
//****************
int OnSucceedSearchingTent() {
  write("You are searching, but except the torches you find nothing "
        "else.\n");
  return 1;
}

int OnFailSearchingTent() {
  write("You search the tent, but you find nothing of interest.\n");
  return 1;
}

//*******
// create
//*******
create() {
  string vitem;
  ::create();
  SetIntShort("Inside a small tent");
  SetIntLong(
    "You are inside the tent standing on the place of former courthouse. "
    "It is a little bit dark here even if it is lighted by some torches. "
    "The ground is as dirty as outside of the tent.\n");

  SetIndoors(1);
  SetCoordinates( ({ ({600,560,0}), C_SYKORATH }));
  SetRegion(REGION_CITY);
  SetIntLight(0);

  SetMap("inner");

  /* details */
  AddVItem( ([
    P_IDS:  ({"dirt","ground"}),
    P_ADS:  ({"dirty"}),
    P_LONG: "A really dirty ground. But that's normal, because the tent "
            "is built on the same ground as outside of it.\n"]) );
  vitem=AddVItem( ([
    P_IDS:  ({"tent"}),
    P_ADS:  ({"small","brown"}),
    P_LONG: "It is a relatively small tent. Huge people has to "
            "lower their head to stand here. The tent itself is made of "
            "brown textile.\n" ]) );
  AddVItem( ([
    P_IDS:  ({"textile"}),
    P_ADS:  ({"brown"}),
    P_LONG: "The textile is simple canvas, but colored in brown.\n" ]) );
  AddVItem( ([
    P_IDS:  ({"courthouse","house"}),
    P_ADS:  ({"former"}),
    P_LONG: "The old courthouse is burned down, you can't see any of it "
            "here.\n" ]) );
  AddVItem( ([
    P_IDS:  ({"torch","torches"}),
    P_ADS:  ({"some"}),
    P_NOGET:"The torches are nearly burned down. You decide to let them "
            "here. They are not really useful for you.\n",
    P_LONG: "Some torches enlighten the room a little bit, but it is even "
            "a mysterious atmosphere here.\n" ]) );

  AddItem(NPC("gipsy"),REFRESH_REMOVE);

  /* commands */
  AddSkill(SK_SEARCH,"tent",50,vitem);
  AddSkill(SK_SEARCH,"dirt",50,({"dirt","dirty ground","ground"}));

  /* Exits */
  AddExit("out","./courthouse");

  Set(P_INT_WIZMSG,
    "%^RED%^add something special, add details!%^RESET%^\n"
    "then remove this message :)\n"
  );
}

