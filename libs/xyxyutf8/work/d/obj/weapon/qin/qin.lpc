// edit by God——qin.c

#include <weapon.h>

inherit F_UNIQUE;

inherit QIN;

void create()
{
        set_name("飞音琴", ({ "qin"}) );
	set_weight(1000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
                set("unit", "把");
		set("material", "wood");
                set("long", "一把琴\n");
                set("no_sell", 1);
                set("no_drop", 1);
                set("no_put", 1);
                set("value", 30000);
                set("wield_msg", "$N拿起$n。\n");
                set("unwield_msg", "$N神情萎靡，无精打采的将$n收了起来。\n");
       	        set("weapon_prop/int", 2);
	}
        init_qin(150);
	setup();
}
