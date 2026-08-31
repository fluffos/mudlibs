#include <std.h>
inherit ARMOUR;

void create() {
    ::create();
    set_name("armour");
    set_short("%^BOLD%^RED%^D%^YELLOW%^w%^BOLD%^RED%^a%^YELLOW%^r"
              "%^BOLD%^RED%^v%^YELLOW%^e%^BOLD%^RED%^n %^YELLOW%^P"
              "%^BOLD%^RED%^l%^YELLOW%^a%^BOLD%^RED%^t%^YELLOW%^e"
              "%^BOLD%^RED%^m%^YELLOW%^a%^BOLD%^RED%^i%^YELLOW%^l%^RESET%^");
    set_long("This armour is worn by dwarven hunters. "
             "   Its made of a great metal, that is only "
             "found in the dwarf town.");
    set_id( ({ "armour" , "dwarven platemail", "platemail", "mail" }) );
    set_ac(6);
    set_mass(45);
    set_curr_value("gold", 40);
    set_type("armour");
    set_limbs( ({ "torso" , "head" }) );
}

int query_auto_load()
{                                   
if (this_player()->query_level() > 10) return 1;
if (wizardp(this_player())) return 1;
 return 0;
}                 
