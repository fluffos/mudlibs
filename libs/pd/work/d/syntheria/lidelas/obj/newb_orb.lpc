#include <std.h>
inherit OBJECT;
void create() {
    ::create();
    set_id(({ "orb" }));
    set_name("orb");
    set_long("The orb emits a soft white glow, it basks the whole square in its light. It gives off a slight amount of warmth. If one were to touch it, it would warm the body.");
    set_short("an orb");
    set_weight(1);
    set("value", 0);
    set_prevent_get( "The orb is secured to the pedestal, which is far too heavy to move." );
}

int goTouch(string str) {
    if (str != "orb") {
        notify_fail("Touch what?\n");
        return 0;
    }
    if (this_player()->query_disable())
    {
    if (this_player()->query_level() < 10) {
        write("You feel warm inside already.");
        }
        return 1;
    }
    if (this_player()->query_level() < 6)
    {
    this_player()->set_disable();
    this_player()->heal(10);
    write("The orb warms your body.");
    }
    else
    {
    this_player()->set_disable();
    write("The orb seems to do nothing");
    }
    return 1;
}
void init() {
    ::init();
        add_action("goTouch", "touch");
}
