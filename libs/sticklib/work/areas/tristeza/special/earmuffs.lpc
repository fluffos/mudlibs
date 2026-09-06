#include <armour.h>

string long;

string my_long();

void create_armour() {
    set_name("earmuffs");
    set_short("A pair of earmuffs");
    set_type("helmet");
    long =
    "They shut shouts up real nicely. Use the command: \n"
    "earmuff <shout_level>, where shout_level is the level of "
    "shout you wish to ignore. "
    "\nNOTE: you must wear them first. "
    "\n";
    set_long(#'my_long);
    set_id(({ "muffs", "earmuffs", "pair of earmuffs" }));
    set_value(200);
    set_unwear_func(this_object());
    set_weight(1);
}

void init_armour() {
    add_action("earmuff", "earmuff");
}

status earmuff(string arg) {
    int x;
    if(query_worn_by() != this_player()) return 0;
    if(!arg) return notify_fail("Set earmuffs to what level? \n"), 0;
    sscanf(arg, "%d", x);
    if(!intp(x)) return notify_fail("You must use a number. \n"), 0;
    if(x > this_player()->query_level()) {
	x = this_player()->query_level();
	this_player()->tell_me(
	  "Can't block shouts of a higher level. Blocking "+x+". "
	);
    }
    this_player()->tell_me(
      "Blocking shouts of level "+x+" and up. "
    );
    this_player()->listen_shout(x);
    return 1;
}

status unwear_me(object wearer, object ta) {
    if(!wearer) return 0;
    wearer->listen_shout(1);
    return ::unwear_me(wearer, ta);
}

string my_long() {
    return long + (query_worn_by() ?
      "You are currently listening to shouts of level "+
      query_worn_by()->listen_shout()+". " : "");
}
