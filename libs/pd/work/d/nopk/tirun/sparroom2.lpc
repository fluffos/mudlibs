//Made using Room generator by Nightshade
//Storm
#include <std.h>
#include <tirun.h>
inherit ROOM;
void create() {
    ::create();
    set_short("Sparring Hall");
    set_properties( (["light" : 3, "night light" : 2, "indoors" : 1]) );
    set_listen("default", "The sound of weapons clashing can be heard.");
    set_long("The Sparring Hall was built to train in various forms of
fighting.  The room is large, with weapons of all sorts displayed in racks
around the room.  To the north is the main part of the hall.");
    set_exits( (["north" : ROOMS+"sparroom"
              ]) );
    set_items( ([ "racks" : "Different sized frames which weapons sit on."
                 ,"weapons" : "Various weapons from around the realms."
                 ]) );
   new("/d/nopk/tirun/fighter/dummy")->move(this_object());
}
