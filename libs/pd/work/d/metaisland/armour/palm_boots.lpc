#include <std.h>
#include <metallicana.h>
inherit ARMOUR;
void create() {
    ::create();
    set_name("boots");
    set_short("%^BOLD%^GREEN%^Pa%^WHITE%^l%^GREEN%^m%^WHITE%^ Bo%^GREEN%^o%^WHITE%^ts%^RESET%^");
    set_long("The inside of the boots is soft and fits well. The light weight materials still provide good protection.");
    set_id(({"boots", "palm boots"}));
    set_ac(5);
    set_weight(15);
    set_curr_value("gold",96);
    set_type("boots");
    set_limbs(({"left foot", "right foot"}));
}
int query_auto_load() {
if (this_player()->query_level() > 30) return 1;
}
