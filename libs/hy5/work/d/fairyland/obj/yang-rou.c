// yang-rou.c

inherit ITEM;
inherit F_FOOD;

void create()
{
        set_name("—Ú»‚", ({"yang rou", "rou"}));
        set_weight(900);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "“ªøÈ”÷∑ ”÷œ„µƒ—Ú»‚°£\n");
                set("unit", "øÈ");
                set("food_remaining", 3);
                set("food_supply", 40);
        }
}
