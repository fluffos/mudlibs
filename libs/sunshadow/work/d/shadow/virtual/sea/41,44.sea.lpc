// sea connection for Serekii

#include <std.h>

inherit ROOM;

int is_virtual() { return 1; }
int is_water() { return 1; }
int is_dockentrance() { return 1; }

void create(){
    set_indoors(1);
    ::create();
    set_light(2);
    set_short("off the coast of an island");
    set_property("no teleport",1);
    set_long(
@OLI
	%^BOLD%^You are on the Saakrune Sea.%^RESET%^
You see the dock leading to Serakii here.
OLI
	);
	set_exits(([
		"north":"/d/shadow/virtual/40,44.sea",
		"south":"/d/shadow/virtual/42,44.sea",
		"east":"/d/shadow/virtual/41,45.sea",
        "west":"/d/shadow/virtual/41,43.sea",
		"dock":"/d/shadow/virtual/sea/serakii.dock"
		]));
	
	set_smell("default","You can smell the sea air.");
	set_listen("default","You can hear the crashing waves along the coast.");
}
		
