#include <std.h>
inherit WEAPON;

create() {
  ::create();
	set_id(({"spear", "kra'toan spear"}));
	set_name("hunting spear");
	set_short("%^ORANGE%^Kra'toan %^RESET%^hunting %^ORANGE%^spear%^RESET%^");
	set_long("This spear has been hand crafted by the Kra'toan people for use by their hunters. It has a four foot shaft with sharpened tip. The wood has been treated with something to make it hard as steel.");
	set_weight(25);
	set_curr_value("gold",120);
	set_wc(11);
	set_ac(1);
	set_type("projectile");
	set_hands(1);
	set_wield("Wielding the spear you feel the urge to hunt.");
        set_decay_rate(1000);
}

int query_auto_load() {
    if(this_player()->query_level() > 34) return 1;
    return 0;
}
