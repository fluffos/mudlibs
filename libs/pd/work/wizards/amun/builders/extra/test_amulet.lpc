#include <std.h>
inherit ARMOUR;
void init() {
    ::init();
    add_action("read_inscription", "read");
}
void create() {
    ::create();
    set_name("Ruby Necklace");
    set("id",({ "necklace", "ruby necklace", "Ruby Necklace"}) );
    set("short", "Ruby Necklace");
    set("long", "The multifaceted oval ruby pendant hangs from a golden chain. On the back of the pendant is a strange inscription.");
    set_weight(5);
    set_curr_value("gold", 50);
    set_type("necklace");
    set_limbs( ({ "head" }) );
    set_ac(3);
}
int read_inscription(string str) {
    if (!str || str != "inscription") return notify_fail("read what?\n");
    write("Pretty amulet blah blah.");
    return 1;
}
