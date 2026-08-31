#include <std.h>
#include <rain.h>
inherit ROOM;

create() {
   ::create();
set_properties( ([ "light" : 3, "night light" : 2, "indoors" :1 ]) );
   set_short("Inside a hut");
   set_long("A small wooden hut. "
            "This hut seems as if no one has entered for a while. "
            "There is a dusty old bed off in the corner and some "
            "burnt ashes in the fireplace. There is an old tunic lying "
            "in the corner.");
   set_items((["bed" : "This bed is a small bed with much dirt and dust "
               "covering it",
               "ashes" : "These ashes have blown all over the house whil"
               "e the owner was not here",
               "tunic" : "It seemed the owner of this house left behind "
               "a tunic"]));
   set_exits((["out" : ROOMS"home4"]));
}
