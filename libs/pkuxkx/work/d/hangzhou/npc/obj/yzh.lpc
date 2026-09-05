// yzh.c 油炸桧 by hubo

inherit ITEM;
inherit F_FOOD;

void create()
{
        set_name("油炸桧", ({"youzhagui"}));
        set_weight(100);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "据说此种点心是为了纪念岳飞而得名\n");
                set("unit", "条");
                set("value", 200);
                set("food_remaining", 4);
               set("food_supply", 30);
        }
}