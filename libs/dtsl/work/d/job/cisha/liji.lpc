
 
inherit ITEM;
inherit F_FOOD;

int do_eat(string arg);

void create()
{
   set_name("滑溜里脊", ({"liji"}));
        set_weight(100);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "这是九江春在楼的名菜滑溜里脊。\n");
                set("unit", "盘");
                set("value",400);
                //set("no_decay",1);
                set("food_remaining",100);
                set("food_supply",100);
        }
}

