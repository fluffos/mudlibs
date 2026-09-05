inherit ITEM;
inherit F_FOOD;
#include <ansi.h>

void create()
{
        set_name("冬菜包", ({ "dongcai bao", "bao" }) );
        set_weight(500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "这是一个学一冬菜包，很受众人欢迎。\n");
                set("unit", "盘");
                set("value", 700);
		set("food_remaining", 10);
                set("food_supply", 40);
                set("material", "water");
        }
        setup();
}

