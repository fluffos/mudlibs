#include <ansi.h>
inherit ITEM;
inherit F_FOOD;

void create()
{
	set_weight(80);
	switch (random(4)) {
       	case 0:
			set_name(HIY"月饼"NOR, ({"gongpin"}));
			set("long", "豆沙馅的月饼，吃起来还算可口.\n");
			break;
       	case 1:
			set_name(HIM"桃子"NOR, ({"gongpin"}));
			set("long", "本地常见的桃子，仔细一看，还有一个虫子洞洞.\n");
			break;
       	case 2:
			set_name(YEL"黏糕"NOR, ({"niangao"}));
			set("long", "黄米面的豆包.\n");
			break;
       	case 3:
			set_name(HIG"青苹果"NOR, ({"gongpin"}));
			set("long", "还没太熟，一股涩涩的味道。\n");
			break;

	}
	set("unit", "个");
	set("value", 15);
	set("food_remaining", 5);
	set("food_supply", 20);
	
}
