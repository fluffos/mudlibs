//Cracked by Roath
// niurou.c 熟牛肉

inherit ITEM;
inherit F_FOOD;

void init();
int do_cut(string);

void create()
{
        set_name("熟牛肉", ({"shou niurou", "rou"}));
        set_weight(200);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "一牒香喷喷的熟牛肉。\n");
                set("unit", "牒");
                set("value", 120);
                set("food_remaining", 3);
                set("food_supply", 80);
        }
        setup();
}
