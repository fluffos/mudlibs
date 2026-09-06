/*
 * part of the eatcorpse quest
 * made by magictcs - 9 jun 97
 *
 * last changes:
 * [m] 11 jan 97 - remade
 */

#include <properties.h>
#include <moving.h>
#include <npc.h>
#include <regions.h>
#include <coordinates.h>
#include <sykorath.h>
#include <skills.h>

inherit SY_STREET;

int aside;
int potion;

//******************
// property handling
//******************
int SetAside(int s) { return aside=s; }
int QueryAside() { return aside; }
int SetPotion(int p) { return potion=p; }
int QueryPotion() { return potion; }

//***************
// search command
//***************
int OnSucceedSearchingPile() {
  object ob;
  if (potion) {
    write("You search the pile and find a potion.\n");
    ob=clone_object(QUEST("eatcorpse/giantwisdom"));
    ob->move(TO,M_SILENT);
    TP->Take(ob,PUTGET_FULL);
    potion--;
  } else {
    write("You found nothing, but you get dirty fingers.\n");
  }
  return 1;
}

int OnFailSearchingPile() {
  write("Oh, you get dirty fingers.\n");
  return 1;
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
    write("As you move the pile of heap aside, you detect an inscription "
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
    "You are on a dirty road. A house is standing west. On the ground "
    "lies a pile of dirt. North can be seen the main plaza.\n");

  SetIndoors(0);
  SetCoordinates( ({ ({620,560,0}), C_SYKORATH }));
  SetRegion(REGION_CITY);

  SetMap("inner");

  /* details */
  AddVItem( ([
    P_IDS:  ({"road"}),
    P_ADS:  ({"dirty"}),
    P_LONG: #'IntLong ]) );
  AddVItem( ([
    P_IDS:  ({"plaza"}),
    P_ADS:  ({"main"}),
    P_LONG: "The way north leads back to it.\n" ]) );
  AddDetail("north","The main plaza is north.\n");
  AddDetail("ground",#'lookground);
  AddVItem( ([
    P_IDS:  ({"pile of dirt","pile","dirt"}),
    P_NOGET:"You don't want to get dirt, want you?\n",
    P_LONG: "Really dirty dirt. But it looks like that some has moved "
            "this pile in the last time.\n" ]) );
  AddVItem( ([
    P_IDS:  ({"inscription"}),
    P_LONG: #'lookinscription,
    P_READ_MSG: #'readinscription ]) );

  /* commands */
  AddRoomCmd("move",#'do_move);

  // should ever suceed
  // very easy to find!
  AddSkill(SK_SEARCH,"pile",30,({"pile","pile of dirt","dirt"}));

  /* exits */
  AddExit("south","./mainplazane");

  Set(P_INT_WIZMSG,
    "%^RED%^add details (make them recursiv?)!%^RESET%^\n"
    "then remove this message :)\n"
  );
}

//******
// reset
//******
reset() {
  ::reset();
  aside=0;
  potion=1;
}

