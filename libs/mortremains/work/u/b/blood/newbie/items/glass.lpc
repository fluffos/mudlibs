
#include <commands.h>
#include <mudlib.h>

#define SYNTAX "Syntax: envision <playername>\n"

inherit OBJECT ;

int charges;

void create() {
    charges = 6;

    seteuid(getuid());
    set ("id", ({ "glass", "glass of life" }) ) ;
    set ("short", "@@query_short");
    set("long", @EndText
The glass of life is a spherical shaped jewel of some unknown type polished
so carefully that it seems as clear as glass. The item can be used to see
other people through out the world, where ever they happen to be located.
Etched in tiny letters are the words 'envision <playername>'.
EndText
    );
    set ("mass", 1) ;
    set("enchantment", 5);
    set("value",   5000);
}

void init() {
    add_action("envision", "envision");
}

string query_short() {
    string str = "The Glass of Life";

    if (environment() && TP == environment())
	str += " [ "+charges+" charges ]";

    return str;
}

int envision(string str) {
    object ob;

    if (!str) {
	write(SYNTAX);
	return 1;
    }

    ob = find_player(str);

    if (!ob) {
	write(capitalize(str)+" is not logged in.\n");
	return 1;
    }

    if (wizardp(ob)) {
	write("You cannot get an image of an immortal.\n");
	return 1;
    }

    write(CMD_LOOK->living_description(ob));
    charges--;

    return 1;
}

/* EOF */
