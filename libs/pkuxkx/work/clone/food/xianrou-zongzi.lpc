inherit ITEM;
inherit F_FOOD;
#include <ansi.h>

void create()
{
        set_name("鲜肉粽子", ({ "xianrou zongzi", "zongzi" }) );
        set_weight(500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "这是一个鲜肉粽子，散发着热气，好诱人啊～\n");
                set("unit", "个");
                set("value", 10000);
                set("food_remaining", 20);
                set("food_supply", 40);
                set("material", "meat");
        }
        setup();
}

