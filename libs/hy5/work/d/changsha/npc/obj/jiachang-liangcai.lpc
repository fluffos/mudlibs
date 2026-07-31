
 
inherit ITEM;
inherit F_FOOD;

void create()
{
   set_name("家常凉菜", ({"liang cai","cai"}));
        set_weight(100);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "这是一盘不错的家常凉菜。\n");
                set("unit", "盘");
                set("value", 1000);
                set("food_remaining", 40);
                set("food_supply", 50);
        }
}

