
 
inherit ITEM;
inherit F_FOOD;

void create()
{
   set_name("宫爆鸡丁", ({"gongbao jiding","jiding"}));
        set_weight(100);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "这是一盘香气四溢的宫爆鸡丁。\n");
                set("unit", "盘");
                set("value", 2000);
                set("food_remaining", 30);
                set("food_supply", 50);
        }
}

