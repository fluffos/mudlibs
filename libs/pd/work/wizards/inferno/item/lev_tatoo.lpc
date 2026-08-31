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
   return ob+
          " has a tatoo of a rainbow on his forehead.\n";
}
