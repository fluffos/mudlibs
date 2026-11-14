/* 
 * part of the town
 * made by magictcs - 1 jun 97
 * part of the eatcorpse quest - entry to the forest
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

inherit SY_STREET;

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

//*******
// create
//*******
create() {
  ::create();
  SetIntShort("A road");
  SetIntLong(
    "You are on a dirty road. On the ground is a small puddle. A house is "
    "standing north. A huge sign is nailed above the door of it. "
    "South can be seen the main plaza.\n");

  SetIndoors(0);
  SetCoordinates( ({ ({580,560,0}), C_SYKORATH }));
  SetRegion(REGION_CITY);

  SetMap("inner");

  /* details */
  AddVItem( ([
    P_IDS:  ({"road"}),
    P_ADS:  ({"dirty"}),
    P_LONG: #'IntLong ]) );
  AddVItem( ([
    P_IDS:  ({"house"}),
    P_LONG: "The house looks like a really dark ones. The house "
            "seems protected by a strong dark magic.\n" ]) );
  AddVItem( ([
    P_IDS:  ({"sign"}),
    P_ADS:  ({"huge"}),
    P_LONG: "Some letters are painted onto them with red color. "
            "You can read the sign.\n",
    P_READ_MSG: "You read the sign:\n"
            "--> Voodoo Doll Shop <--   (written in big letters)\n"
            "------>   open   <------   (in smaller ones).\n" ]) );
  AddVItem( ([
    P_IDS:  ({"plaza"}),
    P_ADS:  ({"main"}),
    P_LONG: "The way south leads back to it.\n" ]) );
  AddVItem( ([
    P_IDS:  ({"puddle"}),
    P_ADS:  ({"small","wet"}),
    P_LONG: "A small puddle with dirty water. Yes because this is a "
            "dirty road. There is nothing special with this puddle.\n" ]) );
  AddVItem( ([
    P_IDS:  ({"water"}),
    P_ADS:  ({"dirty"}),
    P_LONG: "The water is really dirty.\n" ]) );

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
  AddExit("south","./mainplazanw");

  Set(P_INT_WIZMSG,
    "%^RED%^add details!%^RESET%^\n"
    "then remove this message :)\n"
  );
}

