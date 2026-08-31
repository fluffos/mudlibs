#include <std.h>

inherit OBJECT;

void create() {
  ::create();
  set_name("cake");
  set("id",({"cake","birthday cake"}));
  set("short","A large birthday cake");
  set_long("The cake has a number of candles all lit up, creating a cheery glow.  A light frosting covers the soft cake.  It looks like you could <cut a piece> of cake if you wanted.  There is something written in the frosting.");
  set_prevent_get("You'd ruin the party if you took the whole cake!");
  set("read", "Happy Birthday!");
  set_weight(10);
  set_value(0);
  set_prevent_get("A little greedy, aren't we?");
}

void init() {
  ::init();
  add_action("cut","cut");
}

int cut(string str) {
  object ob;

  if(str != "a piece")
    return 0;

  write("You grab a knife and cut yourself a large piece of cake!");

  say(this_player()->query_cap_name()+" cuts a large piece of cake for themselves!");

  ob = new(FOOD);
  ob->set_name("piece of cake");
  ob->set_short("a %^BOLD%^large %^BLUE%^piece %^RESET%^of %^CYAN%^cake%^RESET%^");
  ob->set_long("It's a large piece of cake for you to eat.");
  ob->set_strength(3+random(7));
  ob->set_id(({"cake", "piece", "piece of cake", "food"}));
  ob->move(this_player());

  return 1;
}
