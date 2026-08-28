//    A small vial that holds the curiously stron potion of the Darke 
//    grass.

#include <std.h>

inherit OBJECT;

string extra_desc;
mixed arg;

void empty_vial();

void create() {
  ::create();
    set_name("vial");
    empty_vial();
    set_long("This vial may be used to carry single doses of magical "+
	     "salves and elixirs.  It must be held in your inventory "+
	     "whenever you use a skill or item that creates a potion.");
    set_weight(3);
    set_value(3);
    return;
}

void init() {
  ::init();
    add_action("drink_func", "drink");
    return;
}

int drink_func(string str) {
  string what, where;

  if(!str || !query_property("drink func")) return 0;
  if(present(str, this_player()) != this_object()) return 0;
 //Can't use a healin potion in combat? ++Drizzt 6/2/96
 // if(this_player()->query_current_attacker()) {
 //   write("You cannot do that while in combat!");
 //   return 1;
 //  }
  write("You quaff the potion.");
  message("info", (string)this_player()->query_cap_name() +
	  " quaffs a potion.", all_inventory(environment(this_player())),
	  ({ this_player() }) );
  what = query_property("drink func");
  where = query_property("drink obj");
  empty_vial();
  if(!what || !where) return notify_fail("Potion BUG!!!");
  return (int)call_other(where, what, this_player(), arg);
}

int query_vial() { return 1; }

void fill_vial(string str, string func, string obj, mixed r) {
  if(!str || !obj) return;
  set_property("drink func", func);
  set_property("drink obj", obj);
  arg = r;
  extra_desc = str;
  return;
}

int id(string str) {
  string no_art;
  
  if(!query_property("drink func")) return ("vial" == str);
  else if(extra_desc) {
    no_art = replace_string(extra_desc, "a ", "", 1);
    no_art = replace_string(no_art, "an ", "", 1);
    return ("vial" == str || extra_desc == str ||
			      "potion" == str || no_art == str);
  }
  else return ("vial" == str || "potion" == str);
}

string query_short() {
  if(query_property("drink func")) return "A small vial filled with "+
    extra_desc;
  else return "A small empty vial";
}

void empty_vial() {
  set_property("drink func", 0);
  set_short("A small empty vial");
  set_value(3);
  return;
}






