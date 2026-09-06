// Living gate!

#include <npc.h>

string
my_long(int mode, object me) {
    if(open) return "There are have brass gates here, thrown wide open.";
    return "The gates are closed, blocking your way.";
}

create_monster() {
    set_name("gate");
    set_long(#'my_long);
    set_level(50);
}
