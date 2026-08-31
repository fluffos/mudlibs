#include <std.h>
#include <amun.h>
inherit WORKROOM;
int sigma;
int cmd_start(string str);
void init() {
    ::init();
    add_action("cmd_start", "start");
    add_action("move_desk", "move");
    add_action("move_board", "move");
}
object bb;
void create() {
    ::create();
    set_properties(([ "light" : 2, "night light" : 0, "no attack" : 1, "no magic" : 1, "no steal" : 1, "no bump" : 1]));
    set("short", "Amun's Castle");
    set("long","%^BOLD%^%^WHITE%^This room is an open room, with no walls at the base of a %^RESET%^%^ORANGE%^t%^RED%^r%^ORANGE%^ee%^BOLD%^%^WHITE%^. There is a large desk, placed in the center of the room, that holds all of Amuns computer and small trinkets. %^RESET%^%^GREEN%^W%^ORANGE%^i%^GREEN%^l%^GREEN%^d%^ORANGE%^l%^GREEN%^i%^ORANGE%^f%^GREEN%^e %^BOLD%^%^WHITE%^can be seen all around, as the walls are nonexistant.%^RESET%^");
    set_smell("default", "%^BOLD%^%^WHITE%^There is a smell of %^GREEN%^p%^RESET%^%^GREEN%^i%^BOLD%^%^GREEN%^n%^RESET%^%^GREEN%^e%^BOLD%^%^WHITE%^ wafting through the workroom.%^RESET%^");
    set_exits( ([ "huck" : "/wizards/huckleberry/workroom", "tirun" : "/d/nopk/tirun/square", "lounge" : "/d/nopk/standard/adv_inner", "north" : "/wizards/amun/bedroom", "blus" : "/wizards/ironman/workroom" ]) );
    bb = new("std/bboard");
    bb->set_name("Board of Greatness");
    bb->set_id( ({ "board", "board of", "of greatness", "board of greatness", "greatness" }) );
    bb->set_max_posts(200);
    bb->set_edit_ok( ({ "amun" }) );
    bb->set_location("/wizards/amun/workroom");
    bb->set_short("%^BOLD%^%^WHITE%^B%^RESET%^o%^BOLD%^%^WHITE%^a%^RESET%^r%^BOLD%^%^WHITE%^d %^RESET%^o%^BOLD%^%^WHITE%^f %^RESET%^G%^BOLD%^%^WHITE%^r%^RESET%^e%^BOLD%^%^WHITE%^a%^RESET%^t%^BOLD%^%^WHITE%^n%^RESET%^e%^BOLD%^%^WHITE%^s%^RESET%^s");
    bb->set_long("This board is for Amun, or her friends, to leave code or comments.");
    bb->set_board_id("amun_board");
    bb->move(environment(this_object()));
    new("/wizards/amun/desk")->move(this_object());
    allow_read_access( ({ "artemis", "overkill", "elathius" }) );
    allow_scan_access( ({ "elathius" }) );
    allow_write_access( ({ "elathius" }) );
    allow_guest_access( ({ "carina" }) );
    set_blocked_dirs( ({"bin", "cmds", "extra", "eyeofhell", "guilds", "hamenstomb", "heaven", "illuminati", "lastsaints", "marshes", "neverland", "sky"}) );
}
int cmd_start(string str) {
    if (!str || str=="") {
	notify_fail("Start where?\n");
	return 0;
    }
    if (str!="here")     {
	notify_fail("You cannot start there.\n");
	return 0;
    }
    this_player()->set_primary_start("/wizards/amun/workroom");
    write("You are now set to start here.");
    return 1;
}
int move_desk(string str) {
    if (!str || str != "desk") return notify_fail("move what?\n");
    write("%^BOLD%^%^RED%^You move the desk out of the way and are thrown into a room that reminds you of the '%^WHITE%^Revenge of the Nerds%^RED%^'.%^RESET%^");
    this_player()->move_player("/wizards/daos/workroom");
    return 1;
}
int move_board(string str) {
    if (!str || str != "board") return notify_fail("move what?\n");
    write("%^BOLD%^%^RED%^You move the board and are thrown into a dungeon!%^RESET%^");
    this_player()->move_player("/wizards/elathius/vampire/room");
    return 1;
}
