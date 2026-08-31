//  Stat Bonus Potion

#include <std.h>

inherit OBJECT;

void create() {
    ::create();
    set_name("bonus potion");
    set_short("a small potion");
    set_long("A red potion with white streaks swirling about.  You might "
      "try <quaff>ing it.");
    set_id(({ "potion","small potion" }));
}

void init() {
    ::init();
    add_action("quaff", "quaff");
}

int quaff(string str) {
    if(!str || str == "")
	return notify_fail("Quaff what?\n");
    write("You quaff down the potion and you feel a rush of energy flow "
      "through your body. This feeling of empowerment will not last long...\n");
    this_player()->add_stat_bonus("wisdom", 2, 1800);
    this_player()->add_stat_bonus("strength", 2, 1800);
    this_player()->add_stat_bonus("constitution", 2, 1800);
    this_player()->add_stat_bonus("dexterity", 2, 1800);
    this_player()->add_stat_bonus("charisma", 2, 1800);
    this_player()->add_stat_bonus("intelligence", 2, 1800);
    this_player()->add_magic_protection(({0,5,1800}));
    this_object()->remove();
    return 1;
}

