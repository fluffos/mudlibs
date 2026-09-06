/* 
 * part of the graveyard
 *
 * introduced:
 * Magictcs 17 jul 97 - first version
 *
 * updated:
 * Magictcs - 23 feb 98 - remade, added skills
 */

// TODO: add more details,exits
// TODO: change exit up
// TODO: maybe add a special exit (hidden behind the spiderwebs?)
// TODO: you can use it if you cut the filament?
// TODO: call a giant spider if you touch the filament?!

#include <properties.h>
#include <moving.h>
#include <regions.h>
#include <coordinates.h>
#include <sykorath.h>

inherit BASEROOM;

//****************
// touch spiderweb
//****************
int touch(string str) {
  notify_fail("Touch what?\n");
  if (!str) return 0;
  if (member(({"spiderweb","spiderwebs","some spiderwebs","web","webs"}),
    str)!=-1) {
    write(
    "You touch the filament of the spiderweb. The filament is very sticky.\n"
    "You can't go away.\n");
    TP->Set("TOUCHWEB",1);
    show(NAME+" touches the filament of the spiderweb.\n");
    return 1;
  }
  return 0;
}

//**************
// cut spiderweb
//**************
int IsSword(object weapon) {
  if (weapon->QueryWeaponType()==WT_SWORD) return 1;
  return 0;
}

int cut(string str) {
  object *weapons,*objs;
  notify_fail("Cut filament?\n");
  if (!str) return 0;
  if (str=="filament") {
    weapons=TP->QueryWeapons();        // wielded weapons
    weapons=filter(weapons,"IsSword");
    if (sizeof(weapons)) {
      tell_room(TO,NAME+" cuts the filament with his weapon.\n"
        "All are free again.\n");
      objs=all_inventory();
      filter_objects(objs,"Set","TOUCHWEB",0);
      return 1;
    }
    write("You need a sharp sword to do this!\n");
    return 1;
  }
  return 0;
}

//*******
// create
//*******
create() {
  ::create();
  SetIntShort("In a tomb");
  SetIntLong(
    "You have entered a tomb under the small chapel of the graveyard. "
    "You see some spiderwebs around. Looks like that noone was here for "
    "a long time.\n");
  SetIndoors(1);
  SetCoordinates( ({ ({800,640,0}), C_SYKORATH }));
  SetRegion(REGION_CITY);

  /* details */
  AddVItem( ([
    P_IDS:  ({"tomb"}),
    P_LONG: #'IntLong ]) );
  AddVItem( ([
    P_IDS:  ({"chapel"}),
    P_ADS:  ({"small"}),
    P_LONG: "The small chapel is up (where you come from).\n" ]) );
  AddVItem( ([
    P_IDS:  "graveyard",
    P_LONG: "You remember the graveyard, the chapel belongs to it.\n" ]) );
  AddDetail(({"spiderweb","spiderwebs","some spiderwebs","web","webs"}),
    "Better don't touch them. The filament looks very thin, but it may be\n"
    "harder than it looks like.\n");
  AddDetail("filament",
    "The filament consists of hundreds of thin hairlines, hard and sticky.\n");

  /* commands */
  AddRoomCmd("cut","cut");
  AddRoomCmd("touch","touch");

  /* exits */
  AddExit("up","./gravechapel");
}

// forbid leaving of player which had touched the spiderweb
int prevent_leave(object dest,int method,mixed extra) {
  if (!TP->Query("TOUCHWEB")) return 0;    // allowed
  write("To leave the tomb - cut the spiderweb with a sharp weapon!\n");
  return ME_NO_LEAVE;
}

