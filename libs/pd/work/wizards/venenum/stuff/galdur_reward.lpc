#include <security.h>
inherit ARMOUR;

string extralook =  "%^BOLD%^%^RED%^Galdur The Slayer.%^RESET%^";
string extra_look();

void create() {
    ::create();
    set_name("ring of the slayer");
    set("id", ({"ring", "slayer", "ring of the slayer", "slayer ring"}) );
    set_short("Ring of the Slayer");
    set_long("This band signifies Galdur's great accomplishment, slaying Sasayaki when he was possessed by Asmodeus.");
    set_type("ring");
    set_ac(0);
    set_limbs( ({"left hand", "right hand"}) );
}

int query_auto_load() {
    return 1;
}
string extra_look() {return extralook+"\n";}
