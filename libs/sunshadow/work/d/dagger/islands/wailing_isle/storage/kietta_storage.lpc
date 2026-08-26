// Chernobog & Titania (2/2/22)
// The Wailing Isle - Voodoo Herbalist Inventory

#include <std.h>
#include "../defs.h"
inherit ROOM;

void create(){
    ::create();
    set_properties((["light" : 1, "indoors" : 1]));
    set("short", "voodoo herbalist of the Wailing Isle");
    set("long", "You really shouldn't be here, how rude.");
}

void reset(){
    object storage;
    
    ::reset();
    
    storage = this_object();
    while(!present("pirate's booty tobacco 5")) new("/d/common/obj/misc/tobacco/pirates_booty_tobacco")->move(storage);
    while(!present("pipe 2")) new("/d/common/obj/misc/pipe")->move(storage);
    while(!present("medium-bodied cigar 5")) new("/d/common/obj/misc/tobacco/medium_bodied_cigar")->move(storage);
    while(!present("full-bodied cigar 5")) new("/d/common/obj/misc/tobacco/full_bodied_cigar")->move(storage);
    while(!present("cigarette 5")) new("/d/common/obj/misc/tobacco/cigarette")->move(storage);
    while(!present("case 2")) new("/d/common/obj/misc/tobacco/cigarette_case")->move(storage);
    while(!present("packet of herbs 15")) new("/d/common/obj/brewing/herb_inherit")->move(storage);
    if(!present("herb pouch")) new("/d/common/obj/brewing/herb_pouch")->move(storage);
}

