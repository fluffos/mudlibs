// jitui.c 鸡腿
#include <ansi.h>
inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name(YEL"胡饼"NOR, ({ "hu bing", "bing" }) );
	set_weight(200);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "一种涂上芝麻，抹上油脂的7寸大小烧饼。\n");
		set("unit", "枚");
    set("value", 100);
		set("food_remaining", 5);
    set("food_supply", 15);
	}
	setup();
}