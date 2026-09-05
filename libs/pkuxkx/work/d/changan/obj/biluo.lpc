// jitui.c 鸡腿
#include <ansi.h>
inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name(YEL"蟹黄饆饠"NOR, ({ "xiehuang biluo", "biluo" }) );
	set_weight(100);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "饆饠源自波斯语，一种从西域传过来的包馅面食，包裹着蟹黄的饆饠美味异常。\n");
		set("unit", "枚");
    set("value", 150);
		set("food_remaining", 2);
    set("food_supply", 15);
	}
	setup();
}