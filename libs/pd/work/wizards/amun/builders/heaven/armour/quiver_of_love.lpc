#include <std.h>
#include <amun.h>
inherit QUIVER;
void create() {
    ::create();
    set_name("Quiver of Love");
    set("id", ({ "quiver", "quiver of", "quiver of love" }) );
    set("short", "%^BOLD%^%^WHITE%^Q%^RESET%^ui%^BOLD%^%^WHITE%^v%^RESET%^e%^BOLD%^%^WHITE%^r %^RESET%^o%^BOLD%^%^WHITE%^f L%^MAGENTA%^o%^WHITE%^v%^MAGENTA%^e%^RESET%^");
    set("long", "%^BOLD%^%^WHITE%^This quiver has many magical arrows.%^RESET%^");
    set_type("quiver");
    set_ac(3);
    set_limbs( ({ "torso" }) );
    set_weight(17);
    set_curr_value("gold", 100);
}
int query_auto_load() {
    if (this_player()->query_level() > 40)
	return 1;
}
