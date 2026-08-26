#include "..cave.h"

inherit OBJECT;

void create() {
    ::create();
    seteuid(getuid());
    set("name","fear-obj");
}

void init() {
    write("You cower in the corner.\n");
    call_out(30,"EndFear");
    say(TP->QCN+" cowers in the corner.\n");
}

void EndFear() {
    write("You suddenly feel more courageous.\n");
    remove();
}
