// qingcai.c 青菜

inherit ITEM;
inherit F_FOOD;

void create()
{
        set_name("青菜", ({ "qingcai" }));
        set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "这是一碗青菜。\n");
                set("unit", "碗");
                set("value", 50);
                set("food_remaining", 1);
                set("food_supply", 20);
        }
    setup();
}
