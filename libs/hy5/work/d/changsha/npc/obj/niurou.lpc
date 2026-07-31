
 
inherit ITEM;
inherit F_FOOD;

void create()
{
   set_name("牛肉", ({"niu rou","rou"}));
        set_weight(100);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "这是一块香气四逸的牛肉。\n");
                set("unit", "个");
                set("value", 100);
                set("food_remaining", 10);
                set("food_supply", 50);
        }
}

