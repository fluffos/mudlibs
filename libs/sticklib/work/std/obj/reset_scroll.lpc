#include <treasure.h>

void create_treasure() {
    set_name("scroll of time distortion");
    set_short("Scroll of time distortion");
    set_long(
      "This scroll has been written with flowing red runes, and seems "
      "to be very powerful... Reading it could do something very "
      "strange, and perhaps dangerous. "
    );
    set_id(({ "scroll", "scroll of time distortion" }));
    set_value(1000);
    set_weight(1);
}

void init_treasure() {
    add_action("read", "read");
}

int read(string str) {
    if(id(str)) {
	environment(this_player())->tell_here(
	  "The entire room seems to shift and wave! You feel a bit dizzy. ");
	environment(this_player())->reset();
	this_player()->tell_me("The scroll disappears. ");
	destruct(this_object());
	return 1;
    }
    return 0;
}
