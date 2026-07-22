
 
inherit ITEM;
inherit F_FOOD;

void create()
{
   set_name("花生", ({"hua sheng","sheng"}));
        set_weight(100);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "这是一碟炒花生。\n");
                set("unit", "碟");
                set("value", 20);
                set("food_remaining", 5);
                set("food_supply", 20);
        }
}

