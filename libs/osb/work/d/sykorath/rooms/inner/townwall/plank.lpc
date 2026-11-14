
/*
 * part of the townwall
 *
 * last changes:
 * [m] 26 jan 98 - first version
 */

#include <properties.h>
#include <regions.h>
#include <coordinates.h>
#include <moving.h>
#include <npc.h>
#include <sykorath.h>

int plank;

inherit TOWNWALL;

//***********
// properties
//***********
int QueryPlank() { return plank; }
int SetPlank(int p) { return plank=p; }

//****************
// special details
//****************
string look_west_loophole() {
  if (plank) {
    return "This loophole is blocked by a large plank.\n";
  }
  return "You see some parts of the inner city there.\n";
}

string look_plank() {
  if (plank) {
    return "A large plank of oak wood blocks the view to the west.\n";
  }
  return 0;
}

//***************
// get the plank?
//***************
int cmd_gettake(string str) {
  object ob;
  if (!str) return 0;
  if (present(str)) return 0;
    if (sizeof(regexplode(norm_id(str),
    "^(the|a|an|[ ])*(large )*plank( from | of )*(the|a|an|[ ])*"
    "(west )*(loophole)*$"))==3) {
    if (plank) {
      ob=clone_object("/std/thing");
      if (ob) {
        ob->SetProperties( ([
          P_IDS:  ({"plank"}),
          P_ADS:  ({"large"}),
          P_SHORT:"a large plank",
          P_LONG: "A large plank of oak wood.\n",
          P_WEIGHT: 670,
          P_VALUE:  19,
        ]) );
        ob->move(TO,M_SILENT);
        TP->Take(ob,PUTGET_FULL);
        plank=0;
      }
      return 1;
    }
    return 0;
  }
  return 0;
}

//*******
// create
//*******
create() {
  ::create();
  plank=1;
  SetIntShort("Inside the townwall");
  SetIntLong(
    "You are inside the townwall. One loophole is to the west and another "
    "to the east.\n");

  SetIndoors(1);
  SetCoordinates( ({ ({700,580,5}), C_SYKORATH }));
  SetRegion(REGION_CITY);

  /* details */
  AddVItem( ([
    P_IDS:  ({"townwall"}),
    P_ADS:  ({"inside"}),
    P_LONG: #'IntLong ]) );
  AddVItem( ([
    P_IDS:  ({"loophole"}),
    P_ADS:  ({"one"}),
    P_LONG: "At which one do you want to look at? There is one to the "
            "east and another to the west.\n" ]) );
  AddVItem( ([
    P_IDS:  ({"loopholes"}),
    P_ADS:  ({"two","some"}),
    P_LONG: "There are two loopholes here, you can look at the west or "
            "the east one!\n" ]) );
  AddVItem( ([
    P_IDS:  ({"loophole west","west loophole"}),
    P_LONG: #'look_west_loophole ]) );
  AddVItem( ([
    P_IDS:  ({"loophole east","east loophole"}),
    P_LONG: "You see some parts of the outer city there.\n" ]) );
  AddVItem( ([
    P_IDS:  ({"plank"}),
    P_ADS:  ({"large"}),
    P_LONG: #'look_plank ]) );

  /* commands */
  AddRoomCmd("get", "cmd_gettake");
  AddRoomCmd("take","cmd_gettake");

  /* exits */
  AddExit("north","./spiderroom");
  AddExit("south","./town70x60");

  Set(P_INT_WIZMSG,
    "%^RED%^add something special, add details!%^RESET%^\n"
    "then remove this message :)\n"
  );
}

//**************
// special reset
//**************
reset() {
  object ob;
  ::reset();
  if (!plank) {
    show_room(TO,"A worker comes along and cries:\n"
      "'Waaaah - ever the same - the west loophole should be closed!'\n");
    ob=present("plank");
    if (ob) {
      show_room(TO,"And the worker takes the plank and nails it back to "
        "the west loophole.\n");
      ob->remove();
    } else {
      show_room(TO,"And the worker takes a plank from his inventory and "
        "nails it to the west loophole.\n");
    }
      show_room(TO,"Than he walks away.\n");
    plank=1;
  }
}
