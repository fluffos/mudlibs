/* C.A.R.T. Central Station -- Mateese, 10-Dec-95
 *
 * The old Main Station of the C.A.R.T. system, now out of function.
 * See also /d/archwiz/common/room/pirate/dark7.c
 */

#include <config.h>
#include <properties.h>
#include <rooms.h>
#include <nightday.h>
#include <weather.h>

#include "path.h"

inherit "/std/room";

/*-----------------------------------------------------------------------*/

void create()
{
  ::create();

  // Main description
  Set(P_INT_SHORT, "C.A.R.T. Main Station");
  Set(P_INT_LONG,
"This is, or better: was the central station of the C.A.R.T. underground "
"system. Several lines run through this station, but the tracks are now "
"rusted and covered with dirt, and the tunnels cave in after a few steps. "
"Under the ceiling small magic light balls hover and dimly illuminate "
"the hall, during daytime some sunlight shines in through the escalator "
"shafts. The escalators lead up to Central Plaza.\n"
     );
  Set(P_INT_SMELL, "The smell in the room is that of dust, age and stale air.\n");
  Set(P_INT_NOISE, "It is silent except for silent trips of small feet.\n");

  // The lighting depends on the actual sunlight, so pretend that
  // we're an outdoors room.
  // Also let the magic light balls still radiate a bit light.
  // The details for 'sky' and 'heaven' need to be deactivated.
  Set(P_OUTDOORS, 1);
  Set(P_SUNBRIGHT, (30 * MAX_SUNBRIGHT) / 100);
  Set(P_BRIGHT, (10 * MAX_SUNBRIGHT) / 100);
  AddDetail (({ "sky", "heaven" }), "You can't see it here.\n");

  // Exits
  AddExit("up", CITY("vill_green"));
  AddExit("east", CART("yellow1")); HideExit("east", HIDE_ALWAYS);

  // Miscellaneous
  Set(P_CARTROOM, 1);

  // Details
  AddDetail(({"ramp", "escalator", "escalators", "escalator ramp" }),
"The escalators lead upwards to the surface. They are very old and clearly "
"out of function - maybe they are going to be repaired some day. "
"During day time, the shafts give access to dim sunlight, illuminating the "
"hall.\n"
           );
  AddDetail(({ "magic balls", "light balls", "balls"
             , "small magic balls", "small light balls", "small balls"}),
"The balls hover under the ceiling, held by some unseen force.\n"
"The intention of their placing was to illuminate the hall, but as it seems "
"noone thought of refreshing their power reserves so they're hardly glowing "
"anymore.\n"
           );
  AddDetail(({ "magic ball", "light ball", "ball"
             , "small magic ball", "small light ball", "small ball"}),
"The lighting ball hovers under the ceiling, out of reach for you. "
"Its power reserves are nearly exhausted and its glow can hardly be seen.\n"
           );
  AddDetail(({ "track", "tracks", "rail", "rail tracks", "rails" }),
"The tracks run through the hall. In former days, trains were busily running "
"on them, but since the closing of the C.A.R.T. they haven't been in use "
"anymore. The lack of care shows in stains of rust and dirt on them.\n"
           );
  AddDetail( ({"rust", "stains of rust", "rust stains", "rust stain" }),
"Stains of rust are visible everywhere on the tracks.\n"
           );
  AddDetail( "dirt",
"Stones, sand, splinters of wood and other debris, scattered over the tracks.\n"
"Nothing interesting at all.\n"
           );
  AddDetail( ({ "tunnel", "tunnels" }),
"The tracks lead into tunnels under the earth. However, all tunnels but one "
"caved in and can't be passed anymore. Just the tunnel leading east still "
"seems trespassable.\n"
           );

  // Items

  // A partly random number of rats.
  AddItem( ({ MONSTER("rat"), MONSTER("rat"), MONSTER("rat"), 0, 0})
         , REFRESH_DESTRUCT, 0, 5);

  // An old transit map.
  AddItem( "/std/thing", REFRESH_ALWAYS
         , ([ P_SHORT: "a C.A.R.T. transit map"
            , P_LONG:
"This is an old map of the C.A.R.T. network. The writing on it bleached out "
"over the time, but parts of it are still readable.\n"
            , P_HELP_MSG:
"Maps give some information about paths and other connections between "
"locations. Usually, one has to read them.\n"
            , P_READ_MSG:
"Only parts of the map are still readable, the remainder bleached out.\n"
"You read:\n"
               "  -   C. .R T.  ED L  E - -\n"
               "  G asto  ur  - C ntr   S at n   Cra y  astle - Mi  \n"
               "\n"
               "  --   .A.R.T. YELLOW\n"
   "  Cresce    ake - Mirkwo d For              ey - Cent        ion - Beach\n"
               "\n"
               "    - C.A.   . BLUE LINE -\n"
               "  Sun Al  y - Bea\n"
            , P_IDS: ({ "map", "thing" })
            , P_ADS:
              ({"transit", "c.a.r.t.", "c.a.r.t", "cart" })
            , P_WEIGHT: 100
            , P_VALUE: 5
           ])
         );
}

/*-----------------------------------------------------------------------*/
varargs mixed * FilterWeatherData(object client, mixed *data, int newstate)

/* This function is called by the nightday-Server when it notifies
** the players here.
** We intercept it to change the WD_CDESC.
*/

{
  switch(newstate)
  {
    case ND_SUNRISE:
      data[WD_CDESC] =
"A bit of sunlight dimly shines through the escalator shafts.\n";
      break;

    case ND_PRENOON:
    case ND_DAY:
      data[WD_CDESC] =
"The dim reflection of sunlight in the escalator shafts brightens a bit.\n";
      break;

    case ND_POSTNOON:
    case ND_PREFALL:
      data[WD_CDESC] =
"The sunlight shining through the escalator shafts dims.\n";
      break;

    case ND_FALL:
      data[WD_CDESC] = "The escalator shafts fall completely dark.\n";
      break;

    case ND_PRENIGHT:
    case ND_NIGHT:
    case ND_PREDAWN:
    case ND_DAWN:
    default:
      // Return 0 to suppress the change as it's not visible here.
      return 0;
  }
  return ::FilterWeatherData(client, data, newstate);
}

/*************************************************************************/
