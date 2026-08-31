#include <std.h>
#include <amun.h>
inherit ARMOUR;
void create() {
    ::create();
    set_name("white collar");
    set("id", ({ "collar", "white collar" }) );
    set("short", "%^BOLD%^%^WHITE%^white collar%^RESET%^");
    set("long",
      "%^BOLD%^%^WHITE%^This collar was made for the priests to wear. "
      "It symbolizes their commitment to a higher power.%^RESET%^"
    );
    set_type("necklace");
    set_ac(1);
    set_limbs( ({ "neck" }) );
    set_weight(30);
    set_curr_value("gold", 25); 
}
int query_auto_load() {
    return this_player()->query_level() >= 30;
}
