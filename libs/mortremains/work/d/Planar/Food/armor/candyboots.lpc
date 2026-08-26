#include <mudlib.h>

inherit ARMOR ;

void create() {
    seteuid(getuid());

    set("id", ({ "boots", "candy coating" }) );
    set("short", "candy coated boots");
    set("long", @EndText
These are boots made of what looks like paper, dipped in that stuff 
they use on candy apples. These candy coated boots were definatally
not made for walking.
EndText
    );
    set_armor_type("boots");
    set("value", 10);
}
void init() {
    add_action("eat", "eat");
}
int eat(string str) {
    if(!str) {
	write("Eat what the boots?\n");
	return 1;
    }
    if (id(str)) {
	write("You gobble up the boots.\n");
	say(TPN+" munches down on thier boots.\n");
	remove();
	return 1;
    }
    return 0;
}
