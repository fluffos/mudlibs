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
    set_smell("default", "The scent of pine fills the air.");
    set_long("The paths all look the same.  It would be very easy to get lost here.  They weave in and out of the pine trees.  A large cliff blocks any attempt to travel north.");
    set_exits( (["northwest" : ROOMS+"fourteen"
             ,"southwest" : ROOMS+"twelve"
             ,"east" : ROOMS+"third"
              ]) );
    set_items( ([ "cliff" : "The sheer cliff would be impossible to climb."
                 ,({"tree","trees"}) : "The trees are %^GREEN%^dark green%^RESET%^.  They have shed their brown needles all over the ground."
                 ,"needles" : "There are many needles all over the ground."
                 ,"path" : "It seems to be fairly well travelled."
                 ]) );
}
