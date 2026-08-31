#include <std.h>
#include <amun.h>
inherit ROOM;
void create() {
    ::create();
    set_property("indoors", 1);
    set_property("light", 2);
    set("short", "EYE OF HELL");
    set("long","%^BOLD%^%^RED%^While entering this room, a large howl can be heard. Flames burn all around and %^BLACK%^demons %^RED%^seem to appear out of nowhere, glaring slyly. The walls and ceiling are all dripping with blood of the innocent women and children that have been slaughtered without mercy. Something can be seen moving in the %^BLACK%^darkened corner %^RED%^as bats take flight above the large cliff. A burnt and rotten hand falls off the side of the cliff onto the path.%^RESET%^");
    set_items( ([ "corner": "%^BOLD%^%^BLACK%^This corner is pitch black and uninviting. Something can be seen moving around.%^RESET%^", "blood": "%^RESET%^%^RED%^Some of it looks fresh.%^RESET%^", "cliff": "%^RESET%^%^ORANGE%^The cliff is full with rocks and shadows dancing off of them.%^RESET%^", "rocks": "%^RESET%^%^RED%^The rocks look as if they were used in battle.  There is some fresh flesh on a few of them." ]) );
    set_exits( ([ "west": HELLROOM+"eye_of_hell_9", "east": HELLROOM+"eye_of_hell_11"  ]) );
}
