
#include <mudlib.h>

inherit WEAPON;

void create() {
    set("id", ({ "bombpop", "mace" }) );
    set("short", "A bombpop");
    set("long", @PicklE
This looks like a Bombpop, 3 colors. It looks like a mace, you could eat
it, but it might be a bit dirty.
PicklE
    );
    set_weapon_type("mace");
    set("name", "bombpop");
    set_verbs(({ "slash", "stab", "cut" }));
    set("value", 10);
}
void init() {
    add_action("eat", "eat");
}
int eat(string str) {
    if (!str) {
	write("Eat what, the bombpop?\n");
	return 1;
    }
    if (id(str)) {
	say (TPN+" eats their sword, right in front of you.\n");
	write("You gobble up the sword till nothing remains.\n");
	remove();
	return 1;
    }
    return 0;
}
