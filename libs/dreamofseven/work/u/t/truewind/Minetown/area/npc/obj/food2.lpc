inherit ITEM;
inherit F_FOOD;

void create()
{
        set_name("包裝大餅乾", ({ "packed cookie","cookie" }) );
        set_weight(40);
        {
                set("long", "一片大大的特製餅乾，看起來很普通的樣子，據說吃了有益精神。\n");
                set("unit", "個");
                set("value", 100);       //參考價格為回復點數總和除以5
                set("heal_hp",70);      //可以是"heal_hp"或是"heal_mp",也可以都有.
                set("heal_mp",5);
                set("food_remaining", 5);
        }
        setup();
}