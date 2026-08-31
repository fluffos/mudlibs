#include <security.h>
inherit ARMOUR;

void create() {
    ::create();
    set_name("holy cross");
    set("id", ({"cross", "holy", "holy cross"}) );
    set_short("%^YELLOW%^H%^RESET%^%^BOLD%^o%^RESET%^l%^YELLOW%^y %^RESET%^%^BOLD%^C%^RESET%^r%^YELLOW%^o%^RESET%^%^BOLD%^s%^RESET%^s");
    set_long("This cross is worn only by the saints handpicked as God's right hand men.");
    set_type("amulet");
    set_ac(0);
    set_limbs( ({"torso"}) );
}

int query_auto_load() {
    return 1;
}

int drop(){return 1;}
int give(){return 1;}
int sell(){return 1;}
int bury(){return 1;}
