// part of the town
// made by magictcs - 1 jun 97
// part of the eatcorpse quest - entry to the forest
// TODO: update coords

#include <properties.h>
#include <moving.h>
#include <npc.h>
#include <regions.h>
#include <coordinates.h>
#include <sykorath.h>

inherit BASEROOM;

//*************
// enter puddle
//*************
int enterpuddle(string str) {
  if (!str) return 0;
  if (member(({"puddle","small puddle"}),norm_id(str))!=-1) {
    write("You step into the puddle.\n");
    TP->move(DFOREST("forest25"),M_GO,"leaves into the puddle");
    return 1;
  }
  return 0;
}

//**************************
// drink water (from puddle)
//**************************
int dodrink(string str) {
  string *exp;
  notify_fail("Drink what from where?\n");
  if (!str) return 0;
  exp=explode(str," from ");
  if (sizeof(exp)!=2) return 0;
  if (member(({"water","dirty water"}),exp[0])!=-1)
    if (member(({"puddle","small puddle","wet puddle","dirty puddle"}),
      exp[1])!=-1) {
      write(
      "You go down on your knees to drink "+str+", but then you see the "
      "dirt in the water and you decide to let it be.\n");
      show(NAME+" wants to drink "+str+" but decide better not to do it.\n");
      return 1;
    }
  return 0;
}

create() {
  ::create();
  SetIntShort("A road");
  SetIntLong(
    "You are on a dirty road. On the ground is a small puddle. A house is\n"
    "standing north. A huge sign is nailed above the door of it.\n"
    "South can be seen the main plaza.\n");
  SetIndoors(0);
  SetCoordinates( ({ ({0,0,0}), C_SYKORATH }));
  Set(P_REGION,REGION_CITY);

  /* details */
  AddDetail(({"road","dirty road"}),#'IntLong);
  AddDetail(({"house"}),
    "The house looks like a really dark ones. The house seems protected by\n"
    "a strong dark magic.\n");
  AddDetail(({"sign","huge sign","sign above door","huge sign above door",
    "sign above the door","huge sign above the door"}),
    "Some letters are painted onto them with red color.\n"
    "You can read the sign.\n");
  AddReadMsg(({"sign","huge sign","sign above door","huge sign above door",
    "sign above the door","huge sign above the door"}),
    "You read the sign:\n"
    "--> Voodoo Doll Shop <--   (written in big letters)\n"
    "------>   open   <------   (in smaller ones).\n");
  AddDetail(({"main plaza"}),
    "The way south leads back to it.\n");
  AddDetail(({"puddle","small puddle","wet puddle"}),
    "A small puddle with dirty water. Yes because this is a dirty road.\n"
    "There is nothing special with this puddle.\n");
  AddDetail(({"water","dirty water"}),
    "The water is really dirty.\n");

  /* command */
  AddRoomCmd("enter",#'enterpuddle);
  AddRoomCmd("drink",#'dodrink);

  /* exits */
  AddDoor("north","./voodooshop",
    ([ P_SHORT:    "a wooden door",
       P_LONG:     "A small wooden door, some marks and signs are painted "
                   "onto it.\n",
       P_DOORCODE: "voodooshopdoor",
       P_ADS:      ({"wooden"}),
       P_SUB_DETAILS:  ([
                   ({"mark","marks"}): "The marks are painted in red color.\n",
                   ({"sign","signs"}): "It looks like a pentagram.\n",
                   ({"magic","dark magic"}): "You can just feel it.\n"
                   ])
    ]) );
  AddExit("south","./mainplaza");
}

