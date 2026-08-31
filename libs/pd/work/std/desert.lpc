#include <std.h>
inherit VIRTUALROOM;

void init() {
    ::init();
    if (!query_night() && this_player()->is_player()) {
	write("You feel weak from the searing heat.");
	this_player()->add_hp(-10);
	this_player()->add_sp(-5);
	remove_call_out("take_damage");
	call_out("take_damage", 150, this_player());
    }
}

int take_damage(object tp) {
    if (!query_night() && present(tp)) {
	tell_object(tp, "You feel weak from the searing heat.");
	tp->add_hp(-10);
	tp->add_sp(-5);
	remove_call_out("take_damage");
	call_out("take_damage", 150, tp);
    }
    return 1;
}
