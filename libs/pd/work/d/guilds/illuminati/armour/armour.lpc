#include <std.h>
inherit ARMOUR;

void create() {
    ::create();
    set_name("armour");
    set_short("%^YELLOW%^H%^WHITE%^o%^YELLOW%^ly %^WHITE%^C%^YELLOW%^e%^WHITE%^nt%^YELLOW%^au%^WHITE%^r %^YELLOW%^A%^WHITE%^rm%^YELLOW%^ou%^WHITE%^r");
    set_long("%^BOLD%^These claddings are used to protect the legs of a centaur%^RESET%^.");
    set_id(({"cladding", "holy centaur armour"}));
    set_ac(1);            
    set_mass(60);
    set_curr_value("gold", 400);
    set_type("leggings");
    set_limbs(({"horse torso", "right rear leg", "right foreleg", "left rear leg", "left foreleg"}));
    set_wear("%^BOLD%^Your legs feel heavier as the %^YELLOW%^H%^WHITE%^o%^YELLOW%^ly %^WHITE%^C%^YELLOW%^e%^WHITE%^nt%^YELLOW%^au%^WHITE%^r %^YELLOW%^A%^WHITE%^rm%^YELLOW%^ou%^WHITE%^r%^RESET%^ snaps in place.");
    set_remove("%^BOLD%^Your legs feel lighter as your %^YELLOW%^H%^WHITE%^o%^YELLOW%^ly %^WHITE%^C%^YELLOW%^e%^WHITE%^nt%^YELLOW%^au%^WHITE%^r %^YELLOW%^A%^WHITE%^rm%^YELLOW%^ou%^WHITE%^r%^RESET%^ is removed.");
}

int query_auto_load() { 
    if(this_player()->query_guild() == "illuminati") return 1;

}
