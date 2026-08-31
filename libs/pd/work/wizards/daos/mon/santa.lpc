#include <std.h>

inherit MONSTER;

#define COLORS ({"%^BOLD%^GREEN%^green%^RESET%^", "%^BOLD%^CYAN%^cyan%^RESET%^", "%^BOLD%^YELLOW%^yellow%^RESET%^", "%^BOLD%^MAGENTA%^magenta%^RESET%^"})

#define NOCOLORS ({"green", "cyan", "yellow", "magenta"})

object ob;

void create() {
    ::create();
    set_name("santa");
    set("id", ({"santa"}) );
    set_short("Santa Claus");
    set_long("This is a jolly old man with a white beard wearing a red suit.  He "
      "might give you a gift if you ask.");
    set_race("human");
    set_body_type("human");
    set_gender("male");
    set_level(30);
}

void init() {
    add_action("ask", "ask");
}

int ask(string str) {
    string who, gift;
    int i, x;

    if (!str || sscanf(str, "%s for %s", who, gift) != 2) {
	return notify_fail("Ask Santa for what?\n");
    }
if(this_player()->query_property("receivedgift")) {
	return notify_fail("You already have a gift.\n");
    }
    i = random(sizeof(COLORS));
    x = random(10);
    ob = new("/std/object");
    ob->set_name("gift");
    ob->set_id( ({"gift", NOCOLORS[i]+" gift"}) );
    ob->set_short(COLORS[i]+" gift");
    ob->set_long("This is a gift from Santa.");

    switch(COLORS[i]) {
    case "%^BOLD%^GREEN%^green%^RESET%^":
	this_player()->add_stat_bonus("strength", x);
	break;
    case "%^BOLD%^CYAN%^cyan%^RESET%^":
	this_player()->add_stat_bonus("dexterity", x);
	this_player()->fix_vital_bonus();
	break;

    case "%^BOLD%^YELLOW%^yellow%^RESET%^":
	this_player()->add_stat_bonus("constitution", x);
	this_player()->fix_vital_bonus();
	break;
    case "%^BOLD%^MAGENTA%^magenta%^RESET%^":
	this_player()->add_stat_bonus("wisdom", x);
	this_player()->fix_vital_bonus();
	break;
    default: return 1;
    }
    ob->move(this_player());
this_player()->set_property("receivedgift", 1);
    force_me("say Here you go, "+this_player()->query_cap_name()+".");
    call_out("query_auto_load", 0);
    return 1;
}

int query_auto_load() {
    if (this_player()->query_name() == this_player()->query_name()) {
	return 1;
    }
}







