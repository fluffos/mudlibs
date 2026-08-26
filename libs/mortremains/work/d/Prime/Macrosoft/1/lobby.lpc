
#include "macrosoft.h"

inherit MS_STD_ROOM;

void create() {
    ::create();
    set("short", "Macrosoft Corporate Office Lobby");
    set("long", wrap(
	"You are standing in the main lobby of the corporate office "+
	"of the Macrosoft Corporation, the single largest and "+
	"(according to rumor) most corrupt and depraved corporation "+
	"in the known world. The ceiling of this room reaches several "+
	"dozen feet up, and is covered by a vast mural. The polished "+
	"granite floors are engraved with a forty-foot Macrosoft "+
	"corporate logo."
      ));
    set("exits", ([
      "east" : FLOOR_1("restrooms"),
      "north" : FLOOR_1("frontdesk"),
      "south" : FLOOR_1("entrance"),
    ]) );
    set("item_desc", ([
    "logo" : wrap("It appears to be a massive stylized bronze hand "+
        "making some kind of one fingered gesture."),
    "mural" : wrap("It seems to contain hundreds of images of the "+
        "same unassuming, bespectacled man in all manner of angelic "+
        "poses. Most of the images have wings, and some appear to be "+
        "performing miracles."),
    ]) );
}

/* EOF */
