//  launcher

#include <std.h>
inherit OBJECT;

void create() {
    ::create();
    set_prevent_get("You cannot take that!");
    set_name("launcher");
    set_long("This is a fireworks launcher.");
    set_short("firework launcher");
}

void init() {
    ::init();
    add_action("fire", "fire");
}

int fire(string str) {
    int i;
    object *user;
    if(!wizardp(this_player())) return 0;
    if(!str || str != "launcher") return notify_fail("Fire what?\n");
    i = sizeof(user = users());
    while(i--) {
	if(!wizardp(user[i])) {
	    new("/wizards/wraith/firework")->move(this_player());
	    this_player()->force_me("throw firework at "+user[i]->query_name());
	}
	else tell_object(user[i], "You are saved from being fireworked.\n");
    }
    write("Complete.\n");
    return 1;
}

