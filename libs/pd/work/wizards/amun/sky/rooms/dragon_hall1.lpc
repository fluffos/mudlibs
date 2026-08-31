#include <std.h>
#include <amun.h>
inherit ROOM;
void create() {
    ::create();
    set_property("indoors", 1);
    set_property("light", 2);
    set("short", "Sky Temple");
    set("long","%^BOLD%^%^BLACK%^There are large prints of what looks to be a %^RED%^dr%^BLUE%^ag%^WHITE%^on %^BLACK%^all over the %^WHITE%^fluffy clouds%^BLACK%^. A few %^GREEN%^pl%^RESET%^%^ORANGE%^a%^BOLD%^%^GREEN%^nts %^BLACK%^can be seen magically growing to the south. Towards the north, the sound of %^BLACK%^dr%^RED%^ag%^BLUE%^on%^WHITE%^s %^BLACK%^can be heard. There is a strange smell flowing through the air.%^RESET%^");
    set_items( ([ "prints": "%^BOLD%^%^BLACK%^There are large prints of what looks to be a %^RED%^dr%^BLUE%^ag%^WHITE%^on %^BLACK%^all over the %^WHITE%^fluffy clouds%^BLACK%^.%^RESET%^", "plants": "%^BOLD%^%^BLACK%^A few %^GREEN%^pl%^RESET%^%^ORANGE%^a%^BOLD%^%^GREEN%^nts %^BLACK%^can be seen magically growing to the south.%^RESET%^" ]) );
    set_exits( ([ "north" : SKYROOM "dragon_hall2", "south" : SKYROOM "ls_3" ]) );
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
    if((string)this_player()->query_race() != "dragon") {
	write("You cannot penetrate the force field that blocks the passage.");
	say(this_player()->query_cap_name()+" tries to get into the "
	  "dragon's sanctuary, but fails.", this_player());
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
