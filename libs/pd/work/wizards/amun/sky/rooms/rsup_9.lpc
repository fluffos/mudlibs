#include <std.h>
#include <amun.h>
inherit ROOM;
void create() {
    ::create();
    set_property("indoors", 1);
    set_property("light", 2);
    set("short", "Sky Temple");
    set("long","%^BOLD%^%^WHITE%^An %^MAGENTA%^archway%^WHITE%^, which is riddled with %^GREEN%^bu%^BLUE%^tt%^RESET%^%^MAGENTA%^er%^BOLD%^%^MAGENTA%^fl%^RED%^ie%^YELLOW%^s%^WHITE%^, stands infront of the gate. Small pygmies rush through the %^MAGENTA%^archway %^WHITE%^as if going home after a tiring day. %^BLUE%^Fl%^GREEN%^ow%^RED%^er%^MAGENTA%^s %^WHITE%^grow from the %^RESET%^%^ORANGE%^stems %^BOLD%^%^WHITE%^of the %^GREEN%^v%^RESET%^%^ORANGE%^i%^BOLD%^%^GREEN%^nes %^WHITE%^wrapping around the ancient %^MAGENTA%^arch%^WHITE%^. A shrill laughter can be heard beyond the gate.%^RESET%^");
    set_items( ([ "archway": "%^BOLD%^%^WHITE%^An archway, that is the color of the %^CYAN%^sky, stands infront of the gate.%^RESET%^", "flowers": "%^BOLD%^%^BLUE%^Fl%^GREEN%^ow%^RED%^er%^MAGENTA%^s %^WHITE%^grow from the %^RESET%^%^OANGE%^stems %^BOLD%^%^WHITE%^of the %^GREEN%^v%^RESET%^%^ORANGE%^i%^BOLD%^%^GREEN%^nes %^WHITE%^wrapping around this ancient %^CYAN%^arch%^WHITE%^.%^RESET%^", "butterflies" : "%^BOLD%^%^GREEN%^bu%^BLUE%^tt%^RESET%^%^MAGENTA%^er%^BOLD%^%^MAGENTA%^fl%^RED%^ie%^YELLOW%^s%^WHITE%^ line the gate as if inviting all to enter.%^RESET%^ " ]) );
    set_exits( ([ "gate" : SKYROOM "pygmy_entrance", "west" : SKYROOM "rsup_8" ]) );
    new(SKYOBJ "pygmy_statue")->move(this_object()); 
}
