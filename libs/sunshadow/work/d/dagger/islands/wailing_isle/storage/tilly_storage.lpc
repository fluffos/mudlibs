// Chernobog & Titania (2/2/22)
// The Wailing Isle - Fishmonger Inventory

#include <std.h>
#include "../defs.h"
inherit ROOM;

void create(){
    ::create();
    set("short", "fishmonger of the Wailing Isle");
    set("long", "You really shouldn't be here, how rude.");
}

void reset(){
    object storage;
    
    ::reset();
    
    storage = this_object();
    while(!present("seafood "+roll_dice(4, 6)+"")) new(OBJ"seafood")->move(storage);
}

