
 
inherit ITEM;
inherit F_FOOD;

void create()
{
   set_name("红烧羊肉", ({"hongshao yangrou","yangrou"}));
        set_weight(100);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "这是一盘香辣红烧羊肉。\n");
                set("unit", "盘");
                set("value", 400);
                set("food_remaining", 20);
                set("food_supply", 70);
        }
}

