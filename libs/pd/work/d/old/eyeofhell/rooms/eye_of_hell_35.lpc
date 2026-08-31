#include <std.h>
#include <amun.h>
inherit ROOM;
void create() {
    ::create();
    set_property("indoors", 1);
    set_property("light", 2);
    set("short", "EYE OF HELL");
    set("long","%^BOLD%^%^RED%^The path now breaks off into another direction.  The parth towards to northwest is darker and scarier than the one towards the east.  The sound of screaming is echoing off the cave walls.%^RESET%^");
    set_items( ([ "path": "%^RESET%^%^RED%^This path looks as if it is stained with years of blood.%^RESET%^", "blood": "%^RESET%^%^RED%^Some of it looks fresh.%^RESET%^", "cliff": "%^RESET%^%^ORANGE%^The cliff is full with rocks and shadows dancing off of them.%^RESET%^", "rocks": "%^RESET%^%^RED%^The rocks look as if they were used in battle.  There is some fresh flesh on a few of them." ]) );
    set_exits( ([ "west": HELLROOM+"eye_of_hell_36", "east": HELLROOM+"eye_of_hell_34", "southwest": HELLROOM+"middle_11" ]) );
    new(HELLMON+"headless_horseman")->move(this_object());
    new(HELLMON+"black_centaur")->move(this_object());
}
