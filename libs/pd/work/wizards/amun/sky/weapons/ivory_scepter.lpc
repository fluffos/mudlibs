#include <std.h>
#include <amun.h>
inherit WEAPON;                                                         
void create() {
    ::create();                                                             
    set_name("ivory scepter");
    set("id", ({ "ivory scepter", "scepter" }) );
    set("short",
      "%^BOLD%^%^WHITE%^i%^RESET%^v%^BOLD%^%^WHITE%^o"
      "%^RESET%^r%^BOLD%^%^WHITE%^y "
      "%^RESET%^s%^BOLD%^%^WHITE%^c%^RESET%^e%^BOLD%^%^WHITE%^p"
      "%^RESET%^t%^BOLD%^%^WHITE%^e%^RESET%^r"
    );
    set("long",
      "%^BOLD%^%^WHITE%^This "
      "%^RESET%^s%^BOLD%^%^WHITE%^c%^RESET%^e%^BOLD%^%^WHITE%^p"
      "%^RESET%^t%^BOLD%^%^WHITE%^e%^RESET%^r "
      "%^BOLD%^%^WHITE%^gleams "
      "i%^RESET%^v%^BOLD%^%^WHITE%^o%^RESET%^r%^BOLD%^%^WHITE%^y "
      "in the light. Below the smoothed top, rings of gold wave "
      "from the sides and tinkle with each movement.%^RESET%^"
    );
    set_weight(20);
    set_curr_value("gold", 125);
    set_wc(9);
    set_type("blunt");
}
int query_auto_load() {
    return this_player()->query_level() >= 36;
}
