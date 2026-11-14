#include <money.h>
#include "path.h"
#include <rooms.h>

inherit "std/room";
inherit "/lib/raceportal";

void create() {
	::create();

  /* --- Portal stuff --- */
  SetPortalRace(({"gnome", "halfling"}));
  SetPortalRoom("/d/halfling/common/room/hobbiton/church");
  SetPortalDetail(
({ "A plain wooden bench, the hazyness vanishing on closer view.\n"
 , "The bench is certainly not of the right size for you.\n"
 , "The bench looks as if it could vanish every moment.\n"
 , "The bench gains reality as you look closer - enough reality to even be\n"
   "in two places at once, like a portal.\n"
   "It indeed could be possible to sit down on to it, and perhaps even\n"
   "with other players.\n"
})
                  );
  SetPortalSingle(
({ "Something is definitely wrong, as you can't sit down onto the bench.\n"
 , "You can't sit down on what's not really here.\n"
 , ({ "sits down onto a bench", "leaves" })
 , ({ "stands up from a bench", "arrives" })
 , "sit down onto the bench and at the same time stand up from a bench "
   "within a chapel"
})
                 );
  SetPortalMulti(
({ "Something is definitely wrong, as you can't sit down onto the bench.\n"
 , "You can't sit down on what's not really here.\n"
 , ({ " sits down onto a bench.\n", "Someone leaves.\n" })
 , ({ " and %% sit down onto a bench.", "Some people leave.\n"})
 , ({ " and a group of people sit down onto a bench.\n", "Some people leave.\n"})
 , ({ " stands up from a bench.\n", "Someone arrives.\n"})
 , ({ " and %% stand up from a bench.", "Some people arrive.\n"})
 , ({ " and a group of people stand up from a bench.\n", "Some people arrive.\n"})
 , "You sit down onto the bench and at the same time stand up from a bench "
   "in front of a guardpost.\n\n"
 , "You and %% sit down onto the bench, just to stand up from another.\n"
 , ", %% sit down onto a bench, just to stand up from another.\n"
 , "You and a group of people sit down onto the bench, just to stand up "
   "from another.\n\n"
 , ", a group of people sit down onto the bench, "
   "just to stand up from another.\n\n"
})
                );
  /* --- Portal stuff --- */

	SetIntShort("Stone Bridge");
	SetIntLong(
"You are standing on an old massive stone bridge. There are guardposts "
"at both ends of the bridge but they are deserted and decaying. "
"To the east the road runs into Nightfall City, buildings are standing "
"besides the street which become larger in the distance. "
"To the west the road leads into a forest. The road is in a even "
"worse condition than on the east side of the bridge.\n");
       SetIndoors(0);
       AddItem(OBJ("stick"),REFRESH_REMOVE);
        AddItem("/obj/money",REFRESH_REMOVE,
        (["Money":MONEY_DEMON->CreateMoney((random(10)+5),({"copper"}))]));
       AddExit("east",   "./vill_green");
       AddExit("west","./wild1");

  AddDetail(({"guardposts", "guardpost"}),
 "The guardposts sure had seen better times. The bricks are cracked and\n"
 "mellowing, the concrete even worse. Lichens covers the stone, and grass\n"
 "and flowers grow from the cracks.\n"
 "However, there is bench in front of one of the guardposts which doesn't\n"
 "look decaying - it's rather hazy though.\n"
           );
  AddDetail("grass", 
  "Brave leafs of grass, growing out of the cracks. You even notice\n"
  "some shamrocks in between.\n"
           );
  AddDetail(({"shamrock", "shamrocks"}), 
  "Just the ordinary variant with three leaves.\n"
           );
  AddDetail(({"flower", "flowers"}),
  "Growing with the grass, they make a nice colored patch inmidst\n"
  "the green and grey.\n"
           );

  /* --- Portal Stuff --- */
  AddDetail(({"bench", "hazy bench"}), #'PortalDetail);
  /* --- Portal Stuff --- */

  /* --- Portal Stuff --- */
  AddExit("bench", PortalExit());
  HideExit("bench", HIDE_ALWAYS);

  AddRoomCmd( "sit"
  ,PortalExit(({
    "onto bench","onto the bench","onto hazy bench","down",
    "onto the hazy bench"}))
            );
  /* --- Portal Stuff --- */
}
