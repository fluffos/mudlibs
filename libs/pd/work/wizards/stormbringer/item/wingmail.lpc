#include <std.h>
inherit ARMOUR;
void create() {
 ::create();
   set_name("wingmail");
   set_short("a set of wingmail");
   set_id(({ "armour", "wingmail", "set of wingmail" }));
   set_long("The silvered wingmail covers the wings completely, "
      "giving them excellent protection, but they prevent flying.");
   set_weight(8);
   set_curr_value("gold", 25+random(20));
   set_type("wing armour");
   set_limbs(({ "left wing", "right wing" }));
   set_ac(4);
   set_wear((: "extra_worn" :));
   set_remove((: "extra_removed" :));
}
void init() {
   ::init();
   add_action("do_fly", "fly");
}
int do_fly(string str) {
   if(this_player() != this_object()->query_worn())
     return 0;
   write("As you try to fly, you find yourself unable to move"
         " your wings because of the heavy armor.");
   return 1;
}
int extra_worn() {
    write("You struggle to get into your wing armour");
    this_player()->set_paralyzed(5,"You are still struggling with your wingarmour.");
    return 1;
}
int extra_removed() {
    write("You struggle to get out of your wing armour");
    this_player()->set_paralyzed(5,"You are still struggling with your wingarmour.");
    return 1;
}
int query_auto_load() { if (this_player()->query_level() >= 20) return 1; }
