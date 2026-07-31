// dumpling.c 包子    
                     
#include <ansi.h>

inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name(GRN"西瓜"NOR, ({"xigua", "gua"}));
	set_weight(80);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "一个绿油油的西瓜。\n");
		set("unit", "个");
		set("value", 100);
		set("food_remaining", 3);
		set("food_supply", 50);
	}
}
