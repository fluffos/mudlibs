#include <std.h>

inherit LOCKER;

void create() {
    set_path("/adm/save/votes/unholystorage");
    ::create();
    set_properties( ([ "no attack"   : 1,
        "no magic"    : 1,
        "no bump"     : 1,
        "light"       : 2,
        "night light" : 2,
        "no teleport" : 1,
        "no scry" : 1,
        "indoors" : 1,
        "no steal"    : 1 ]) );

    set("short", "Unholy Storage Room");
    set("long", "%^BOLD%^%^RED%^A small, warm room stands before you. You can see what seems to be many rib cages of different sizes and shapes protruding from the walls, almost as if the dead bodies make up the room itself. Muffled screams and moans emit from the rib cages. Upon closer inspection you notice that the ribcages can be opened, what a great place to <store> something for later use!");
    set_exits(([
        "south" : "/d/guilds/unholy/unholyroom"
      ]));
}
