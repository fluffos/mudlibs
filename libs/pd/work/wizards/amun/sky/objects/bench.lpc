#include <std.h> 
#include <amun.h>
inherit OBJECT;
void create() {
    ::create();
    set_name("bench");
    set("id", ({"bench"}) );
    set_short("%^RESET%^%^ORANGE%^B%^RED%^e%^ORANGE%^nch%^RESET%^");
    set_long("%^BOLD%^%^WHITE%^This bench was placed here to aid those who have tired feet after a long travel. It is said to have healing powers.%^RESET%^");
    set_prevent_get("CLETPO! Don't take me!");
    set_weight(75);
}
void init() {
    ::init();
    add_action("sit", "sit");
}

int sit(string str) {
    if (str == "on bench") {
	write("%^BOLD%^%^CYAN%^You sit down on the cushioned bench to rest and feel your whole body tingle.%^RESET%^");
	this_player()->add_hp(200+random(300));
	this_player()->add_sp(100+random(200));
	this_player()->add_mp(100+random(200));
	this_player()->set_paralyzed(8);
	return 1;
    }
    write("The only thing to sit on is the bench.");
    return 1;

}
