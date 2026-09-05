inherit ITEM;
inherit F_FOOD;
#include <ansi.h>

void create()
{
        set_name("扬州炒饭", ({ "yangzhou chaofan", "chaofan" }) );
        set_weight(5000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "这是一碗扬州炒饭，米饭上点缀着火腿、鸡蛋、黄瓜等。\n");
                set("unit", "碗");
		set("value", 3000);
                set("food_remaining", 25);
                set("food_supply", 40);
                set("material", "rice");
        }
        setup();
}

