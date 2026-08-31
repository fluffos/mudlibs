#include <std.h>
#include <citrin.h>

inherit ROOM;

void create() {
    ::create();
    set_name("Citrin Forest");
    set_short("a forest");
    set_long("The path is completely covered in darkness.  All light "
      "seems to be absorbed into the surrounding making it "
      "almost impossible to make out what is what.");
    set_items(([
      ]));
    set_exits(([
	"northwest":ROOMS"7",
	"east":ROOMS"9",
      ]));
    set_properties((["light":1,"night light":1,"forest":1,]));
}

void reset() {
    int i;
    ::reset();
    if(random(2)) i = 2;
    else i = 1;
    if(!present("shadow")) {
	while(i--) {
	    new(MON"shadow")->move(this_object());
	}
    }
}

//  Created by Whit
