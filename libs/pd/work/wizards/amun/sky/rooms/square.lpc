#include <std.h>
#include <amun.h>
inherit ROOM;
int sigma;
int cmd_start(string str);
void init() {
    ::init();
    add_action("cmd_start", "start");
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
    set_listen("default", "%^BOLD%^%^GREEN%^The sound of wildlife can be heard.%^RESET%^");
    set_short("Sky Temple");
    set("long","%^BOLD%^%^YELLOW%^Sky Temple%^RESET%^\n"
      "%^BOLD%^%^WHITE%^A %^YELLOW%^sunray shines brightly %^WHITE%^through the break in the clouds towards the east, allowing the room to be bathed in %^YELLOW%^sunlight%^WHITE%^. The white fluffy clouds offer unnatural support for all who tread on them, and remain as beautiful as they once were, like a fresh new powder of snow. The square has become quite busy, as the hustle and bustle of the town grows. The water in the fountain makes a soft trickling noise.%^RESET%^");
    set_exits((["north" : ROOMS "square1",
	"south" : SKYROOM "ls_10",
	"east" :  SKYROOM "rs_1",
	"north" : SKYROOM "ls_11",
	"northwest" : SKYROOM "board_room",
	"west" :  SKYROOM "ls_1"]));
    set_items( ([
	"rays" : "%^BOLD%^%^YELLOW%^The sunrays shine sparatically through breaks in the clouds.%^RESET%^",
	"clouds" : "%^BOLD%^%^WHITE%^The clouds stretch as far as the naked eye can see and look like a fresh new powder of snow, untouched and beautiful.%^RESET%^",
	"mirror" : "%^BOLD%^%^WHITE%^This is not an ordinary mirror, it moves as if waves in an ocean, it looks like a looking glass! You maybe able to %^YELLOW%^find %^WHITE%^people with it.%^RESET%^" ]) );
}
void reset() {
    ::reset();
    if(!present("fountain"))
	new(SKYOBJ "stone_fountain")->move(this_object());
    if(!present("angel"))
	new(SKYMOB "angel_warrior")->move(this_object());
}
int cmd_start(string str) {
    if (!str || str=="") {
	notify_fail("Start where?\n");
	return 0;
    }

    if (str!="here")     {
	notify_fail("You cannot start there.\n");
	return 0;
    }

    this_player()->set_primary_start(SKYROOM "square");
    write("You are now set to start here.");
    return 1;
}
