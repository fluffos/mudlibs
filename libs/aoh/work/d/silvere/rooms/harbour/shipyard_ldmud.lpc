// The shipyard of Silvere
// created:   Taurec [11-June-1997]
// last changed: Sonic [05-Jul-1997] added regions/coordinates

#include <silvere.h>
#include <properties.h>
#include <coordinates.h>
#include <msgclass.h>
#include <regions.h>
#include <macros.h>
#include <rooms.h>
inherit BASEROOM;

string check_king()
{
   msg_room(TO,CMSG_ROOM,
      CAP(NAME(TP))+" asks one of the workers about the Lu'meyn.\n",
      ({TP}) );
   return
      "You stop one of the workers and ask him about the Lu'meyn. The "
      "man turns at you, frustrated that you disturbed him. Then he "
      "says:\n"
      "Well, the Lu'meyn is our ruler. He is in the palace in the "
      "center of Silvere. That's all I can tell you. And now get the "
      "hell out of my way and let me do my work.\n";
}

varargs void create()
{
   ::create();
   Set(P_INDOORS,1);
   Set(P_INT_SHORT,"The shipyard of Silvere");
   Set(P_INT_WIZMSG,
      "This is a shipyard, new ships are built here and are moved over "
      "some rails into the water south.\n"
      "A rope may be retrieved here, later.\n"
      " South: back to the quay.\n");

   Set(P_INT_LONG,
      "You are in the shipyard of Silvere. Big piles of planks, ropes, "
      "canvas and nails are lying around everywhere. Cauldrons full of "
      "hot tar spread a strong smell. There are several frames of yet "
      "unfinished ships to see and lots of workers buzz around hectically "
      "to fulfill what the Lu'meyn instructed them to do.\n");

  Set(P_INT_SMELL,"You smell a mixture of odors coming from wood, tar "
                  "and the sweat of hard working men.\n");
  Set(P_INT_NOISE,"You hear a big noise coming from knocking hammers, saws, "
                  "loudly shouting men and mistakenly dropped planks all "
                  "around you.\n");

   AddDetail(({"frames","frame","ships","ship","skeletons"}),
     "Once these ships are finished and launched into the sea, they will "
     "roam the oceans and bring many brave adventurers to new, unknown "
     "coasts. These mere skeletons of ships already radiate a certain "
     "elegance and pride.\n");
   AddDetail("pile","Planks, ropes, canvas, nails everywhere.\n");
   AddDetail(({"tar","cauldrons","cauldron"}),
     "This hot, steaming tar is used to close the gaps between the planks of "
     "the ships. Its smell is intense, and you don't feel like to take "
     "a hot bath in these cauldrons yet ;)\n");
   AddSmell("tar","Bah! This smells really ugly!\n");
   AddDetail("nails","These are really big, bad, awesome nails.\n");
   AddDetail(({"planks","plank"}),
     "Long planks, used for the ships construction. You wonder how "
     "many trees had to die for that.\n");
   AddDetail(({"ropes","rope"}),
     "Huge coils of rope are piled here. Perhaps you could just try "
     "to grab one, noone would remark it in all this hectic activity.\n");
   AddDetail("workers",
     "They are all tall, powerful men, working hard to complete the "
     "ships. Some of them curse you savagely because you prevent "
     "them from working by just standing around and doing nothing.\n");
   AddDetail("lu'meyn",#'check_king);

   Set(P_INT_MAP,"harbour");
   Set(P_REGION, REGION_CITY|REGION_HARBOUR);
   Set(P_COORDINATES, ({ ({ -240,-10,0 }), C_SILVERE }) );
   Set(P_NOWAY_MSG,
"You run silly around and cause some chaos, as you come into the "
"path of some of the workers.\n");
  AddExit("south",SIL_HARBOUR("quay1_1"));
}
