#include <std.h>
#include <amun.h>
inherit ROOM;
void create() {
    ::create();
    set_property("indoors", 1);
    set_property("light", 2);
    set("short", "EYE OF HELL");
    set("long","%^BOLD%^%^WHITE%^The path now ends in the middle of the eye.  There is a bright light causing the room to become blinding.  There are many cages, holding prisoners, danglin in the air.%^RESET%^");
    set_items( ([ "path": "%^RESET%^%^RED%^This path looks as if it is stained with years of blood.%^RESET%^", "cages": "The prisoners are being tortured in these cages.%^RESET%^", "walls": "%^RESET%^%^ORANGE%^The walls give a home to many prisoners within the eye of hell.%^RESET%^", "faces": "%^RESET%^%^RED%^These faces are those of the prisoners in the eye.  They do not look pretty.%^RESET%^" ]) );
    set_exits( ([ "southeast": HELLROOM+"middle_44", "northeast": HELLROOM+"middle_43" ]) );
    new(HELLMON+"lucifer")->move(this_object());
}
