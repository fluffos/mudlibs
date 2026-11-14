// made by magictcs - 1 aug 97

// TODO: add a disease for being in here! (maybe add it with notify_enter and
// remove it with notify_leave?)
// TODO: code the disease for _wine_sick_   (sick from the wine spirit)
// TODO: update coords

#include <properties.h>
#include <moving.h>
#include <sykorath.h>
#include <npc.h>
#include <regions.h>
#include <coordinates.h>

inherit BASEROOM;

//***************
// go out of cask
//***************
int go_out() {
  write("You leave the cask. You feel much better!\n");
  return TP->move(OUTER("winery"),M_GO,"leaves the cask");
}

//*******************
// adding the disease
//*******************
void notify_enter(object oldenv,int method,mixed extra) {
  object ob;
  ::notify_enter(oldenv,method,extra);
  if (interactive(PO)) {
    // ob=clone_object(OBJ("wine_sick"));    // not coded actually !
    // if (ob) ob->move(PO,M_SILENT);
  }
}

//*********************
// removing the disease
//*********************
void notify_leave(object dest,int method,mixed extra) {
  object ob;
  ::notify_leave(dest,method,extra);
  if (interactive(PO)) {
    ob=present("_wine_sick_",TP);
    if (ob) ob->remove();
  }
}

//*******
// create
//*******
create() {
  ::create();
  SetIntShort("Inside a cask");
  SetIntLong(
    "This is the inside of a huge cask. It is nearly as huge that you can "
    "stand without kneeling on the ground of the cask.\n"
    "The cask is made of oak wood and it is empty, but it has to be used in"
    "the last time. You smell some spirit of wine. Better not to stay to "
    "long in this cask!\n"
    "Some light comes through the bunghole.\n");
  SetIndoors(0);
  SetCoordinates( ({ ({66,42,0}), C_SYKORATH }));
  Set(P_REGION,REGION_CITY);

  /* special smell */
  SetIntSmell("You smell the spirit of an old wine.\n");
  AddSmell(({"spirit","wine","spirit of wine"}),
    "You sniff the spirit - hmm could be an old 'Bon Soir'.\n");

  /* details */
  AddDetail(({"cask","huge cask","empty cask"}),#'IntLong);
  AddVItem( ([
    P_IDS:  ({ "ground" }),
    P_LONG: "The ground is made of oak wood (just like the wall or the "
            "ceiling and it is a little bit round, because it is a round "
            "cask!\n"
    ]) );
  AddVItem( ([
    P_IDS:  ({ "wall","walls" }),
    P_LONG: "The walls are made of the same wood as the ground. The walls "
            "are round too. You see some words on the wall.\n"
    ]) );
// TODO: VITEM id withmore than one word didn't work!
// TODO: add some interesting words here - maybe a hint for a miniquest?
  AddVItem( ([
    P_IDS:  ({ "word","words","words on wall","word on wall" }),
    P_ADS:  ({ "some" }),
    P_READ_MSG: "You read: xxxxxxx\n",
    P_LONG: "The word are very old, but they are still readable.\n"
    ]) );
  AddVItem( ([
    P_IDS:  ({ "ceiling" }),
    P_LONG: "Yes the ceiling is made of the same wood as the walls or the "
            "ground. The ceiling is round too, because of the inner form of "
            "the cask.\n"
    ]) );
  AddVItem( ([
    P_IDS:  ({ "wood" }),
    P_ADS:  ({ "oak","old","very old" }),
               // don't split "very old" to "very" and "old" !
    P_LONG: "It is very old oak wood. Look like older than centuries. Many "
            "good old wines had to be in here before you visited the cask.\n"
    ]) );
  AddVItem( ([
    P_IDS:  ({ "wine","spirit of wine" }),
    P_LONG: "You can't see any wine here, but you smell the spirit of wine.\n"
    ]) );
  AddVItem( ([
    P_IDS:  ({ "light" }),
    P_ADS:  ({ "some" }),
    P_LONG: "It is a little bit darker in the cask than the outside. But "
            "this is normal due to the little bunghole. There is no other "
            "place or hole, where light can enter the cask.\n"
    ]) );
  AddVItem( ([
    P_IDS:  ({ "bunghole","hole" }),
    P_ADS:  ({ "small","little" }),
    P_LONG: "This is the place where you entered the cask. You can leave the "
            "cask by using this bunghole again. Some light comes into the "
            "interior of the cask through this small hole.\n"
    ]) );


  SetIntLight(-10);             // it's a little bit dark inside

  /* exits */
  AddExit("out",#'go_out);
}

