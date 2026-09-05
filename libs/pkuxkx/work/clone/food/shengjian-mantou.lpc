inherit ITEM;
inherit F_FOOD;
#include <ansi.h>

void create()
{
        set_name("生煎馒头", ({ "shengjian mantou", "mantou" }) );
        set_weight(10);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "这是一个生煎馒头，金黄、硬香带脆，馒身白色，软而松，肉馅鲜嫩，引人食指大动。\n");
                set("unit", "个");
		set("value", 200);
		set("food_remaining", 4);
                set("food_supply", 10);
                set("material", "bread");
        }
        setup();
}

