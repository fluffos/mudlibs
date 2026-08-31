//  Created by Whit
#include <std.h>
#include <citrin.h>

inherit ROOM;

void create() {
    ::create();
    set_name("dirt path");
    set_short("an old dirt path");
    set_long("The path leads farther to the east away from the heavy "
      "populized cities.  The wind blows slightly here causing "
      "constant swirling of dust from the road.  Small trees "
      "and tall grass line the sides of the path.");
    set_items(([
	"path":"An old dirt path surrounded by trees and grass.",
	"dust":"The dust makes it hard to see.",
	({"tall grass","grass"}):"The tall grass sways in the breeze.",
	({"trees","small trees"}):"The small trees seems to grow "
	"larger the further east you go."
      ]));
    set_exits(([
	"east":ROOMS"2",
        "west":"/d/forest/nwvforest1/wrooms/room111",
      ]));
   ROOMS"6"->reset();
    set_properties((["light":1,"night light":1,"forest":1,]));
}

void reset() {
    ::reset();
    if(!present("sign")) 
	new(OBJ"sign")->move(this_object());
}
void init() {
    ::init();
    add_action("look", "look");
}

int look(string str) {
    if(str != "hole" && str != "at hole") return 0;
    if(!present("sign"))
	write("There is a hole where the sign was.\n");
    else write("You do not notice that here.\n");
    return 1;
}

