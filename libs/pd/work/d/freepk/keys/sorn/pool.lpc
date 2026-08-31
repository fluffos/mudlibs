#include <std.h>
inherit OBJECT;

void create() {
    ::create();
    set_name("pool");
    set_short("%^BOLD%^%^BLUE%^a freshwa%^CYAN%^te%^BLUE%^r pool%^RESET%^");
    set_long("The small pond on this island is fresh water, and can "
      "be drunk. You can't help but think about entering the "
      "pool for a refreshing bath.");
    set_prevent_get("You only manage to get a few drops.");
    set_id(({ "pool", "pond", "freshwater pond", "freshwater pool" }));
}

int enter(string str) {
    if (!str) return 0;
    if (str != "pond" && str != "pool") return 0;
    write("%^BOLD%^%^BLUE%^You dive into pool!");
    say(this_player()->query_cap_name()+" dives into the pool!",
      this_player());
    this_player()->move_player("/d/freepk/keys/sorn/pool1", "pond");
    return 1;
}

int drink(string str) {
    if (!str || str == "") return 0;
    if (str != "from pond" && str != "from pool" && str != "pool"
      && str != "pond") return 0;
    if (this_player()->query_disable()) return notify_fail("You're "
	  "busy doing something else.\n");
    write("You drink from the pool.. refreshing.");
    this_player()->heal(10);
    this_player()->set_disable(1);
    return 1;
}

void init() {
    ::init();
    add_action("drink", "drink");
    add_action("enter", "bathe");
    add_action("enter", "dive");
    add_action("enter", "wade");
    add_action("enter", "enter");
}
