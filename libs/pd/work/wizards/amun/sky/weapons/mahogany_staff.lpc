#include <std.h>
#include <amun.h>
inherit WEAPON;                                                         
void create() {
    ::create();                                                             
    set_name("mahogany staff");
    set("id", ({ "staff", "mahogany staff" }) );
    set("short",
      "%^BOLD%^%^WHITE%^m%^RESET%^%^ORANGE%^a%^BOLD%^%^WHITE%^h"
      "%^RESET%^%^ORANGE%^o%^BOLD%^%^WHITE%^g%^RESET%^%^ORANGE%^a"
      "%^BOLD%^%^WHITE%^n%^RESET%^%^ORANGE%^y "
      "%^BOLD%^%^WHITE%^s%^RESET%^%^ORANGE%^t%^BOLD%^%^WHITE%^a"
      "%^RESET%^%^ORANGE%^f%^BOLD%^%^WHITE%^f%^RESET%^"
    );
    set("long",
      "%^BOLD%^%^WHITE%^This m%^RESET%^%^ORANGE%^a%^BOLD%^%^WHITE%^h"
      "%^RESET%^%^ORANGE%^o%^BOLD%^%^WHITE%^g%^RESET%^%^ORANGE%^a"
      "%^BOLD%^%^WHITE%^n%^RESET%^%^ORANGE%^y "
      "%^BOLD%^%^WHITE%^s%^RESET%^%^ORANGE%^t%^BOLD%^%^WHITE%^a"
      "%^RESET%^%^ORANGE%^f%^BOLD%^%^WHITE%^f is made from the finest wood "
      "in the Sky Temple. It was crafted by the greatest of their monks."
      "%^RESET%^"
    );
    set_weight(20);
    set_curr_value("gold", 125);
    set_wc(10);
    set_type("blunt");
}
int query_auto_load() {
    return this_player()->query_level() >= 36;
}
