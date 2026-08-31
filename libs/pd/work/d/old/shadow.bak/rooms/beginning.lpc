//Made using Room generator by Nightshade
//Path connecting Mountains/lodos to Tenebrae

#include <std.h>
#include <shadow.h>
inherit ROOM;

void create() {
    ::create();
    set_short("Forest Path");
    set_properties( (["light" : 3, "night light" : 2]) );
    set_property("forest", 1);
    set_listen("default", "The ocassional twig snapping can be heard.");
    set_smell("default", "The scent of pine fills the air");
    set_long("The road is softer here than the hard rock path to the northeast.  A few pine trees are scattered across the landscape.  A large cliff blocks any attempt to travel north.  The trail enters the forest to the west, and enters the mountains to the northeast.");
    set_exits( (["west" : ROOMS+"second"
             ,"northeast" : "/d/lodos/mount4"
              ]) );
    set_items( ([ "cliff" : "The sheer cliff would be impossible to climb."
                 ,({"tree","trees"}) : "The trees are dark green.  They have shed their brown needles all over the ground."
                 ,"needles" : "There are many needles all over the ground."
                 ,"path" : "It seems to be fairly well travelled."
                 ]) );
}

void reset() {
    ::reset();
    if(!present("sign",this_object()))
        new(OBJ+"forestsign")->move(this_object());
}
