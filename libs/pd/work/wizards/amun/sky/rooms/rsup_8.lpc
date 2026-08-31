#include <std.h>
#include <amun.h>
inherit ROOM;
void create() {
    ::create();
    set_property("indoors", 1);
    set_property("light", 2);
    set("short", "Sky Temple");
    set("long","%^BOLD%^%^WHITE%^The %^YELLOW%^light %^WHITE%^becomes bright again as the path moves closer to the gate to the east. The %^RESET%^%^ORANGE%^l%^GREEN%^e%^ORANGE%^a%^GREEN%^v%^ORANGE%^e%^GREEN%^s%^BOLD%^%^WHITE%^ grow more abundant as the path moves along. An %^BOLD%^%^CYAN%^cold%^WHITE%^ breeze moves through the area, giving even the %^GREEN%^v%^RESET%^%^ORANGE%^i%^BOLD%^%^GREEN%^nes %^WHITE%^the chills. A shrill laughter can be heard beyond the gate.%^RESET%^");
    set_items( ([ "light": "%^BOLD%^%^WHITE%^The %^YELLOW%^light %^WHITE%^becomes bright again as the path moves closer to the gate to the west.%^RESET%^", "vines": "%^BOLD%^%^GREEN%^The vines reach up around the clouds offering beautiful scenery.%^RESET%^" ]) );
    set_exits( ([ "east" : SKYROOM "rsup_9", "north" : SKYROOM "rsup_7", "down" : SKYROOM "hm_nook" ]) );
    add_pre_exit_function("down", "go_down");
}
void init() {
    ::init();
    add_action("lookin", "peer");
}
int go_down() {
    if(wizardp(this_player())){
	write("Mighty immortals are always welcome into the hall.");
	return 1;
    }
    if((string)this_player()->query_level() != "high mortal") {
	write("You cannot penetrate the force field that blocks the passage.");
	say(this_player()->query_cap_name()+" tries to get into the "
	  "elite's sanctuary, but fails.", this_player());
	return 0;
    }
    return 1;
}
int lookin(string str) {
    string *disallow;
    disallow = ({ "down", "d" });
    if(member_array(str, disallow) == -1)
	return 0;
    else {
	message("info", "This hall is closed off from view.", this_player(),
	);
	return 1;
    }
    message("bug", "ERROR: This shouldn't happen!", this_player(), );
    return 1;
}
