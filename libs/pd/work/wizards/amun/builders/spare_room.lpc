#include <std.h>
#include <amun.h>
inherit ROOM;
#define ALLOWED ({"amun", "daos", "rull", "artemis", "hepualahaole", "stormbringer", "whit", "luna"})
#define DISALLOW ({"sky", "art", "nesoo", "ill", "marshes", "saints", "out", "tomb"})
void create() {
    ::create();
    set_properties(([  "no attack"   : 1,
	"no magic"    : 1,
	"no bump"     : 1,
	"light"       : 2,
	"no scry"     : 1,
	"indoors"     : 1,
	"no steal"    : 1
      ]));
    set("short", "Amun Bedroom");
    set("long", "%^BOLD%^%^WHITE%^This room was made in secret by Amun. Only certain people are allowed to venture into this area. The entire room is made up of doors, each one leading to a different area. The doors are marked with the areas they lead to.%^RESET%^");
    set_items((["doors" : "%^BOLD%^%^WHITE%^The entire room is made up of doors, each one leading to a different area. The doors are marked with the areas they lead to.%^RESET%^" ]));
    set_exits( ([ "marsh" : MARSHROOM "marsh_square", "tomb" : ROOMS "hamen_square", "ill" : ILLROOM "ill_14", "saints" : GUILDROOM "portal_room", "sky" : SKYROOM "square", "nesoo" : "/wizards/nesoo/workroom", "art" : "/wizards/artemis/workroom", "out" : "/wizards/amun/bedroom" ]) );
}
void init() {
    ::init();
    add_action("look_in", "peer");
    add_action("go_sky", "sky");
    add_action("go_art", "art");
    add_action("go_marsh", "marsh");
    add_action("go_saints", "saints");
    add_action("go_out", "out");
    add_action("go_tomb", "tomb");
    add_action("go_ill", "ill");
    add_action("go_nesoo", "nesoo");
}
int go_sky(string str) {
    if (member_array(this_player()->query_name(), ALLOWED) == -1) {
	write("%^BOLD%^%^RED%^You try to get into the door, but the door slams in your face!%^RESET%^", this_player());
	return 1;
    }
    return 0;
}
int go_art(string str) {
    if (member_array(this_player()->query_name(), ALLOWED) == -1) {
	write("%^BOLD%^%^RED%^You try to get into the door, but the door slams in your face!%^RESET%^", this_player());
	return 1;
    }
    return 0;
}
int go_marsh(string str) {
    if (member_array(this_player()->query_name(), ALLOWED) == -1) {
	write("%^BOLD%^%^RED%^You try to get into the door, but the door slams in your face!%^RESET%^", this_player());
	return 1;
    }
    return 0;
}
int go_saints(string str) {
    if (member_array(this_player()->query_name(), ALLOWED) == -1) {
	write("%^BOLD%^%^RED%^You try to get into the door, but the door slams in your face!%^RESET%^", this_player());
	return 1;
    }
    return 0;
}
int go_tomb(string str) {
    if (member_array(this_player()->query_name(), ALLOWED) == -1) {
	write("%^BOLD%^%^RED%^You try to get into the door, but the door slams in your face!%^RESET%^", this_player());
	return 1;
    }
    return 0;
}
int go_ill(string str) {
    if (member_array(this_player()->query_name(), ALLOWED) == -1) {
	write("%^BOLD%^%^RED%^You try to get into the door, but the door slams in your face!%^RESET%^", this_player());
	return 1;
    }
    return 0;
}
int go_nesoo(string str) {
    if (member_array(this_player()->query_name(), ALLOWED) == -1) {
	write("%^BOLD%^%^RED%^You try to get into the door, but the door slams in your face!%^RESET%^", this_player());
	return 1;
    }
    return 0;
}
int go_out(string str) {
    if (member_array(this_player()->query_name(), ALLOWED) == -1) {
	write("%^BOLD%^%^RED%^You try to get into the door, but the door slams in your face!%^RESET%^", this_player());
	return 1;
    }
    return 0;
}
int look_in(string str) {
    if(member_array(str, DISALLOW) != -1) {
	write("%^BOLD%^%^RED%^There are no windows in this door!%^RESET%^", this_player());
	return 1;
    }
    return 0;
}
