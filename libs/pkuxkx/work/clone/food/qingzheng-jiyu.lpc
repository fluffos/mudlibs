inherit ITEM;
inherit F_FOOD;
#include <ansi.h>

void create()
{
        set_name("清蒸鲫鱼", ({ "qingzheng jiyu", "jiyu" }) );
        set_weight(10);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "这是一盘清蒸鲫鱼，鲜气扑鼻。\n");
                set("unit", "盘");
                set("value", 1200);
                set("food_remaining", 5);
                set("food_supply", 20);
                set("material", "meat");
        }
        setup();
}

