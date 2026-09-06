// A small road, that leads to a sell-only shop
// created:       Sonic    [29-May-1997]
// last changed:  Sonic    [01-Jul-1997]  added region/coordinates
//                Tune     [26-Apr-1998]  description, details

#include <silvere.h>
#include <properties.h>
#include <coordinates.h>
#include <regions.h>
#include <moving.h>
#include <macros.h>
#include <rooms.h>
#include <nightday.h>

inherit SILBASEROOM;

string QueryIntNoise()
{
   if ( ({int})NIGHTDAY->IsDay() )
     return
       "The pleasant cooing of the pigeons nearly drowns out the "
       "loud brassy banging of the nearby smithy.\n";
     else return
       "The occaional creaking of wheels in the night, some distant"
       " voices raised in a tavern brawl, and the constant lapping "
       "of the waves in the harbour.\n";
}

string listen_pigeons()
{
   if ( ({int})NIGHTDAY->IsDay() )
     return
       "The soft cooing creates a quiet lullabye.\n";
   else return
     "The pigeons are asleep for the night. There will "
     "be nothing to hear until morning dawns.\n";
}


string look_pigeons()
{
    if ( ({int})NIGHTDAY->IsDay() )
      return
        "They bob and peck at one another incessantly.\n";
    else return
        "Their heads bob unconsciously, dreaming pleasant "
        "pigeon dreams.\n";
}

string look_buildings()
{
    if ( ({int})NIGHTDAY->IsDay() )
      return
        "The faded fascades, constructed of wood and plaster, "
        "wattle and daub, have without a doubt seen better days.\n";
    else
    {
      switch( ({int})NIGHTDAY->QueryState() )
      {
        case ND_EVENING:
        case ND_TWILIGHT:
         return
          "Dim, dirty latticed windows glow yellow from the "
          "warm fires lit in brick hearths inside the homes "
          "along the grubby lane.\n";
         break;
        case ND_NIGHT:
         return
          "A few solitary flickers in grubby windows indicate "
          "that a person here and there is still awake at this "
          "late hour.\n";
         break;
        case ND_PREDAWN:
         return
          "The dim grey of early morning makes the lane appear "
          "almost two dimensional, flat and unreal.\n";
       }
     }
     return 0;
}

varargs void create()
{
   ::create();
   Set(P_INDOORS,0);

   Set(P_INT_SHORT,"small road");
   Set(P_INT_LONG,
    "The storefront fascades along this lane seem to be not "
    "so well cared for as the more imposing buildings up in "
    "the main street. @@TimeMsg@@ A smaller lane disappers "
    "eastwards into a mass of crooked old cottages. A badly "
    "painted sign hangs lopsidedly on the side of one of the "
    "nearby buildings.\n"
   );

   Set(P_TIME_MSG,
    ([ DAY_DEFAULT_MSG:
        "Pigeons roost among the exposed beams of the houses, "
        "cooing and dropping their distinctive greeting cards "
        "along the walls.",
       NIGHT_DEFAULT_MSG:
        "The lamps are not so plentiful as on the high street, "
        "and the stink from the back garden privies is strong."
    ]) );

   Set(P_INT_WIZMSG,
    " SOUTH: to a small shop and the restaurant.\n"
    " NORTH: back to the road.\n"
    " EAST:  the way to the blacksmith.\n");

   AddVItem(
    ([ P_IDS: ({ "pigeon", "pigeons" }),
       P_NOISE: #'listen_pigeons,
       P_LONG: #'look_pigeons
    ]) );

   AddVItem(
    ([ P_IDS: ({ "buildings", "fascades", "houses" }),
       P_LONG: #'look_buildings /*'*/
    ]) );

   AddVItem(
    ([ P_IDS: "sign",
       P_ADS: ({ "grey", "warped", "weathered" }),
       P_READ_MSG: "SHOPPE THATT WAY ->",
       P_LONG: "The grey board, warped and weathered, "
        "was evidently hung up at some time now long "
        "past. Green, crooked letters, painstakingly "
        "hand-painted, spell out: \n\n"
        "                   SHOPPE THATT WAY -> \n"
    ]) );

  SetIntNoise(#'listen_pigeons /*'*/);

   Set(P_INT_MAP,"silvere1");
   Set(P_REGION,REGION_CITY);
   Set(P_COORDINATES, ({ ({ -150,20,0 }), C_SILVERE }) );

   Set(P_NOWAY_MSG,
"You walk into the wall like an idiot. Somehow you have the feeling, that\
 everyone laughs at you.\n");
   AddExit("east",   SIL_WEST("wsmithroad1"));
   AddExit("north",  SIL_WEST("westroad4"));
   AddExit("south",  SIL_WEST("westshop2"));
}
