#include <std.h>
#include <amun.h>
inherit ARMOUR;
void create() {
    ::create();
    set_name("pygmy cap");
    set("id", ({ "pygmy cap", "cap", "pygmy" }) );
    set("short",
      "%^BOLD%^%^BLUE%^p%^CYAN%^y%^BLUE%^g%^CYAN%^m%^BLUE%^y "
      "%^CYAN%^c%^BLUE%^a%^CYAN%^p%^RESET%^"
    );
    set("long",
      "%^BOLD%^%^CYAN%^This cap was created by the "
      "%^BLUE%^p%^CYAN%^y%^BLUE%^g%^CYAN%^m%^BLUE%^i%^CYAN%^e%^BLUE%^s "
      "%^CYAN%^in the sky. It offers little protection, "
      "but is quite cute!%^RESET%^"
    );
    set_type("helmet");
    set_ac(1);
    set_limbs( ({ "head" }) );
    set_weight(10);
    set_curr_value("gold", 50); 
}
int query_auto_load() {
    return this_player()->query_level() >= 30;
}
