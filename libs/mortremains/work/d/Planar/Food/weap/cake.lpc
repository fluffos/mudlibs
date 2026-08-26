#include <mudlib.h>

inherit WEAPON;

void create() {
    set("id", ({ "cake", "sword" }) );
    set("short", "A piece of cake");
    set("long", @PicklE
This is a piece of cake fasioned into a sword. It looks a bit hard,
but you could prolly eat it if you wanted to.
PicklE
    );
    set_weapon_type("sword/short");
    set("name", "cake");
    set_verbs(({ "slash", "stab", "cut" }));
    set("value", 10);
}
void init() {
    add_action("eat", "eat");
}
int eat(string str) {
    if (!str) {
	write("Eat what, the cake?\n");
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
