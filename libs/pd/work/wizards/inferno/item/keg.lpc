#include <std.h>
inherit OBJECT;
int pour(string str);

void create() {
 ::create();
   set_name("keg");
   set_short("a keg of beer");
   set_long("Type <pour [name]> to pour yourself a beer!");
   set_weight(1);
   set_value(10000);
   set_id(({ "keg" }));
}

int get() { return 0; }

int pour(string str) {
   object ob;
   if (!str) {
      write("Syntax: <pour [drink_name]>");
      return 1;
   }
   ob = new("/std/drink");
   ob->set_name(str);
   ob->set_strength(30);
   ob->set_type("alcoholic");
   ob->set_short(str);
   ob->set_id(({ str, "drink" }));
   ob->set_long("A drink poured by "+this_player()->query_cap_name());
/*
   ob = new("/wizards/inferno/can");
   ob->this_name(str);
   ob->set_short(str);
   ob->set_id(({ "drink", str }));
   ob->set_value(0);
   ob->set_long("A drink poured by "+this_player()->query_cap_name());
*/
   ob->move(this_player());
   tell_room(environment(this_player()), this_player()->query_cap_name()+
          " pours "+str, ({ this_player() }));
   write("You pour "+str);
   return 1;
}

void init() {
 ::init();
   add_action("pour", "pour");
}
