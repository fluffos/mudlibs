#include <std.h>
#include <amun.h>
inherit ROOM;
void create() {
    ::create();
    set_property("indoors", 1);
    set_property("light", 2);
    set("short", "Sky Temple");
    set("long","%^BOLD%^%^WHITE%^An archway, that is %^YELLOW%^golden %^WHITE%^from the %^YELLOW%^sunlight%^WHITE%^, stands infront of the gate. Angels rush through the %^YELLOW%^archway %^WHITE%^as if going home after a tiring day of shopping. I%^RESET%^c%^BOLD%^%^WHITE%^i%^RESET%^c%^BOLD%^%^WHITE%^l%^RESET%^e%^BOLD%^%^WHITE%^s form on the arch of the archway, hanging down with %^YELLOW%^golden %^WHITE%^specs gleaming off of them. Snow begins to gently fall, leaving the already white clouds riddled with a fresh new powder.%^RESET%^");
    set_items( ([ "archway": "%^BOLD%^%^WHITE%^An archway, that is %^YELLOW%^golden %^WHITE%^from the %^YELLOW%^sunlight%^WHITE%^, stands infront of the gate.%^RESET%^", "iciles": "%^BOLD%^%^WHITE%^I%^RESET%^c%^BOLD%^%^WHITE%^i%^RESET%^c%^BOLD%^%^WHITE%^l%^RESET%^e%^BOLD%^%^WHITE%^s form on the arch of the archway, hanging down with %^YELLOW%^golden %^WHITE%^specs gleaming off of them.%^RESET%^" ]) );
    set_exits( ([ "east" : SKYROOM "lsup_2", "gate" : SKYROOM "angel_entrance" ]) );
    new(SKYOBJ "angel_statue")->move(this_object());
}
