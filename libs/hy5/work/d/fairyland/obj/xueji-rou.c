// xzhang.c —©º¶»‚

inherit ITEM;
inherit F_FOOD;

void create()
{
        set_name("—©º¶»‚", ({"xueji rou", "rou"}));
        set_weight(900);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "“ª÷ª”÷∑ ”÷∞◊µƒ—©º¶»‚°£\n");
                set("unit", "øÈ");
                set("food_remaining", 3);
                set("food_supply", 40);
        }
}
