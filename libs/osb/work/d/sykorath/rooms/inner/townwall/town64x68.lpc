/*
 * part of the townwall
 *
 * last changes:
 * [m] 8 feb 98 - first version
 */

#include <properties.h>
#include <regions.h>
#include <coordinates.h>
#include <moving.h>
#include <nightday.h>
#include <skills.h>
#include <sykorath.h>

inherit TOWNWALL;

//*********
// get/take
//*********
int cmd_take(string str) {
  if (!str) return 0;
  if (present(str)) return 0;
  // hey - regulaer expressions are cool :)
  // 'the' or 'a' or 'some' followed by
  // 'weapon(s)' or 'all' - perhaps followed by
  // 'from' or 'of' followed by
  // 'the' or 'a' or 'some'
  // 'shelf' or 'shelves'
  // fit (for example): 'weapon', 'some weapons from shelves' and so on
  if (sizeof(regexplode(norm_id(str),
    "^(the|a|some| )*(weapon|weapons|all)([ ](from|of| )*(the|a|some| )*"
    "(shelf|shelves))*$"
  ))!=3) return 0;
  write("You take one of the old and rusty weapons, but as you take a "
        "closer look at it, you see that it is really useless. You "
        "decide to let it here.\n");
  show(NAME+" examines the shelves.\n");
  return 1;
}

//*******
// create
//*******
create() {
  ::create();
  SetIntShort("Inside the townwall");
  SetIntLong(
    "This is a small chamber inside the townwall. Some shelves standing "
    "here.\n");

  SetIndoors(1);
  SetCoordinates( ({ ({640,680,5}), C_SYKORATH }));
  SetRegion(REGION_CITY);

  /* details */
  AddVItem( ([
    P_IDS:  ({"townwall","chamber"}),
    P_ADS:  ({"inside"}),
    P_LONG: #'IntLong ]) );
  AddVItem( ([
    P_IDS:  ({"shelf"}),
    P_ADS:  ({"wooden"}),
    P_LONG: "It contains some old and rusty weapons, not reall useful "
            "for you.\n" ]) );
  AddVItem( ([
    P_IDS:  ({"shelves"}),
    P_ADS:  ({"some","wooden"}),
    P_LONG: "Some wooden shelves, which contain some weapons. But the "
            "weapons looks very old and rusty.\n" ]) );
  AddVItem( ([
    P_IDS:  ({"weapon","weapons"}),
    P_ADS:  ({"some"}),
    P_LONG: "Well some old and rusty weapons, not very useful.\n" ]) );

  /* commands/skills */
  AddRoomCmd("get", #'cmd_take);
  AddRoomCmd("take",#'cmd_take);
  AddSkill(SK_SEARCH,"shelf",50,({"shelf","shelves","some shelves"}));

  /* exits */
  AddExit("northeast","./town67x65");
  AddExit("west","./town61x68");

  Set(P_INT_WIZMSG,
    "%^RED%^add something special, add details!%^RESET%^\n"
    "then remove this message :)\n"
  );
}

