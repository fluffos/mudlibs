
#include <mudlib.h>

inherit WEAPON;

void create() {
    set("id", ({ "whip", "licorice" }) );
    set("short", "A black licorice whip");
    set("long", @PicklE
This is a piece of candy that has been used as a whip. You could eat
it, but it might be a bit dirty.
PicklE
    );
    set_weapon_type("whip");
    set("name", "licorice whip");
    set_verbs(({ "slash", "stab", "cut" }));
    set("value", 10);
}
void init() {
    add_action("eat", "eat");
}
int eat(string str) {
    if (!str) {
	write("Eat what, the whip?\n");
	return 1;
    }
    if (id(str)) {
	say (TPN+" eats their whip, right in front of you.\n");
	write("You gobble up the whip till nothing remains.\n");
	remove();
	return 1;
    }
    return 0;
}
