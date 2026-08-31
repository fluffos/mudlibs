#include <std.h>
#include <metallicana.h>
inherit ARMOUR;
void create() {
    ::create();
    set_name("steel breastplate");
    set_short("%^ORANGE%^S%^WHITE%^tee%^ORANGE%^l Br%^WHITE%^eastpla%^ORANGE%^te");
    set_long("A sturdy steel breastplate. It would be good armour.");
    set_id(({"steel breastplate", "breastplate"}));
    set_ac(9);
    set_weight(32);
    set_curr_value("gold",89);
    set_type("armour");
    set_limbs(({"torso"}));
}
int query_auto_load() {
if (this_player()->query_level() > 44) return 1;
}
