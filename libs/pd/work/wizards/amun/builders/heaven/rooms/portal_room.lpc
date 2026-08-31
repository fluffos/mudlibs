#include <std.h>
#include <amun.h>
inherit ROOM;
void create() {
    ::create();
    set_property("indoors", 1);
    set_property("light", 2);
    set("short", "Portal Room");
    set("long","%^BOLD%^%^WHITE%^This is a holding room for anyone who wishes to past between the realms of Heaven and Earth. A slight breeze finds it's way through the room and chills the air enough to make it comfortable. There are cushioned chairs littered around for those who are waiting to take comfort. The sound of birds can be heard coming from outside the door.");
    set_items( ([ "chairs": "%^BOLD%^%^YELLOW%^These chairs look quite comfortable.%^RESET%^" ]) );
    set_exits( ([ "north" : HEVROOM "heaven_square" ]) );
    new(HEVARM "portal")->move(this_object());
}
