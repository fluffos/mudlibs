#include <std.h>
inherit WEAPON;

create() {
 ::create();
   set_id(({ "hammer", "old sledge hammer", "sledge hammer" }) );
   set_name("hammer");
   set_short(
    "%^BOLD%^%^BLACK%^a%^RESET%^%^RED%^n%^BOLD%^%^BLACK%^ "
    "o%^RESET%^%^RED%^l%^BOLD%^%^BLACK%^d%^RESET%^%^RED%^ "
    "s%^BOLD%^%^BLACK%^l%^RESET%^%^RED%^e%^BOLD%^%^BLACK%^d%^RESET%^%^RED%^g%^BOLD%^%^BLACK%^e%^RESET%^%^RED%^ "
    "h%^BOLD%^%^BLACK%^a%^RESET%^%^RED%^m%^BOLD%^%^BLACK%^m%^RESET%^%^RED%^e%^BOLD%^%^BLACK%^r%^RESET%^");
   set_long("The black hammer has a three foot long "
            "handle. It may be old, but it will get the job done.");
   set_weight(7);
    set_curr_value("gold", 35);
   set_hands(2);
   set_wc(4);
   set_type("blunt");
}

int query_auto_load() { return 1; }
