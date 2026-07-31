// dish.c ≤ÀÎ»

inherit ITEM;
inherit F_LIQUID;

void create()
{
        set_name("≤ÀÎ»", ({ "dish" }));
        set_weight(40);
        /*if (clonep())
                set_default_object(__FILE__);
        else*/ {
                set("unit", "∑›");
                set("remaining", 5);
                set("drink_supply", 15);
        }
             set("liquid", ([ 
                     "type": "soup", 
                     "name": "Ã¿", 
                     "remaining": 15, 
                     "drunk_apply": 3, 
             ])); 
}
