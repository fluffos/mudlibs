#include <std.h>
#include <amun.h>
inherit ROOM;
void create() {
    ::create();
    set_property("indoors", 1);
    set_property("light", 2);
    set("short", "EYE OF HELL");
    set("long","%^BOLD%^%^RED%^The path moving towards the middle of the eye' is bright with fire.  In the walls are seperate caves with bars in the front.  Faces behind these bars are demented and burnt.  This is not a good place.%^RESET%^");
    set_items( ([ "path": "%^RESET%^%^RED%^This path looks as if it is stained with years of blood.%^RESET%^", "fire": "%^RESET%^%^RED%^The fire dances off the walls casting strange shadows.%^RESET%^", "walls": "%^RESET%^%^ORANGE%^The walls give a home to many prisoners within the eye of hell.%^RESET%^", "faces": "%^RESET%^%^RED%^These faces are those of the prisoners in the eye.  They do not look pretty.%^RESET%^" ]) );
    set_exits( ([ "east": HELLROOM+"middle_26", "west": HELLROOM+"middle_24" ]) );
    new(HELLMON+"headless_horseman")->move(this_object());
    new(HELLMON+"black_centaur")->move(this_object());
    new(HELLMON+"banshee")->move(this_object());
    new(HELLMON+"she_raknid")->move(this_object());
}
