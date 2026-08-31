//Tirun Sewers
//By Nightshade

#include <std.h>
#include <sewer.h>
inherit ROOM;

void create() {
    ::create();
    set_short("Entrance to hades");
    set_properties(([ "indoors" : 1, "no teleport" : 1 ]));
    set_listen("default", "%^RESET%^%^RED%^Flames crackle from the pit");
    set_smell("default", "Burning sulfur thickly fills the air.");
    set_long("%^RESET%^%^RED%^A stifiling heat emanates from the pit.\n%^RESET%^"
      "The walls of this place are made up of jagged rocks, the floor uneven "
      "as the \"path\" veers dangerously close to a humongus pit.  The path"
      " seems to circle the pit.  Fighting is everywhere, as demons jump out"
      " of the pit, meeting the awaiting angels.  The pit is directly north"
      " and the path goes both to the east and west.  The entrance to this "
      "level is also to the south.");
    set_exits( (["south" : ROOMS+"bottom"
	,"east" : ROOMS+"bottom2"
	,"west" : ROOMS+"bottom17"
      ]) );
    set_items( ([ ({"rocks", "walls"}) : "The walls and ground are rough, unworked rocks."
	,"pit" : "The pit drops straight down into a fiery inferno."
	,"fire" : "Little jets of fire erupt from the pit, forming demons."
	,"demons" : "Demons are jumping out of the flaming pit fully armed!"
	,"angels" : "The angels are heavily armed, fighting back the horde of demons."
      ]) );
}

void reset() {
    ::reset();
    if(!present("demon", this_object())) {
	new(MOB"demon")->move(this_object());
	if(random(4) == 0)
	    new(MOB"demon")->move(this_object());
    }
    if(!present("angel", this_object())) {
	new(MOB"angel")->move(this_object());
	if(random(4) == 0)
	    new(MOB"angel")->move(this_object());
    }
}
