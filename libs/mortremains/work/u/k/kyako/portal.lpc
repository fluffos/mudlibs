/*
// Ilzarion wrote this.  Not sure when. Cyanide added this header.
// 21 Jan 98  Cyanide added support for effects. Also did
//		some neatening. Ilzarion is NOT a neat coder.  ;)
// 04 Feb 98  Cyanide made sure your followers actually follow 
//      you through portals...
*/

#include <mudlib.h>
#include <commands.h>

inherit OBJECT;

void create() {
	set("id", ({ "#PORTAL#" }) );
	set("short", "@@query_short");
}

/*****************************************************/

void init() {
	add_action("go", "go");
}

/*****************************************************/

int go(string str) {
	object thiskey;
	string direction, keyname, destination;
	string effects;

	direction = query("direction");
	keyname = query("portalkey");
	destination = query("destination");
	thiskey = present(keyname, this_player());

	if (!query("effects"))
		effects = "Suddenly, you find yourself... elsewhere.\n";
	else
		effects = query("effects");

	if ((str == direction) && (thiskey)){
		tell_object(TP, effects);
		this_player()->move_player(destination);
		CMD_GO->do_follow( TP, str );
		return 1;
	}


	return 0;
}

/*****************************************************/

string query_short() {
	if (this_player()->query_skill("Portal Feel")) 
	return ("You sense a portal here.");
}


/* EOF */
