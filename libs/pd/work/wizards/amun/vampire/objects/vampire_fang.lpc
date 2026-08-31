#include <std.h>
#include <vampq.h>
inherit OBJECT;
void create() {
    ::create();
    set_name("Vampire Fang");
    set("id", ({"fang", "tooth", "vampire quest fang"}) );
    set_short("%^BOLD%^%^BLACK%^Vampire %^BOLD%^%^WHITE%^F%^RESET%^%^RED%^a%^BOLD%^%^WHITE%^ng%^RESET%^");
    set_long("%^BOLD%^%^WHITE%^This f%^RESET%^%^RED%^a%^BOLD%^%^WHITE%^ng was a gift from the %^RED%^'%^WHITE%^Pale-skinned Man%^RED%^'%^WHITE%^. If us%^RESET%^%^RED%^e%^BOLD%^%^WHITE%^d correctly, it can be used to get through a t%^RESET%^%^RED%^o%^BOLD%^%^WHITE%^ugh gate.%^RESET%^");
    set_weight(1);
}
int query_auto_load() {
    if (this_player()->query_level() >= 20)
	return 1;
}
