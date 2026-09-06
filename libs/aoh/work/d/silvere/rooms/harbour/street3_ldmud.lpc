// A small crossing. Roads lead from here to the ports.
// created:          Sonic  [26-May-1997]
// last changed      Sonic  [05-Jul-1997] added region/coordinates
//                   Taurec [09-Oct-1997] added improved roomdesc.
//                   Taurec [08-Jan-1998] added all obvious VItems:)

#include <silvere.h>
#include <properties.h>
#include <coordinates.h>
#include <nightday.h>
#include <regions.h>
#include <moving.h>
#include <rooms.h>
inherit HARBOUR_BASEROOM;

mixed look_lamps();
string look_spots();

varargs void create()
{
   ::create();
   Set(P_INDOORS,0);
   Set(P_INT_SHORT,"A street");
   Set(P_INT_LONG,
    "You are at the shore of a small bay west of Silvere. It protects "
    "the city's harbour from storm and rough tides. The small sandy road that "
    "meanders down from the city splits here. @@TimeMsg@@\n");
   Set(P_TIME_MSG,([
     DAY_DEFAULT_MSG:
       "The view over the bay is fantastic. Ships come and go, entering "
       "the harbour or sailing away into the blue infinity of the ocean. "
       "You catch your breath at the sight of their white sails slowly "
       "dwindling away until they are nothing more than small spots on "
       "the horizon. Two strong towers guard the entrance to the harbour.",
     NIGHT_DEFAULT_MSG:
       "The black water of the harbour reflects the flickering fires "
       "that burn on the two towers, marking the harbour entrance. Far "
       "away in the dark of the ocean to the west there are some lost "
       "spots of light scattered in the night. These must be the "
       "position-lamps of the lonely ships that did "
       "not manage to reach the harbour in time before sunset."
  ]));
  Set(P_INT_WIZMSG,
    "A sign that shows directions to the different docks will be made.\n"
    "East: City-Gates, Harbourmaster, Inn\n"
    "Northwest: quay #1 and the northern defense tower\n"
    "Southwest: quay #2 and the southern defense tower\n");

// ************* VITEMS ***************

   AddVItem(([
     P_IDS: ({"lamps","position-lamps"}),
     P_ADS: ({"lost","scattered"}),
     P_LONG: #'look_lamps
   ]));

   AddVItem(([
     P_IDS: ({"spots"}),
     P_ADS: ({"small","lost"}),
     P_LONG: #'look_spots
   ]));

   AddVItem(([
     P_IDS: ({"road","street"}),
     P_ADS: ({"paved","small","sandy"}),
     P_LONG:
      "A small paved street, covered with sand from the surrounding dunes.\n"
   ]));

   Set(P_INT_MAP,"harbour");
   Set(P_REGION, REGION_CITY|REGION_HARBOUR);
   Set(P_COORDINATES, ({ ({ -230,10,0 }), C_SILVERE }) );
   Set(P_NOWAY_MSG,"You run silly around and nearly fall in the water.\n");

   AddExit("east",      SIL_HARBOUR("street2"));
   AddExit("northwest", SIL_HARBOUR("quay1_1"));
   AddExit("southwest", SIL_HARBOUR("quay2_1"));

   AddItem(OBJ("xalstatue"),REFRESH_NONE);
}

mixed look_lamps()
{
  if (({int})NIGHTDAY->IsDay()) return 0;
  else return
   "You see the lost lights of the lonely ships out there on the huge ocean. "
   "Small are we compared to that watery infinity of the sea of Shamyra...\n";
}

string look_spots()
{
  if (({int})NIGHTDAY->IsDay()) return
   "These little white spots are the sails of ships out there in "
   "the ocean.\n";
  else return
   "These small bright spots are the position-lamps "
   "of the lonely ships out there in the sea of Shamyra, "
   "still not at home in the shelter of their home-harbour.\n";
}
