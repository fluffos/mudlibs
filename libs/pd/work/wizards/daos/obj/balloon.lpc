#include <std.h>

#define TP this_player()

inherit OBJECT;

string *colors = ({"%^BOLD%^RED%^red%^RESET%^", "%^BOLD%^BLUE%^blue%^RESET%^", "%^BOLD%^YELLOW%^yellow%^RESET%^", "%^BOLD%^GREEN%^green%^RESET%^","%^BOLD%^MAGENTA%^pink%^RESET%^"});
int i;

void create() {
    ::create();
    i = random(sizeof(colors)); 
    set_name("balloon");
    set("id", ({"balloon", "red balloon"}) );
    set_short("A "+colors[i]+" balloon");
    set_long("This is a "+colors[i]+" balloon.");
}

void init() {
    add_action("cmd_bop", "bop");
}

int cmd_bop(string str) {
    object ob;

    if (!str || !(ob = find_player(str))) 
	return notify_fail("That person is not online.\n");

    write("You bop "+capitalize(str)+" in the nose with a "+colors[i]+" "
      "balloon and shout 'Bop'!");
    message("info", capitalize(TP->query_name())+" bops you in the nose with " 
      "a "+colors[i]+" balloon.", find_player(str));
    return 1;
}

int query_auto_load() {
    if(this_player()->query_name() == "johnathan")
	return 1;
}
