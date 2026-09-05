// dianxin.c 甜点心
inherit ITEM;
inherit F_FOOD;
void create()
{
        set_name("甜点心", ({"dian xin","dianxin"}));
        set_weight(100);
        if (clonep())
                set_default_object(__FILE__);
        else
        {
                set("long", "一只江南产的甜点心。 \n");
                set("unit", "份");
                set("food_remaining", 5);
                set("food_supply", 30);
        }
}
