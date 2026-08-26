#include <mudlib.h>

inherit ARMOR ;

void create() {
    seteuid(getuid());

    set("id", ({ "helmet", "chocolate" }) );
    set("short", "a white chocolate helmet");
    set("long", @EndText
This is a helmet made of white chocolate. It dosen't offer much
protection, but it looks yummy to eat.
EndText
    );
    set_armor_type("helmet");
    set("value", 10);
}
void init() {
    add_action("eat", "eat");
}
int eat(string str) {
    if(!str) {
	write("Eat what the helmet?\n");
	return 1;
    }
    if (id(str)) {
	write("You gobble up the helmet.\n");
	say(TPN+" munches down on thier helmet.\n");
	remove();
	return 1;
    }
    return 0;
}
