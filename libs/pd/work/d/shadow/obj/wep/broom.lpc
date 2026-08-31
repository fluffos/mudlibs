#include <std.h>;
#include <shadow.h>;

inherit WEAPON;

void create() {
  ::create();

  set("id",({"broom","blunt","sweeper"}));
  set_name("broom");
  set("short","Chimney Broom");
  set("long","This is the broom of a kindly chimney sweep.");
  set_weight(9);
    set_curr_value("gold", 40);
  set_ac(1);
  set_wc(6);
  set_type("blunt");
  set_decay_rate(1000);
}

int query_auto_load() {
  if (this_player()->query_level() > 20)
  return 1;
}
