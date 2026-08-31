#include <std.h>
inherit ARMOUR;
int extra_worn() {
    write("You struggle to get into your wing claws.");
    this_player()->set_paralyzed(1,"You are still struggling with your wing claws.");
    return 1;
}
int extra_removed() {
    write("You struggle to get out of your wing claws.");
    if(this_object()->query_worn())
    this_object()->query_worn()->set_paralyzed(1,"You are still struggling with your wing claws.");
    return 1;
}
void create() {
 ::create();
   set_name("wingclaws");
   set_short("pair of wingclaws");
   set_id(({ "armour", "wingclaw", "wingclaws" }));
   set_long("This strange piece of armour is made to wrap around a winged "
      "humanoid's torso and wings. It ends in a claw above each wing.");
   set_weight(8);
   set_curr_value("gold", 25);
   set_type("wing armour");
   set_limbs(({ "left wing", "right wing" }));
   set_ac(2);
   set_wear((: extra_worn :));
   set_remove((: extra_removed :));
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
int query_auto_load() { if (this_player()->query_level() >= 10) return 1; }
