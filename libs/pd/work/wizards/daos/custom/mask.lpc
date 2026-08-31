#include <std.h>

inherit ARMOUR;

void create() {
    ::create();
    set_properties( (["no steal" : 1]) );
    set_name("mask");
    set("id", ({ "mask", "cerulean mask" }) );
    set_short("%^BLUE%^Ce%^RESET%^BOLD%^%^BLUE%^r%^RESET%^%^BOLD%^CYAN%^ul%^RESET%^"
      "%^BOLD%^ea%^RESET%^BOLD%^CYAN%^n%^RESET%^ %^BOLD%^CYAN%^M%^RESET"
      "%^BOLD%^BLUE%^a%^RESET%^BLUE%^sk%^RESET%^");
    set_long("%^BOLD%^BLACK%^This mask was composed out of a strange material "
      "which reflects every shade of%^RESET%^ %^BLUE%^blue%^RESET%^BOLD%^BLACK%^. "
      "This one of a kind mask was created especially for%^RESET%^ %^BOLD%^Kumi "
      "%^RESET%^BOLD%^BLACK%^by a great armorer of Minori%^RESET%^");
    set_type("mask");
    set_limbs( ({"head"}) );
}

int drop() {
    return 1;
}

int sell() {
    return 1;
}

int bury() {
    return 1;
}

int query_auto_load() {
    if(this_player()->query_name() == "kumi")
	return 1;
}

