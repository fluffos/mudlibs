
#include <std.h>
#include <id4.h>

inherit OBJECT;

string color, owner, long, short;

int do_rub(string str);

void set_shortandlong(string);
void set_color(string c) { color = c; }
void set_owner(string n) { owner = n; }

void set_shortandlong(string col) {
  switch (col) {
    case "red":
      set_name("claw");
      set_id( ({ "claw", "dragon claw", "old dragon claw" }) );
      set_short("an old dragon claw");
      set_long("This dragon claw is very old and as long as most "
	       "swords. The tip is very sharp and has a bit of blood "
	       "dried on it.");
    break;

    case "blue":
      set_name("scale");
      set_id( ({ "scale", "dragon scale", "old dragon scale" }) );
      set_short("an old dragon scale");
      set_long("This is a scale from a dragon. It looks very old, "
	       "and it is chipped a little along one side.");
    break;

    default:
    case "white":
      set_name("tooth");
      set_id( ({ "tooth", "dragon tooth", "old dragon tooth" }) );
      set_short("an old dragon tooth");
      set_long("An old, cracked tooth from a dragon. It is bright white "
	       "and as large as a man's head.");
    break;

    case "black":
      set_name("horn");
      set_id( ({ "horn", "dragon horn", "old dragon horn" }) );
      set_short("an old dragon horn");
      set_long("An ancient horn from a dragon. It is very sharp, and a "
	       "deep black in color.");
    break;
  }
  set_long(query_long(0)+" A bit of old magic still clings to it, "
    "and can be used by <rub>bing "+definite_article(query_name())+".");
  if (owner)
  set_long(query_long(0)+"\nIt is a gift to "+capitalize(owner)+
           " from a "+color+" dragon.");
  set_id(query_id() + ({ "dragon_quest_token" }) );
}

void create() {
  ::create();
  set_property("no store", 1);
  set_weight(1);
  set_curr_value("gold", 0);
}

void init_arg(mixed *args) {
  if (sizeof(args)) {
    set_owner(args[0]);
    set_color(args[1]);
    set_shortandlong(args[1]);
  }
}

mixed *query_auto_load() {
  return ({ base_name(this_object()),
    ({ owner, color })
  });
}

void init() {
  ::init();
  add_action("do_rub", "rub");
}

int do_rub(string str) {
  object tp = this_player();
  object env = environment(tp);
  object to = this_object();
  string stat;

  if (tp != environment(to)) return 0;
  if (!str || present(str, tp) != to) return 0;
  if (!color)
    return notify_fail("You rub "+definite_article(query_short())+
	               ", but nothing happens.\n");
  switch (color) {
    case "red": stat = "strength"; break;
    case "blue": stat = "constitution"; break;
    case "white": stat = "wisdom"; break;
    case "black": stat = "intelligence"; break;
  }

  if (tp->query_stat_bonus(stat))
    return notify_fail("You rub "+definite_article(query_short())+
	               ", but nothing happens.\n");

  message("info", "You rub "+definite_article(query_short())+
    " and feel some magic flow through you.", tp);

  tp->add_stat_bonus(stat, 5, 300);

  return 1;
}


