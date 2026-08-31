#include <std.h>
#include <tombar.h>
inherit ARMOUR;
int shine;
void create() {
    ::create();
    set_name("pendant");
    set_short("silver pendant");
    set_long("This is a small, silver pendant.  Of unknown origin there might be someone in "
      "the world like an antique dealer that might want one of these.");
    set_id(({"pendant", "silver pendant"}));
    set_weight(2);
    set_ac(1);
    set_limbs(({"torso"}));
    set_curr_value("gold", 0);
}
void init() {
    ::init();
    add_action("shine", "shine");
}
int shine(string str) {
    if(!str && str != "pendant" && str != "silver pendant") return notify_fail("Shine what?\n");
    write("You shine the pendant intentivly.\n");
    say(this_player()->query_cap_name()+" shines "+nominative(this_player())+" pendant.");
    shine = 1;
    call_out("remove_shine", 20);
    return 1;
}
int remove_shine() {
    write("The shine from your pendant disappears.\n");
    say("The shine from "+this_player()->query_cap_name()+"'s disappears.");
    shine = 0;
}
