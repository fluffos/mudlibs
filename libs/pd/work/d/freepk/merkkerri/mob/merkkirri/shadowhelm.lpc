#include <std.h>
inherit ARMOUR;

void create() {
::create();
set_name("helm");
set_short("%^RESET%^%^BLUE%^Helm of %^BOLD%^%^BLACK%^sh%^RESET%^%^BLUE%^ad%^BOLD%^%^BLACK%^ows%^RESET%^");
set_long("%^RESET%^%^BLUE%^The helm of shadows is a four-horned warhelm made of a strange black metal.  It has a built in visor that is shaped to appear as the blackened skull of a gnoll.  The metal is light and gives ample ventilation--always a plus while travelling in the hot Merkkirri jungles.%^RESET%^");
set_wear("%^BLUE%^You wear the helm of shadows and lock the visor into place.%^RESET%^");
set_remove("%^BLUE%^You unlock the visor and remove the helm of shadows.%^RESET%^");
set_id(({"helm", "warhelm", "helm of shadows", "shadowhelm"}));
set_ac(6);
set_weight(15);
set_type("helmet");
set_limbs(({"head"}));
}
int query_auto_load() {
if (this_player()->query_level() < 35) return 0;
return 1;
 }
