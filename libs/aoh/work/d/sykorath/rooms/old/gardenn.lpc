// part of the town
// made by magictcs - 14 jul 97

#include <properties.h>
#include <moving.h>
#include <npc.h>
#include <nightday.h>
#include <sykorath.h>

inherit BASEROOM;

int plucked;

//******
// pluck
//******
pluck(str) {
  object ob;
  notify_fail("Pluck what?\n");
  if (member(({"nettle","stinging nettle","nettles","stinging nettles"}),
    str)==-1) return;
  if (!plucked) {
     write("The other nettles are of no interest for you.\n");
     return 1;
  }
  plucked=0;
  say(NAME+" plucks s nettle.\n");
  write("You pluck a stinging nettle.\n");
  ob=clone_object(WEAPON("wnettle"));
  if (ob) TP->Take(ob,PUTGET_FULL);
  return 1;
}

//***************
// detailhandling
//***************
string lookgardener() {
  if (present("gardener")) return 0;
  return
  "Sometimes you see a gardener here, which is taking care over the fields\n"
  "with the nettles.\n";
}

//*******
// create
//*******
create() {
  ::create();
  plucked=1;
  SetIntShort("In a garden");
  SetIntLong(
    "This is part of a small garden. You see some fields of stinging nettles\n"
    "around.\n");
  SetIndoors(0);

  /* details */
  AddDetail("garden",#'IntLong);
  AddDetail(({"field","fields","some fields"}),
    "The fields are very beautiful. They can't belong to this city.\n"
    "The gardener works very hard here!\n");
  AddDetail("gardener",#'lookgardener);
  AddDetail(({"nettle","nettles","stinging nettle","stinging nettles"}),
    "Some very cruel stinging nettles . Maybe you can pluck them?\n");

  /* commands */
  AddRoomCmd("pluck",#'pluck);

  /* exits */
  AddExit("south","./gardenm");
}

reset() {
  ::reset();
  plucked=1;
}

