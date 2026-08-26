// Chernobog & Titania (2/2/22)
// The Wailing Isle - General Store Inventory

#include <std.h>
#include "../defs.h"
inherit ROOM;

void create(){
    ::create();
    set_properties((["light" : 1, "indoors" : 1]));
    set("short", "general store of the Wailing Isle");
    set("long", "You really shouldn't be here, how rude.");
}

void reset(){
    object storage;
    
    ::reset();
    
    storage = this_object();
    while(!present("canvas 2")) new("/d/common/obj/misc/canvas")->move(storage);
    while(!present("large sack 2")) new("/d/common/obj/misc/sack")->move(storage);
    while(!present("rope 6")) new("/d/common/obj/misc/rope")->move(storage);
    while(!present("flint")) new("/d/common/obj/misc/flint")->move(storage);
    while(!present("bullseye")) new("/d/common/obj/misc/bullseye")->move(storage);
    while(!present("reg_oil 3")) new("/d/common/obj/misc/oil")->move(storage);
    while(!present("deck")) new("/d/shadow/obj/misc/deckofcards")->move(storage);
    while(!present("eyepatch")) new("/d/common/obj/misc/eyepatch")->move(storage);
    while(!present("bandage 3")) new("/d/common/obj/misc/bandage")->move(storage);
    while(!present("bloodshard 3")) new("/d/common/obj/special/bloodshard")->move(storage);
    while(!present("fishing net 10")) new(OBJ"fishing_net")->move(storage);
}

