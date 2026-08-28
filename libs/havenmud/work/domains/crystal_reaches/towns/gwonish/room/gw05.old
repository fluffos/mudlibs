#include <lib.h>
#include "../gwonish.h"
inherit LIB_ROOM;

static void create() {
	::create(); SetClimate("sub-tropical");
        SetNewsgroups( ({ "religion.kuthar" }) );
	SetShort("a dismal and quiet part of the swamp");
	SetExits( ([
	  "north" : GWONISH_ROOM "gw09",
	  "east"  : GWONISH_ROOM "gw06",
	  ]) );
	SetItems( ([
	  "mound" : "The mound is small, but could be entered if someone "
	            "felt the need.",
	  ]) );
	SetLong("The swamp path curves here, heading from the north to the "
	        "east. Lying in the center of this clearing is a small mound "
	        "that serves as a burial and disposal area for corpses. "
	        "To the north, the path seems to lead out of the village, while "
	        "to the east it heads deeper into the swamp.");
	SetSmell( ([
	  "default" : "A terrible smell comes from the mound.",
	  ]) );
	SetListen( ([
	  "default" : "It seems quiet enough that even the swamplife avoids "
	              "this area.",
	  ]) );
	SetEnters( ([
	  "mound" : GWONISH_ROOM "cemetery",
	  ]) );
	SetInventory( ([
	  GWONISH_NPC "healer" : 1,
          GWONISH_NPC "shaman" : 1,
	  ]) );
}
