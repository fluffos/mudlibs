#include <std.h>
inherit ARMOUR;
int extra_worn() {
    write("%^RED%^You are there, the sounds of battle fill the air.  A demon is in front of you, he swings his sword and you duck then slice open his stomach with your claws... %^RESET%^the illusion fades.\n");
    this_player()->set_paralyzed(1,"You are still struggling with your blood wings.");
    return 1;
}
int extra_removed() {
    write("A small voice whispers in your head, \"You will be back\"\n");
    if(this_object()->query_worn())
    this_object()->query_worn()->set_paralyzed(1,"You are still struggling with your blood wings.");
    return 1;
}
void create() {
 ::create();
   set_name("blood wings");
   set_short("%^RED%^B%^ORANGE%^l%^RED%^oo%^ORANGE%^d %^RED%^W%^ORANGE%^ings%^RESET%^");
set_id(({ "armour", "blood wings", "bloodwings", "wings", "blood" }));
   set_long("%^GREEN%^%^BOLD%^In the third book of Annari, it is said that Ilithyd cut off the head of the demon general of the invading army and fashioned himself wing armour from the thick horns. They still drip with the blood of the demon.%^RESET%^");
   

   set_weight(8);
   set_curr_value("gold", 25);
   set_type("wing armour");
   set_limbs(({ "left wing", "right wing" }));
   set_ac(3);
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
