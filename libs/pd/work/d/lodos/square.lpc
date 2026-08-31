#include <lodos.h>
#include <std.h>
inherit ROOM;

void create() {
    object ob;
    ::create();
    set_short("Lodos Town Square");
    set_long("The town square is bustling with citizens, "
      "adventurers and people from all over the land. "
      "A strange steel statue has been errected in the "
      "center of the square. A large temple can to seen "
      "to the east, and shops to the north and south.");
    set_items(([ "temple" : "It is to the east of here.",
	"shops" : "They are to the north and south." ]));
    set_exits(([ "east" : ROOMS"town1",
	"south" : ROOMS"stown1",
	"west" : ROOMS"wroad1",
	"north" : ROOMS"town4"]));
    ob = new(BBOARD);
    ob->set_name("board");
    ob->set_id( ({ "board" }) );
    set_properties((["light" : 2, "no attack" : 1, "no bump" : 1,
	"no magic" : 1, "no steal" : 1, "no castle" : 1 ]));
    ob->set_board_id("lodos_town");
    ob->set_max_posts(75);
    ob->set_edit_ok("inferno");
    ob->set_location(ROOMS"square");
    ob->set("short", "the Lodos Adventurer's board");
    ob->set("long", "Adventurers come here to post.");
}

void reset() {
    ::reset();
    if (!present("statue"))
	new(OBJ"statue")->move(this_object());
    if (!present("bard"))
	new(MOB"bard")->move(this_object());
}
