//rose_key.c
//opens the bedside table.
//Nsd  march 5, 2000

#include <mudlib.h>

inherit OBJECT;

create() {
    set("to_lock", "rose key");
    set("name", "rose key");
    set("long", "A key with the shape of a rose. It opens the table lock.\n");
    set("short", "A rose key");
    set("id", ({ "key", "rose key" }));
    set("lock_turn", 10);
    set("prevent_drop", 1);
    set("author", "nsd");
    set("prevent_give", 1);
    set("prevent_clean", 1);
    set("mass", 0);
}
int query_auto_load() { return 1; }
