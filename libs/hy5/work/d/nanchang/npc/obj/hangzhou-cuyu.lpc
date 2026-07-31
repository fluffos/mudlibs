
 
inherit ITEM;
inherit F_FOOD;

void create()
{
   set_name("南昌醋鱼", ({"hangzhou cuyu","yu","fish","cuyu"}));
        set_weight(200);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "这是南昌的特色菜[南昌醋鱼]。\n");
                set("unit", "条");
                set("value", 500);
                set("food_remaining", 30);
                set("food_supply", 50);
        }
}

