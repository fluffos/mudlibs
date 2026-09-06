#include <room.h>
#include "weddings.h"

#define TP this_player()
inherit "/basic/misc/emote";   

void
create_room(){


    set_light_level(LT_LIGHTS);
    set(ROOM_WD,WD_OUTDOORS);
    set(NO_PK);
    set_short("The wedding reception hall");
    set_long("You are surrounded by the chapel's garden patio \
reception area. The fence must be eight feet tall and covered with \
flowing ivy and dozens of blossoms. Below your feet is a red brick \
tiled dance floor, you notice the band playing a tune off to the side. \
Across from the band there is table set up with dozens of champagne \
flutes, filled with bubbling champagne. On another table there is an \
extraordinary four tiered wedding cake, that practically twinkles in \
the setting sun. This festive setting is the perfect place to celebrate \
a new marriage.");

    set_items(([
	"band":"The band is made up of four violinists, playing finely \
crafted instruments"
      ]));
    set_exits((["out":WEDDING+"chapel"]));
    set_commands((["emote":"emote_cmd"]));  
    add_permanent(WEDDING+"carriage");
}

