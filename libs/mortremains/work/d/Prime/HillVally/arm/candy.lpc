#include <mudlib.h>

inherit ARMOR ;

void create() {
    seteuid(getuid());

    set("id", ({ "plate", "chocolate", "plate mail", "suit" }) );
    set("short", "chocolate plate mail");
    set("long", @EndText
Whereas this dosen't offer much protection, it does look yummy.
It looks like sheets of chocolate melted together.
EndText
    );
    set_armor_type("plate");
    set("value", 30);
}
void init() {
    add_action("eat", "eat");
}
int eat(string str) {
    if(!str) {
	write("Eat what the platemail?\n");
	return 1;
    }
    if (id(str)) {
	write("You gobble up the platemail.\n");
	say(TPN+" munches down on thier platemail.\n");
	remove();
	return 1;
    }
    return 0;
}
