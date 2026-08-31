#include <std.h>
#include <citrin.h>

inherit ROOM;

void create() {
    ::create();
    set_name("village streets");
    set_short("walking through villages");
    set_long("The city streets seem abandoned here.  No footprints "
      "of any kind are here.  A small, rundown shack can be seen "
      "sitting to the northwest of the street.  A strange wind "
      "howls tingling the fear of even the bravest of creatures.");
    set_exits((["south":ROOMS"29", "northeast":ROOMS"27","enter":ROOMS"shacks/shack2"]));
    set_properties((["light":1,"night light":1]));
    set_smell("default", "A musty smell lingers in the air.");
}

void reset() {
    ::reset();
    if(!present("shack")) 
	new(OBJ"shack")->move(this_object());
}

