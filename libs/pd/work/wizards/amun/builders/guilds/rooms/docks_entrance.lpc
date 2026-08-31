#include <std.h>
#include <daemons.h>
#include <guild.h>
#include <boat.h>
inherit ROOM;
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
    set("long","%^ORANGE%^The sand that covers the ground is soft and cool on the feet of travelers. The deep colored specks reach down towards the south where the %^BOLD%^%^CYAN%^o%^WHITE%^c%^CYAN%^ean %^RESET%^%^ORANGE%^is threatening to wash them away. A %^BOLD%^%^WHITE%^cool b%^CYAN%^r%^WHITE%^eeze %^RESET%^%^ORANGE%^filters up from the southern sea making the whole area serene. There is a shack to the east where a woman can be seen helping travelers with something.%^RESET%^");
    set_items( (["sand" : "%^ORANGE%^The sand is soft and cool to the touch.%^RESET%^", "specks" : "%^ORANGE%^The sand is soft and cool to the touch.%^RESET%^", "ocean" : "%^BOLD%^%^CYAN%^The ocean is thundering along the shore.%^RESET%^", "shack" : "There is a shack to the east where a woman can be seen behind the counter." ]) );
    set_exits( ([ "south" : GROOM "docks", "up" : GROOM "board_room", "enter shack" : GROOM"spare_boat" ]) );
    add_exit_alias("enter shack", "shack");
}
