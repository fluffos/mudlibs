#include <lca.h>
#include <std.h>

inherit ROOM;
int open;
void create() {
    ::create();
    set_name("the backroom of a church");
    set_short("somewhere deep in an abandoned city");
    set_long("The backroom is quite small compared to that of the hall.  "
      "A table sits in the middle of the room with chairs on all sides "
      "of it.  A book sits on top of the table.  A cabinet is on the south "
      "wall.");
    set_exits(([ 
        "west":PRESENT"10",
        "up":PRESENT"t1",
      ]));
    set_items(([
	"cabinet":"It sits by the south wall and holds the precious "
	"treasures"
	"of the church.",
	"book":"It is old and dusty.  There would be no way to get it.",
      ]));
    set_properties(([ "light":2, "night light":1, "city":1 ]));
}

void reset() {
    ::reset();
    open=0;
}

void init() {
    ::init();
    add_action("open", "open");
}

int open(string str) {
    if(!str || str != "book") return notify_fail("Open what?\n");
    if(open) {
	write("You open the book to find nothing inside.\n");
	message("environment", "Opens the book to find nothing inside.", 
	  environment(this_player()), ({this_player()}) );
	return 1;
    }
    write("You open the book to find a key hidden inside.\n");
    say(this_player()->query_cap_name()+" opens the book and finds a key inside.\n");
    new(OBJ+"steelkey")->move(this_player());
    open=1;
    return 1;
}

