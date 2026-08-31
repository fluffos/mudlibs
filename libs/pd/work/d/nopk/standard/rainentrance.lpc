#include <std.h>
#include <sindarii.h>
inherit ROOM;

void init() {
    ::init();
    add_action("enter", "enter");
}

void create() {
    ::create();
    set_property("light", 2);
    set("short", "The north end of West Road");
    set("day long",
	"West Road comes to an end in the forest to the north.  "
	"There is a huge, ancient tree which provides cover to the "
	"entire end area of the road. A hole opens into a hollow inside.  "
	"Honin Road is far to the south.");
    set("night long",
        "Far to the south, Honin Road can be seen. A huge, ancient tree which "
        "provides cover tot he entire end area of the road. West Road ends here, "
        "leaving only south. A hole in the tree opens into a hollow inside. At "
        "the end of West Road is a northern forest.");
    set_items(
	(["tree" : "It must be older than Tirun itself.",
	  "hole" : "You might even be able to enter the tree.",
	  "road" : "This end of the road is shaded by the huge "
	           "tree of mysterious origins.",
	  "foo" : "You're daft.",
	  "bar" : "Had to check that too, eh?"]) );
    set_exits( 
	      (["south" : ROOMS"lorroad2" ]));
}

int enter(string str) {
    if(!str) {
	write("Enter what?\n");
	return 1;
    }
    if(str != "hole" && str != "tree") {
	write("You can't do that here.\n");
	return 1;
    }
    this_player()->move_player(ROOMS"mage_join", "into the tree");
    return 1;
}

