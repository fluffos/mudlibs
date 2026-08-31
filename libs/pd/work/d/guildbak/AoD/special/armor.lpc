#include <std.h>
inherit ARMOUR;
void create() {
    ::create();
    set_name("%^RED%^%^BOLD%^H%^WHITE%^u%^RED%^m%^WHITE%^a%^RED%^n %^WHITE%^R%^RED%^i%^WHITE%^b%^RED%^c%^WHITE%^a%^RED%^g%^WHITE%^e%^RESET%^");
    set("id", ({"ribcage", "armour", "armor", "human"}) );
    set("short","%^RED%^%^BOLD%^H%^WHITE%^u%^RED%^m%^WHITE%^a%^RED%^n %^WHITE%^R%^RED%^i%^WHITE%^b%^RED%^c%^WHITE%^a%^RED%^g%^WHITE%^e%^RESET%^"); 
    set("long", "%^BLACK%^%^BOLD%^The %^WHITE%^a%^BLACK%^rmy %^WHITE%^o%^BLACK%^f %^WHITE%^d%^BLACK%^arkness uses a ti%^WHITE%^tani%^BLACK%^um alloy to harden the ribcages of its victims. No blade in this %^RED%^h%^YELLOW%^e%^RED%^l%^YELLOW%^l%^BLACK%^ could pierce or crack such a masterwork piece of armour.");
    set_weight(45);
    set_type("armour");
    set_limbs(({"torso","left arm","right arm"}));
    set_ac(15);
    set_curr_value("gold",300);
    set_wear("%^WHITE%^%^BOLD%^The armor covers your body and you feel MUCH safer%^RESET%^");
    set_remove("%^WHITE%^%^BOLD%^You feel much more vulnerable.%^RESET%^");

}
int query_auto_load() {
    if (this_player()->query_guild()=="AoD") return 1;

}
