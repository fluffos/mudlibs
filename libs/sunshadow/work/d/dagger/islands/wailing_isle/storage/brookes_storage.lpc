// Chernobog & Titania (3/25/22)
// The Wailing Isle - Brookes Secret Inventory

#include <std.h>
#include "../defs.h"
inherit ROOM;

void create(){
    ::create();
    set_properties((["light" : 1, "indoors" : 1]));
    set("short", "Brookes secret inventory of the Wailing Isle");
    set("long", "You really shouldn't be here, how rude.");
}

void reset(){
    object brookes, item;
    
    ::reset();
    
    brookes = this_object();
    while(!present("metal 3")){
        item = new("/std/obj/metal");
        item->move(brookes);
        item->set_metal_quality(10);
    }
    while(!present("cloth 3")){
        item = new("/std/obj/cloth");
        item->move(brookes);
        item->set_cloth_quality(10);
    }
    while(!present("wood 3")){
        item = new("/std/obj/wood");
        item->move(brookes);
        item->set_wood_quality(10);
    }
}

