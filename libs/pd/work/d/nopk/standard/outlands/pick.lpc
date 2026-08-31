#include <std.h>
inherit OBJECT;

void create() {
 ::create();
   set_name("lockpick");
   set_short("a small, silver lockpick");
   set_long("These small, silver tools are used to pick locks, "
            "part of most theives' arsenal. The lockpick is two "
            "small, needle-like tools, that could fit in almost any "
            "lock.");
   set_id(({ "lockpick", "pick", "tool", "arsenal" }));
   set_property("lockpicking tool", 25);
   set_weight(3);
}

int query_auto_load() { if (this_player()->query_class() == "rogue") return 1; }
