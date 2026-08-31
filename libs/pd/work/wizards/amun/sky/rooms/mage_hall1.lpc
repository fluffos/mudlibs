#include <std.h>
#include <amun.h>
inherit ROOM;
void create() {
    ::create();
    set_property("indoors", 1);
    set_property("light", 2);
    set("short", "Sky Temple");
    set("long","%^BOLD%^%^CYAN%^The clouds begin to shift slightly as the wind grows stronger. To the north, %^GREEN%^li%^CYAN%^gh%^MAGENTA%^ts %^CYAN%^can be seen flickering under the small crack at the bottom of the door. %^GREEN%^Pl%^RESET%^%^ORANGE%^a%^BOLD%^%^GREEN%^nts %^CYAN%^magically grow through a %^WHITE%^tuft of clouds %^CYAN%^towards the south. Small sounds that sound like incantations can be heard wafting through the area.%^RESET%^");
    set_items( ([ "clouds": "%^BOLD%^%^WHITE%^The clouds begin to shift slightly as the wind grows stronger.%^RESET%^", "lights": "%^BOLD%^%^CYAN%^The lights can be seen coming through the crack at the bottom of the door.%^RESE%^" ]) );
    set_exits( ([ "north" : SKYROOM "mage_hall2", "south" : SKYROOM "ls_5" ]) );
    add_pre_exit_function("north", "go_north");
}
void init() {
    ::init();
    add_action("lookin", "peer");
}
int go_north() {
    if(wizardp(this_player())){
	write("Mighty immortals are always welcome into the hall.");
	return 1;
    }
    if((string)this_player()->query_class() != "mage") {
	write("You cannot penetrate the force field that blocks the passage.");
	say(this_player()->query_cap_name()+" tries to get into the "
	  "mage's sanctuary, but fails.", this_player());
	return 0;
    }
    return 1;
}
int lookin(string str) {
    string *disallow;
    disallow = ({ "north", "n" });
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
