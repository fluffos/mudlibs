/*
 * part of the townwall - room above the main gate
 *
 * last changes:
 * [m] 25 jan 98 - first version
 */

#include <properties.h>
#include <moving.h>
#include <regions.h>
#include <coordinates.h>
#include <skills.h>
#include <sykorath.h>

inherit TOWNWALL;

//*****************
// enter loopholes?
//*****************
// allowed:
//   enter (the|a|an) [east|west] loophole(s)
//   enter (the|a|an) loophole(s) (to) (the|a|an) [east|west]
int cmd_enter(string str) {
  string *exp;
  if (!str) return 0;
  // split at 'loophole(s)'
  exp=regexplode(strip_article(norm_id(str)),
      "[ ]*(loophole|loopholes)[ ]*(to)*[ ]*");
  if (sizeof(exp)!=3) {
    notify_fail("Enter the loophole?\n",NOTIFY_NOT_VALID);
    return 0;
  }
  if ((exp[0]=="east") || (strip_article(exp[2])=="east")) {
    write("The loophole to the east is too small to enter.\n");
    show(NAME+" tries to enter the loophole to the east, but fails.\n");
    return 1;
  }
  if ((exp[0]=="west") || (strip_article(exp[2])=="west")) {
    write("The loophole to the west is too small to enter.\n");
    show(NAME+" tries to enter the loophole to the west, but fails.\n");
    return 1;
  }
  notify_fail("Enter which loophole, the east or the west ones?\n",
              NOTIFY_NOT_VALID);
  return 0;
}

//*******
// create
//*******
create() {
  ::create();
  SetIntShort("Above the main gate");
  SetIntLong(
    "You are in the room above the main gate of the inner townwall. To "
    "the north and south are two towers. The ground is a little bit "
    "dirty. To the east and west you see two loopholes.\n");
  SetIndoors(1);
  SetCoordinates( ({ ({500,600,5}), C_SYKORATH }));
  SetRegion(REGION_CITY);

  /* details */
  AddDetail("tower","Which tower do you want to look at? the north or "
    "the south one?\n");
  AddVItem( ([
    P_IDS:  ({"south tower","tower south"}),
    P_LONG: "You can go south to go into it.\n" ]) );
  AddVItem( ([
    P_IDS:  ({"north tower","tower north"}),
    P_LONG: "You can go north to reach that tower.\n" ]) );
  AddVItem( ([
    P_IDS:  ({"towers"}),
    P_ADS:  ({"two"}),
    P_LONG: "The towers are the north and the south tower, right between "
            "the main gate.\n" ]) );
  AddVItem( ([
    P_IDS:  ({"townwall"}),
    P_ADS:  ({"high","inner"}),
    P_LONG: "You are inside of the townwall.\n" ]) );
  AddVItem( ([
    P_IDS:  ({"gate"}),
    P_ADS:  ({"main"}),
    P_LONG: "You can't see it from here!\n" ]) );
  AddVItem( ([
    P_IDS:  ({"loophole"}),
    P_LONG: "There are two loopholes. Do you want to look the west or the "
            "east loophole?\n" ]) );
  AddVItem( ([
    P_IDS:  ({"loopholes"}),
    P_ADS:  ({"two"}),
    P_LONG: "You see two of them, one to the west and one to the "
            "east. Normally they are used to defend the inner city with "
            "distance weapons.\n" ]) );
  AddVItem( ([
    P_IDS:  ({"east loophole","loophole east"}),  // don't change it to ads!
    P_LONG: "You take a short view to the loophole to the east. Even if it "
            "is very small, you can see a part from the inner city - "
            "the mainplaza.\n" ]) );
  AddVItem( ([
    P_IDS:  ({"west loophole","loophole west"}),  // don't change it to ads!
    P_LONG: "You look through the loophole to the west. Even if it "
            "is small, you can see a little bit from the outer city - "
            "the place before the main gate.\n" ]) );

  /* commands */
  AddRoomCmd("enter","cmd_enter");
  AddSkill(SK_SEARCH,"dirt",75,({"ground","dirty ground","dirt"}));

  /* exits */
  AddExit("north","./towern_up");
  AddExit("south","./towers_up");

  Set(P_INT_WIZMSG,
    "%^RED%^add more details!%^RESET%^\n"
    "then remove this message :)\n"
  );
}

