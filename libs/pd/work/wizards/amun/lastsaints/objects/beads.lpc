#include <std.h>
#include <amun.h>
inherit STONE;
void create() {
    ::create();
    set_name("beads");
    set_short("%^RESET%^%^ORANGE%^Beads%^RESET%^");
    set_long("%^RESET%^%^ORANGE%^Beads %^BOLD%^%^WHITE%^are meand for you to pray on, but these beads usually know your deepest thoughts and can hear your prayers for more magical powers. When you rub it, it hears your call.%^RESET%^");
    set_id( ({ "bead", "beads" }) );
    set_action("rub");
    set_remove_mess("%^BOLD%^%^WHITE%^The %^RESET%^ORANGE%^Beads %^BOLD%^%^WHITE%^fade away into nothingness.%^RESET%^");
    set_levels(({"blackened", "darkened", "flickering", "glowing", "beaming",
	"blazing" }));
    set_use_mess("%^BOLD%^%^WHITE%^You rub the %^RESET%^ORANGE%^Beads %^BOLD%^%^WHITE%^and instantly gain more power.");
    set_mass(1);
    set_value(0);
}
