#include <ansi.h>
#include <weapon.h>
inherit HAMMER;

void create()
{
	set_name( WHT"银轮"NOR,({ "yin lun" ,"lun" }));
	set_weight(1000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "把");
		set("long","这是一把纯银打造的轮子。\n");
		set("value", 800000);
		set("material", "wood");
		set("wield_msg", "$N抽出一柄$n握在手中。\n");
		set("unwield_msg","$N将手中的$n放回腰间。\n");
	}
        init_hammer(200);
	setup();
}
