#include <std.h>
#include <amun.h>
inherit ROOM;
void create() {
    ::create();
    set_property("indoors", 1);
    set_property("light", 2);
    set("short", "Sky Temple");
    set("long","%^RESET%^%^WHITE%^The clouds begin to thin, making the road move drastically downhill. %^BOLD%^%^BLACK%^Darkness encompasses the entire area to the south, which allows shadows to walk around freely. %^RESET%^The air feels heavy in this room, making it hard to breath. Dead butterflies can be seen strewn about the ground.%^RESET%^");
    set_items( ([ "clouds": "%^RESET%^%^WHITE%^The clouds begin to thin, making the road move drastically downhill.%^RESET%^", "butterflies": "%^RESET%^Dead butterflies can be seen strewn about the ground.%^RESET%^" ]) );
    set_exits( ([ "south" : SKYROOM "rogue_hall2", "north" : SKYROOM "rs_4" ]) );
    add_pre_exit_function("south", "go_south");
}
void init() {
    ::init();
    add_action("lookin", "peer");
}
int go_south() {
    if(wizardp(this_player())){
	write("Mighty immortals are always welcome into the hall.");
	return 1;
    }
    if((string)this_player()->query_class() != "rogue") {
	write("You cannot penetrate the force field that blocks the passage.");
	say(this_player()->query_cap_name()+" tries to get into the "
	  "rogue's sanctuary, but fails.", this_player());
	return 0;
    }
    return 1;
}
int lookin(string str) {
    string *disallow;
    disallow = ({ "south", "s" });
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
