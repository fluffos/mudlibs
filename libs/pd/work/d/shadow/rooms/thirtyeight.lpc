//Path connecting Mountains/lodos to Tenebrae

#include <std.h>
#include <shadow.h>
inherit ROOM;

void create() {
    ::create();
    set_short("Forest Path");
    set_properties( (["light" : 2, "night light" : 1]) );
    set_property("forest", 1);
    set_listen("default", "The ocassional twig snapping can be heard.");
    set_smell("default", "The scent of pine fills the air.");
    set_long("This must be the cursed town of Tenebrae.  The gate can been seen to the south, while the path to the north and east travels into the forest.");
set_exits( (["north" : ROOMS+"thirtyseven", "south" : ROOMS+"gate"]) );
//set_exits( (["north" : ROOMS+"thirtyseven"]) );
    set_items( ([ ({"tree","trees"}) : "The trees are %^GREEN%^dark green%^RESET%^.  They have shed their brown needles all over the ground."
                 ,"needles" : "There are many needles all over the ground."
                 ,"path" : "It seems to be fairly well travelled."
                 ,"roots" : "The roots are large and gnarled."
                 ]) );
}
