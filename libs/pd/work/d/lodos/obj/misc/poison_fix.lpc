#include <std.h>
#include <lodos.h>
inherit OBJECT;

int drink(string str);

void create() {
 ::create();
   set_name("potion");
   set_short("a potion of purification");
   set_long("Within this bottle lies a pale white liquid.");
   set_weight(3);
   set_value(0);
   set_id(({ "potion", "potion of purification", "purify", "purification" }));
}

int drink(string str) {
   object ob;
   if (!str) return 0;
   ob = present(str, this_player());
   if (ob != this_object()) return 0;
   this_player()->add_poisoning(-(25 + random(13)));
   write("Your body convulses in response to the strong potion.");
   this_player()->add_hp(-random(7));
   say(this_player()->query_cap_name()+" gulps down a potion and convulses.", this_player());
   ob = new(OBJECT);
   ob->set_name("bottle");
   ob->set_short("an empty bottle");
   ob->set_id(({ "bottle" }));
   ob->set_long("This empty bottle used to hold something..");
   ob->set_weight(1);
   ob->value(0);
   ob->move(this_player());
   this_object()->remove();
   return 1;
}

void init() {
 ::init();
   add_action("drink", "drink");
}
