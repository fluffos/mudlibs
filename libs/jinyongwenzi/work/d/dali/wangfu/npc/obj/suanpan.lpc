// Modify By River 98/12
#include <weapon.h>

inherit HAMMER;

void create()
{
        set_name("铜算盘", ({ "tong suanpan", "suanpan" }) );
        set_weight(6000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "把");
                set("long", "这是一把铜制的算盘。\n");
                set("value", 1000);
		set("material", "iron");
		set("wield_msg", "$N拿出一把$n，拨弄了两下，然後握在手中。\n");
		set("unwield_msg", "$N放下手中的$n。\n");
	}

        init_hammer(15);
	setup();
}
