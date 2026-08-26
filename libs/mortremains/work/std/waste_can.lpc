#include <mudlib.h>

inherit CONTAINER ;

void create() {
    ::create() ;
    set("author", "cyanide");
    set("short", "a blue waste receptacle");
    set("id", ({ "can", "receptacle" }) );
    set_possible_to_close(0);
    set_open_long(@EndText
A can to put worthless stuff in.
EndText
    );
    set("prevent_get", 1);
    set ("mass", 200) ;
    // Capacity is the total amount of mass than can be put in the bag, and
    // volume is the total amount of bulk that can be put in.
    set("capacity", 10000);
    set ("volume", 225) ;
}

// Since both container.c and lock.c have inits, we have to call
// init in both.

void init() {
    container::init() ;
}
