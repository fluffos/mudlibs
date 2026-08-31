#include <lib.h>

inherit LIB_STORAGE;

void create() {
    ::create();
    SetKeyName("chest");
    SetAdjectives(({"wooden","heavy"}));
    SetId(({"chest"}));
    SetShort("a wooden chest");
    SetLong("This is a heavy wooden chest used to store items.");
    SetMaxCarry(9000);
    SetInventory(([
                "/domains/cave/obj/omni" : 1,
                "/domains/cave/armor/boobytrap_ring" : 1,
                "/domains/cave/armor/necklace" : 1,
                ]));
    SetMoney( ([
                //"dollars" : random(50)+50,

                "universal credits" : random(200000)+200000,
                ]) );
    SetMass(2000);
    SetBaseCost("universal credits",50);
    SetCanClose(1);
    SetClosed(1);
    SetPreventGet("The chest does not budge.");
}

void init(){
    ::init();
}
