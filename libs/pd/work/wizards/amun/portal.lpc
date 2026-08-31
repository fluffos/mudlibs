#include <std.h>
#include <amun.h>
inherit OBJECT;
void create() {
    ::create();
    set_id(({"portal", "Guild Portal"}));
    set_name("Guild Portal");
    set_long("%^BOLD%^%^WHITE%^The Guild Portal links all the Guild Halls together. You may %^RED%^<enter> %^WHITE%^any of these places:%^RESET%^\n  %^BOLD%^%^YELLOW%^aod%^RESET%^\n  %^BOLD%^%^YELLOW%^saints%^RESET%^\n  %^YELLOW%^bs%^RESET%^\n  %^BOLD%^%^YELLOW%^vort%^RESET%^\n  %^BOLD%^%^YELLOW%^ds%^RESET%^\n  %^BOLD%^%^YELLOW%^ill%^RESET%^\n  %^BOLD%^%^YELLOW%^unholy%^RESET%^\n  %^BOLD%^%^YELLOW%^forsaken%^RESET%^\n  %^BOLD%^%^YELLOW%^dw%^RESET%^\n");
    set_short("%^BOLD%^WHITE%^Guild %^YELLOW%^Portal%^RESET%^");
    set_weight(0);
    set_prevent_get("The portal is ethereal and cannot be touched, only passed through.");
}
void init() {
    ::init();
    add_action("travel", "enter");
}
int travel(string str) {
    if (!str || str == "")
	return notify_fail("Where are you going?\n");
    if (str == "aod") {
	this_player()->move_player("/d/guilds/AoD/hall", "into the portal");
	write("\nStepping through the portal find yourself in the hall of AOD.\n");
	return 1;
    }
    if (str == "saints") {
	this_player()->move_player("/d/guilds/lastsaints/rooms/last_saints_board", "into the portal");
	write("\nStepping through the portal find yourself in the hall of the Last Saints.\n");
	return 1;
    }
    if (str == "bs") {
	this_player()->move_player("/d/guilds/blacksails/hall", "into the portal");
	write("\nStepping through the portal find yourself in the hall of Blacksails.\n");
	return 1;
    }
    if (str == "vort") {
	this_player()->move_player("/d/guilds/vorticon/hall", "into the portal");
	write("\nStepping through the portal find yourself in the hall of Vorticon.\n");
	return 1;
    }
    if (str == "ds") {
	this_player()->move_player("/d/guilds/darksoul/hall", "into the portal");
	write("\nStepping through the portal find yourself in hall of the Darksouls.\n");
	return 1;
    }
    if (str == "ill") {
	this_player()->move_player("/d/guilds/illuminati/rooms/board", "into the portal");
	write("\nStepping through the portal find yourself in hall of Illuminati.\n");
	return 1;
    }
    if (str == "unholy") {
	this_player()->move_player("/d/guilds/unholy/hall", "into the portal");
	write("\nStepping through the portal find yourself in hall of Unholy.\n");
	return 1;
    }
    if (str == "forsaken") {
	this_player()->move_player("/d/guilds/forsaken/hall", "into the portal");
	write("\nStepping through the portal find yourself in hall of Forsaken.\n");
	return 1;
    }
    if (str == "dw") {
	this_player()->move_player("/d/guilds/dw/hall", "into the portal");
	write("\nStepping through the portal find yourself in the of Dragon Warriors.\n");
	return 1;
    }
    write("You sure that is a place?");
    return 1;
}
