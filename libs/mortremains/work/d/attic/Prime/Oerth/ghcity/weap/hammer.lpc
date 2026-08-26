#include <mudlib.h>
inherit WEAPON;

void create(){
seteuid(getuid());
set("name", "Warhammer");
set_weapon_type("hammer");
set("id", ({"hammer", "weapon", "warhammer"}));
set("short", "Warhammer");
set("long", @Endtext
This hammer was crafted long ago by Dwarves. It is still
in fine condition, and could still be quite painful.
Endtext
);
set_bonus(3);
set_verbs(({"bash", "smite", "maul", "crush"}));
set_verbs2(({"bashes", "smites", "mauls", "crushes"}));
set("value", 1500);
}
