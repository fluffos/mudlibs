#include <std.h>
#include <metallicana.h>
inherit ARMOUR;
int extra_worn() {
    write("You struggle to get into your wing armour.");
    this_player()->set_paralyzed(3,"You are still struggling with your wing armour.");
    return 1;
}
int extra_removed() {
    write("You struggle to get out of your wing armour.");
    this_player()->set_paralyzed(3,"You are still struggling with your wing armour.");
    return 1;
}
void create() {
    ::create();
    set_name("forest wingmail");
    set_short("%^GREEN%^Fo%^YELLOW%^re%^RESET%^%^GREEN%^st win%^YELLOW%^gma%^RESET%^%^GREEN%^il%^RESET%^");
    set_long("The armour is woven out of stands of palm leaves. The multiple layers of leaves are ideal for bone plates to be inserted. This makes for light weight protective armour.");
    set_id(({"forest wingmail", "wing mail", "armour"}));
    set_ac(6);
    set_weight(25);
    set_curr_value("gold",183);
    set_type("wing armour");
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
    if(this_player()->query_level() != "56") return 0;
    return 1; }
