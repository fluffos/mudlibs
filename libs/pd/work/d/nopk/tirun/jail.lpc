#include <std.h>
#include <tirun.h>

inherit ROOM;

string *jailed;

void create()
{
    ::create();
    set_properties((["no teleport" : 1, "indoors" : 1, "no attack" : 1, "no steal" : 1,]));
    set_short("The jail.");
    set_long("The jail is poorly maintained. The only window in the "
      "jail is barrded and rusty. Chains are set into the wall "
      "that are used to chain prisoners up with.");
    set_exits( ([ "west" : ROOMS "sveros3"]) );
    add_pre_exit_function("west", "go_west");
    add_pre_exit_function("up", "go_up");
    add_invis_exit("up");
    jailed = ({});
}

int go_west() {
    string person;
    int i;

    person = this_player()->query_name();
    i = sizeof(jailed);
    while(i--) {
	if(jailed[i] == person) {
	    write("The bars of your cell prevent you from leaving!");
	    say(this_player()->query_cap_name()+" bumps into the bars of their cell.");
	    return 0;
	}
    }
    if(this_player()->query_mounted())
	this_player()->force_me("buck "+this_player()->query_mounted()->query_name());
    return 1;
}

int go_up() {
    if (this_player()->query_guild() == "chosen") {
	write("You walk up a hidden staircase.");
	say(this_player()->query_name()+" walks up a hidden staircase.");
	return 1;
    }
}


void add_prisoner(object tp, int seconds) {
    message("info", "You have been thrown in Jail.", tp);
    call_out("do_describe", 4, tp);
    jailed += ({tp->query_name()});
    call_out("release_person", seconds, tp);
    tp->move(this_object());
}

void do_describe(object tp) {
    tp->describe_current_room(tp->query_verbose());
}

void release_person(object tp) {
    message("info", "The guards open the cell and let you out.", tp);
    message("info", "The guards open the cell and release "+tp->query_cap_name(), environment(tp), tp);
    jailed -= ({tp->query_name()});
    tp->set_recent_outlaw(0);
    tp->set_outlaw(0);
}

void init() {
    ::init();
    add_action("quit", "quit");
}

int quit(string str) {
    write("You must serve your time first!");
    return 1;
}
