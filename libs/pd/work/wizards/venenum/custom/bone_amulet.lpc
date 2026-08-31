#include <security.h>
inherit ARMOUR;

void create() {
    ::create();
    set_name("amulet");
    set("id", ({"amulet"}) );
    set_short("%^BOLD%^%^YELLOW%^a%^RESET%^%^BOLD%^mulet %^BOLD%^%^YELLOW%^o%^RESET%^%^BOLD%^f%^BOLD%^%^YELLOW%^ t%^RESET%^%^BOLD%^he%^RESET%^%^RED%^ a%^BOLD%^gnostic %^RESET%^%^BOLD%^%^YELLOW%^a%^RESET%^%^BOLD%^rchangel%^RESET%^");
    set_long("%^BOLD%^The chains of this amulet are platinum, and it glows with holy light,%^BLACK%^ yet the pendant is dark and strange, a cross with a %^RED%^red%^BLACK%^ slash through it glows brightly.%^RESET%^");
    set_type("amulet");
    set_ac(0);
    set_limbs( ({"torso"}) );
}

int query_auto_load() {
    if (this_player()->query_name() == "bone"){return 1;}
    return 0;
}

int drop(){return 1;}
int give(){return 1;}
int sell(){return 1;}
int bury(){return 1;}
