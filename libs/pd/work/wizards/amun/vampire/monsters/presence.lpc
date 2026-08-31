#include <std.h>
#include <tirun.h>
#include <vampq.h>

inherit MONSTER;

void create() {
    ::create();

    set_name("Presence");
    set_short("%^BLACK%^Presence%^RESET%^");
    set_long("I'm not real!");
    set_level(1);
    set_id(({"presence"}));
    set_mass(11);
    set_value(0);
    set_exp(0);
    new(VO"vampire_fang")->move(this_object());
}

int query_invis() {return 1;}

int query_ghost() {return 1;}

void catch_tell(string str) {
    object tp, ob;
    string a, b;
    tp = this_player();

    if(this_player() == (ob = this_object())) return;
    if((sscanf(str, "%flask to%s", a, b) == 2) || (sscanf(str, "%sflask to%s", a, b) == 2)) {
	write("%^CYAN%^A Pale-skinned man says:%^RESET%^ Thank you!");
	write("A Pale-skinned man takes a long drink from the flask and is rejuvenated.");
	write("\n%^CYAN%^A Pale-skinned man says:%^RESET%^ For helping me I will help you.");
	write("%^CYAN%^A Pale-skinned man says%^RESET%^ When I was a young vampire this fang brought me luck, maybe it will do the same for you. Take it and good luck on your journey.");
	write("A Pale-skinned man places his hand on your temple and pulls you in a trance.");
	force_me("give fang to "+tp->query_name());
	return;
	this_player()->move_player(VR"transroom");
	find_object(VR"transroom")->start_fmv("quest");
	this_player()->add_hp(-200);
	return;
    }
}
