#include <std.h>
#include <guild.h>
inherit ROOM;

void init() {
    ::init();
    add_action("lift_rock", "lift");
} 
void create() {
    ::create();
    set_properties(([
	"light":2, "night light":2, "no attack":1, "no magic":1, 
	"no bump":1, "no steal":1, "indoors":1, "no teleport":1,
      ]));

    set_short("%^BOLD%^%^BLACK%^D%^WHITE%^a%^BLACK%^r%^WHITE%^k "
      "%^BOLD%^%^BLACK%^S%^WHITE%^o%^BLACK%^u%^BLACK%^l%^WHITE%^s "
      "%^BOLD%^%^BLACK%^Dungeon%^RESET%^");
    set_long("%^BOLD%^%^BLACK%^You are standing in the Dark Souls dungeon. "
      "%^RESET%^RED%^Blood%^BOLD%^%^BLACK%^ has been %^BOLD%^%^BLACK%^splattered "
      "all over the ground. Some old rotting %^BOLD%^%^WHITE%^bones%^BOLD%^%^BLACK%^ crunch "
      "%^BOLD%^%^BLACK%^and scatter underfoot. Several cells can be seen around the "
      "%^BOLD%^%^BLACK%^room. Shackles and chains hang from the ceiling.  There is a "
      "%^BOLD%^%^BLACK%^sign above the door.%^RESET%^");
    set_listen("default", "%^BOLD%^%^WHITE%^You hear screams echoing around the dungeon.");
    set_items((["blood" : "This is some old %^RED%^blood%^RESET%^ "
	"dried up on the floor.",
	"cells" : "The cells have strong metal bars guarding "
	"the entrance and some %^BOLD%^%^WHITE%^bones%^RESET%^ "
	"laying on the cot of one of the cells.",
	"bones" : "These are %^BOLD%^%^WHITE%^white%^RESET%^ "
	"bones just laying there.",
	"sign" : "%^BOLD%^%^WHITE%^It clearly reads: "
	"%^BLACK%^%^BOLD%^Escape is futile, you will be assimilated!"]));
    set_exits(([
	"north" : ROOMS"darksoul/shop",
	"up" : ROOMS"darksoul/hall",
	"east" : ROOMS"darksoul/praying",
	"west" : ROOMS"darksoul/lockerd",
	"south" : ROOMS"darksoul/ashes"
      ]));
}
int lift_rock(string str) {
    if(!str) {
	notify_fail("What?\n");
	return 0;
    }
    if(str != "rock") {
	notify_fail("What?\n");
	return 0;
    }
    message("info", "The rock lifts opening an exit down. Hurry, the exit is already closing!", this_player());
    add_exit(ROOMS"darksoul/view_room", "down");
    call_out("go_rock", 5);
    return 1;
}
void go_rock() {
    remove_exit("down");
}
