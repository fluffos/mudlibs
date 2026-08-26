#include <mudlib.h>
#include <config.h>

inherit PRIVATE_ROOM;

void create() {
    ::create();
    seteuid(getuid());

    set("light", 1);
    set("short", "Drift's Residence");
    set("c_long", "\n");
}

void init() {
    ::init();
}
