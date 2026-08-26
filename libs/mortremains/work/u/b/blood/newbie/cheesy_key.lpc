
#include <mudlib.h>

inherit OBJECT;

void create() {
    set ("to_lock", "cheese key");
    set ("name", "cheese key");
    set ("long", @EndLong
A strange key, made entirely of some hard, alien cheese... probably best
not to eat it.
EndLong );
    set ("short", "a cheesy key");
    set ("id", ({ "key", "cheesy key", "cheese key", "cheese" }));
    set("lock_turn", 30);
    set("value", 1);
}

void init() {
    add_action("eat", "eat");
}

int eat(string str) {
    if (TO->id(str)) {
        write("You eat the key. Yumm!\n");
        say(TPN+" eats a key made of cheese.\n");
        remove();
        return 1;
    }
    return 0;
}

/* EOF */