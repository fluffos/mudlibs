
 
inherit ITEM;
inherit F_FOOD;

void create()
{
   set_name("咸菜", ({"xian cai","cai"}));
        set_weight(100);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "这是一盘精致的咸菜。\n");
                set("unit", "盘");                
                set("value", 20);
                set("food_remaining", 5);
                set("food_supply", 20);
        }
}

