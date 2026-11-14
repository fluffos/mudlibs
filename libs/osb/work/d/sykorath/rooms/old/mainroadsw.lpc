// part of the town
// made by magictcs - 9 jun 97
// TODO: update coords

#include <properties.h>
#include <moving.h>
#include <npc.h>
#include <regions.h>
#include <coordinates.h>
#include <sykorath.h>

inherit BASEROOM;

int aside;
int potion;

//***************
// search command
//***************
int search(string str) {
  object ob;
  string norm;
  notify_fail("You found nothing\n");
  if (!str) return 0;
  norm=norm_id(str);
  if (member(({"pile","pile of dirt","dirt"}),norm)!=-1) {
    if (potion) {
      write("You search the pile of dirt and find a potion.\n");
      show(NAME+" searches the pile of dirt.\n");
      ob=clone_object(BASE+"eatcorpse/giantwisdom");
      ob->move(TO,M_SILENT);
      TP->Take(ob,PUTGET_FULL);
      potion--;
      return 1;
    } else {
      write("You search the pile of dirt but find nothing yet.\n");
      show(NAME+" searches the pile of dirt.\n");
      return 1;
   }
  }
  return 0;
}

//*************
// move command
//*************
int do_move(string str) {
  string norm;
  notify_fail("Move what?\n");
  if (!str) return 0;
  norm=norm_id(str);
  if (member(({"pile","pile of dirt","dirt"}),norm)!=-1) {
    if (aside) {
      write("You move the heap back to its origin position.\n");
      show(NAME+" moves the heap back.\n");
      aside--;
      return 1;
    }
    write("As you move the pile of heap aside, you detect an inscription\n"
          "under the dirt.\n");
    show(NAME+" moves the heap aside.\n");
    aside++;
    return 1;
  }
  return 0;
}

//*****************
// look inscription
//*****************
string lookinscription () {
  if (aside) return
    "There is an inscription on the ground. You can read it.\n";
  return 0;
}

// TODO: change the message here!?
string readinscription() {
  if (aside) return
    "You read in biggest lettern:\n"
    "--> Better search the pile <--\n";
  return 0;
}

string lookground() {
  if (aside) return
    "A pile of dirt lies there. Yes it is a real dirty road.\n"
    "An inscription is on the ground.\n";
  return "A pile of dirt lies there. Yes it is a real dirty road.\n";
}

//*******
// create
//*******
create() {
  ::create();
  aside=0;
  potion=1;
  SetIntShort("A road");
  SetIntLong(
    "You are on a dirty road. A house is standing west.\n"
    "On the ground lies a pile of dirt. North can be seen the main plaza.\n");
  SetIndoors(0);
  SetCoordinates( ({ ({0,0,0}), C_SYKORATH }));
  Set(P_REGION,REGION_CITY);

  /* details */
  AddDetail(({"road","dirty road"}),#'IntLong);
  AddDetail(({"house","bank"}),
    "The house looks like a bank. You can store your money there.\n");
  AddDetail(({"main plaza"}),
    "The way north leads back to it.\n");
  AddDetail("north","The main plaza is north.\n");
  AddDetail("ground",#'lookground);
  AddDetail(({"pile of dirt","pile","dirt"}),
    "Really dirty dirt. But it looks like that some has moved this pile\n"
    "in the last time.\n" );
  AddDetail("inscription",#'lookinscription);
  AddReadMsg("inscription",#'readinscription);

  /* commands */
  AddRoomCmd("move",#'do_move);
  AddRoomCmd("search",#'search);

  /* exits */
  AddExit("northeast","./mainplaza");
  AddExit("west","./bank");
  AddExit("south","./itemple");
}

reset() {
  ::reset();
  aside=0;
  potion=1;
}
