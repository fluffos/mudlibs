#include <std.h>
#include <amun.h>
inherit ROOM;
void create() {
    ::create();
    set_property("indoors", 1);
    set_property("light", 2);
    set("short", "Sky Temple");
    set("long","%^BOLD%^%^WHITE%^This area was made for those who wish to take a load off and relax after a long day of work. A large bench can be see to the south. A soothing breeze flows through the area, allowing a sweet smell of %^MAGENTA%^perfumes %^WHITE%^to encompass the area. The %^YELLOW%^sunlight shines brightly %^WHITE%^bringing warmth to all who enter.%^RESET%^");
    set_items( ([ "sunlight": "%^BOLD%^%^WHITE%^The %^YELLOW%^sunlight shines brightly %^WHITE%^bringing warmth to all who enter.%^RESET%^" ]) );
    set_exits( ([ "north" : SKYROOM "rs_2", "south" : SKYROOM "rs_9" ]) );
}
