#include <treasure.h>
#define FIND_MODULE "/areas/tristeza/special/locate_module"

void create_treasure() {
    set_name("scroll of location");
    set_short("Scroll of location");
    set_long("This is a scroll of location. Read it to divine the "
      "location of an object. "
    );
    set_id(({ "scroll", "location scroll" }));
    set_value(500);
    set_weight(1);
}

void init_treasure() {
    add_action("read", "read");
}

int read(string str) {
    if(!id(str)) return notify_fail("Read what? \n"), 0;
    this_player()->tell_me(
      "You read the scroll... "
    );
    (FIND_MODULE)->find_unique();
    destruct(this_object());
    return 1;
}
