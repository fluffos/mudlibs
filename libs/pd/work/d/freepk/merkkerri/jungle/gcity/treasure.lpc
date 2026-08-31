#include <std.h>
inherit BAG;

void create() {
    object money;

    ::create();
    set_id( ({"chest", "treasure chest"}) );
    set_name("chest");
    set_short("a treasure chest");
    set_long("A solid iron chest with a lock.\nIt is closed.");
    set_no_clean(1);
    set_prevent_get("The chest itself is too heavy for you.");
    set_value(100);
    set_max_internal_encumbrance(2000);
    //   set_possible_to_close(1);
    set_lock("locked");
    set_property("magic hold", 10);
    set_key("ruby_key");
    money = new("std/obj/coins");
    money->set_money("platinum", random(5));
    money->set_money("gold", random(50));
    money->set_money("electrum", random(50));
    money->set_money("silver", random(100));
    money->move(this_object());
    toggle_closed();
}

