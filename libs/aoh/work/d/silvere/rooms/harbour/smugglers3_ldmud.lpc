// The smugglers hideout, chamber
// created:    Taurec [23-Dec-1997]

#include <silvere.h>
#include <properties.h>
#include <coordinates.h>
#include <regions.h>
#include <moving.h>
#include <macros.h>
inherit BASEROOM;

void opened_leave_msg();
void closed_leave_msg();

int leave_cave(){
  object smug2;
  if (!TP) return 0;
  smug2 = find_object(SIL_HARBOUR("smugglers2"));
  if (!smug2)
  smug2 = load_object(SIL_HARBOUR("smugglers2"));
  if(({int})smug2->QueryIsOpen()==1) opened_leave_msg();
  else{
    closed_leave_msg();
    smug2->SetIsOpen(1);
  }
  TP->move(SIL_HARBOUR("smugglers2"),M_GO);
  return 1;
}

void opened_leave_msg(){
  write("You leave the cave through the thigh tunnel. "
   "A fresh breeze welcomes you outside.\n");
  show_room(SIL_HARBOUR("smugglers2"),NAME(TP)+" comes out of "
   "the dark opening in the dune suddenly.\n","Somehow you feel "
   "that someone enters the room.\n");
  show_room(this_object(),NAME(TP)+" leaves the chamber through "
   "the tunnel.\n","You hear someone leaving the chamber through "
   "the tunnel.\n",({TP}));
}

void closed_leave_msg(){
  write("You leave the cave through the thigh tunnel. With a "
   "strenuous push, you remove the metal sheet from the "
   "exit and get outside. Ahhhh... finally fresh air again.\n");
  show_room(SIL_HARBOUR("smugglers2"),"You think you've got a "
   "hallicunation - but truly! There's someone coming right out "
   "of the inside of a dune! Looking closer, you see that it's "
   +NAME(TP),"You hear something heavy sliding over the sand. "
   "The noise stops. Now you hear someone breathing.\n");
  show_room(this_object(),NAME(TP)+" leaves the chamber through "
   "the tunnel.\n","You hear someone leaving the chamber through "
   "the tunnel.\n",({TP}));
}

varargs void create()
{
   ::create();
   Set(P_INDOORS,1);
   Set(P_INT_SHORT,"The smugglers den");
   Set(P_INT_LONG,
     "This is the inside of the dune, the smugglers hideout.\n");
   Set(P_INT_MAP,"harbour");
   Set(P_REGION, REGION_CITY|REGION_HARBOUR);
   Set(P_COORDINATES, ({ ({ -260,20,0 }), C_SILVERE }) );
   Set(P_NOWAY_MSG,
     "In an attack of claustropoby, you run against the next wall.\n");
   AddExit("leave",#'leave_cave);
}
