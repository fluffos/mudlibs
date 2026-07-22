// rat-meat.c 鼠肉
// 修改：中山大学  张三丰（Micro）----Micro_Liang@Hotmail.Com

inherit ITEM;
inherit F_FOOD;

void create()
{
        set_name("鼠肉", ({ "rat meat", "meat" }) );
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "这是一块鼠肉。\n");
                set("unit", "块");
                set("value", 50);
                set("food_remaining", 4);
                set("food_supply", 50);
        }
        setup();
}

