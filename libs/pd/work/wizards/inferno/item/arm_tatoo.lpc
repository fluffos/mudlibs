#include <std.h>

inherit OBJECT;

string owner;
void create() {
    set_name("tatoo");
    set_short("");
    set_id( ({ "tatoo" }));
    set_weight(0);
}

int drop() { return 1; }

string extra_look() {
    string ob;
    ob = environment(this_object())->query_cap_name();
    return "%^BOLD%^%^GREEN%^"+ob+
           " has a tatoo of a goblin on his left arm.%^RESET%^\n";
}
