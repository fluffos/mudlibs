#include "path.h"
#include <properties.h>
#include <rooms.h>

inherit "std/room";

#if 0
try_down() {
  write(
"As you want to step on the old escalator, you notice that someone must "
"have turned it off. Anyway, a barrier is blocking your way further down. "
"You decide not to go down. This C.A.R.T. Station is obviously closed.\n");
  return 1;
}
#endif

create() {
  ::create();
  SetIntShort("Central Plaza");
  SetIntLong(
"You are on the central plaza of the city. Sunset Boulevard joins Main Street "
"from the south. Pieces of paper are blown over the concrete floor, where grass "
"and flowers are growing out of cracks. The wind is howling through the huge "
"buildings towering around the plaza.\n\n"
"The news board is HERE. It contains more than one group - to see the "
"group names, use list groups. All the groups listed here are read/write "
"for players, so please give us your feedback! Type help board for more "
"info on using the board.\n");
  AddDetail(({"ramp","escalator ramp"}),
  "It looks very old and is clearly out of function. Maybe it is going to be\n"
  "repaired some day.\n"
  "Down, at the end of the ramp, dim light can be seen.\n");
  AddDetail(({"step","steps"}),
"The steps are clean and tidy. Someone seems to take care about them.\n");
  AddDetail("people",
  "Strange folk... Wonder what they are doing on this lonely place?\n");
  AddDetail(({"tents","tent"}),
"In fact, it seems as if there were several tents.\n");
  AddDetail("structure",
  "Wooden beams which are nailed together. It looks a bit unsafe.\n");
  AddDetail(({"buildings","building","destruction"}),
"There are huge buildings around the plaza, with monstrous entrance portals "
"and tell of a prosperous age. Many windows are broken, the broken glass "
"gnashes under your feet. There is only one undestructed building to be seen: "
"The church.\n");
  AddDetail(({"portal","portals"}),
  "The portal of the church is wonderful: White and red sandstones changes "
"with small windows. The other portals are mostly ruins. Perhaps someone "
"will restore the once beautiful sight of Nightfall City soon.\n");
  AddDetail(({"windows","window","holes","hole"}),
  "The most windows around are broken. The only ones left in whole are those "
"of the city church.\n");
  AddDetail(({"doors","door","heavy door","heavy doors","wooden door",
    "wooden doors","heavy wooden doors","heavy wooden door"}),
"They are very heavy wooden doors which are battered badly and lying down on "
"the floor. You can hardly see anything in the dim interior of the cathedral.\n");
  AddDetail("sign",
"There is white lettering on a blue background, and besides a red and yellow "
"stripe there are also the words 'Central Plaza'. The sign is really made of "
"glass and through a hole you can see an empty light socket inside.\n");
  AddDetail("socket","It is just an old light socket.\n");
AddDetail("interior","You'll have to go inside the cathedral to see more.\n");
  AddDetail(({"flag","flagpole"}),
"The pole is old and rusted. The flag, however, seems to be undamaged. It "
"shows the symbol of Nightfall, a symbolized half red sun over green fields.\n");
AddDetail("symbol","It is the red sun over green fields!\n");
  AddDetail("grass","It's green");
  AddDetail("glass","Some glass lies on the ground: broken.\n");
  AddDetail(({"floor","ground"}),"It is covered with grass and glass.\n");
  AddDetail(({"flower","flowers"}),"They are growing between the stones.\n");
  AddDetail(({"plaza","central plaza"}),"The midth of the town.\n");
  AddDetail(({"crack","cracks"}),"The are cracks all over the ground.\n");
  AddDetail(({"paper","pieces of paper","pieces","piece","piece of paper"}),
  "The wind blows the paper all over the plaza.\n");
  AddDetail(({"center","center of the plaza","center of plaze"}),
"There's a flagpole in the center of the plaza.\n");
  AddDetail(({"city","town","nightfall-city","nightfall city","capital",
    "nf-city","nf city"}),
"Nightfall City is the capital of the world and you are just in front\n"
"of its wonderful church.\n");
  AddDetail(({"church","city church","church of creation"}),
  "You wonder how it can be, but the church is still intact. An enormous "
"building made out of red and white sandstone. The rocks it is built of are "
"large but fit perfectly one into the other. They make the front of the church "
"look like covered with a huge ornament. The doors are under a huge gateway "
"built out of changing red/white smaller blocks. It builds something like "
"a 'V' that stands upside down. There are small holes in the front that are "
"filled with coloured glass. The sight is fascinating. You feel that this "
"church saw generations of adventurers come and go. It is for sure the oldest, "
"but also one of the most fascinating buildings of Nightfall. There is none "
"who stayed here for longer who doesn't know it.\n"
  );
  SetExplorable(({"church","city church","church of creation"}));
  AddDetail(({"blocks","block","rock","rocks","sandstone"}),
  "The blocks are made of sandstone of different colors. Some are red, some "
"are white.\n");
  SetIndoors(0);
  AddExit("north","./church");
  AddExit("south","./boul1");
  AddExit("west","./hump");
  AddExit("east","./vill_track");
  AddExit("down", CART("central"));
  AddItem(OBJ("asimov"), REFRESH_HOME);
  // BEGONE AddItem(LADY,REFRESH_DESTRUCT);
  AddItem(OBJ("sunclock"), REFRESH_HOME);
  AddItem(OBJ("parksign"),REFRESH_HOME);
  AddItem( "/std/board", REFRESH_HOME,
          ([ P_SHORT : "the central board",
             P_LONG  : "This is the central board.\n",
             "Groups" : ({ "players", "ideas\\.*", "flames" })
            ]) );
}
