#include <rain.h>
#include <std.h>
inherit ROOM;

create() {
   ::create();
set_properties( ([ "light" : 3, "night light" : 2, "indoors" :1 ]) );
   set_short("Inside of an elven househould");
   set_long("An elven cottage. "
            "This is a small house with no furnishing. Off in the south"
            "west corner of this cottage there is a pile of hay to sleep "
            "on. There seems to be no one occupying this household.");
   set_exits((["out" : ROOMS"home3"]));
   set_items((["hay" : "A pile of old hay"]));
}
