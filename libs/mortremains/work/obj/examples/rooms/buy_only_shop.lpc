// This is a replica of a shop in the town of Sigil.
// Use this room as an example for making BUY ONLY SHOPS.
// -Chronos.

#include <mudlib.h>
#define SIGIL "/d/Outer/Sigil/"

inherit BUYONLY_SHOP ;

void create() {
    ::create();
    seteuid(getuid());
    // This defines the stock of the store the first time it's loaded.
    // Every time the store resets, it _might_ start replacing items
    // or adding more to the stock.
    stock = ([
    "shovel" : 2 + random(2),
    "torch" : 10 + random(10),
    "sack"  : 3 + random(10),
    "m8ball" : 1 + random(2),
  ]) ;
    set ("light", 1) ;
    set ("objects", ([ "alluvius" : "/d/Outer/Sigil/monsters/alluvius" ]) );
    set("short", "Ruskin's Antique Shoppe.") ;
    set ("long", @ENDLONG
Ruskin's Antique Shoppe is rumored to be among the oldest of Sigil's 
business district residents.  Ruskin is said to deal in the mystical
arts, and supposedly sells keys to the legendary "portals" of the
multiverse.  These portals are rumored to exist in various places all
over the world, and Ruskin is said to know of them all.

Commands are: list, buy <item>
ENDLONG
    );
    set("shopkeeper", "alluvius") ;
    set("shop_dir", SIGIL+"antiques/") ; // dont forget the trailing /
    set("restock_msg", @ENDMSG
A small boy drop a package off behind the counter.
ENDMSG
    );
    set ("exits", ([
    ]));
    reset();
}
