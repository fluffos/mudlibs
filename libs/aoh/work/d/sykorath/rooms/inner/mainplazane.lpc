/* part of the mainplaza of the town
 * made by magictcs - 22 may 97
 *
 * last changes:
 * [m] 08 jan 97 - remade, added sun clock
 */

// TODO: add a push for the sunclock?
//       push depends on strength(skill)
// TODO: version 1: push sunclock to sunlight -> dwarf/gnome comes
// TODO:            and repairs it?
// TODO: version 2: push sunclock -> small opening in ground?
// TODO: version 3: push sunclock -> something lies under the sunclock?
// add 'repair' command for sunclock

#include <properties.h>
#include <moving.h>
#include <regions.h>
#include <coordinates.h>
#include <ansi.h>
#include <sykorath.h>

inherit BASEROOM;

int sun_available;
int sun_repaired;

//******************
// property handling
//******************
int SetSunAvailable(int s) { return sun_available=s; }
int QuerySunAvailable() { return sun_available; }
int SetSunRepaired(int r) { return sun_repaired=r; }
int QuerySunRepaired() { return sun_repaired; }

//****************
// special details
//****************
// TODO: add a time msg? hmm no?!
// clock works, when standing in sunlight
string look_sunclock() {
  if (!sun_available)
    return
    "The sunclock is very damaged. Noone is responsible for the clock. "
    "But the sunclock doesn't need any remaking, because the sun isn't "
    "shining to this place. Sun is blocked by the huge townwall in the "
    "east and by the houses west and northwest.\n";
  return
  "The sunclock stand now in full sunlight (check time) blabla bla...\n"
  "will never happen actually...\n";
}

//*******
// create
//*******
create() {
  ::create();
  sun_available=0;
  sun_repaired=0;
  SetIntShort("The main plaza");
  SetIntLong(
    "This place is part of the main plaza of the town.\n"
    "A sunclock is here.\n");

  SetIndoors(0);
  SetCoordinates( ({ ({620,580,0}), C_SYKORATH }));
  SetRegion(REGION_CITY);

  SetMap("inner");

  /* details */
  AddVItem( ([
    P_IDS:  ({"plaza","place"}),
    P_ADS:  ({"this","main"}),
    P_LONG: #'IntLong ]) );
  AddDetail("town","You are standing inmids the town.\n");
  AddVItem( ([
    P_IDS:  ({"clock","sunclock"}),
    P_NOGET:"You can't get the sunclock. Even if it is damaged, it it too "
            "heavy to get.\n",
    P_ADS:  ({"sun","damaged"}),
    P_LONG: #'look_sunclock ]) );
  // change next both details if sunclock is repaired/pushed!
  AddVItem( ([
    P_IDS:  ({"townwall","wall"}),
    P_ADS:  ({"town","huge"}),
    P_LONG: "The huge townwall blocks the sunlight to the sunclock. Some "
            "other parts of the room are enlighted by sunrays.\n" ]) );
  AddVItem( ([
    P_IDS:  ({"house","houses"}),
    P_ADS:  ({"some"}),
    P_NOGET:"The houses are fixed to the ground (and too heavy to get).\n",
    P_LONG: "There are some houses around which block the sunlight to "
            "the sunclock. That's the reason why nobody repairs the "
            "sunclock.\n" ]) );

  /* commands */

  /* Exits */
  AddExit("west",     "./mainplazan");
  AddExit("south",    "./mainplazae");
  AddExit("northeast","./puddle");
  AddExit("southwest","./mainplazam");
  AddExit("north",    "./pile");

  Set(P_INT_WIZMSG,
    "%^RED%^check the sun clock, add push command there"
    "check the coords, add details!%^RESET%^\n"
    "then remove this message :)\n"
  );
}

//**************
// special reset
//**************
// TODO: add special msg, when the sunclock becomes damaged again
// TODO: add special messgae if sunclock is moved back by a cruel giant :)
reset() {
  ::reset();
  sun_available=0;
  if (sun_repaired) {
    show_room(TO,"The sunclock is hit by a giant fire bolt. It is "
              "damaged now.\n");
  }
  sun_repaired=0;
}

