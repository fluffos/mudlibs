#include <std.h>
#include <amun.h>
inherit ROOM;
void create() {
    ::create();
    set_property("indoors", 1);
    set_property("light", 2);
    set("short", "Sky Temple");
    set("long","%^BOLD%^%^WHITE%^The %^YELLOW%^light %^WHITE%^becomes bright again as the path moves closer to the gate to the west. The laughter and singing grow a little louder along the path. An %^BOLD%^%^CYAN%^cold%^WHITE%^ breeze moves through the area, giving even the %^GREEN%^v%^RESET%^%^ORANGE%^i%^BOLD%^%^GREEN%^nes %^WHITE%^the chills. Small patches of melting s%^RESET%^n%^BOLD%^%^WHITE%^ow can be seen ontop of the clouds.%^RESET%^");
    set_items( ([ "light": "%^BOLD%^%^WHITE%^The %^YELLOW%^light %^WHITE%^becomes bright again as the path moves closer to the gate to the west.%^RESET%^", "vines": "%^BOLD%^%^GREEN%^The vines reach up around the clouds offering beautiful scenery.%^RESET%^", "snow" : "%^BOLD%^%^WHITE%^The snow is spread sparactically around the area, leaving the already white clouds a brighter white.%^RESET%^" ]) );
    set_exits( ([ "north" : SKYROOM "lsup_7", "west" : SKYROOM "lsup_9", "down" : SKYROOM "elite_nook" ]) );
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
    if((string)this_player()->query_level() != "elite") {
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
