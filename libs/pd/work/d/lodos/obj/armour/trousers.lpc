#include <std.h>
inherit ARMOUR;
string get_color();

void create() {
 ::create();
   set_name("trousers");
   set_short("pair of "+get_color()+" trousers");
   set_id(({ "trousers" }));
   set_long("A simple old pair of trousers.");
   set_weight(2);
     set_curr_value("gold", 35);
   set_type("trousers");
   set_limbs(({ "right leg", "left leg" }));
   set_ac(1);
}

string get_color() {
   switch (random(10)) {
      case 1: return "red";
      case 2: return "brown";
      case 3: return "black";
      case 4: return "white";
      case 5: return "orange";
      case 6: return "green";
      case 7: return "purple";
      case 8: return "magenta";
      case 9: return "blue";
      case 10: return "cyan";
      default: return "puce";
   }
}
