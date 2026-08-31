#include <std.h>
inherit ARMOUR;
void create() {
    ::create();
    set_name("%^BLACK%^%^BOLD%^T%^WHITE%^a%^BLACK%^b%^WHITE%^i %^BLACK%^S%^WHITE%^h%^BLACK%^o%^WHITE%^e%^BLACK%^s%^RESET%^");
    set("id", ({"tabi", "shoes", "tabi shoes", "boots"}) );
    set("short","%^BLACK%^%^BOLD%^T%^WHITE%^a%^BLACK%^b%^WHITE%^i %^BLACK%^S%^WHITE%^h%^BLACK%^o%^WHITE%^e%^BLACK%^s%^RESET%^"); 
    set("long", "%^BLACK%^%^BOLD%^The stealthy shoes allow you to walk without making a single sound. with a soft cushion on the bottom and the two-toed socks, you are now the %^GREEN%^envy%^BLACK%^ of all other ni%^WHITE%^n%^BLACK%^ja's!%^RESET%^");
    set_weight(4);
    set_type("boots");
    set_limbs(({"left foot","right foot"}));
    set_ac(2);
    set_curr_value("gold",300);
    set_wear("%^BLACK%^%^BOLD%^The slippers slide onto your feet with ease, your step is %^YELLOW%^lighter%^BLACK%^, your strides longer and you make not a single sound.%^RESET%^");
    set_remove("%^RED%^You sigh heavily as you remove the comfortable Tabi Shoes%^RESET%^");

}
int query_auto_load() {
    if (this_player()->query_guild()=="AoD") return 1;

}
