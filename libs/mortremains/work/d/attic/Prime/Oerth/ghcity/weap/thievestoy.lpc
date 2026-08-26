#include <mudlib.h>
inherit WEAPON;

void create(){
seteuid(getuid());
set("name", "Shortsword");
set_weapon_type("sword/short");
set("bksb_mult", 5);
set("id", ({"sword", "shortsword", "#BKSB#"}) );
set("short", "Shortsword");
set("long", @Endtext
This small slender blade was crafted in the depths
of the Hell Furnance Mountains by the ArchLich Vecna
himself. 
Endtext
);
set_bonus(5);
set_verbs(({"pierce", "cut", "stab", "jab", "maul", "slash"}));
set_verbs2(({"pierces", "cuts", "stabs", "jabs", "mauls", "slashes"}));
set("value", 1800);
}

