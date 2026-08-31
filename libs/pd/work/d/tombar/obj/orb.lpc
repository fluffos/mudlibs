//  Orb

#include <std.h>

inherit OBJECT;
string col;

void create() {
    ::create();
    if(!col) col="red";
    set_name("an orb");
    set_id(({ "orb", "orb_quest_tombar" }));
    switch(col) {
    case "blue":
	set_short("a blue orb");
	set_long("The %^BOLD%^%^BLUE%^blue%^RESET%^ orb seems light, almost like your "
	  "holding nothing at all.  A strange energy emancipates "
	  "from the orb.");
	set_weight(3);
	break;
    case "green":
	set_short("a green orb");
	set_long("The %^BOLD%^%^GREEN%^green%^RESET%^ orb seems light, almost like your "
	  "holding nothing at all.");
	set_weight(3);
	break;
    default:
	set_short("a red orb");
	set_long("The %^BOLD%^%^RED%^red%^RESET%^ orb seems heavy.");
	set_weight(60);
	break;
    }
    set_curr_value("gold", 500);
}

void set_color(string s) { col=s; create(); }
string query_color() { return col?col:"red"; }

