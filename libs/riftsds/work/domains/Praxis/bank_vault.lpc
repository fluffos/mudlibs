#include <lib.h>

inherit LIB_ROOM;

void create() {
    ::create();
    SetProperty("light", 2);
    SetProperty("indoors", 1);
    SetShort( "The bank vault");
    SetLong(
            "The Praxis Bank keeps all cash it has on hand in this otherwise "
            "empty vault.  The door on the south end leads to the lobby.");
    SetExits( 
            (["south" : "/domains/Praxis/bank"]) );
}

void reset() {
    object money;

    ::reset();
    if(!present("money")) {
        money = new("/std/lib/pile");
        money->SetCurrency("universal credits", random(100000));

        money->move(this_object());
    }
}
void init(){
    ::init();
}
