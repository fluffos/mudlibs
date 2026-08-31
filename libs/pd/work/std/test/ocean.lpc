#include <teststd.h>


inherit ROOM;
void create() {
    ::create();
    set_properties(([
      "outdoors": 1,
      "ocean" : 1,
      "light" : 1,
    ]));
}

void init() {
    ::init();
    if (this_player()->is_player()) {
	write("You feel weaker from the lack of oxygen.");
	this_player()->add_hp(-10);
	this_player()->add_sp(-5);
        remove_call_out("take_damage");
	call_out("take_damage", 120, this_player());
    }
}

int take_damage(object tp) {
    if (present(tp)) {
	tell_object(tp, "You feel weaker from the lack of oxygen.");
	tp->add_hp(-10);
	tp->add_sp(-5);
        remove_call_out("take_damage");
	call_out("take_damage", 120, tp);
	return 1;
    }
}
