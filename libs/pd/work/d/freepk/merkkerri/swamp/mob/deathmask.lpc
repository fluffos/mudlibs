#include <std.h>
inherit ARMOUR;

void init() {
::init();
add_action("necrowear", "wear");

}

void create() {
    ::create();
set_name("death mask");
set_short("a Merkkirri %^BOLD%^BLACK%^death%^RESET%^ mask");
set_long("The Merkkirri necromancers wear such masks as they bestow them with greater magical powers.  They generally are made from the face bones of several differing humanoids.");
set_id(({"death mask"}));
set_ac(2);
set_weight(6);
set_curr_value("gold",120);
set_type("mask");
set_limbs(({"head"})); 
}

int necrowear(string what) {
int ibonus, nbonus;
ibonus = 5;
nbonus = 15;
if (what != "death mask") return 0;
if (what == "death mask") {
if (this_player()->query_subclass() != "necromancer") return 0;
message("info", this_player()->query_cap_name()+" wears the mask of the Merkkirri necromancers.\n", environment(this_player()));
this_player()->add_stat_bonus("intelligence", ibonus);
this_player()->add_skill_bonus("necromancy", nbonus);
return 1;
}
}




int query_auto_load() {return 1; }
