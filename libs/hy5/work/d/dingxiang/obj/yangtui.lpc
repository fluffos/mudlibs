
 
inherit ITEM;
inherit F_FOOD;

void create()
{
   set_name("烤羊腿", ({"kao yangtui","yangtui"}));
        set_weight(100);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "这是一个香气四溢的烤羊腿。\n");
                set("unit", "个");
                set("value", 100);
                set("food_remaining", 30);
                set("food_supply", 50);
        }
}

