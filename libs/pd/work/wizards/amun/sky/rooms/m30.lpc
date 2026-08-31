#include <std.h>
#include <amun.h>
inherit ROOM;
void create() {
    ::create();
    set_property("indoors", 1);
    set_property("light", 2);
    set("short", "Sky Park");
    set("long","%^BOLD%^%^CYAN%^The walkway continues east and west at this point. The surrounding %^WHITE%^clouds %^CYAN%^constantly shift oddly mimicking different textured walking surfaces. One moment, it looks like a %^WHITE%^milky marble %^CYAN%^and the next, prickly like %^GREEN%^grass%^CYAN%^. A gentle breeze swirls playfully through the room.%^RESET%^");
    set_items( ([ "walkway": "%^BOLD%^%^WHITE%^This s%^RESET%^t%^BOLD%^%^WHITE%^o%^RESET%^n%^BOLD%^%^WHITE%^e walkway is magically places for travelers to walk on.%^RESET%^" ]) );
    set_exits( ([ "east" : SKYROOM "m31", "west" : SKYROOM "m29" ]) );
}
