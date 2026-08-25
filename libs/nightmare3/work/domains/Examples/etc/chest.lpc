/*    /d/Praxis/obj/misc/chest.c
 *    from Nightmare IV
 *    a lockable treasure chest
 *    created by Descartes of Borg 940212
 */

#include <std.h>
#include <objects.h>

inherit STORAGE;

void create() {
    object money;

    ::create();
    set_name("chest");
    set_id( ({ "chest" }) );
    set_adjectives( ({ "orc", "treasure" }) );
    set_short("an orc treasure chest");
    set_long("A huge treasure chest with a great big lock on it.");
    set_mass(2000);
    set_value(100);
    set_max_encumbrance(2000);
    set_can_close(1);
    set_can_lock(1);
    set_prevent_put("A treasure chest?  Right!");
    set_property("magic hold", 10);
    set_key("orc_treasure");
    money = new(OB_COINS);
    money->set_money("platinum", random(5));
    money->set_money("gold", random(100));
    money->set_money("copper", random(10000));
    money->move(this_object());
    set_closed(1);
    set_locked(1);
}
