// yuebing.c 月饼

#include <ansi.h>

inherit ITEM;
inherit F_FOOD;

void create()
{      
	set_name(YEL"月饼"NOR, ({"yue bing", "bing"}));
	set_weight(200);
	if (clonep())
		set_default_object(__FILE__);
	else {
	 	set("long", "这是个中国人在中秋节长吃的月饼，烤制精细，甜而不腻。\n");
		set("unit", "个");
		set("value", 150);
		set("food_remaining", 3);
		set("food_supply", 60);
	}
}
