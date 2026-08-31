#include <std.h>
#include <vampq.h>
inherit ROOM;
void create() {
    ::create();
    set_properties(([  "no bump" : 1, "light" : 2, "no scry" : 1, "indoors" : 1 ]));
    set("short", "Haunted Mansion");
    set("long", "%^BOLD%^%^BLACK%^It's haunted and it's scary!%^RESET%^");
    set_items((["nothing" : "%^BOLD%^%^BLACK%^It's nothing!%^RESET%^" ]));
    set_exits( ([ "east" : VR"haunted_BP_3", "north" : VR"haunted_BP_5", "northeast" : VR"haunted_BP_6", "northwest" : VR"haunted_BP_4", "west" : VR"haunted_BP_1" ]) );
}
