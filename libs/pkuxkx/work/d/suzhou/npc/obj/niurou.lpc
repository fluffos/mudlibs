// huotui.c

inherit ITEM;
inherit F_FOOD;
#include <ansi.h>

void create()
{
        set_name(HIG"豌豆"+HIM"辣牛肉"NOR, ({ "wandou niurou", "wandou", "niurou" }) );
        set_weight(900);
	if( clonep() )
		set_default_object(__FILE__);
	else {
                set("long", "鲜香软嫩的豌豆加上滑嫩而不碎的牛肉，构成了这道红绿分明、鲜香微辣、回味悠长的美味佳肴。\n");
                set("unit", "碗");
                set("value", 700);
                set("food_remaining", 4);
		set("food_supply", 20);
		set("material", "meat");
	}
	setup();
}

