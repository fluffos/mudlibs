// turou.c ºìÉÕ¹·Èâ

inherit ITEM;
inherit F_FOOD;

void create()
{
        set_name("¶¯ÎïÏÊÈâ", ({"xian rou", "xianrou"}));
        set_weight(300);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "Ò»¿éÑªÁÜÁÜµÄ¶¯ÎïÏÊÈâ¡£\n");
                set("unit", "Íë");
                set("value", 200+random(300));
                set("food_remaining", 4);
                set("food_supply", 80);
        }
}

