#include <std.h>
inherit WEAPON;

create() {
 ::create();
   set_id(({ "halberd", "axe" }));
   set_name("halberd");
   set_short("a sharp bladed halberd");
   set_long("Fixed on a wooden shaft, about seven feet long, is a large "
     "axe blade, angled for maximum impact. The end of the blade tapers "
     "to a long spear point or awl pike. On the back is a hook probably "
     "for piercing or attacking armour, or dismounting riders.");
   set_weight(14);
    set_curr_value("gold", 60);
   set_hands(2);
   set_wc(7);
   set_type("projectile");
}

int query_auto_load() { if (this_player()->query_skill("projectile") >= 20) return 1; }
