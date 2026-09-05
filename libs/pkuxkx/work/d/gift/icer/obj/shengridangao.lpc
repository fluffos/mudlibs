// dumpling.c 包子
#include <ansi.h>
inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name(HIY"生日蛋糕"NOR, ({"shengri dangao", "dangao","cake"}));
	set_weight(80);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "一个香喷喷的生日蛋糕，上面用奶油写着『生日快乐！』几个字。\n");
		set("unit", "个");
		set("value", 50);
		set("food_remaining", 100);
             set("food_supply", 10);
	}
}
