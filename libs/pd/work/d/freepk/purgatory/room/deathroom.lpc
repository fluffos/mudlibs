#include <std.h>
#include <purgatory.h>


inherit ROOM;

void create() {
    ::create();
     set_name("deathroom");
     set_short("deathroom");
     set_long("%^BOLD%^%^BLACK%^Death, destruction and evil seep through the stones in this "
"%^BOLD%^%^BLACK%^room, filling it to bursting. Many a brave soul has stepped "
"%^BOLD%^%^BLACK%^in here to try and conquer the Grim Reaper but none have "
"%^BOLD%^%^BLACK%^succeeded. %^RESET%^%^RED%^D%^BOLD%^%^BLACK%^e%^RESET%^%^RED%^a%^BOLD%^%^BLACK%^t%^RESET%^%^RED%^h%^RESET%^%^BOLD%^%^BLACK%^ waits for his next challenge........ ");
     set_properties(([
        "light"       : 2,
        "no bump"     : 1,
        "no steal"    : 1,

]));
    set_smell("default", "Rotting meat and the stench of death fills the room");
    set_listen("default", "Wailing of tortured souls echoes around you");

set_exits((["north" : "/wizards/wraith/workroom" ]) ); 
}

void reset() {
    ::reset();

    if (!present("death"));
        new(MOBS"Death")->move(this_object());
}
