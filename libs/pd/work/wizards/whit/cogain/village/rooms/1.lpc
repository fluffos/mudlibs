//  Whit

#include <std.h>
#include <cogain.h>

inherit ROOM;
int closed;

void create() {
    ::create();
    set_name("Cogain Village");
    set_short("The Cogain Villa");
    set_long("The tall walls of the castle stand to the south protecting the "
      "city from intrusion.  ");
    set_exits(([
	"north":VROOM+"2",
      ]));
    set_pre_exit_functions( ({"north"}), ({"go_north"}) );
}

string query_long() {
    if(closed)
	return "Outside the city.  Drawbridge is down.";
    return "Outside the city.  Drawbridge is up.";

}

void set_closed(int i) { closed=i; }
int query_closed() { return closed; }

int go_north() {
    if(closed) {
	write("Going north would make you walk into the moat.");
	return 0;
    }
    return 1;
}

