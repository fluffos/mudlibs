// cai by -wyz
inherit ITEM;
inherit F_FOOD;
void create()
{
        set_name( "¿Û÷¶Œr«Ú", ({"china cai", "lychee"}));
        set_weight(200);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", WHT "’‚ «“ªµ˙œ„≈Á≈Áµƒªõ≤À°£\n" NOR);
                set("unit", "µ˙");
                set("value", 150);
                set("food_remaining", 3);
                set("food_supply", 60);
        }
}

