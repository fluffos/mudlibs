inherit ROOM;
#include <std.h>;
#include <shadow.h>;

void create() {
  ::create();
  set_property("outdoors",1);
  set_property("light",0);
  set("short","Clearing in the Woods");
  set("long","This is a small clearing where dealings outside the "
    "legal system take place.  Here forged passes into Tenebrae can be bought."
  "  The trees here press in close, hiding all transactions.  To buy "
    "a pass for 100 gold, type <buy pass>.");
  set_smell("default","The air is dry and odorless here.");
  set_listen("default","The wind rustles in the trees.");
  set_items((["sky":"The sky seems to darken as you head east.",
    "bush":"This is your way out.",
    "trees":"The trees protect from prying eyes.",
    "clearing":"A small clearing."]));
  set_exits((["out":ROOMS "passell"]));
}

void reset() {
  ::reset();
  if(!present("monster")) new(MOB "passman")->move(this_object());
}

void init() {
  ::init();
  add_action("buypass","buy");
}

int buypass(string str) {
  if(!str) {
    notify_fail("Buy what?\n");
    return 0;
  }
  if(str != "pass") {
    notify_fail("That's not for sale!\n");
    return 0;
  }
else {
  if(present("passman")){
  new(OBJ "pass")->move(this_player());
  if (this_player()->query_money("gold")<100)
   {
    write("You have insufficient funds to pay for a pass.");
    return 1;
  }
  this_player()->add_money("gold",-100);
  write("You buy a pass to Tenebrae for 100 gold.");
  say(this_player()->query_cap_name()+" buys a pass, that scoundrel!",this_player());
  return 1;
  }
  else {
  write("Who are you going to buy it from?");
  return 1;
  }
}
}
