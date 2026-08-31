#include <std.h>
#include <daemons.h>
#include <guild.h>
inherit ROOM;
void init() {
    ::init();
    add_action("do_read","read");
}
void create() {
    ::create();
    set_properties( ([ "no attack"   : 1,
	"no magic"    : 1,
	"no bump"     : 1,
	"light"       : 2,
	"night light" : 2,
	"no steal"    : 1 ]) );
    set_property("town",1);
    set("short", "Guild Town");
    set("long","%^ORANGE%^This is a shack barely standing on a small patch of sand. The sand around the shack seems darker due to the shade it provides. The smell of the %^BOLD%^%^CYAN%^o%^WHITE%^c%^CYAN%^ean %^RESET%^%^ORANGE%^filters through the area as a %^BOLD%^%^WHITE%^cool b%^CYAN%^r%^WHITE%^eeze %^RESET%^%^ORANGE%^carries it through. A sign is posted on the counter for all to read.%^RESET%^");
    set_items( (["sand" : "%^ORANGE%^The sand is soft and cool to the touch.%^RESET%^", "specs" : "%^ORANGE%^The sand is soft and cool to the touch.%^RESET%^", "ocean" : "%^BOLD%^%^CYAN%^The ocean is thundering along the shore.%^RESET%^", "shack" : "There is a shack to the east where a woman can be seen behind the counter." ]) );
    set_exits( ([ "west" : GROOM "docks_entrance" ]) );
}
int do_read(string str) {
    if(str != "sign") return notify_fail("Read what?\n");
    write("This shop does the following services: \n");
    write("    <upgrade> : This allows you to upgrade your ship.\n");
    write("<view status> : This shows your ship's status.\n");
    return 1;
}
void reset() {
    ::reset();
    if(!present("jill")) new(GMOB"jill")->move(this_object());
}
