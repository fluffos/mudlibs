#include <std.h>
#include <purgatory.h>
inherit BAG;

void create() {
    object money;

    ::create();
    set_id( ({"chest", "treasure chest", "purgatory chest", "purgatory pension chest"}) );
    set_name("chest");
    set("short", "The purgatory pension chest.");
    set("long", "The purgatory pension chest.\nIt is closed.");
    set_open_long("The purgatory pension chest.\nIt is open.");
    set_closed_long("The purgatory pension chest.\nIt is closed.");
    set_no_clean(1);
    set_weight(2000000);
    set_value(100);
    set_max_internal_encumbrance(2000);
    set_possible_to_close(1);
    set_lock("locked");
    set_key("Key_of_the_dead");
    set_property("magic hold", 10);
    money = new("std/obj/coins");
    money->set_money("platinum", 6543);
    money->set_money("gold", 15884);
    money->move(this_object());
}
