
 
inherit ITEM;
inherit F_FOOD;

void create()
{
   set_name("烤羊肉", ({"kao yangrou","yangrou"}));
        set_weight(100);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "这是一盘香气四溢的烤羊肉。\n");
                set("unit", "盘");
                set("value", 500);
                set("food_remaining", 15);
                set("food_supply", 50);
        }
}

