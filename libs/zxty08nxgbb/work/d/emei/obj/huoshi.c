// huoshi.c
inherit ITEM;

void create()
{
        set_name("火石", ({"fire stone", "stone"}));
        set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "块");
                set("long",
"这是块用来取火的石头。\n");
                set("material", "stone");
        }
}
