#include <std.h>
#include <metallicana.h>
inherit ARMOUR;
void create() {
    ::create();
    set_name("Belt");
    set_short("%^BOLD%^%^BLUE%^W%^WHITE%^a%^BLUE%^t%^WHITE%^e%^BLUE%^r %^BOLD%^%^BLUE%^C%^WHITE%^a%^BLUE%^p%^WHITE%^e%^RESET%^");
    set_long("The Cape is made from the hide of a water snake.");
    set_id(({"cape", "water cape"}));
    set_ac(4);
    set_weight(13);
    set_curr_value("gold",119);
    set_type("cloak");
    set_limbs(({"torso"}));
}
int query_auto_load() {
if (this_player()->query_level() > 44) return 1;
}
