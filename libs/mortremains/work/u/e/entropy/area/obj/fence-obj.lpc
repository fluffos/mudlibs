#include "..cave.h"

inherit OBJECT;

void create() {
    ::create();
    set("name","fence-obj");
}

void init() {
    write("You have a sudden attack of claustraphobia.\n");
    add_action("TryGo","go");
}

int TryGo() {
    write("You try to go, but are stopped by some mystical force.\n");
    return 1;
}
