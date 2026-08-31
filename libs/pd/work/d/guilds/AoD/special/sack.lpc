#include <std.h>
inherit PACK;
void create() {
    ::create();
    set_name("%^BLACK%^%^BOLD%^A%^WHITE%^o%^BLACK%^D %^WHITE%^S%^BLACK%^a%^WHITE%^c%^BLACK%^k%^RESET%^");
    set("id", ({"sack", "aodsack", "Sack"}) );
    set("short", "%^BLACK%^%^BOLD%^A%^WHITE%^o%^BLACK%^D %^WHITE%^S%^BLACK%^a%^WHITE%^c%^BLACK%^k%^RESET%^");
    set("long", "%^WHITE%^%^BOLD%^This trusty sack has carried home many a %^BLUE%^trophy %^WHITE%^from battle. The bag itself is made of elf skin and the string apprears to be a unicorns mane.%^RESET%^");
    set_weight(5);
    set_max_internal_encumbrance(3500);
    set_curr_value("gold", 300);
    set_wear("%^RED%^You %^ORANGE%^snat%^RED%^ch up t%^ORANGE%^he sack i%^RED%^n a firm g%^ORANGE%^rip and th%^RED%^row it over you%^ORANGE%^r shoulder.\n%^RESET%^");
    set_remove("%^BLACK%^%^BOLD%^You remove your sack to cash in your %^GREEN%^loot%^RESET%^.");

}
int query_auto_load() {
    if (this_player()->query_guild()=="AoD") return 1;

}
