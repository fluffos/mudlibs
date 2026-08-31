#include <std.h>

inherit OBJECT;

string fname;

void create() {
    ::create();
    set_name("seal");
    set_short("teleportal seal");
    set_long("This seal will allow you to teleport anywhere that "
      "you mark it to.  To view where it is marked type <view seal>."
      "You may also <recite seal> to use its powers.");
    set_id(({ "teleportal seal", "seal" }));
}

void set_file_name(string str) { fname=str; create(); }
string query_file_name() { return fname; }

void init() {
    ::init();
    add_action("fview", "view");
    add_action("frecite", "recite");
    add_action("fmark", "mark");
}

int fview(string str) {
    string name;

    if(!str || str != "seal") return notify_fail("View what?\n");
    if(!query_file_name() || query_file_name() == "") {
	write("Your seal is not marked for anyplace.\n");
	return 1;
    }
    if(catch(call_other(query_file_name(), "???"))) {
	log_file("/log/errors/datascrolls", this_player()->query_name()+" scroll "+
	  "auto-erase: "+query_file_name()+"\n");
	set_file_name();
	write("The seal erases itself like magic.\nYour seal is unmarked.\n");
	return 1;
    }
    name=find_object(query_file_name())->query_short();
    write("Your seal has been marked for: "+name+"\n");
    return 1;
}

int fmark(string str) {
    if(!str || str != "here") return notify_fail("Syntax: <mark here>\n");
    if(query_file_name()) return notify_fail("This seal is already marked.\n");
    write("You mark your seal.\n");
    say(this_player()->query_cap_name()+" marks "+this_player()->query_possessive()+".\n");
    set_file_name(file_name(environment(this_player())));
    return 1;
}


