// niuwei.c 牛尾

#include <weapon.h>
inherit WHIP;
inherit F_FOOD;

void create()
{
	set_name("牛尾", ({ "niu wei", "wei" }) );
	set_weight(350);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "一条牛的尾巴。\n");
		set("unit", "条");
		set("value", 10);
		set("food_remaining", 2);
		set("food_supply", 10);
		set("wield_msg", "$N抓起一条$n，握在手中当武器。\n");
		}
	init_whip(1);
	setup();
}

