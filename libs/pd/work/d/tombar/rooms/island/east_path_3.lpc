#include <std.h>
#include <tombar.h>

inherit ROOM;
int open;

void create() {
    ::create();
    set_name("Island of Tombar");
    set_properties(([ "light": 1, "night light": 0 ]));
    set_exits(([
		"northeast" : ROOMS"island/lagoon_1",
		"west" : ROOMS"island/east_path_2",
	]));
	set_long("The path winds into the wooded area.  The ground is littered "
		"with splinters of the trees that once stood proud but now lay "
		"destroyed and rotting.  The occasional bug flies here and there "
		"causing a slight buzzing to break the dreadful silence.");
	set_listen("default", "Flying bugs create a small buzzing sound.");
	set_smell("default", "The smell of death and decay lingers.");
}

