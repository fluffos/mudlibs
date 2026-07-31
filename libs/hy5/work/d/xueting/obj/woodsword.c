// liuyun-sword.c
// edit by pian
#include <weapon.h>
inherit SWORD;

void create()
{
	set_name( "木剑" , ({ "wood sword" }) );
	set_weight(6000);

	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "把");
		set("long",@LONG
一把硬木雕成的剑，剑身上有古朴的花纹，但已经被烟火熏的乌七麻黑的了。
LONG
);

		set("valid_number",3);
		set("value", 300);
		set("material", "wood");
		set("wield_msg", "$N「刷」地一声抽出一柄乌七麻黑的$n握在手中。\n");
		set("unwield_msg", "$N将手中的$n收入腰间。\n");
}
        init_sword(15);
        setup();
}
