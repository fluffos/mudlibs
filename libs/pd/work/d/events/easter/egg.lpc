#include <std.h>

inherit OBJECT;

int i;
string str = "What?";

#define COLORS ({"%^BOLD%^RED%^red%^RESET%^", "%^BOLD%^GREEN%^green%^RESET%^", "%^BOLD%^YELLOW%^yellow%^RESET%^", "%^BOLD%^BLUE%^blue%^RESET%^", "%^BOLD%^MAGENTA%^magenta%^RESET%^"})

#define NOCOLORS ({"red", "green", "yellow", "blue", "magenta"})

void create() {
    ::create();
    i = random(sizeof(COLORS));
    set_id( ({"egg", NOCOLORS[i]+" egg"}) );
    set_properties( (["no auction" : 1]) );
    set_name("egg");
    set_short(COLORS[i]+" egg");
    set_long("This is an ordinary egg.");
}

void init() {
    ::init();
    add_action("cmd_eat", "eat");
}


int drop() {
    write(str);
    return 1;
}

int give() {
    write(str);
    return 1;
}

int bury() {
    write(str);
    return 1;
}

int sell() {
    write(str);
    return 1;
}

int cmd_eat() {
    int i = random(100);

    write("You eat the egg.");
    if (i > 80) {
	this_player()->add_poisoning(random(i));
	return 1;
    }
}













