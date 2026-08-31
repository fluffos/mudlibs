#include <std.h>
#include <lodos.h>
inherit OBJECT;

int drink(string str);

void create() {
 ::create();
   set_name("potion");
   set_short("a potion of change");
   set_long("The potion looks cool and refeshing. It is for those "
      "truly adventurous at heart.");
   set_weight(5);
   set_value(0);
   set_id(({ "potion", "change", "potion of change" }));
}

int drink(string str) {
   object ob;
   if (!str) return 0;
   ob = present(str, this_player());
   if (ob != this_object()) return 0;
   write("The thin mixture goes down smooth.");
   this_player()->add_hp(-random(35));
  if (this_player()->query_gender() == "female") {
      if(this_player()->query_race() == "nymph")
         return notify_fail("You don't feel any different.\n");
   say(this_player()->query_cap_name()+" looks more masculine.", this_player());
   this_player()->set_gender("male");
  } else
  if (this_player()->query_gender() == "male") {
   say(this_player()->query_cap_name()+" looks more feminine.", this_player());
   this_player()->set_gender("female");
  }
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
