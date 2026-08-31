#include <std.h>
#include <amun.h>
inherit ROOM;
void create() {
    ::create();
    set_properties(([ "light" : 2, "night light" : 0, "no attack" : 1, "no magic" : 1, "no steal" : 1, "no bump" : 1]));
    set("short", "Sky Temple");
    set("long","%^BOLD%^%^RED%^There is a little pool of blood on the %^WHITE%^soft white %^RED%^of the %^WHITE%^clouds%^RED%^. The %^CYAN%^air %^RED%^is warm and calm the more south the path leads. To the south, the sound of cheering and screaming can be heard. This southern path seems to be moving downhill.%^RESET%^");
    set_items( ([ "blood": "%^BOLD%^%^RED%^The origins of this blood is unknown.%^RESET%^" ]) );
    set_exits( ([ "south" : SKYROOM "fighter_hall2", "north" : SKYROOM "ls_4" ]) );
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
    if((string)this_player()->query_class() != "fighter") {
	write("You cannot penetrate the force field that blocks the passage.");
	say(this_player()->query_cap_name()+" tries to get into the "
	  "fighter's sanctuary, but fails.", this_player());
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
