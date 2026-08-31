#include <std.h>

inherit ARMOUR;

int customized;
int put_on();
int take_off();
int do_short(string str);
int do_long(string str);
void take_input(string str, string what);

void create() {
  ::create();
  set("no store", 1);
  set_name("costume");
  set_id( ({"costume"}) );
  set_short( "a costume" );
  set_long( "The beginnings of a costume. "
            "You can <start costume> to customize it.\n"
	    "It seems like you might really look just "
	    "like the costume when you're done!" );
  set_type("armour");
  set_limbs(({"torso"}));
  set_mass(1);
  set_ac(0);
  set_wear( (: put_on :) );
  set_remove( (: take_off :) );
  customized = 0;
}             

void set_id(string *ids) {
  if (!sizeof(ids)) return;
  ids += ({ "costume" });
  ::set_id(ids);
}

void set_short(string s) {
  if (!strlen(s)) return;
  s = replace_string(s, "%^BLACK%^", "%^BOLD%^%^BLACK%^");
  s += "%^RESET%^";
  set_id(explode(strip_color(s), " "));
  ::set_short(s);
}

void set_long(string s) {
  if (!strlen(s)) return;
  s += "%^RESET%^";
  ::set_long(s);
}

/*
mixed *query_auto_load() {
  return ({ base_name(this_object()),
    ({ customized, query_short(), query_long(0),})
  });
}

void init_arg(mixed *arg) {
  if (sizeof(arg) && arg[0] == 1) {
    set_short(arg[1]);
    set_long(arg[2]);
  }
}
*/

void init() {
  ::init();
  if (!customized)
    add_action("do_short", "start");
}

int put_on() {
  if (customized) {
    this_player()->set_disguised_short(query_short());
    this_player()->set_disguised_long(query_long(0));
    this_player()->set_disguised_id(query_id() - ({ "costume" }) );
  }
  return 1;
}

int take_off() {
  if (customized) {
    this_player()->remove_disguised_short();
    this_player()->remove_disguised_long();
    this_player()->remove_disguised_id();
  }
  return 1;
}

int do_short(string str) {
  object tp = this_player();

  if (!str || str != "costume")
    return notify_fail("Start what?\n");

  message("info", "Enter how your costume should look at a glance (lowercase):", tp);

  input_to("take_input", 0, "short");

  return 1;
}

int do_long(string str) {
  object tp = this_player();

  if (!str || str != "costume")
    return notify_fail("Finish what?\n");

  message("info", "Enter a detailed description of your costume:", tp);

  input_to("take_input", 0, "long");

  return 1;
}

void take_input(string str, string what) {
  if (!str || !strlen(str)) return;

  call_other(this_object(), "set_"+what, str);

  if (what == "short") {
    remove_action("do_short", "start");
    add_action("do_long", "finish");
    set_long("A partially created costume. You can <finish costume> to "
	     "put on the final touches.");
  }
  if (what == "long") {
    remove_action("do_long", "finish");
    customized = 1;
  }
}

