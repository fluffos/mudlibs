//	A "cigarrette" which increases mp regen, but can have
//	Nasty effects on spell casting and operating heavy machiner

#include <std.h>

inherit OBJECT;

void create() {
  ::create();
  set_name("cigarrette");
  set_id( ({ "joint", "j", "doobie", "cigarrette", "marley" }) );
  set_short("An unlit cigarrette");
  set_long("A cigarrette.  Light it with 'light cigarrette', "+
	"smoke it with 'smoke cigarrette'");
  set_weight(4);
  set_value(10);
  return;
}

void remove() {
  write("Your cigarrette goes out.");
  ::remove();
}

void init() {
  ::init();
  add_action("light", "light");
  add_action("smoke", "smoke");
  return;
}

void set_property(string str, mixed val) {
  if(str != "quality") {
    ::set_property(str, val);
    return;
  }
  ::set_property(str, val);
  if(intp(val)) set_value(10 + 3*val);
  return;
}

int light(string str) {
  if(str && present(str, this_player()) == this_object()) {
    if(query("lit")) return notify_fail("It is already lit!\n");
    set("lit", 1);
    set("puffs", 10);
    write("You light up.");
    message("info", this_player()->query_cap_name() + " lights up.",
	all_inventory(environment(this_player())),
	({ this_player() }));
    set_short("A lit cigarrette");
    call_out("remove", 180);
    return 1;
  }
  return 0;
}

int smoke(string str) {
  if(str && present(str, this_player()) == this_object()) {
    if(!query("lit")) return notify_fail("Light it first!\n");
    write("You take a drag.");
    if(!this_player()->add_stoned(props["quality"] * 2))
      write("You are so wasted, further smoking will do no good.");
    message("info", this_player()->query_cap_name() + " takes a drag "+
	"from a cigarrette.",all_inventory(environment(this_player())),
	({ this_player() }));
    set("puffs", query("puffs") - 1);
    if(query("puffs") <= 0) remove();
    return 1;
  }
  return 0;
}

