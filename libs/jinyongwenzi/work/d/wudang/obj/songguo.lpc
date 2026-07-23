// songguo.c
inherit ITEM;
inherit F_FOOD;

void create()
{
        set_name("野松果", ({ "song guo", "guo" }) );
        set_weight(150);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "一颗松子饱满的野松果实。\n");
                set("unit", "枚");
                set("value", 80);
                set("food_remaining", 4);
                set("food_supply", 15);
        }
        setup();
}

