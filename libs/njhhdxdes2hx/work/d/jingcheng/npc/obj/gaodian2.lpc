// gaodian2.c 
// by dwolf 
#include <ansi.h>

inherit ITEM;
inherit F_FOOD;

void create()
{
set_name(MAG"香糕"NOR, ({"xiang gao" }));
	set_weight(80);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", YEL"这是新炒出来的雪花糕，好香啊！\n"NOR);
		set("unit", "个");
		set("value", 50);
		set("food_remaining", 3);
		set("food_supply", 50);
	}
}
