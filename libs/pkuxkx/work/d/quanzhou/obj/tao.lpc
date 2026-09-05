// tao.c 猕猴桃
#include <ansi.h>
inherit ITEM;
inherit F_FOOD;
void create()
{
        set_name(HIG"猕猴桃"NOR,({"mihou tao","tao"}));
	set_weight(40);
	if(clonep())
		set_default_object(__FILE__);
	else
	{
                set("long","一个水灵灵的猕猴桃。\n");
		set("unit","个");
		set("value",100);
                set("food_remaining",5);
                set("food_supply",100);
	}
}
