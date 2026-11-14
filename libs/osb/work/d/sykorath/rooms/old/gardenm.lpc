// part of the town
// made by magictcs - 10 jul 97

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
  if (str!="rose" && str!="roses") return;
  if (!plucked) {
     write("The other roses are of no interest for you.\n");
     return 1;
   }
  plucked=0;
  say(NAME+" plucks some roses.\n");
  write("You pluck some roses.\n");
  ob=clone_object(WEAPON("wrose"));
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
  "with the roses.\n";
}

//*******
// create
//*******
create() {
  ::create();
  plucked=1;
  SetIntShort("In a garden");
  SetIntLong(
    "This is part of a small garden. You see some fields of roses around.\n");
  SetIndoors(0);

  /* details */
  AddDetail("garden",#'IntLong);
  AddDetail(({"field","fields","some fields"}),
    "The fields are very beautiful. They can't belong to this city.\n"
    "The gardener works very hard here!\n");
  AddDetail("gardener",#'lookgardener);
  AddDetail(({"rose","roses"}),
    "Some beautiful roses whith sharp thornes. Maybe you can pluck them?\n");

  /* commands */
  AddRoomCmd("pluck",#'pluck);

  /* items */
  AddItem(NPC("gardener"),REFRESH_HOME);

  /* exits */
  AddExit("north","./gardenn");
  AddExit("east","./gardene");
  AddExit("south","./gardens");
  AddExit("west","./gardenw");
}

reset() {
  ::reset();
  plucked=1;
}

