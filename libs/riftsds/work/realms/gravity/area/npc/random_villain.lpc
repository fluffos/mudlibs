// /realms/gravity/area/npc/random_villain.c
#include <lib.h>

inherit LIB_NPC;

void create() {
    npc::create();
    SetKeyName("villain");
    SetId( ({ "villain", "random villain" }) );
    SetAdjectives( ({ "random" }) );
    SetShort("a random villain");
    SetLong("This is a randomly generated villain.");
    SetRace("human");
    SetClass("fighter");
    SetLevel(5);
    SetGender("male");
    SetInventory( ([
        "/domains/town/weap/shortsword" : "wield sword",
    ]) );
}

void init(){
    ::init();
}