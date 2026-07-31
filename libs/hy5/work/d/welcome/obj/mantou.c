// jitui.c 鸡腿

#include <weapon.h>

inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name("馒头", ({ "man tou","mantou" }) );
	set_weight(350);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "一个馒头。\n");
		set("unit", "个");
		set("value", 0);
		set("food_remaining", 4);
		set("food_supply", 15);
		//set("wield_msg", "$N抓起一根$n，握在手中当武器。\n");
		set("material", "bone");
	}
	//init_hammer(1);
	setup();
}

