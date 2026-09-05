inherit ITEM;
inherit F_FOOD;
#include <ansi.h>

void create()
{
        set_name(YEL"黄河鲤鱼"NOR, ({ "huanghe liyu", "liyu" }) );
        set_weight(50);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "这是一盘黄河鲤鱼，洛阳的特产。\n");
                set("unit", "盘");
                set("value", 1000);
                set("food_remaining", 10);
                set("food_supply", 20);
                set("material", "meat");
        }
        setup();
}

