#include <std.h>
#include <purgatory.h>
inherit BAG;

void create() {
    object money;

    ::create();
    set_id( ({"chest", "treasure chest", "purgatory chest", "purgatory pension chest"}) );
    set_name("chest");
    set("short", "The Purgatory pension chest");
    set("long", "A large iron bound chest. It looks very sturdy and secure.");
    set_no_clean(1);
    set_max_internal_encumbrance(2000);
    set_possible_to_close(1);
    set_closed(1);
    set_lock("locked");
    set_key("Key_of_the_dead");
    set_lockable(1);
    set_property("magic hold", 10);
    set_prevent_get("This chest is much to heavy to lift");
    money = new("std/obj/coins");
    money->set_money("platinum", 25+random(50));
    money->set_money("gold", 200+random(500));
    money->move(this_object());
}
