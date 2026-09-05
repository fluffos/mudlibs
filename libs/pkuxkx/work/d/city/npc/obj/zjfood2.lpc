//By Zine 各地美食

inherit ITEM;
inherit F_FOOD;
#include <ansi.h>
int init_time();
void create()
{
	set_name(HIR"清炖蟹粉狮子头"NOR, ({"shizi tou","tou"}));
	set_weight(700);
	set("long", "这是一盘清炖蟹粉狮子头，让人垂涎欲滴。\n");
	set("unit", "盘");
            set("value", 180);
            set("food_remaining", 2);
            set("food_supply", 120);
			set("yinzhe_prefer",1);
	call_out("init_time",1);
}

int init_time()
{
	set("init_time",time());
}