
 
inherit ITEM;
inherit F_FOOD;

int do_eat(string arg);

void create()
{
   set_name("五香花生", ({"huasheng"}));
        set_weight(20);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "这是一小碟香喷喷的五香花生。\n");
                set("unit", "叠");
                set("value",30);
                //set("no_decay",1);
                set("food_remaining",20);
                set("food_supply",30);
        }
}

