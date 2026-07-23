
 
inherit ITEM;
inherit F_FOOD;

void create()
{
   set_name("长沙臭豆腐", ({"chou doufu","doufu"}));
        set_weight(100);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "这是一盘香气四溢的长沙臭豆腐。\n");
                set("unit", "盘");
                set("value", 2000);
                set("food_remaining", 100);
                set("food_supply", 100);
        }
}

