#include <locations.h>
#include <std.h>
#include <daemons.h>
inherit ROOM;

int cmd_start(string str);

object ob;
void init()
{
    ::init();
    add_action("cmd_start", "start");
}

void create() {
    ::create();
    set_short("Daos' Workroom");
    set_long("%^BOLD%^You have entered the room of Daos.  There is a computer "
      "against the wall, and a window that overlooks all the towns.%^RESET%^");
    set_properties( ([ "indoors" : 1, "no scry" : 1, "no gate" : 1,
	"no teleport" : 1, "light" : 3]) );
    add_exit("/wizards/daos/elite_oil_shop", "north");
    add_exit("/wizards/daos/examples/lair", "lair");
    add_exit("/wizards/daos/examples/square", "square");
    add_exit("/wizards/daos/newbiequestsplash", "newbie");


}
void reset() {
    ::reset();
    if (!present("box"))
	new("/wizards/daos/box")->move(this_object());
    if (!present("portal"))
	new("/wizards/stormbringer/portal")->move(this_object());
}


