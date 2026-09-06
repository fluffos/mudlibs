// A long, wide road from the gates to the west toward the palace
// created:       Sonic    [29-May-1997]
// last changed:  Sonic    [01-Jul-1997] Added region/coordinates
//                Tune     [26-Apr-1999] Long, moved post office to
//                                       here too

#include <silvere.h>
#include <properties.h>
#include <coordinates.h>
#include <msgclass.h>
#include <regions.h>
#include <moving.h>
#include <macros.h>
#include <rooms.h>
inherit SILBASEROOM;

int enter_building(string str)
{
   notify_fail("Enter what?\n",NOTIFY_ILL_ARG);
   if(!str) return 0;
   if(!TP)  return 0;
   if(strstr(lower_case(str),"bank")!=-1 ||
      strstr(lower_case(str),"house")!=-1 ||
      strstr(lower_case(str),"building")!=-1)
   {
      msg_write(CMSG_GENERIC,"You enter the bank.\n");
      TP->move(SIL_WEST("wbank"),M_GO,"east");
      return 1;
   }
}

varargs void create()
{
   ::create();
   Set(P_INDOORS,0);
   Set(P_INT_SHORT,"Westroad");
   Set(P_INT_LONG,
     "The imposing establishment on the east side of the road, built almost completely "
     "of stone, easily upstages every other drab building along this lane. A "
     "grand archway invites you into the foyer of the Counting House of Aberfynne, "
     "the premier banking institution of Silvere for the last several hundred years. "
     "Across the way are the much humbler offices of the Silverean Letter and Parcel "
     "Service.\n");


   Set(P_INT_WIZMSG,
      " WEST:  to the postoffice.\n"
      " EAST:  to the bank of silvere.\n"
      " SOUTH: to the mainroad.\n");

   AddVItem(
    ([  P_IDS : ({ "arch", "archway" }),
        P_ADS : "grand",
        P_LONG : "Fine etching and carving embellish the grand entrace to the "
                 "Counting House of Aberfynne. A carved griffon sits, leering, "
                 "at the base of each side of the archway, their blank stone eyes "
                 "examining each potential client. To one side of the archway  is "
                 "affixed a shining brass plaque.\n"
     ]) );

   AddVItem(
    ([  P_IDS : ({ "plaque" }),
        P_ADS : ({ "shining", "brass" }),
        P_LONG : "The plaque reads: 'The Counting House of Aberfynne, "
                 "purveyors of exclusive financial services. Est. in the "
                 "10th year of the reign of Finnae, Lu'meyna of Silvere.' "
                 "Tiny letters under that read: 'No peddlers or Campbells'.\n"
     ]) );


   AddRoomCmd("enter",#'enter_building /*'*/);

   Set(P_INT_MAP,"silvere1");
   Set(P_REGION,REGION_CITY);
   Set(P_COORDINATES, ({ ({ -140,-10,0 }), C_SILVERE }) );

   Set(P_NOWAY_MSG,
"You run silly around. Somehow you have the feeling, that everyone laughs\
 at you.\n");
   AddExit("east",   SIL_WEST("wbank"));
   AddExit("south",  SIL_WEST("wpostroad1"));
   AddExit("west",   SIL_WEST("wpostoffice"));
}
