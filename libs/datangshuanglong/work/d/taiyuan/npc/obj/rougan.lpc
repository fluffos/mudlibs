
 
inherit ITEM;
inherit F_FOOD;

void create()
{
   set_name("肉干", ({"rou gan","rou"}));
        set_weight(100);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "这是一串肉干，长时间不会腐烂。\n");
                set("unit", "串");
                set("no_decay",1);
                set("value", 50);
                set("food_remaining", 5);
                set("food_supply", 20);
        }
}

