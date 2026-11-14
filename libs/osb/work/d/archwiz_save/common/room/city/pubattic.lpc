/*   Pub Attic  (Mateese, 22-Nov-95)
 *
 * This is intended to be the default home/login room for Oglons, along
 * with a portal to Mandukam.
 * This is in fact an example on how to use /lib/raceportal.
 */

#include "path.h"
#include <config.h>
#include <rooms.h>
#include <moving.h>

inherit "/std/room";
inherit "/lib/raceportal";

#define TP this_player()
#define THIS this_object()

#define FAIRYOBJ "/d/woodland/common/newbiestart/loadfairy"
#define FAIRYLOG "/d/woodland/common/newbiestart/fairy_log"

/*------------------------------------------------------------------------*/
void create() {

  ::create();  /* Initialize the /std/room */

  /* --- Portal stuff --- */
  SetPortalRace("oglon");
  SetPortalRoom("/d/woodland/common/mandukam/church");
  SetPortalDetail(
({ "The mirror image just reflects the dusty room.\n"
 , "You see yourself, standing in a dim and dusty room.\n"
 , "The mirror image is pitch dark, you can't even see yourself.\n"
 ,"Surprisingly you don't see your reflection in the mirror, but instead the\n"
  "view over a square with a cat-shaped statue in midst of it.\n"
  "It appears quite real, as if this mirror were in fact a portal\n"
  "between here and there.\n"
  "It indeed could be possible to step into the mirror, and perhaps even\n"
  "with other players.\n"
})
                  );
  SetPortalSingle(
({ "Something is definitely wrong, as you can't enter the mirror.\n"
 , "You can't use the mirror right now, as it leads nowhere.\n"
 , ({ "steps into the mirror", "leaves" })
 , ({ "steps out of the mirror", "arrives" })
 , "step into the mirror and find yourself emerging out of the trunk "
   "of a tree"
})
                 );
  SetPortalMulti(
({ "Something is definitely wrong, as you can't enter the mirror.\n"
 , "You can't use the mirror right now, as it leads nowhere.\n"
 , ({ " steps into the mirror.\n", "Someone leaves.\n" })
 , ({ " leads %% into the mirror.", "Some people leave.\n"})
 , ({ " leads a group of people into the mirror.\n", "Some people leave.\n"})
 , ({ " steps out of the mirror.\n", "Someone arrives.\n"})
 , ({ " leads %% out of the mirror.", "Some people arrive.\n"})
 , ({ " leads a group of people out of the mirror.\n", "Some people arrive.\n"})
 , "You step into the mirror and find yourself emerging "
   "out of the trunk of a tree.\n\n"
 , "You lead %% through the mirror and out of the statue.\n"
 , " leads %% through the mirror and out on an open place.\n"
 , "You lead a group of people through the mirror and out of the statue.\n\n"
 , " leads a group of people and you through the mirror and out on "
   "an open place.\n\n"
})
                );
  /* --- Portal stuff --- */

  SetIntShort("Pub Attic");

  SetIntLong(
"A bright, happy room.  Its ceiling is also the roof of the house.. well "
"of course, what, did you expect the ceiling to be the basement?  Its "
"shaped like something, and its all regal you see, so anyways, theres "
"this pub see, and theres a rectangle, and its all good.\n"
            );

  AddExit("down", "./pub");

  /* --- Portal Stuff --- */
  AddExit("mirror", PortalExit());
  HideExit("mirror", HIDE_ALWAYS);

  AddRoomCmd( ({"enter", "step"})
            , PortalExit(({"into the mirror", "in to the portal"}))
            );
  /* --- Portal Stuff --- */

  SetIntNoise(
"From below the voices of cheery people and clinging glasses sound through "
"the floor and the stairway.\n"
             );

  AddDetail(({"stairway", "staircase"}),
"The stairway, wooden and dimly lit as the attic itself, leads in a slow "
"curve down to the main room of the pub.\n"
           );
  AddDetail("roof", 
"The roof is made up of wooden planks nailed onto beams. Some kind of color "
"has been applied onto them, and though being old, it still seals the cleaves "
"against rain and wind.\n"
           );
  AddDetail(({"beams", "beam" }),
"Sturdy beams, cut from trees who once happily faltered in the winds. "
"Now they just serve to hold the roof's planks.\n"
           );
  AddDetail(({"planks", "plank" }),
"Sturdy beams, cut from trees who once happily faltered in the winds. "
"Now they just serve to hold the roof's planks.\n"
           );
  AddDetail("floor", 
"The planks of the floor are covered with noticeable layers of dust, here "
"and there marked with footprints.\n"
           );
  AddDetail("dust", 
"The dust lies on the floor and the few items here. Besides being dusty, "
"it's actually rather boring.\n"
           );
  AddDetail(({"footprint", "footprints"}),
"The footprints lead on various paths through the room, with the most "
"prominent path connecting the stairway and the frame beside it.\n"
           );
  AddDetail(({"item","items"}),
"Wrapped in worn blankets as protection against the dust, various outranged "
"items of furniture are put into store here. Lifting the blankets reveals "
"nothing of further interest.\n"
           );
  AddDetail(({"rectangle", "white rectangle"}),
"On closer examination the rectangle becomes recognizable as the wooden "
"frame of a mirror. Surprisingly it is not covered with cloth like the "
"other items here.\n"
"The glass of this man-sized mirror is still intact, the frame is decorated "
"with carvings of eagles and largish cats.\n"
           );
  AddDetail(({"frame","white frame"}),
"Dusty, but surprisingly not covered with cloth like the other items, "
"the frame reveals itself as a man-sized mirror, with the glass intact. "
"The frame is decorated with carvings of eagles and largish cats.\n"
           );
  AddDetail(({"carvings", "carving", "eagle", "eagles", "cat", "cats"}),
"The carvings are intricately made, depicting the animals in various "
"situations of life - hunting, sleeping, flirting, fighting.\n"
"A closer inspection reveals that the depicted figures are neither eagles "
"nor cats, but an animal combining the features of both.\n"
           );

  /* --- Portal Stuff --- */
  AddDetail(({"glass", "portal", "mirror", "image", "mirror image", "view"})
           , #'PortalDetail);
  /* --- Portal Stuff --- */
}

/*------------------------------------------------------------------------*/
/* Newbie oglons are given a newbiefairy as companion.
 * It is created one second after entry, as cloning the autoobjects
 * on relogin happens after the call to notify_enter().
 */

private void give_loadfairy (object who)
{
  object ob;
  mixed  tmp;

  if (!who) return;
  if (present("loadfairy",who))
    return;

  tmp = catch(ob = clone_object(FAIRYOBJ));         
  if (tmp || !ob) 
    {
      tell_object(who, "Error: Cannot clone your companion.\n");
      return;
    }
  if (ME_OK == ob->move(who, M_SILENT)
   || (environment(who) && ME_OK == ob->move(environment(who), M_SILENT))
     )
    return;

  tell_object(who,"Error: Cannot initialize your companion.\n");
  ob->remove();
}

void notify_enter(mixed from, int method, mixed extra) 
{
  object who;

  who = previous_object();

/*
 * I commented the giving of fairies out, as woodland is not existing.
 * Sonic, 01-Jun-1997]
  if ((who->QueryIsPlayer())&&(who->QueryLevel()<=1)) 
    call_out(#'give_loadfairy, 1, who);
*/

  return (::notify_enter(from, method, extra));
}

/*========================================================================*/
