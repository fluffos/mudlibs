#include <std.h>
#include <amun.h>
inherit OBJECT;
void create() {
    ::create();
    set_id(({"portal", "portal of heaven"}));
    set_name("%^BOLD%^%^YELLOW%^Portal %^WHITE%^of %^YELLOW%^Heaven");
    set_long("%^BOLD%^%^WHITE%^The is %^YELLOW%^Heaven's portal%^WHITE%^, it takes travelers back to the real world. There is only one place you may <%^YELLOW%^enter%^WHITE%^>:\n  %^YELLOW%^Portal%^RESET%^\n");
    set_short("%^BOLD%^%^YELLOW%^Portal %^WHITE%^of %^YELLOW%^Heaven%^RESET%^");
    set_weight(0);
    set_prevent_get("The portal is ethereal and cannot be taken, only passed through.");
}
void init() {
    ::init();
    add_action("travel", "enter");
}
int travel(string str) {
    if (!str || str == "")
	return notify_fail("Where are you going?\n");
    if (str == "portal") {
	this_player()->move_player("/d/lodos/l3bell", "into the portal");
	write("\n%^BOLD%^%^WHITE%^Stepping through the portal find yourself in back on the earth.%^RESET%^\n");
	return 1;
    }
    write("You sure that is a place?");
    return 1;
}
