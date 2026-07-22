
 
inherit ITEM;
inherit F_FOOD;

void create()
{
   set_name("鸡腿", ({"ji tui","ji","tui"}));
        set_weight(200);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "这是一个鸡腿。\n");
                set("unit", "个");
                set("value", 500);
                set("food_remaining", 20);
                set("food_supply", 20);
        }
}

