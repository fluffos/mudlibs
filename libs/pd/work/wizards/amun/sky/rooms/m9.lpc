#include <std.h>
#include <amun.h>
inherit ROOM;
void create() {
    ::create();
    set_property("indoors", 1);
    set_property("light", 2);
    set("short", "Sky Park");
    set("long","%^BOLD%^%^CYAN%^As the path continues north, the ground begins to feel damp. It has been said that peacefulness has risen through the boots of the many travelers that have passed through this area. To the north, a bottomless %^BLUE%^w%^CYAN%^a%^BLUE%^t%^CYAN%^e%^BLUE%^rf%^CYAN%^a%^BLUE%^ll%^CYAN%^ is visible, beckoning visitors to continue along the trail.%^RESET%^");
    set_items( ([ "ground": "%^BOLD%^%^WHITE%^The ground is damp from a mist that comes from the north.%^RESET%^", "waterfall": "%^BOLD%^%^BLUE%^A %^BLUE%^w%^CYAN%^a%^BLUE%^t%^CYAN%^e%^BLUE%^rf%^CYAN%^a%^BLUE%^ll%^CYAN%^ can slightly be seen towards the north.%^RESET%^" ]) );
    set_exits( ([ "west" : SKYROOM "m8", "east" : SKYROOM "m10", "north" : SKYROOM "m17" ]) );
}
