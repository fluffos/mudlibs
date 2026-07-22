
 
inherit ITEM;
inherit F_FOOD;

void create()
{
   set_name("炸肉排", ({"zha roupai","roupai"}));
        set_weight(100);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "这是一盘炸肉排。\n");
                set("unit", "盘");
                set("value", 400);
                set("food_remaining", 20);
                set("food_supply", 70);
        }
}

