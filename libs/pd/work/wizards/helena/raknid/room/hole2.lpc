#include <std.h>
#include <hole.h>


inherit ROOM;

void create() {
  ::create();
    set_properties(([ "light" : 1, "night light" : 1, "indoors" : 1, "no bump" : 1, "no teleport" : 1, "no gate" : 1 ]));
    set_short("Raknid Hole");
    set_smell("default", "The smell of decaying and rotting flesh is extremely strong here.");
    set_listen("default", "A eerie silence, accompanied by some oddly familiar scratching sounds.");
    set_long("Decaying corpses and further decayed skeletons lay around here, wrapped up tightly in the same %^BOLD%^%^WHITE%^strange sticky white substance%^RESET%^ which continues to cover the floor, clearly now hanging down from the ceiling here as well. Something large and powerful must have done this to so many dead people...Something huge, and something hungry. The only clear exits are further north again, and south.");
    set_items((["walls" : "Still the same roughly dug out tunnel, but now covered with a thick layer of the sticky white substance, except more as strands than a blanket in this part of the tunnel.", "floor" : "Corpses and skeletons litter the floor, showing evidence of a very hungry, very large...something, who most likely lives in this tunnel.", "ceiling" : "Threads of the sticky white subtance hang from the ceiling in drapes.", "corpses" : "These dead bodies lie about, decaying in various stages and wrapped tightly and thicky with the same %^BOLD%^%^WHITE%^strange sticky white substance%^RESET%^ that is on the floor. Probably shouldn't touch them...", "skeletons" : "These skeletons are not all complete, with various body parts or even whole half bodies missing. They all seem rather recent..."]));
    set_exits( (["north" : ROOMS"hole3", "south" : ROOMS"hole1"]) );
}

void init() {
  ::init();
    add_action("touch", "touch");
}

int ring(string str) {
  if(str)
  if(str != "corpses") return 0;
    write("You reach out to touch one of the corpses, and find nothing interesting.");
    return 1;
}
