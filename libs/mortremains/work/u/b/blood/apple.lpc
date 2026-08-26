
inherit OBJECT;

void create() {
    set("short", "an apple");
    set("long", "Just an apple.\n");
    set("id", ({ "apple" }) );
}

void init() {
    add_action ("eat", "eat");
}

int eat( string str ) {
    if (str!="apple") {
	write("Eat what?\n");
	return 1;
    }

    write("You eat it all! Yum!\n");
    say(TPN+" devours an apple.\n");

    remove();
    return 1;
}

// EOF
