// This is a simple street to connect the harbour with the city-gates
// created:          Sonic [26-May-1997]
// last changed      Sonic [05-Jul-1997] added region/coordinates

#include <silvere.h>
#include <properties.h>
#include <coordinates.h>
#include <regions.h>
#include <moving.h>
#include <rooms.h>
#include <nightday.h>

inherit HARBOUR_BASEROOM;

varargs void create()
{
   ::create();
   Set(P_INDOORS,0);
   Set(P_INT_SHORT,"A street");
   Set(P_INT_LONG,
    "The road parts here around a large stone sun clock set upon "
    "a pedestal. @@SeasonMsg@@ Directly to the east are the city gates of "
    "Silvere. To the northeast is the house of the harbourmaster, "
    "where you can see a window.\n");

   Set(P_INT_WIZMSG,
      "East: City-Gates, Harbourmaster, Inn\n"
      "West: the docking areas.\n");

   AddWindow( "window",
              "This is a large window in the house of the harbourmaster. "
              "It has a wooden frame and high glass panels.\n",
              SIL_HARBOUR("harbourmaster")
              );

   Set(P_SEASON_MSG,
    ([ WINTER: "Down in the harbour basin, gulls screech loudly, "
               "circling low over the choppy winter water.",
       AUTUMN: "The chill autumn winds blowing up from the harbour "
               "signal that winter is not far off.",
       SPRING: "The light spring breeze blowing up from the harbour basin "
               "tosses your hair about.",
       SUMMER: "The stifling heat is summer is quite bearable here above "
               "the harbour, since a light breeze blows up from the basin."
    ]) );

   Set(P_INT_MAP,"harbour");
   Set(P_REGION, REGION_CITY|REGION_HARBOUR);
   Set(P_COORDINATES, ({ ({ -210,10,0 }), C_SILVERE }) );

   Set(P_NOWAY_MSG,"You run in a wall.\n");
   AddExit("east",SIL_HARBOUR("entrance"));
   AddExit("west",SIL_HARBOUR("street2"));

   AddItem(OBJ("sunclock"), REFRESH_DESTRUCT);
}
