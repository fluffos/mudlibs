#include <move.h>
#include <mudlib.h>

inherit OBJECT ;

void create() {

        set ("id", ({ "sign" }) ) ;
        set ("short", "A charred an ancient sign is here.");
        set ("long", "It is a sign, which are traditionally read.\n");
        set ("prevent_get",1);
}
void init() {
        add_action("read","read");
}
int read(string arg) {
        if (!arg) return notify_fail("Read what?\n");
        if (arg != "sign") return notify_fail("Try reading the sign...\n");

    write("                  WARNING\n");
    write(" -----------------------------------------\n");
    write(" You are now entering an area intended for\n");
    write(" high-level players ONLY. Everything past\n");
    write(" this sign is almost exclusively player-\n");
    write(" killing, and the populace are NOT known \n");
    write(" for their friendliness.\n");
    write("\n Be wary, adventurer!\n");

        return 1;
}
