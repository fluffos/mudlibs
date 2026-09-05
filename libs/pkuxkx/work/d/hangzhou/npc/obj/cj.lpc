// cj.c 春卷 by hubo

inherit ITEM;
inherit F_FOOD;

void create()
{
        set_name("春卷", ({"chun juan", "juan"}));
        set_weight(50);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "一盘炸好的春卷\n");
                set("unit", "盘");
                set("value", 200);
                set("food_remaining", 4);
               set("food_supply", 30);
        }
}