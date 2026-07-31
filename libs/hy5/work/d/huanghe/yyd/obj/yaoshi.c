// Hong-yaoshi.c 红钥匙
// zly 99.7.28.

inherit ITEM;

void create()
{
        set_name("红钥匙", ({"hong yaoshi","hys"}));
        set("long",
                "这是一把红钥匙。\n");
        set("unit", "把");
        set("weight", 10);
        set("value", 10000);
        set("no_drop", "这样东西不能离开你。\n");
}
