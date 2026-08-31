#include <std.h>
#include <amun.h>
inherit WEAPON;                                                         
void create() {
    ::create();                                                             
    set_name("ribbed bow");
    set("id", ({ "bow", "ribbed bow"}) );
    set("short",
      "%^BOLD%^%^WHITE%^r%^BLUE%^i%^WHITE%^b%^BLUE%^b%^WHITE%^e%^BLUE%^d "
      "%^WHITE%^b%^BLUE%^o%^WHITE%^w%^RESET%^"
    );
    set("long",
      "%^BOLD%^%^WHITE%^This "
      "%^BOLD%^%^WHITE%^r%^BLUE%^i%^WHITE%^b%^BLUE%^b%^WHITE%^e%^BLUE%^d "
      "%^WHITE%^B%^BLUE%^o%^WHITE%^w is made from rich "
      "%^RESET%^%^RED%^mahogany wood %^BOLD%^%^WHITE%^found in the Sky Temple. "
      "It was forged by the greatest of their monks.%^RESET%^"
    );
    set_type("bow");
    set_weight(20);
    set_curr_value("gold", 175);
    set_wc(10);
    set_type("ranged");
}
int query_auto_load() {
    return this_player()->query_level() >= 36;
}
