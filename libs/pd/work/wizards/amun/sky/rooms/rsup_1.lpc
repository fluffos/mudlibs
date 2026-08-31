#include <std.h>
#include <amun.h>
inherit ROOM;
void create() {
    ::create();
    set_property("indoors", 1);
    set_property("light", 2);
    set("short", "Sky Temple");
    set("long","%^BOLD%^%^BLACK%^A blackened archway, stands infront of the gate. Arms and hands can be seen coming from the gate as if those on the other side are attempting to climb their way out. The sun is blackened and giving off a %^RESET%^%^RED%^heat %^BOLD%^%^BLACK%^that is unbearable. Once alive and beautiful, the plants now lay dead along the pathway.%^RESET%^");
    set_items( ([ "archway": "%^BOLD%^%^BLACK%^A blackened archway, stands infront of the gate. Limbs from bodies can be seen protruding from every space between the bars. These lifeless souls are trying to break free.%^RESET%^", "sun": "%^BOLD%^%^BLACK%^The sun is blackened from the evil doers beyond the gate.%^RESET%^" ]) );
    set_exits( ([ "west" : SKYROOM "rsup_2", "gate" : SKYROOM "fallen_entrance" ]) );
    new(SKYOBJ "fallen_angel_statue")->move(this_object());
}
