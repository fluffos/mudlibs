#include <std.h>
#include <amun.h>
inherit ROOM;
void create() {
    ::create();
    set_property("indoors", 1);
    set_property("light", 2);
    set("short", "Sky Temple");
    set("long","%^BOLD%^%^WHITE%^This room was built by the %^YELLOW%^Angels %^WHITE%^to aid those who need a strong, dependable steed. A soothing breeze flows through the area, allowing a sweet smell of %^MAGENTA%^perfumes %^WHITE%^to encompass the area. The clouds in this area break, as if a small cirlce of sand was placed offering a trotting area for the local horses. The %^YELLOW%^sunlight shines brightly %^WHITE%^bringing warmth to all who enter.%^RESET%^");
    set_items( ([ "clouds": "%^BOLD%^%^WHITE%^The clouds in this area break, as if a small cirlce of sand was placed offering a trotting area for the local horses.%^RESET%^", "sunlight": "%^BOLD%^%^WHITE%^The %^YELLOW%^sunlight shines brightly %^WHITE%^bringing warmth to all who enter.%^RESET%^" ]) );
    set_exits( ([ "south" : SKYROOM "rs_6" ]) );
    new(SKYMOB "horse")->move(this_object());
    new(SKYMOB "pony")->move(this_object());
}
