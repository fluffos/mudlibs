#include <std.h>
inherit ARMOUR;

void create() {
::create();
    set_name("faithwing");
    set_short("%^BOLD%^%^YELLOW%^F%^WHITE%^aith%^YELLOW%^W%^WHITE%^ings%^RESET%^");
    set_long("A platinum breastplate, although it should be heavy it is actually quite light.");
    set_id(({"faithwing", "faithwings", "armour"}));
    set_ac(1);
    set_mass(20);
    set_curr_value("gold", 200);
    set_type("wing armour");
    set_limbs(({"left wing", "right wing"}));
    set_remove("%^BOLD%^%^WHITE%^The %^YELLOW%^holy%^WHITE%^ armour covering your wings disappears as you remove the breastplate.");
}

int query_auto_load() {
    if (this_player()->query_guild()=="illuminati" && this_player()->query_level() > 34) return 1; 
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

