#include <std.h>
#include <amun.h>
inherit LIGHTNING;
void create() {
    lightning::create ();
    set_property("indoors", 1);
   set_properties( ([ "light":2 ]) );
    set("short", "Sky Temple");
    set("long","The ground suddenly shakes from thunder underneath the clouds.
A small shrub made of pure white clouds is floating to the left,and a small
tree to the right. To the south a animals can be seen walking about the park.
The energy in this park is abundant with the charge of the storm below exciting
all the creatures.");
    set_items( ([ "clouds": "The clouds begin to become thin, allowing
travelers to get sparatic glimpses of lightning below them.", "shrub": "This
shrub is made of a small tuft
of clouds.", "tree" : "This tree is made from a small tuft of clouds.",
"animals" : "These animals roam about the park with excitment.", "creatures" :
"These creatures roam about the park with excitment." ]) );
    set_exits( ([ "north" : SKYROOM "ls_10", "south" : SKYROOM "p4" ]) );
}
