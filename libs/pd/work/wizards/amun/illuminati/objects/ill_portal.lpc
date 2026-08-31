#include <std.h>
#include <amun.h>
inherit OBJECT;
void create() {
    ::create();
    set_id(({"portal", "portal of the illuminati"}));
    set_name("%^BOLD%^%^YELLOW%^Portal %^WHITE%^of the %^YELLOW%^Illuminati");
    set_long("%^BOLD%^%^WHITE%^The is the %^YELLOW%^Illuminati portal%^WHITE%^, it links all the halls of the guild together. You may <%^RED%^enter%^WHITE%^> any of these places:\n  %^YELLOW%^Hall%^RESET%^\n  %^YELLOW%^Tirun%^RESET%^\n");
    set_short("%^BOLD%^%^YELLOW%^Portal %^WHITE%^of the %^YELLOW%^Illuminati");
    set_weight(0);
    set_prevent_get("%^BOLD%^%^WHITE%^The portal is ethereal and cannot be touched, only passed through.");
}
void init() {
    ::init();
    add_action("travel", "enter");
}
int travel(string str) {
    if (!str || str == "")
	return notify_fail("Where are you going?\n");
    if (str == "tirun") {
	this_player()->move_player(ILLROOM "ill_37", "into the portal");
	write("\nStepping through the portal find yourself in Tirun.\n");
	return 1;
    }
    if (str == "hall") {
	this_player()->move_player(ILLROOM "ill_14", "into the portal");
	write("\nStepping through the portal find yourself in the Guild Hall.\n");
	return 1;
    }
    write("You sure that is a place?");
    return 1;
}
