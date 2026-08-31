#include <std.h>

inherit OBJECT;

int uses = 10;

void create() {
    ::create();
    set_name("slice of pie");
    set("id", ({"slice", "pie", "pumpkin pie"}) );
    set_short("a slice of pumpkin pie");
    set_long("This is a slice of Luna's pumpkin pie. It has magical restorative powers.");
}

void init() {
    ::init();
    add_action("cmd_eat", "eat");
}

int cmd_eat(string str) {
    if (!str || str != "pie")
        return notify_fail("You can't eat that.\n");
    if (!present("slice", this_player())) 
        return notify_fail("You don't have a slice of pie.\n");
  message("info", "You eat the pie and feel healed.\n", this_player());
  say(this_player()->query_cap_name()+" takes a bite of pie.\n");
    this_player()->add_hp(this_player()->query_max_hp(this_player()->query_hp()));
    this_player()->add_sp(this_player()->query_max_sp(this_player()->query_sp()));
    this_player()->add_mp(this_player()->query_max_mp(this_player()->query_mp()));
    uses--;

    if (uses <= 0) {
        this_object()->remove();
        message("info", "The pie is all gone.\n", this_player());
    }
    return 1;

}
