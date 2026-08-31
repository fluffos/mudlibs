#include <std.h>

#define TP this_player()

inherit OBJECT;

void create() {
    ::create();
    set_name("balloon");
    set("id", ({"balloon", "red balloon"}) );
    set_short("A %^BOLD%^%^RED%^red%^RESET%^ balloon");
    set_long("This is a red balloon.");
}

void init() {
    add_action("cmd_bop", "bop");
}

int cmd_bop(string str) {
    object ob;

    if (!str || !(ob = find_player(str))) 
	return notify_fail("That person is not online.\n");

    write("You bop "+capitalize(str)+" in the nose with a %^BOLD%^%^RED%^red%^RESET%^ "
      "balloon and shout 'Bop'!");
    message("info", capitalize(TP->query_name())+" bops you in the nose with " 
      "a %^BOLD%^%^RED%^red%^RESET%^ balloon.", find_player(str));
    return 1;
}

int query_auto_load() {
    if(this_player()->query_name() == "johnathan")
	return 1;
}
