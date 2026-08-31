#include <std.h>
inherit OBJECT;
int pour(string str);

void create() {
 ::create();
   set_name("machine");
   set_short("a soda machine");
   set_long("A large soda machine. Someone broke it so now it's free. "
     "You can push a button for the following drinks: Coke, Pepsi, "
     "Dr. Pepper, Sprite, Fruitopia, Water, Poweraid, or Mountain Dew.");
   set_weight(1);
   set_value(10000);
   set_id(({ "keg" }));
   set_prevent_get("You cannot take that!");
}

int pour(string str) {
   object ob;
   string name;
   if (!str) return 0;
   switch (lower_case(str)) {
     case "coke":
       name = "Coke";
       break;
     case "pepsi":
       name = "Pepsi";
       break;
     case "fruitopia":
       name = "Fruitopia";
       break;
     case "water":
       name = "water";
       break;
     case "poweraid":
       name = "Poweraid";
       break;
     case "dr pepper":
     case "dr. pepper":
     case "drpepper":
       name = "Dr. Pepper";
       break;
     case "sprite":
       name = "Sprite";
       break;
     case "dew":
     case "mountain dew":
       name = "Moutain Dew";
       break;
     case "jolt":
       name = "Jolt";
       break;
     default:
       return 0;
   }
   ob = new("/wizards/inferno/can");
   ob->this_name(str);
   ob->set_short("a can of "+name);
   ob->set_id(({ "drink", name, "soda" }));
   ob->set_value(0);
   ob->set_long("A can of soda.");
   ob->move(this_player());
   tell_room(environment(this_player()), this_player()->query_cap_name()+
          " pushes a button on the soda machine.", ({ this_player() }));
   write("You push a button and a "+name+" pops out of the machine.");
   return 1;
}

void init() {
 ::init();
   add_action("pour", "push");
}
