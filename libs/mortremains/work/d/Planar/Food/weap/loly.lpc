#include <mudlib.h>

inherit WEAPON;

void create() {
    set("id", ({ "dagger", "lollypop" }) );
    set("short", "A lollypop");
    set("long", @PicklE
This is a lollypop shaped like a dagger, it dosen't look too good for
stabbing purposes, but you could eat it.
it, but it might be a bit dirty.
PicklE
    );
    set("name", "lollypop");
    set_weapon_type("dagger");
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
