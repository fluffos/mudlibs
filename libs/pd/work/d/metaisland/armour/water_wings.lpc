#include <std.h>
#include <metallicana.h>
inherit ARMOUR;
int extra_worn() {
    write("You struggle to get into your wing armour.");
    this_player()->set_paralyzed(2,"You are still struggling with your wing armour.");
    return 1;
}
int extra_removed() {
    write("You struggle to get out of your wing armour.");
    this_player()->set_paralyzed(2,"You are still struggling with your wing armour.");
    return 1;
}
void create() {
    ::create();
    set_name("Water wings");
    set_short("%^BOLD%^%^BLUE%^W%^WHITE%^a%^BLUE%^t%^WHITE%^e%^BLUE%^r %^BOLD%^%^BLUE%^W%^WHITE%^i%^BLUE%^n%^WHITE%^g%^BLUE%^s%^RESET%^");
    set_long("These are special lightweight armour, made from the hide of a water snake.");
    set_id(({"wings", "waterwings"}));
    set_ac(5);
    set_weight(11);
    set_curr_value("gold",91);
    set_type("armour");
    set_limbs(({"left wing", "right wing"}));
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
int query_auto_load() {
if (this_player()->query_level() > 44) return 1;
}
