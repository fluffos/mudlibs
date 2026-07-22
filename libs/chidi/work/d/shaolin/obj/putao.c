// putao.c
inherit ITEM;
inherit F_FOOD;
void create()
{
    set_name("ÆÏÌÑ", ({"putao"}));
    set_weight(1);
    if (clonep())
        set_default_object(__FILE__);
    else {
        set("long", "Ò»¿ÅË®ÁéÁéµÄÆÏÌÑ¡£\n");
        set("unit", "¿Å");
        set("food_remaining", 1);
        set("food_supplay", 5);
    }
}
