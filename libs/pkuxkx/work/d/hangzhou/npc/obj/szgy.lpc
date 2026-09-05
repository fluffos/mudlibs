// szgy.c 松子桂鱼 by hubo

inherit ITEM;
inherit F_FOOD;

void create()
{
        set_name("松子桂鱼", ({"songzi guiyu", "guiyu"}));
        set_weight(100);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "一条大大的，香喷喷的松子桂鱼\n");
                set("unit", "条");
                set("value", 4000);
                set("food_remaining", 5);
               set("food_supply", 30);
        }
}