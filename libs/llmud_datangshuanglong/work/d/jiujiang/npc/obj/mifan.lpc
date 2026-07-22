
 
inherit ITEM;
inherit F_FOOD;

void create()
{
   set_name("米饭", ({"rice"}));
        set_weight(100);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "这是一碗香喷喷的大米饭。\n");
                set("unit", "碗");
                set("value", 60);
                set("food_remaining", 15);
                set("food_supply", 60);
        }
}

