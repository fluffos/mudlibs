#include <std.h>
#include <amun.h>
inherit ROOM;
void create() {
    ::create();
    set_property("indoors", 1);
    set_property("light", 2);
    set("short", "HAMEN'S TOMB");
    set("long","%^BOLD%^%^BLACK%^The r%^RED%^o%^BLACK%^om h%^RED%^a%^BLACK%^s gone %^RED%^p%^BLACK%^itch black wi%^RED%^t%^BLACK%^h %^RED%^red lights %^BLACK%^fli%^RED%^c%^BLACK%^kerin%^RED%^g %^BLACK%^in and %^RED%^o%^BLACK%^ut of the ro%^RED%^o%^BLACK%^m.  The writi%^RED%^n%^BLACK%^gs on the wall%^RED%^s %^BLACK%^are now in %^RED%^b%^BLACK%^right %^RED%^red%^BLACK%^.  The fl%^RED%^o%^BLACK%^oring is ve%^RED%^r%^BLACK%^y loos%^RED%^e%^BLACK%^.\n");
    set_items( ([ "writings": "%^BOLD%^%^BLACK%^In the darkness of the Pyramid, a mythical being can be found. If you find it, and respond to the unclear, you will find the '%^RED%^occulus inferi%^BLACK%^'." ]) );
    set_exits( ([ "up": ROOMS+"hamen_tomb_145", "west": ROOMS+"hamen_tomb_141" ]) );
    new(MON+"criosphinx")->move(this_object());
}
void init() {
    ::init();
    add_action("break_floor", "break");
}
int break_floor(string str) {
    if (!str || str != "floor") return notify_fail("Break what?\n");
    write("%^BOLD%^%^RED%^You break open the floor and are sucked into a %^BLACK%^black hole.  You are winding around in around for what seems like 10 minutes before you are %^RED%^spat out into the %^BLACK%^'Eye of %^RED%^Hell%^BLACK%^'%^RED%^.");
    this_player()->move_player(HELLROOM+"eye_of_hell_1");
    return 1;
}
