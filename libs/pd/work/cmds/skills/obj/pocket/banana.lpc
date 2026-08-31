
#include <std.h>
#include <dirs.h>

inherit FOOD;

void make_peel();

void create() {
  ::create();
  set_name("banana");
  set_id( ({ "banana" }) );
  set_short("a banana");
  set_long("This banana is a pretty big piece of fruit, bright yellow "
    "and with a slightly waxy feel.");
  set_my_mess("You peel the banana and chomp it down.");
  set_your_mess("peels a banana and chomps it down.");
  set_strength(23+random(7));
  set_extra( (: make_peel :) );
  set_weight(1);
  set_servings(1);
}

void make_peel() {
  object tp = this_player();
  object ob = new(DIR_CLASS_CMDS+"/obj/pocket/bananapeel");
  if (ob) {
    if (ob->move(tp)) {
      ob->move(environment(tp));
      ob->set_owner(tp);
    }
  }
}

