#include <rain.h>
#include <std.h>
inherit ROOM;

  void create() {
   ::create();
set_properties( ([ "light" : 3, "night light" : 1, "town" :1 ]) );
    set_short("Merchant path");
    set_long("This is the merchant path which leads to all the shops. "
             "There are some traders and merchants travel along "
             "these roads sometimes. The path continues west.");
    set_exits((["west": ROOMS"mpath2",
                "east": ROOMS"village3"]));

}
