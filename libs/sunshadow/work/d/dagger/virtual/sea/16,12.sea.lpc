// Chernobog & Titania (4/30/22)
// Wailing Isle

#include <std.h>

inherit ROOM;

int is_virtual() { return 1; }
int is_water() { return 1; }
int is_dockentrance() { return 1; }

void create() {
    set_indoors(1);
    ::create();
    set_light(2);
    set_short("You are on the Dagger Sea.");
    set_property("no teleport",1);
    set_long(
@OLI
        %^BOLD%^You are on the Dagger Sea.%^RESET%^
The dock for the Wailing Isle is here.
OLI
	);
	set_exits(([
        "west" : "/d/dagger/virtual/16,11.sea",
		"east" : "/d/dagger/virtual/16,13.sea",
        "north" : "/d/dagger/virtual/15,12.sea",
        "south" : "/d/dagger/virtual/17,12.sea",
		"dock":"/d/shadow/virtual/sea/wailing_isle.dock"
		]));
	
    set_smell("default","The smells of the city wharf reek of fish.");
	set_listen("default","You can hear the wailing of the wind through the cliffs of the isle.");
}
		
