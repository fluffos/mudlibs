// rice.c

inherit ITEM;
inherit F_FOOD;

void create()
{
        set_name("鲜花粥", ({ "zhou" }) );
        set_weight(80);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "一个碗以百花做成的粥。\n");
                set("unit", "碗");
                set("value", 0);
                set("food_remaining", 50);
                set("food_supply", 60);
        }
}
