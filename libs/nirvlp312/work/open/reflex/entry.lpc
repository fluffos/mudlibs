#include "/players/reflex/lib/lib.h"
inherit ROOM;

void create() {
::create();
    set_short("Hallway to the Nirvana Council Chamber");
    set_long(
	"This is a lengthy hallway leading north to the main council\n"+
	"chamber.  Along the east wall are numerous scenes depicting\n"+
	"famous events in Nirvana history.  On the west wall are written\n"+
	"the laws of the land, in their entirety, describing the rules\n"+
	"and conduct of the world of Nirvana.  The floor is made of\n"+
	"Italian marble, and the walls are trimmed in the finest oak,\n"+
	"lined with gold.  There are torches lit with mystic "+BLU+BOLD+
	"blue flames\n"+NORM+
	"lining the pathway to the council chamber.  You can leave the\n"+
	"chamber through the doorway to the south.\n");
    set_items(([
        "wall" :
        "Would you like to look at the "+BOLD+"east wall"+NORM+" or "+BOLD+
	"west wall"+NORM+"?\n",
	"east wall" :
	"There are many paintings lining this wall, dating from creation\n"+
	"all the way to the present.  Famous battles, legends and Gods are\n"+
	"all shown here.\n",
	"west wall" :
	"Along this wall you see all the regulations in the land of\n"+
	"Nirvana.  You can type 'help' to read them.\n",
	"floor" :
	"The finest Italian marble, it makes a clicking sound when you walk.\n",
	"torches" :
	"These wrought iron torches glow with a mystical blue flame,\n"+
	"strangly they are not hot to the touch.\n",
        ]));
    set_smells(([
	"default" :
	"You smell nothing in paticuliar.\n",
	]));
    set_sounds(([
	"default" :
	"You only hear the clicking of your boots on the marble.\n",
	]));
    set_chat_frequency(80);
    set_exits(([
        "north" : "/players/reflex/realms/council/chamber",
        "south" : "/room/",
        ]));
    set_light(1);
    replace_program(ROOM);
}
