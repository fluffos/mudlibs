#include <std.h>
inherit ARMOUR;

void create() {
    ::create();
    set_name("acrilite wings");
    set_id(({"acrilite wings", "wings", "acrilite", "wing"}));
    set_short("%^BOLD%^%^WHITE%^Acrili%^RESET%^te Win%^BOLD%^%^WHITE%^gs%^RESET%^");
    set_long("%^BOLD%^%^WHITE%^These wings were forged for the pure and holy.%^RESET%^");
    set_type("wing armour");
    set_ac(2);
    set_limbs( ({ "right wing", "left wing" }) );
    set_weight(15);
    set_curr_value("gold", 100);  
}
int query_auto_load() {
    if (this_player()->query_level() >= 25)
	return 1;
}
void init() {
    ::init();
    add_action("do_fly", "fly");
}
int do_fly(string str) {
    if(this_player() != this_object()->query_worn())
	return 0;
    write("As you try to fly, you find yourself unable to move your wings because of the heavy armor.");
    return 1;
}
