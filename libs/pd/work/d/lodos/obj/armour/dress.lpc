#include <std.h>
inherit ARMOUR;
string get_color();

void create() {
 ::create();
   set_name("dress");
   set_short("long "+get_color()+" dress");
   set_id(({ "dress" }));
   set_long("A well worn-in, yet still beautiful, dress.");
   set_weight(3);
    set_curr_value("gold", 30);
   set_type("dress");
   set_limbs(({ "right arm", "left arm", "left leg", "right leg",
      "torso" }));
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
      case 11: return "golden";
      default: return "silver";
   }
}
int query_auto_load() { return 1; }
