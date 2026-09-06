// A rather small road, leading north to south
// created:       Sonic    [08-Jun-1997]
// last changed:  Sonic    [01-Jul-1997]  added regions/coordinates

#include <silvere.h>
#include <properties.h>
#include <coordinates.h>
#include <nightday.h>
#include <regions.h>
#include <moving.h>
#include <macros.h>
#include <rooms.h>
inherit SILBASEROOM;

int enter_healer(string str)
{
   notify_fail("Enter what?\n",NOTIFY_ILL_ARG);
   if(!str) return 0;
   if(!TP)  return 0;
   if(strstr(lower_case(str),"healer")!=-1 ||
      strstr(lower_case(str),"house")!=-1 ||
      strstr(lower_case(str),"building")!=-1)
   {
      write("You enter the house of the healer.\n");
      TP->move(SIL_WEST("whealer"),M_GO,"north");
      return 1;
   }
}

varargs void create()
{
   ::create();
   Set(P_INDOORS,0);
   Set(P_INT_SHORT,"Before the house of the healer");
   Set(P_INT_LONG,
  "The great city wall runs parallel to the west side of this street."
  "To the north is a small house. Bunches of dried herbs are hanging "
  "in the windows.\n");

   Set(P_INT_WIZMSG,
" NORTH: (or ENTER) into the house of the healer.\n\
 SOUTH: to the mainroad.\n");

   AddVItem(
	    ([ P_IDS: ({ "wall" }),
	    P_ADS: ({ "city", "great" }),
	    P_LONG:
	    "The city's wall has been built from huge blocks of grey "
	    "stone. It looks very solid, and by no means easily breachable. "
	    "Guards are patrolling on top of it, keeping an eye on the "
	    "harbour and the countryside surrounding the city.\n"
	     ]) );

   AddDetail( "guards", "They are patrolling on the city wall.\n" );

   AddVItem(
	    ([ P_IDS: ({ "stone", "blocks", "block" }),
	    P_ADS: ({ "grey", "huge", "massive" }),
	    P_LONG:
	    "The city wall has been built from massive blocks of grey "
	    "stone.\n"
	     ]) );

   AddDetail( ({"harbour", "countryside"}), "You can't see any of it. "
              "The wall blocks your sight.\n" );

   AddVItem(
       ([ P_IDS: ({ "house" }),
	    P_ADS: ({ "small" }),
	    P_LONG:
	    "North of you is a small house. Behind the windows, you can "
	    "see bunches of dried herbs. A faint, sweetly smell emanates "
	    "from the house, noticeable even from this distance.\n"
	    ]) );

   AddDetail( ({"window", "windows"}), "Behind the windows of the house "
           "you glimpse bundles of herbs which have been hung there to dry.\n");

   AddVItem(
       ([ P_IDS: ({"herbs", "bunches", "bundles"}),
	    P_ADS: ({"dried"}),
	    P_LONG:
	    "Bundled herbs can be seen hanging behind the windows.\n",
	    P_SMELL:
	    "The herbs are inside, and since the windows are closed, you "
	    "can't smell them.\n"
	     ]) );
   AddVItem(
       ([ P_IDS: ({"street"}),
	    P_ADS: ({"small"}),
	    P_LONG:
	    "You are on a small street branching north off Westway. The "
	    "street is paved with cobblestones.\n",
	    ]) );

   AddDetail( "cobblestones", "This small street is paved with cobblestones "
	      "instead of the large flagstones you saw on Westway.\n" );




   AddRoomCmd("enter",#'enter_healer /*'*/);

   Set(P_INT_MAP,"silvere1");
   Set(P_REGION,REGION_CITY);
   Set(P_COORDINATES, ({ ({ -180,0,0 }), C_SILVERE }) );

   Set(P_NOWAY_MSG,
"You walk into the wall like an idiot. Somehow you have the feeling that\
 everyone laughs at you.\n");
   AddExit("north",SIL_WEST("whealer"));
   AddExit("south",SIL_WEST("westroad1"));
}
