#include <lib.h>

inherit LIB_CHAIR;

void create() {
    chair::create();
    SetKeyName("wooden shelf");
    SetId( ({ "shelf" }) );
    SetAdjectives( ({ "wood","wooden", "simple", "medium-sized" "medium sized" }) );
    SetShort("a wooden shelf");
    SetLong("It is a simple shelf made of wood.");
    SetInventory(([
                "/domains/default/obj/cheatbook" : 1,
                "/domains/default/obj/phints" : 1,
                ]));
    SetMass(274);
    SetBaseCost("universal credits",1);
    SetBaseCost("universal credits",1);
    SetMaxCarry(5000);
    inventory_visible();
    inventory_accessible();
}

void init(){
    ::init();
}

mixed CanGet(object ob) { return "The shelf does not budge.";}
