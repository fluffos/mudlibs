#include <std.h>
#include <amun.h>
inherit ROOM;
void create() {
    ::create();
    set_property("indoors", 1);
    set_property("light", 2);
    set("short", "Sky Temple");
    set("long","%^BOLD%^%^WHITE%^An archway, that is the color of the %^CYAN%^sky%^WHITE%^, stands infront of the gate. Gods and Goddesses rush through the %^CYAN%^archway %^WHITE%^as if going home after a tiring day of shopping. %^BLUE%^Fl%^GREEN%^ow%^RED%^er%^MAGENTA%^s %^WHITE%^grow from the %^RESET%^%^ORANGE%^stems %^BOLD%^%^WHITE%^of the %^GREEN%^v%^RESET%^%^ORANGE%^i%^BOLD%^%^GREEN%^nes %^WHITE%^wrapping around this ancient %^CYAN%^arch%^WHITE%^. Around the gate little patches of melting snow can be seen melting.%^RESET%^");
    set_items( ([ "archway": "%^BOLD%^%^WHITE%^An archway, that is the color of the %^CYAN%^sky, stands infront of the gate.%^RESET%^", "flowers": "%^BOLD%^%^BLUE%^Fl%^GREEN%^ow%^RED%^er%^MAGENTA%^s %^WHITE%^grow from the %^RESET%^%^OANGE%^stems %^BOLD%^%^WHITE%^of the %^GREEN%^v%^RESET%^%^ORANGE%^i%^BOLD%^%^GREEN%^nes %^WHITE%^wrapping around this ancient %^CYAN%^arch%^WHITE%^.%^RESET%^", "snow" : "%^BOLD%^%^WHITE%^The snow begins to melt as the path through the gate leads deeper.%^RESET%^" ]) );
    set_exits( ([ "gate" : SKYROOM "gods_entrance", "east" : SKYROOM "lsup_8" ]) );
    new(SKYOBJ "gods_statue")->move(this_object());
}
