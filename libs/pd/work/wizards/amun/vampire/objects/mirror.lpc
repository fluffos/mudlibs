#include <std.h>
#include <lodos.h>
#include <vampq.h>
inherit OBJECT;
int flag;
void create() {
    ::create();
    set_name("Black-edged Mirror");
    set("id", ({"mirror"}) );
    set_short("%^BOLD%^%^BLACK%^Black-edged Mirror%^RESET%^");
    set_long("%^BOLD%^%^BLACK%^This mirror is lined with black edging and unlike the room it was found in, it is sparkling clean. Your reflection is staring back at you as if it is alive, inviting you in. As you focus on it for a bit longer the glass seems to shimmer and swirl ever so softly. Prehaps if you tried harder you might make some sense out of all this.\n\nA small inscription can be seen on the back.%^RESET%^");
    set_weight(1);
    flag = 0; 
}
mixed *query_auto_load() {
    if (this_player()->query_level() >= 20)
	return ({ base_name(this_object()), ({ flag }) });
    else return 0; 
}
void init_arg(mixed *args) {
    flag = args[0];
}
void init() {
    ::init();
    add_action("focus", "focus");
    add_action("read", "read");
    add_action("capture", "capture");
    add_action("release", "release");
}
int focus(string str) {
    if (str == "in mirror") {
	write("%^BOLD%^%^RED%^You focus all your energy into the mirror.%^RESET%^");
	this_player()->move(VR"transroom2");
	this_player()->force_me("look");
	find_object(VR"transroom2")->start_fmv("mirror");
	flag = 1;
	return 1;
    }
    write("%^BOLD%^%^RED%^You focus on the mirror and find nothing...%^RESET%^");
    return 1;
}
int read(string str) {
    if(!str)
	return notify_fail("Read what?\n");

    switch(str) {
    case "inscription":
	write("%^BOLD%^%^RED%^'%^WHITE%^There is a moment in time%^BLACK%^... %^WHITE%^When a mortal excels to a new status%^BLACK%^... %^WHITE%^It will open up an opportunity to either remort their ways and start again, or continue on and fulfill their destiny%^BLACK%^...\n\n%^WHITE%^At that time this mirrors true potential will show%^RED%^'%^RESET%^");
	break;
    }
    return 1;
}

int capture(string str) {
    if (str == "girl") {
	write("%^BOLD%^%^BLACK%^You hold the mirror directly out infront of you.\n\nThe room starts to %^WHITE%^s%^BLACK%^h%^WHITE%^ake%^BLACK%^ as a %^WHITE%^bright %^YELLOW%^blinding %^WHITE%^light%^BLACK%^ shines out.\n\nAn enormous t%^WHITE%^hu%^BLACK%^ndercl%^WHITE%^ap%^BLACK%^ followed by a %^WHITE%^flash%^BLACK%^ of %^YELLOW%^light%^BLACK%^ as the girl is sucked into the mirror.%^RESET%^");
	if (present("girl", environment(this_player()))) present("girl", environment(this_player()))->remove();
	return 1;
    }
    write("Nothing seems to happen...\n");
    return 1;

}

int release(string str) {
    object girl;
    if(!str)
	return notify_fail("Release who?\n");

    switch(str) {
    case "girl":
	write("%^BOLD%^%^BLACK%^The mirror shakes vigorously\n\nThe girl is thrown out of the mirror onto the ground\n%^RESET%^");
	new(VM"girl")->move(environment(this_object()));
	break;
    }
    return 1;
}
